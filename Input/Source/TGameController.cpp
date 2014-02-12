/*<---------------------------------------------
| This is the source file for TGameController |
| class which is a wrapper for DirectInput  & |
| XInput(360 Controllers) for Gamepad & Force |
| Feedback functionality for use with the     |
| Troglodyte Game Engine.                     |
-----------------------------------------------
| Author : Will (DecipherOne) Canada          |
| February 17, 2008                           |
| (c) DecipherOne Productions ARR             |
----------------------------------------------*/

//This class is based on Microsoft Examples for using
//DirectInput and XInput and uses sections of those examples.

#include "PCHEADER.h"

#define SAFE_DELETE(p)  { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } }
#define INPUT_DEADZONE  ( 0.24f * FLOAT(0x7FFF) )  // Default to 24% of the +/- 32767 range.   This is a reasonable default value but can be altered if needed.

XINPUT_DEVICE_NODE *  TGameController::g_pXInputDeviceList = NULL;
bool TGameController::g_bFilterOutXinputDevices = true;
LPDIRECTINPUT8  TGameController::g_pDI = NULL;
LPDIRECTINPUTDEVICE8 TGameController::g_pJoystick = NULL;
std::string TGameController::DeviceNames[8]; 
int TGameController::count = 0;
bool TGameController::hasGeneric = false;


TGameController::TGameController()
{

	
	

}

////////////////////////////////////////////////////////////////////////////////

HRESULT TGameController::SetupForIsXInputDevice()
{
	IWbemServices*          pIWbemServices = NULL;
    IEnumWbemClassObject*   pEnumDevices   = NULL;
    IWbemLocator*           pIWbemLocator  = NULL;
    IWbemClassObject*       pDevices[20]   = {0};
    BSTR                    bstrDeviceID   = NULL;
    BSTR                    bstrClassName  = NULL;
    BSTR                    bstrNamespace  = NULL;
    DWORD                   uReturned      = 0;
    bool                    bCleanupCOM    = false;
    UINT                    iDevice        = 0;
    VARIANT                 var;
    HRESULT                 hr;

    // CoInit if needed
    hr = CoInitialize(NULL);
    bCleanupCOM = SUCCEEDED(hr);

    // Create WMI
    hr = CoCreateInstance( __uuidof(WbemLocator),
                           NULL,
                           CLSCTX_INPROC_SERVER,
                           __uuidof(IWbemLocator),
                           (LPVOID*) &pIWbemLocator);

    if( FAILED(hr) || pIWbemLocator == NULL ) 
	{
        goto LCleanup; 
	}

    // Create BSTRs for WMI
    bstrNamespace = SysAllocString( L"\\\\.\\root\\cimv2" ); 

	if( bstrNamespace == NULL ) 
	{
		goto LCleanup;
	}

    bstrDeviceID  = SysAllocString( L"DeviceID" );   

	if( bstrDeviceID == NULL ) 
	{
		goto LCleanup;        
	}

    bstrClassName = SysAllocString( L"Win32_PNPEntity" );    
	
	if( bstrClassName == NULL )
	{
		goto LCleanup;        
	}
    
    // Connect to WMI 
    hr = pIWbemLocator->ConnectServer( bstrNamespace, NULL, NULL, 0L, 
                                       0L, NULL, NULL, &pIWbemServices );

    if( FAILED(hr) || pIWbemServices == NULL )
	{
		goto LCleanup;
	}

    // Switch security level to IMPERSONATE
    CoSetProxyBlanket( pIWbemServices, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, NULL, 
                       RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, 0 );                    

    // Get list of Win32_PNPEntity devices
    hr = pIWbemServices->CreateInstanceEnum( bstrClassName, 0, NULL, &pEnumDevices ); 

    if( FAILED(hr) || pEnumDevices == NULL )
	{
        goto LCleanup;
	}

    // Loop over all devices
    for( ;; )
    {
        // Get 20 at a time
        hr = pEnumDevices->Next( 10000, 20, pDevices, &uReturned );
        if( FAILED(hr) )
            goto LCleanup;
        if( uReturned == 0 )
            break;

        for( iDevice=0; iDevice<uReturned; iDevice++ )
        {
            // For each device, get its device ID
            hr = pDevices[iDevice]->Get( bstrDeviceID, 0L, &var, NULL, NULL );
            if( SUCCEEDED( hr ) && var.vt == VT_BSTR && var.bstrVal != NULL )
            {
                // Check if the device ID contains "IG_".  If it does, then it’s an XInput device
                // Unfortunately this information can not be found by just using DirectInput 
                if( wcsstr( var.bstrVal, L"IG_" ) )
                {
                    // If it does, then get the VID/PID from var.bstrVal
                    DWORD dwPid = 0, dwVid = 0;
                    WCHAR* strVid = wcsstr( var.bstrVal, L"VID_" );
                    if( strVid && swscanf( strVid, L"VID_%4X", &dwVid ) != 1 )
                        dwVid = 0;
                    WCHAR* strPid = wcsstr( var.bstrVal, L"PID_" );
                    if( strPid && swscanf( strPid, L"PID_%4X", &dwPid ) != 1 )
                        dwPid = 0;

                    DWORD dwVidPid = MAKELONG( dwVid, dwPid );

                    // Add the VID/PID to a linked list
                    XINPUT_DEVICE_NODE* pNewNode = new XINPUT_DEVICE_NODE;
                    if( pNewNode )
                    {
                        pNewNode->dwVidPid = dwVidPid;
                        pNewNode->pNext = TGameController::g_pXInputDeviceList;
                        TGameController::g_pXInputDeviceList = pNewNode;
                    }
                }
            }   
            SAFE_RELEASE( pDevices[iDevice] );
        }
    }

LCleanup:
    if(bstrNamespace)
	{
        SysFreeString(bstrNamespace);
	}

    if(bstrDeviceID)
	{
        SysFreeString(bstrDeviceID);
	}

    if(bstrClassName)
	{
        SysFreeString(bstrClassName);
	}

    for( iDevice=0; iDevice<20; iDevice++ )
	{
        SAFE_RELEASE( pDevices[iDevice] );
	}

    SAFE_RELEASE( pEnumDevices );
    SAFE_RELEASE( pIWbemLocator );
    SAFE_RELEASE( pIWbemServices );

    return hr;
}

///////////////////////////////////////////////////////////////////////////////////


bool TGameController::IsXInputDevice( const GUID* pGuidProductFromDirectInput )
{
    // Check each xinput device to see if this device's vid/pid matches
    XINPUT_DEVICE_NODE * pNode = TGameController::g_pXInputDeviceList;
    while( pNode )
    {
        if( pNode->dwVidPid == pGuidProductFromDirectInput->Data1 )
		{
            return true;
		}

        pNode = pNode->pNext;
    }

    return false;
}

///////////////////////////////////////////////////////////////////////////////////

void TGameController::CleanupForIsXInputDevice()
{
    // Cleanup linked list
    XINPUT_DEVICE_NODE * pNode = TGameController::g_pXInputDeviceList;
    while( pNode )
    {
        XINPUT_DEVICE_NODE* pDelete = pNode;
        pNode = pNode->pNext;
        SAFE_DELETE( pDelete );
    }
}

//////////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
// Name: InitDirectInput()
// Desc: Initialize the DirectInput variables.
//-----------------------------------------------------------------------------
bool TGameController::InitDirectInput()
{
    HRESULT hr;

    // Register with the DirectInput subsystem and get a pointer
    // to a IDirectInput interface we can use.
    // Create a DInput object
    if( FAILED( hr = DirectInput8Create( GetModuleHandle(NULL), DIRECTINPUT_VERSION, 
                                         IID_IDirectInput8, (VOID**)&TGameController::g_pDI, NULL ) ) )
	{
        return false;
	}

	

    if(TGameController::g_bFilterOutXinputDevices )
	{
        SetupForIsXInputDevice();
	}

    DIJOYCONFIG PreferredJoyCfg = {0};
    DI_ENUM_CONTEXT enumContext;
    enumContext.pPreferredJoyCfg = &PreferredJoyCfg;
    enumContext.bPreferredJoyCfgValid = false;

    IDirectInputJoyConfig8* pJoyConfig = NULL;  
    if( FAILED( hr = TGameController::g_pDI->QueryInterface( IID_IDirectInputJoyConfig8, (void **) &pJoyConfig ) ) )
	{
		return false;
	}

    PreferredJoyCfg.dwSize = sizeof(PreferredJoyCfg);
    if( SUCCEEDED( pJoyConfig->GetConfig(0, &PreferredJoyCfg, DIJC_GUIDINSTANCE ) ) ) // This function is expected to fail if no Joystick is attached
	{
		enumContext.bPreferredJoyCfgValid = true;
	}

    SAFE_RELEASE( pJoyConfig );

	

    // Look for a Joystick 
    if( FAILED( hr = TGameController::g_pDI->EnumDevices( DI8DEVCLASS_GAMECTRL, 
                                         EnumJoysticksCallback,
                                         &enumContext, DIEDFL_ATTACHEDONLY ) ) )
	{
        return false;
	}

    if( TGameController::g_bFilterOutXinputDevices )
	{
        CleanupForIsXInputDevice();
	}

    // Make sure we got a Joystick
    if( NULL == g_pJoystick )
    {
       return false;
    }

    // Set the data format to "simple Joystick" - a predefined data format 
    //
    // A data format specifies which controls on a device we are interested in,
    // and how they should be reported. This tells DInput that we will be
    // passing a DIJOYSTATE2 structure to IDirectInputDevice::GetDeviceState().
    if( FAILED( hr = g_pJoystick->SetDataFormat( &c_dfDIJoystick2 ) ) )
	{
        return false;
	}

	// Enumerate the Joystick objects. The callback function enabled user
    // interface elements for objects that are found, and sets the min/max
    // values property for discovered axes.
    if( FAILED( hr = g_pJoystick->EnumObjects( EnumObjectsCallback, 
                                                (VOID*)TrogWin.hWnd, DIDFT_ALL ) ) )
	{
        return false;
	}

    // Set the cooperative level to let DInput know how this device should
    // interact with the system and with other DInput applications.
    if( FAILED( hr = g_pJoystick->SetCooperativeLevel(TrogWin.hWnd, DISCL_EXCLUSIVE | 
                                                             DISCL_FOREGROUND ) ) )
	{
        return false;
	}

    



	

    return true;
}


////////////////////////////////////////////////////////////////////////////////


//-----------------------------------------------------------------------------
// Name: EnumJoysticksCallback()
// Desc: Called once for each enumerated Joystick. If we find one, create a
//       device interface on it so we can play with it.
//-----------------------------------------------------------------------------
BOOL CALLBACK TGameController::EnumJoysticksCallback( const DIDEVICEINSTANCE* pdidInstance,
                                     VOID* pContext )
{
	


    HRESULT hr;


	//Filterout 360 Controlers so they can be handled by XNA
    if( TGameController::g_bFilterOutXinputDevices && IsXInputDevice( &pdidInstance->guidProduct ) )
        return DIENUM_CONTINUE;


    // Obtain an interface to the enumerated Joystick.
    hr = g_pDI->CreateDevice( pdidInstance->guidInstance, &g_pJoystick, NULL );

    // If it failed, then we can't use this Joystick. (Maybe the user unplugged
    // it while we were in the middle of enumerating it.)
    if( FAILED(hr) ) 
	{
		hasGeneric = false;
		InputLog_Gamepads.WriteMessage("User Unplugged Controller");
        return DIENUM_CONTINUE;
	}

	else
	{
		InputLog_Gamepads.WriteMessage("Generic Gamepads or Joysticks found.");
		hasGeneric = true;
	}

	// store all the enumerated Joysticks names and let the user pick which
	// device they want to use else where.

	if(count<7)
	{	
		DeviceNames[count] = pdidInstance->tszProductName;

		if(DeviceNames[count]!="")
		{
			InputLog_Gamepads.WriteMessage("Gamepad Device - "+ DeviceNames[count] +
				"has been found.");
			count += 1;
		}
	}
	else
	{
		MessageBox(NULL,"You have too many Generic Game Controllers Connected to your computer.\n"
			" Please limit the number to 8 and then try restarting the application.","Game Controller Connection Error!",
			MB_ICONERROR|MB_OK);
		ErrorLog.WriteMessage("You have too many Generic Game Controllers Connected to your computer.\n"
			" Please limit the number to 8 and then try restarting the application.");
		PostQuitMessage(0);
		count = 0;
	}

    return DIENUM_CONTINUE;
}

//////////////////////////////////////////////////////////////////////////////////


BOOL CALLBACK TGameController::EnumObjectsCallback( const DIDEVICEOBJECTINSTANCE* pdidoi,
                                   VOID* pContext )
{
    HWND hDlg = (HWND)pContext;
	DIDEVCAPS Capability;
    HRESULT hr;


	Capability.dwSize = sizeof(DIDEVCAPS);

	
	

	// Determine how many axis the joystick has (so we don't error out setting
	// properties for unavailable axis)

	if (FAILED(hr = g_pJoystick->GetCapabilities(&Capability))) 
	{
	 return hr;
	}

	

	static int nSliderCount = Capability.dwAxes;  // Number of returned slider controls
	static int nPOVCount = Capability.dwPOVs;     // Number of returned POV controls

    // For axes that are returned, set the DIPROP_RANGE property for the
    // enumerated axis in order to scale min/max values.

	
    if( pdidoi->dwType & DIDFT_AXIS )
    {
        DIPROPRANGE diprg; 
        diprg.diph.dwSize       = sizeof(DIPROPRANGE); 
        diprg.diph.dwHeaderSize = sizeof(DIPROPHEADER); 
        diprg.diph.dwHow        = DIPH_BYID; 
        diprg.diph.dwObj        = pdidoi->dwType; // Specify the enumerated axis
        diprg.lMin              = -32768; 
        diprg.lMax              = +32768; 
    

        // Set the range for the axis
        if( FAILED( g_pJoystick->SetProperty( DIPROP_RANGE, &diprg.diph ) ) ) 
            return DIENUM_STOP;
         
    } 
	

	//Set the DeadZone

	DIPROPDWORD dipdw;
    dipdw.diph.dwSize       = sizeof(DIPROPDWORD);
    dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
    dipdw.diph.dwObj        = DIJOFS_X;
    dipdw.diph.dwHow        = DIPH_BYOFFSET;
    dipdw.dwData            = INPUT_DEADZONE;

    g_pJoystick->SetProperty(DIPROP_DEADZONE,&dipdw.diph);

	dipdw.diph.dwObj = DIJOFS_Y;         
	g_pJoystick->SetProperty(DIPROP_DEADZONE,&dipdw.diph);

    dipdw.diph.dwObj = DIJOFS_Z;
    g_pJoystick->SetProperty(DIPROP_DEADZONE,&dipdw.diph);

    dipdw.diph.dwObj = DIJOFS_RX;
    g_pJoystick->SetProperty(DIPROP_DEADZONE,&dipdw.diph);

    dipdw.diph.dwObj = DIJOFS_RY;
    g_pJoystick->SetProperty(DIPROP_DEADZONE,&dipdw.diph);
        
    dipdw.diph.dwObj = DIJOFS_RZ;
    g_pJoystick->SetProperty(DIPROP_DEADZONE,&dipdw.diph);

    return DIENUM_CONTINUE;
}



////////////////////////////////////////////////////////////////////////////////


HRESULT TGameController::UpdateGenericState()
{
	
    HRESULT     hr;
	DIJOYSTATE2 js;  
	

	int c=0;

	do
	{
		hr = g_pJoystick->Acquire();

		if(hr==DIERR_UNPLUGGED)
		{
			Generics[c].isConnected = false;
			Generics[c].DeviceID =-1;
			Generics[c].DeviceName ="";
			InputLog_Gamepads.WriteMessage("A Gamepad is unplugged.");
			return hr;
		
		}

	

			Generics[c].isConnected = true;
			Generics[c].DeviceID = c;
			Generics[c].DeviceName = DeviceNames[c];



			if( NULL == g_pJoystick ) 
				return S_OK;

			// Poll the device to read the current state
			hr = g_pJoystick->Poll(); 
			if( FAILED(hr) )  
			{
				// DInput is telling us that the input stream has been
				// interrupted. We aren't tracking any state between polls, so
				// we don't have any special reset that needs to be done. We
				// just re-acquire and try again.
				
				while( hr == DIERR_INPUTLOST ) 
					hr = g_pJoystick->Acquire();

				// hr may be DIERR_OTHERAPPHASPRIO or other errors.  This
				// may occur when the app is minimized or in the process of 
				// switching, so just try again later 
				return S_OK; 
			}

			// Get the input's device state
			if( FAILED( hr = g_pJoystick->GetDeviceState( sizeof(DIJOYSTATE2), &js ) ) )
				return hr; // The device should have been acquired during the Poll()


			//Update our Generics struct Data for Axis and the Digital Pad

			
			//Digital Pad

			switch(js.rgdwPOV[0])
			{
			case 0://North
				{
					Generics[c].Digi_Pad.N = true;
					Generics[c].Digi_Pad.NE = false;
					Generics[c].Digi_Pad.E = false;
					Generics[c].Digi_Pad.SE = false;
					Generics[c].Digi_Pad.S = false;
					Generics[c].Digi_Pad.SW = false;
					Generics[c].Digi_Pad.W = false;
					Generics[c].Digi_Pad.NW = false;
					InputLog_Gamepads.WriteMessage("User pressed North on the digital pad.");
					break;
				}


			case 4500://North East
				{
					Generics[c].Digi_Pad.N = false;
					Generics[c].Digi_Pad.NE = true;
					Generics[c].Digi_Pad.E = false;
					Generics[c].Digi_Pad.SE = false;
					Generics[c].Digi_Pad.S = false;
					Generics[c].Digi_Pad.SW = false;
					Generics[c].Digi_Pad.W = false;
					Generics[c].Digi_Pad.NW = false;
					InputLog_Gamepads.WriteMessage("User pressed NE on the digital pad.");
					break;
				}

			
			case 9000://East
				{
					Generics[c].Digi_Pad.N = false;
					Generics[c].Digi_Pad.NE = false;
					Generics[c].Digi_Pad.E = true;
					Generics[c].Digi_Pad.SE = false;
					Generics[c].Digi_Pad.S = false;
					Generics[c].Digi_Pad.SW = false;
					Generics[c].Digi_Pad.W = false;
					Generics[c].Digi_Pad.NW = false;
					InputLog_Gamepads.WriteMessage("User pressed East on the digital pad.");
					break;
				}

			
			case 13500://South East
				{
					Generics[c].Digi_Pad.N = false;
					Generics[c].Digi_Pad.NE = false;
					Generics[c].Digi_Pad.E = false;
					Generics[c].Digi_Pad.SE = true;
					Generics[c].Digi_Pad.S = false;
					Generics[c].Digi_Pad.SW = false;
					Generics[c].Digi_Pad.W = false;
					Generics[c].Digi_Pad.NW = false;
					InputLog_Gamepads.WriteMessage("User pressed SE on the digital pad.");
					break;
				}

			case 18000://South
				{
					Generics[c].Digi_Pad.N = false;
					Generics[c].Digi_Pad.NE = false;
					Generics[c].Digi_Pad.E = false;
					Generics[c].Digi_Pad.SE = false;
					Generics[c].Digi_Pad.S = true;
					Generics[c].Digi_Pad.SW = false;
					Generics[c].Digi_Pad.W = false;
					Generics[c].Digi_Pad.NW = false;
					InputLog_Gamepads.WriteMessage("User pressed South on the digital pad.");
					break;
				}

			case 22500://South West
				{
					Generics[c].Digi_Pad.N = false;
					Generics[c].Digi_Pad.NE = false;
					Generics[c].Digi_Pad.E = false;
					Generics[c].Digi_Pad.SE = false;
					Generics[c].Digi_Pad.S = false;
					Generics[c].Digi_Pad.SW = true;
					Generics[c].Digi_Pad.W = false;
					Generics[c].Digi_Pad.NW = false;
					InputLog_Gamepads.WriteMessage("User pressed SW on the digital pad.");
					break;
				}
			case 27000://West
				{
					Generics[c].Digi_Pad.N = false;
					Generics[c].Digi_Pad.NE = false;
					Generics[c].Digi_Pad.E = false;
					Generics[c].Digi_Pad.SE = false;
					Generics[c].Digi_Pad.S = false;
					Generics[c].Digi_Pad.SW = false;
					Generics[c].Digi_Pad.W = true;
					Generics[c].Digi_Pad.NW = false;
					InputLog_Gamepads.WriteMessage("User pressed West on the digital pad.");
					break;
				}

			case 31500://North West
				{
					Generics[c].Digi_Pad.N = false;
					Generics[c].Digi_Pad.NE = false;
					Generics[c].Digi_Pad.E = false;
					Generics[c].Digi_Pad.SE = false;
					Generics[c].Digi_Pad.S = false;
					Generics[c].Digi_Pad.SW = false;
					Generics[c].Digi_Pad.W = false;
					Generics[c].Digi_Pad.NW = true;
					InputLog_Gamepads.WriteMessage("User pressed SW on the digital pad.");
					break;
				}

			default:
				{
					Generics[c].Digi_Pad.N = false;
					Generics[c].Digi_Pad.NE = false;
					Generics[c].Digi_Pad.E = false;
					Generics[c].Digi_Pad.SE = false;
					Generics[c].Digi_Pad.S = false;
					Generics[c].Digi_Pad.SW = false;
					Generics[c].Digi_Pad.W = false;
					Generics[c].Digi_Pad.NW = false;
					break;
				}
			}

			//Analog Sticks

			Generics[c].Left_TX = js.lX;
			Generics[c].Left_TY = js.lY;
			Generics[c].Right_TX = js.lRz;
			Generics[c].Right_TY = js.rglSlider[0];

			

			//Test for button presses 128 of them.
			int k =0;

			do
			{
				if(js.rgbButtons[k]==128)
				{
					if(Generics[c].Buttons[k])
					{
						Generics[c].preButtons[k]=true;
					}
					Generics[c].Buttons[k]=true;
					

					std:string b_s = to_string(long long(k));
					InputLog_Gamepads.WriteMessage(Generics[c].DeviceName +"\n"+
						"- User pressed button : "+ b_s);

				}


				else
				{
					Generics[c].Buttons[k]=false;
					Generics[c].preButtons[k]=false;
				}

				k++;

			}
			while(k<=127);

			c++;

	}
	while(c<count);


	
    return S_OK;
}




/////////////////////////////////////////////////////////////////////////////////

void TGameController::FreeDirectInput()
{
	
    // Unacquire the device one last time just in case 
    // the app tried to exit while the device is still acquired.
    if( g_pJoystick ) 
        g_pJoystick->Unacquire();
    
    // Release any DirectInput objects.
    SAFE_RELEASE( g_pJoystick );
    SAFE_RELEASE( TGameController::g_pDI ); 
}

//////////////////////////////////////////////////////////////////////////////////

TGameController::~TGameController()
{

}

//////////////////////////////////////////////////////////////////////////////////

void TGameController::Set360States()
{

	 DWORD dwResult; 
	 
	int c=0;

	do
	{

		// Simply get the state of the controller from XInput.
        dwResult = XInputGetState( c, &m360s[c].State );

        if( dwResult == ERROR_SUCCESS )
		{
			m360s[c].isConnected = true;
			m360s[c].DeviceID = c;
			m360s[c].DeviceName = "360 Controller";
			XInputSetState(c,&m360s[c].FF);
		}
	
        else
		{
            m360s[c].isConnected= false;  
			m360s[c].DeviceID =-1;
			m360s[c].DeviceName ="";
			
		}

		

		c ++;

	}
	while(c<=3);

}

/////////////////////////////////////////////////////////////////////////////////

void TGameController::Get360State()
{

	int c=0;

	do
	{


		//If the controllers connected look for a change in the device states from the previous update.
		if(m360s[c].isConnected && m360s[c].PrevPacketNum != m360s[c].State.dwPacketNumber) 
		{

			// Zero value if thumbsticks are within the dead zone 
				if( m360s[c].State.Gamepad.sThumbLX < INPUT_DEADZONE && m360s[c].State.Gamepad.sThumbLX > -INPUT_DEADZONE)
                {   
                    m360s[c].State.Gamepad.sThumbLX = 0;
                }

				if( m360s[c].State.Gamepad.sThumbLY < INPUT_DEADZONE && m360s[c].State.Gamepad.sThumbLY > -INPUT_DEADZONE) 
				{
					m360s[c].State.Gamepad.sThumbLY = 0;
				}

                if( m360s[c].State.Gamepad.sThumbRX < INPUT_DEADZONE && m360s[c].State.Gamepad.sThumbRX > -INPUT_DEADZONE)   
                {
                    m360s[c].State.Gamepad.sThumbRX = 0;
                    
                }

				if( m360s[c].State.Gamepad.sThumbRY < INPUT_DEADZONE && m360s[c].State.Gamepad.sThumbRY > -INPUT_DEADZONE)
				 {
					 m360s[c].State.Gamepad.sThumbRY = 0;
				 }

			// Check for Trigger DeadZones 

				if( m360s[c].State.Gamepad.bLeftTrigger < XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
				{
					m360s[c].State.Gamepad.bLeftTrigger = 0;
				}

				if( m360s[c].State.Gamepad.bRightTrigger < XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
				{
					m360s[c].State.Gamepad.bRightTrigger = 0;
				}



			// Check for Button Presses //
		//---------------------------------//


				//Digital Pad up
				if(m360s[c].State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
				{
					if(m360s[c].prevState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
					{
						m360s[c].prevDigi_Pad.N = true;
						InputLog_Gamepads.WriteMessage("User is holding North on the 360 digital pad.");

					}

					else
					{
						m360s[c].prevDigi_Pad.N = false;
					}

					m360s[c].Digi_Pad.N = true;
					InputLog_Gamepads.WriteMessage("User pressed North on the 360 digital pad.");
				}

				else
				{
					m360s[c].Digi_Pad.N = false;
				}

				//Digital Pad down
				if(m360s[c].State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)
				{
					if(m360s[c].prevState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)
					{
						m360s[c].prevDigi_Pad.S = true;
						InputLog_Gamepads.WriteMessage("User is holding South on the 360 digital pad.");
					}

					else
					{
						m360s[c].prevDigi_Pad.S = false;
					}
					m360s[c].Digi_Pad.S = true;
					InputLog_Gamepads.WriteMessage("User pressed South on the 360 digital pad.");
				}

				else
				{
					m360s[c].Digi_Pad.S = false;
				}

				//Digital Pad Right
				if(m360s[c].State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
				{
					if(m360s[c].prevState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
					{
						m360s[c].prevDigi_Pad.E = true;
						InputLog_Gamepads.WriteMessage("User is holding East on the 360 digital pad.");
					}

					else
					{
						m360s[c].prevDigi_Pad.E = false;
					}

					m360s[c].Digi_Pad.E = true;
					InputLog_Gamepads.WriteMessage("User pressed East on the 360 digital pad.");
				}

				else
				{
					m360s[c].Digi_Pad.E = false;
				}


				//Digital Pad Left
				if(m360s[c].State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)
				{
					if(m360s[c].prevState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)
					{
						m360s[c].prevDigi_Pad.W = true;
						InputLog_Gamepads.WriteMessage("User is holding  West on the 360 digital pad.");
					}

					else
					{
						m360s[c].prevDigi_Pad.W = false;
					}
					m360s[c].Digi_Pad.W = true;
					InputLog_Gamepads.WriteMessage("User pressed West on the 360 digital pad.");
				}

				else
				{
					m360s[c].Digi_Pad.W = false;
				}


				//Digital Pad Up & Right

				if(m360s[c].Digi_Pad.N & m360s[c].Digi_Pad.E )
				{
					if(m360s[c].prevDigi_Pad.N & m360s[c].prevDigi_Pad.E )
					{
						m360s[c].prevDigi_Pad.NE = true;
					}

					else
					{
						m360s[c].prevDigi_Pad.NE = false;
					}

					m360s[c].Digi_Pad.NE = true;
				}

				else
				{
					m360s[c].Digi_Pad.NE = false;
				}


				//Digital Pad Down & Right

				if(m360s[c].Digi_Pad.S & m360s[c].Digi_Pad.E )
				{
					if(m360s[c].prevDigi_Pad.S & m360s[c].prevDigi_Pad.E )
					{
						m360s[c].prevDigi_Pad.SE = true;
					}

					else
					{
						m360s[c].prevDigi_Pad.SE = false;
					}

					m360s[c].Digi_Pad.SE = true;
				}

				else
				{
					m360s[c].Digi_Pad.SE = false;
				}

				//Digital Pad Down & Left

				if(m360s[c].Digi_Pad.S & m360s[c].Digi_Pad.W )
				{
					if(m360s[c].prevDigi_Pad.S & m360s[c].prevDigi_Pad.W )
					{
						m360s[c].prevDigi_Pad.SW = true;
					}

					else
					{
						m360s[c].prevDigi_Pad.SW = false;
					}

					m360s[c].Digi_Pad.SW = true;
				}

				else
				{
					m360s[c].Digi_Pad.SW = false;
				}

				//Digital Pad Up & Left

				if(m360s[c].Digi_Pad.N & m360s[c].Digi_Pad.W )
				{
					if(m360s[c].prevDigi_Pad.N & m360s[c].prevDigi_Pad.W )
					{
						m360s[c].prevDigi_Pad.NW = true;
					}

					else
					{
						m360s[c].prevDigi_Pad.NW = false;
					}

					m360s[c].Digi_Pad.NW = true;
				}

				else
				{
					m360s[c].Digi_Pad.NW = false;
				}


				//Left thumbstick
				if(m360s[c].State.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB)
				{
					if(m360s[c].prevState.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB)
					{
						m360s[c].preButtons.LeftThumb = true;
					}

					else
					{
						m360s[c].preButtons.LeftThumb = false;
					}

					m360s[c].Buttons.LeftThumb = true;
				}

				else
				{
					m360s[c].Buttons.LeftThumb = false;
				}

				//Right thumbstick
				if(m360s[c].State.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB)
				{
					if(m360s[c].prevState.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB)
					{
						m360s[c].preButtons.RightThumb = true;
					}

					else
					{
						m360s[c].preButtons.RightThumb = false;
					}

					m360s[c].Buttons.RightThumb = true;
				} 

				else
				{
					m360s[c].Buttons.RightThumb = false;
				}

				//Left Shoulder
				if(m360s[c].State.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
				{
					if(m360s[c].prevState.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
					{
						m360s[c].preButtons.LeftShoulder = true;

					}

					else
					{
						m360s[c].preButtons.LeftShoulder = false;
					}

					m360s[c].Buttons.LeftShoulder = true;
					InputLog_Gamepads.WriteMessage("User pressed Left Bump on the 360 digital pad.");
				}

				else
				{
					m360s[c].Buttons.LeftShoulder = false;
				}

				//Right Shoulder
				if(m360s[c].State.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER)
				{
					if(m360s[c].prevState.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER)
					{
						m360s[c].preButtons.RightShoulder= true;
					}

					else
					{
						m360s[c].preButtons.RightShoulder = false;
					}

					m360s[c].Buttons.RightShoulder = true;
					InputLog_Gamepads.WriteMessage("User pressed Right Bump on the 360 digital pad.");
				}

				else
				{
					m360s[c].Buttons.RightShoulder = false;
				}

				//Back Button
				if(m360s[c].State.Gamepad.wButtons & XINPUT_GAMEPAD_BACK)
				{
					if(m360s[c].prevState.Gamepad.wButtons & XINPUT_GAMEPAD_BACK)
					{
						m360s[c].preButtons.Back  = true;
					}

					else
					{
						m360s[c].preButtons.Back = false;
					}

					m360s[c].Buttons.Back = true;
					InputLog_Gamepads.WriteMessage("User pressed BackButton on the 360 digital pad.");
				}

				else
				{
					m360s[c].Buttons.Back = false;
				}

				//Start Button
				if(m360s[c].State.Gamepad.wButtons & XINPUT_GAMEPAD_START)
				{
					if(m360s[c].prevState.Gamepad.wButtons & XINPUT_GAMEPAD_START)
					{
						m360s[c].preButtons.Start = true;
					}

					else
					{
						m360s[c].preButtons.Start = false;
					}

					m360s[c].Buttons.Start = true;
					InputLog_Gamepads.WriteMessage("User pressed Start on the 360 digital pad.");
				}

				else
				{
					m360s[c].Buttons.Start = false;
				}

				//A Button
				if(m360s[c].State.Gamepad.wButtons & XINPUT_GAMEPAD_A)
				{
					if(m360s[c].prevState.Gamepad.wButtons & XINPUT_GAMEPAD_A)
					{
						m360s[c].preButtons.A = true;
					}

					else
					{
						m360s[c].preButtons.A = false;
					}

					m360s[c].Buttons.A = true;
					InputLog_Gamepads.WriteMessage("User pressed A on the 360 digital pad.");
				}

				else
				{
					m360s[c].Buttons.A = false;
				}

				//B Button
				if(m360s[c].State.Gamepad.wButtons & XINPUT_GAMEPAD_B)
				{
					if(m360s[c].prevState.Gamepad.wButtons & XINPUT_GAMEPAD_B)
					{
						m360s[c].preButtons.B = true;
					}

					else
					{
						m360s[c].preButtons.B = false;
					}

					m360s[c].Buttons.B = true;
					InputLog_Gamepads.WriteMessage("User pressed B on the 360 digital pad.");
				}

				else
				{
					m360s[c].Buttons.B = false;
				}

				//Y Button
				if(m360s[c].State.Gamepad.wButtons & XINPUT_GAMEPAD_Y)
				{
					if(m360s[c].prevState.Gamepad.wButtons & XINPUT_GAMEPAD_Y)
					{
						m360s[c].preButtons.Y = true;
					}

					else
					{
						m360s[c].preButtons.Y = false;
					}

					m360s[c].Buttons.Y = true;
					InputLog_Gamepads.WriteMessage("User pressed Y on the 360 digital pad.");
				}

				else
				{
					m360s[c].Buttons.Y = false;
				}

				//X Button
				if(m360s[c].State.Gamepad.wButtons & XINPUT_GAMEPAD_X)
				{
					if(m360s[c].prevState.Gamepad.wButtons & XINPUT_GAMEPAD_X)
					{
						m360s[c].preButtons.X = true;
					}

					else
					{
						m360s[c].preButtons.X= false;
					}

					m360s[c].Buttons.X = true;
					InputLog_Gamepads.WriteMessage("User pressed X on the 360 digital pad.");
				}

				else
				{
					m360s[c].Buttons.X = false;
				}

				

			// Check different Thresholds //
		//-----------------------------------//

				// Left Thumb barely being pressed Left
				if(m360s[c].State.Gamepad.sThumbLX < 0 && 
					m360s[c].State.Gamepad.sThumbLX > -10924)
				{
					m360s[c].L_Thumb.Neg_X_small = true;
				}

				else
				{
					m360s[c].L_Thumb.Neg_X_small = false;
				}

				// Left Thumb being pressed Left
				if(m360s[c].State.Gamepad.sThumbLX < -10923 && 
					m360s[c].State.Gamepad.sThumbLX > -21847 )
				{
					m360s[c].L_Thumb.Neg_X = true;
				}

				else
				{
					m360s[c].L_Thumb.Neg_X = false;
				}

				// Left Thumb being pressed all the way over Left
				if(m360s[c].State.Gamepad.sThumbLX < -21846 && 
					m360s[c].State.Gamepad.sThumbLX > -32769)
				{
					m360s[c].L_Thumb.Neg_X_large = true;
				}

				else
				{
					m360s[c].L_Thumb.Neg_X_large  = false;
				}



				// Left Thumb barely being pressed Right
				if(m360s[c].State.Gamepad.sThumbLX > 0 && 
					m360s[c].State.Gamepad.sThumbLX < 10924)
				{
					m360s[c].L_Thumb.Pos_X_small = true;
				}

				else
				{
					m360s[c].L_Thumb.Pos_X_small = false;
				}

				// Left Thumb being pressed Right
				if(m360s[c].State.Gamepad.sThumbLX > 10923 && 
					m360s[c].State.Gamepad.sThumbLX < 21847 )
				{
					m360s[c].L_Thumb.Pos_X = true;
				}

				else
				{
					m360s[c].L_Thumb.Pos_X = false;
				}

				// Left Thumb being pressed all the way over Right
				if(m360s[c].State.Gamepad.sThumbLX > 21846 && 
					m360s[c].State.Gamepad.sThumbLX < 32769)
				{
					m360s[c].L_Thumb.Pos_X_large = true;
				}

				else
				{
					m360s[c].L_Thumb.Pos_X_large = false;
				}


				// Left Thumb barely being pressed Down
				if(m360s[c].State.Gamepad.sThumbLY < 0 && 
					m360s[c].State.Gamepad.sThumbLY > -10924)
				{
					m360s[c].L_Thumb.Neg_Y_small = true;
				}

				else
				{
					m360s[c].L_Thumb.Neg_Y_small = false;
				}

				// Left Thumb being pressed Down
				if(m360s[c].State.Gamepad.sThumbLY < -10923 && 
					m360s[c].State.Gamepad.sThumbLY > -21847 )
				{
					m360s[c].L_Thumb.Neg_Y = true;
				}

				else
				{
					m360s[c].L_Thumb.Neg_Y = false;
				}

				// Left Thumb being pressed all the way Down
				if(m360s[c].State.Gamepad.sThumbLY < -21846 && 
					m360s[c].State.Gamepad.sThumbLY > -32769)
				{
					m360s[c].L_Thumb.Neg_Y_large = true;
				}

				else
				{
					m360s[c].L_Thumb.Neg_Y_large = false;
				}


				// Left Thumb barely being pressed Up
				if(m360s[c].State.Gamepad.sThumbLY > 0 && 
					m360s[c].State.Gamepad.sThumbLY < 10924)
				{
					m360s[c].L_Thumb.Pos_Y_small = true;
				}

				else
				{
					m360s[c].L_Thumb.Pos_Y_small = false;
				}

				// Left Thumb being pressed UP
				if(m360s[c].State.Gamepad.sThumbLY > 10923 && 
					m360s[c].State.Gamepad.sThumbLY < 21847 )
				{
					m360s[c].L_Thumb.Pos_Y = true;
				}

				else
				{
					m360s[c].L_Thumb.Pos_Y = false;
				}

				// Left Thumb being pressed all the way Up
				if(m360s[c].State.Gamepad.sThumbLY > 21846 && 
					m360s[c].State.Gamepad.sThumbLY < 32769)
				{
					m360s[c].L_Thumb.Pos_Y_large = true;
				}

				else
				{
					m360s[c].L_Thumb.Pos_Y_large = false;
				}

				//--------------------------------------------------------------


				// Right  Thumb barely being pressed Left
				if(m360s[c].State.Gamepad.sThumbRX < 0 && 
					m360s[c].State.Gamepad.sThumbRX > -10924)
				{
					m360s[c].R_Thumb.Neg_X_small = true;
				}

				else
				{
					m360s[c].R_Thumb.Neg_X_small = false;
				}

				// Right Thumb being pressed Left
				if(m360s[c].State.Gamepad.sThumbRX < -10923 && 
					m360s[c].State.Gamepad.sThumbRX > -21847 )
				{
					m360s[c].R_Thumb.Neg_X = true;
				}

				else
				{
					m360s[c].R_Thumb.Neg_X = false;
				}

				// Right  Thumb being pressed all the way over Left
				if(m360s[c].State.Gamepad.sThumbRX < -21846 && 
					m360s[c].State.Gamepad.sThumbRX > -32769)
				{
					m360s[c].R_Thumb.Neg_X_large = true;
				}

				else
				{
					m360s[c].R_Thumb.Neg_X_large  = false;
				}



				// Right  Thumb barely being pressed Right
				if(m360s[c].State.Gamepad.sThumbRX > 0 && 
					m360s[c].State.Gamepad.sThumbRX < 10924)
				{
					m360s[c].R_Thumb.Pos_X_small = true;
				}

				else
				{
					m360s[c].R_Thumb.Pos_X_small = false;
				}

				//Right  Thumb being pressed Right
				if(m360s[c].State.Gamepad.sThumbRX > 10923 && 
					m360s[c].State.Gamepad.sThumbRX < 21847 )
				{
					m360s[c].R_Thumb.Pos_X = true;
				}

				else
				{
					m360s[c].R_Thumb.Pos_X = false;
				}

				// Right  Thumb being pressed all the way over Right
				if(m360s[c].State.Gamepad.sThumbRX > 21846 && 
					m360s[c].State.Gamepad.sThumbRX < 32769)
				{
					m360s[c].R_Thumb.Pos_X_large = true;
				}

				else
				{
					m360s[c].R_Thumb.Pos_X_large = false;
				}


				// Right  Thumb barely being pressed Down
				if(m360s[c].State.Gamepad.sThumbRY < 0 && 
					m360s[c].State.Gamepad.sThumbRY > -10924)
				{
					m360s[c].R_Thumb.Neg_Y_small = true;
				}

				else
				{
					m360s[c].R_Thumb.Neg_Y_small = false;
				}

				// Right  Thumb being pressed Down
				if(m360s[c].State.Gamepad.sThumbRY < -10923 && 
					m360s[c].State.Gamepad.sThumbRY > -21847 )
				{
					m360s[c].R_Thumb.Neg_Y = true;
				}

				else
				{
					m360s[c].R_Thumb.Neg_Y = false;
				}

				// Right  Thumb being pressed all the way Down
				if(m360s[c].State.Gamepad.sThumbRY < -21846 && 
					m360s[c].State.Gamepad.sThumbRY > -32769)
				{
					m360s[c].R_Thumb.Neg_Y_large = true;
				}

				else
				{
					m360s[c].R_Thumb.Neg_Y_large = false;
				}


				// Right  Thumb barely being pressed Up
				if(m360s[c].State.Gamepad.sThumbRY > 0 && 
					m360s[c].State.Gamepad.sThumbRY < 10924)
				{
					m360s[c].R_Thumb.Pos_Y_small = true;
				}

				else
				{
					m360s[c].R_Thumb.Pos_Y_small = false;
				}

				// Right Thumb being pressed UP
				if(m360s[c].State.Gamepad.sThumbRY > 10923 && 
					m360s[c].State.Gamepad.sThumbRY < 21847 )
				{
					m360s[c].R_Thumb.Pos_Y = true;
				}

				else
				{
					m360s[c].R_Thumb.Pos_Y = false;
				}

				// Right  Thumb being pressed all the way Up
				if(m360s[c].State.Gamepad.sThumbRY > 21846 && 
					m360s[c].State.Gamepad.sThumbRY < 32769)
				{
					m360s[c].R_Thumb.Pos_Y_large = true;
				}

				else
				{
					m360s[c].R_Thumb.Pos_Y_large = false;
				}


			// Check Trigger Thresholds
		//------------------------------//

				if(m360s[c].State.Gamepad.bLeftTrigger > 0 &&
					m360s[c].State.Gamepad.bLeftTrigger < 86)
				{
					m360s[c].Triggers.leftTriggerpress_small = true;
				}

				else
				{
					m360s[c].Triggers.leftTriggerpress_small = false;
				}

				if(m360s[c].State.Gamepad.bLeftTrigger > 85 &&
					m360s[c].State.Gamepad.bLeftTrigger < 171)
				{
					m360s[c].Triggers.leftTriggerpress = true;
				}

				else
				{
					m360s[c].Triggers.leftTriggerpress = false;
				}


				if(m360s[c].State.Gamepad.bLeftTrigger > 170 &&
					m360s[c].State.Gamepad.bLeftTrigger < 256)
				{
					m360s[c].Triggers.leftTriggerpress_large = true;
				}

				else
				{
					m360s[c].Triggers.leftTriggerpress_large = false;
				}


				//----------------------------------------------------

				if(m360s[c].State.Gamepad.bRightTrigger > 0 &&
					m360s[c].State.Gamepad.bRightTrigger < 86)
				{
					m360s[c].Triggers.rightTriggerpress_small = true;
				}

				else
				{
					m360s[c].Triggers.rightTriggerpress_small = false;
				}

				if(m360s[c].State.Gamepad.bRightTrigger > 85 &&
					m360s[c].State.Gamepad.bRightTrigger < 171)
				{
					m360s[c].Triggers.rightTriggerpress = true;
				}

				else
				{
					m360s[c].Triggers.rightTriggerpress = false;
				}


				if(m360s[c].State.Gamepad.bRightTrigger > 170 &&
					m360s[c].State.Gamepad.bRightTrigger < 256)
				{
					m360s[c].Triggers.rightTriggerpress_large = true;
				}

				else
				{
					m360s[c].Triggers.rightTriggerpress_large = false;
				}

		}

        //store our previous state data for next frame
		m360s[c].prevState = m360s[c].State;
		c ++;

	}
	while(c<=3);


}

/////////////////////////////////////////////////////////////////////////////////

void TGameController::UpdateStates()
{
	
		Set360States();
		Get360State();

		if(hasGeneric) //Make sure a generic device is connected.
		{
			UpdateGenericState();
		}
}