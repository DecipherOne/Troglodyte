/*---------------------------------------------
| This is the header file for TGameController |
| class which is a wrapper for DirectInput  & |
| XInput(360 Controllers) for Gamepad & Force |
| Feedback functionality for use with the     |
| Troglodyte Game Engine.                     |
-----------------------------------------------
| Author : Will (DecipherOne) Canada          |
| February 17, 2008                           |
| (c) DecipherOne Productions ARR             |
| DirectInput & XInput (c) Microsoft Corp.    |
----------------------------------------------*/

//This class is based on Microsoft Examples for using\\
DirectInput and XInput and uses sections of those examples.

#ifndef _TGameControl_
#define _TGameControl_

struct XINPUT_DEVICE_NODE //!struct for a link list to Xinput Devices (Used for filtering 360 Controllers in direct X
{
    DWORD dwVidPid;
    XINPUT_DEVICE_NODE* pNext;
};

/////////////////////////////////////////////////////////////////////////////////


struct DI_ENUM_CONTEXT
{
    DIJOYCONFIG* pPreferredJoyCfg;
    bool bPreferredJoyCfgValid;
};

/////////////////////////////////////////////////////////////////////////////////

struct m360Triggers //!< This struct is used to determince various pressures for the triggers on the 360 controller
{
	bool leftTriggerpress_small; //!< Used to signal the left trigger is being pressed (Small threshold amount - barely being pressed)
	bool leftTriggerpress_large; //!< Used to signal the left trigger is being pressed (Large threshold amount - being pressed all the way)
	bool leftTriggerpress;       //!< Used to signal the left trigger is being pressed (Medium press, or just a generic press when thresholds aren't needed)
	bool rightTriggerpress_small;//!< Used to signal the right trigger is being pressed (Small threshold amount - barely being pressed)
	bool rightTriggerpress_large;//!< Used to signal the right trigger is being pressed (Large threshold amount - being pressed all the way)
	bool rightTriggerpress;      //!< Used to signal the right trigger is being pressed (Medium press, or just a generic press when thresholds aren't needed)
};
/////////////////////////////////////////////////////////////////////////////////

struct m360Thumb //!< This struct contains directional presses for theLeft Thumb stick, it also senses varing degrees of pressure in a direction.
{
	bool Pos_Y_small; //!< Used to signal the thumb stick is being pressed up (Small threshold amount - barely being pressed)
	bool Pos_Y_large; //!< Used to signal the thumb stick is being pressed up (Large threshold amount - being pressed completely)
	bool Pos_Y;		//!< Used to signal the thumb stick is being pressed up (Medium press, or just a generic press when thresholds aren't needed)

	bool Neg_Y_small; //!< Used to signal the thumb stick is being pressed down (Small threshold amount - barely being pressed)
	bool Neg_Y_large; //!< Used to signal the thumb stick is being pressed down (Large threshold amount - being pressed completely)
	bool Neg_Y;		//!< Used to signal the thumb stick is being pressed down (Medium press, or just a generic press when thresholds aren't needed)


	bool Pos_X_small; //!< Used to signal the thumb stick is being pressed left (Small threshold amount - barely being pressed)
	bool Pos_X_large; //!< Used to signal the thumb stick is being pressed left(Large threshold amount - being pressed completely)
	bool Pos_X;		//!< Used to signal the thumb stick is being pressed left (Medium press, or just a generic press when thresholds aren't needed)

	bool Neg_X_small; //!< Used to signal the thumb stick is being pressed right (Small threshold amount - barely being pressed)
	bool Neg_X_large; //!< Used to signal the thumb stick is being pressed right (Large threshold amount - being pressed completely)
	bool Neg_X;		//!< Used to signal the thumb stick is being pressed right (Medium press, or just a generic press when thresholds aren't needed)
};

/////////////////////////////////////////////////////////////////////////////////

struct Dpad//!< This struct contains presses associated with cardinal directions on the Digital pad. North being up.
{
	bool N;
	bool NW;
	bool NE;
	bool E;
	bool W;
	bool S;
	bool SE;
	bool SW;
};

////////////////////////////////////////////////////////////////////////////////

struct m360Buttons //!< This struct contains presses associated with the buttons on the 360 controller
{
	bool LeftShoulder;
	bool RightShoulder;
	bool LeftThumb;
	bool RightThumb;
	bool Back;
	bool Start;
	bool A;
	bool B;
	bool X;
	bool Y;
};

////////////////////////////////////////////////////////////////////////////////

struct _GenericController_   //!< This struct contains data for a generic (Non-360) gamepad.
{
	bool isConnected;       //!< Used to check the device for connectivity.
	std::string DeviceName; //!< The device name that is gotten durring enumeration.
	int DeviceID;           //!< The number of the gamepad of total enumerated.
	bool Buttons[128];      //!< Registers button presses for up to 128 buttons.
	bool preButtons[128];   //!< Used to signal previous button presses.
	int Left_TX;            //!< Threshold for the left thumb stick X axis.
	int Right_TX;           //!< Threshold for the right thumb stick x axis.(Reads information from the Rotation Z axis data from direct input)
	int Left_TY;            //!< Threshold for the left thumb y axis.
	int Right_TY;           //!< Threshold for the right thumb stick x axis.(Reads data from the rglSlider[0] directinput value)
    Dpad Digi_Pad;     //!< Digital Pad Instance (Reads data from the POV array in DirectInput)

	
};

//////////////////////////////////////////////////////////////////////////////////

struct _360Controller_  //!< This struct contains data for Xbox 360 Controllers
{
	bool isConnected;       //!< Used to check the device for connectivity.
	std::string DeviceName; //!< The device name that is gotten durring enumeration.
	int DeviceID;           //!< The number of the gamepad of total enumerated.
	XINPUT_STATE State;     //!< The structure used with XInput
	XINPUT_STATE prevState;     //!< used to store the previous state for button presses
	DWORD PrevPacketNum;    //!< Used for comparison with the packet number in the XINPUT_STATE struct.

	XINPUT_VIBRATION FF;    //!< Instance of the data for Force Feedback
	m360Triggers Triggers;  //!< Instance of the data for Trigger presses
	m360Thumb L_Thumb;  //!< Instance of the data for the Left Thumbstick
	m360Thumb R_Thumb; //!< Instance of the data for the Right Thumbstick
	Dpad Digi_Pad;     //!< Instance of the data for the Digital Pad
	Dpad prevDigi_Pad; //!< stores previous frame data for digi pad button presses
	m360Buttons Buttons;    //!< Instance of the data for the Button Presses
	m360Buttons preButtons;    //!< Instance of the data for the Button Presses

};


///////////////////////////////////////////////////////////////////////////////////


class TGameController
{

	HRESULT SetupForIsXInputDevice(); //!< Used to filter out XInput Devices from DirectInput so they can be handled by XInput instead.
	static bool IsXInputDevice( const GUID* pGuidProductFromDirectInput ); //!< Returns true if the DirectInput device is also an XInput device.
	void CleanupForIsXInputDevice(); //!< Cleans up an XInput Device.
	static LPDIRECTINPUT8       g_pDI;   //!< Actual Instance of Direct Input      
	static BOOL CALLBACK    EnumObjectsCallback( const DIDEVICEOBJECTINSTANCE* pdidoi, VOID* pContext );
	static BOOL CALLBACK    EnumJoysticksCallback( const DIDEVICEINSTANCE* pdidInstance, VOID* pContext );
	static bool    g_bFilterOutXinputDevices; //!< Used to filter out XInput Devices from DirectInput so they can be handled by XInput instead.
	static XINPUT_DEVICE_NODE * g_pXInputDeviceList; //!< Used for filtering out XInput Devices from DI
	HRESULT UpdateGenericState(); //!< Updates the state for Generic Input devices using DirectInput
	void Get360State();  //!< Checks  the state data(button presses) for Xbox controllers using XInput

	
	

public:

	static LPDIRECTINPUTDEVICE8 g_pJoystick;  //!< Acutal structure used with directInput
	static std::string DeviceNames[8]; //!< Storage for our Gamepad Devices
	_GenericController_  Generics[8];  //! 8 Structs for Generic Gamepads
	_360Controller_      m360s[4];  // 4 XInput Gamepad structs

	static bool hasGeneric; //!< Used to signal that a generic controller is connected and needs to be processed as such



	static int count;
	void Set360States(); //!< Called to check connections on the controllers and update the button presses. Automatically sets connection variable depending upon state.(Handles 4 Controllers)
	bool InitDirectInput(); //!< Initializes Direct Input
	void FreeDirectInput(); //!< Free's Direct Input
	
	void UpdateStates();    //!< Calls both updates for generic and 360 controllers

	bool DisplayControlInfo(int h_offset, int w_offset); //!< This function writes the Device Information to the screen Ideally called from a debug type of interface for a game developer.(Should be called after Input updates) h_offset and w_offest are the starting positions for printing the text to the screen.

	TGameController(); //!< Default Constructor
	~TGameController(); //!< Default Destructor

};


#endif
