#include "PCHEADER.H"

TCreateWindow TrogWin; //Instance of TCreateWindow Class
UpdatesManager MainState; //Updates Rendering and Input for the Mouse and Keyboard
TrogAuxFunctions FM; 
//Log Files (Declared here and as externs is .pch so can be used any where.)
TrogLog Log_Index("Index","Logs");
TrogLog AppLog("Main_APP","Logs");
TrogLog ErrorLog("Errors","Logs");
TrogLog InputLog_Gamepads("Input Gamepads","Logs");
TrogLog InputLog_Mouse("Input Mouse","Logs");
TrogLog InputLog_Keyboard("Input Keyboard","Logs");
TrogLog ObjectsLog("Objects","Logs");
TrogLog ScenesLog("Scenes","Logs");
TrogLog ResourceLog("Resources","Logs");

Shader Tex_Shade; //A shader object used for texture stuffs.

TAudio MainAudio; //Set An Instance for OpenAL Context
TGameController Gamepads; //Instance of our GameController class
SettingsManager SM; //Used for initalizing the Visual Settings

GS_HML Game_Manager; //Instance of our Game State Hidden Management Layer
PFonts CourierFont;  //The Administrative Font

LRESULT	CALLBACK WndProc(HWND, UINT, 
		WPARAM, LPARAM); // Event handler

int WINAPI WinMain(	HINSTANCE	hInstance,HINSTANCE	hPrevInstance,				
			LPSTR lpCmdLine,int	nCmdShow)				
{
	//In debug mode all logging is enabled by default.
	// Otherwise, additional logging must be enabled through the console.
	Log_Index.SetisEnabled(true);
	AppLog.SetisEnabled(true);
	ErrorLog.SetisEnabled(true);
#ifdef DEBUG
	
	InputLog_Gamepads.SetisEnabled(true);
	InputLog_Mouse.SetisEnabled(true);
	InputLog_Keyboard.SetisEnabled(true);
	ObjectsLog.SetisEnabled(true);
	ScenesLog.SetisEnabled(true);
	ResourceLog.SetisEnabled(true);
	//-----------------------------
	AppLog.WriteMessage("Running in DEBUG mode: ALL Logging Enabled by default.");
#endif

	AppLog.WriteMessage("The Application Entered the running state");
	srand ( time(NULL)^2);                  //Seed rand once for the entire application.
	MSG	msg;								    // Windows Message Structure
	bool done = false;						// Bool Variable To Exit Loop


    /////////////////////////////////////////////////////////////////////////
	//Sound Initalization
	MainAudio.InitOpenAL();
	//3d fixed point listening 
	MainAudio.SetListenerPos(0.0,0.0,-1.0); 
	MainAudio.SetListenerOrien(0.0, 0.0,-1.0,0.0,1.0, 0.0);
	MainAudio.SetListenerVel(0.0,0.0,0.0);
	AppLog.WriteMessage("OpenAL Initialized Successfully");

	//Initialize DirectInput & XInput

	Gamepads.InitDirectInput();
	AppLog.WriteMessage("DirectInput Initallized Successfully");
   

	//Initialize Python

	Py_Initialize();

	char ** argv;
	argv = new char *;
	PySys_SetArgv(0,argv);

	AppLog.WriteMessage("Python Initialized Successfully");

	
    ////////////////////////////////////////////////////////////////////////
	//Window Initialization


	//Quick 

#ifdef DEBUG   
	// Create Our OpenGL Window
	if(!TrogWin.GetActive())
	{
		if (!TrogWin.CreateGLWindow("Fleet",640,480,32,0))
		{
			AppLog.WriteMessage("In Debug Mode : Windowed failed to be created.");
			return 0;							// Quit If Window Was Not Created
		}

		TrogWin.SetActive(true);
		AppLog.WriteMessage("In Debug Mode : Window has been created.");
		AppLog.WriteMessage("OpenGL successfully initialized.");
	}


	/*!******************************************************
	* The section below does not work in Debug Mode        *
	********************************************************/


#else // Otherwise Load Settings from Config.ini
	
	// Create Our OpenGL Window
	if(!TrogWin.GetActive())
	{
			if(SM.Load_V_Settings()!=0)  //Load Video Initalization settings from config.ini
			{
				//if the config file could not be found, initialize with defualt settings

				if (!TrogWin.CreateGLWindow("Troglodyte Version 0.7.5 ",800,600,32,false))
				{
					return 0;							// Quit If Window Was Not Created
				}
				else
				{
					AppLog.WriteMessage("Config.ini could not be loaded. Default Window Created.");
				}
			}

				
			//Convert SM.V_Settings.AppName from a string to a const char * for window display

			const char * WindowText=NULL;

			WindowText = SM.V_Settings.AppName.c_str();

			
		   if (!TrogWin.CreateGLWindow((char *)WindowText,SM.V_Settings.width,SM.V_Settings.height,
					SM.V_Settings.CBits,SM.V_Settings.fullscreen))
				{
					MessageBox(NULL,"The Application could not be initialized!",
						"Applicaton Creation Error!",MB_ICONEXCLAMATION|MB_OK);
					return 0;							// Quit If Window Was Not Created
				}

				TrogWin.SetActive(true);
				AppLog.WriteMessage("Window Succesfully created using config.ini");
	}

#endif	



	//Setup our global font used throughout administrative engine functionality.
	float tempH = TrogWin.GetHeight() * .035;
	float tempW = TrogWin.GetWidth() * .075;
	float fontsize = tempH + tempW /2.75;
	fontsize=fontsize/2;
	CourierFont.BuildFont(fontsize,false,false,false,"Courier New");
	AppLog.WriteMessage("Our Global Font was created successfully.");

	//Initialize our global shaders.
	Tex_Shade.installShaders("../resources/shaders/texture.vert",
			"../resources/shaders/texture.frag");
	AppLog.WriteMessage("Texture shader Loaded into memory.");

	//Start the main Loop
	AppLog.WriteMessage("Entering Main Game Loop.");
	while(!done)	
	{

		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))		//Poll for Windows Messages
		{

			if (msg.message==WM_QUIT)
			{
				done=true;					
			}
			else							
			{

				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else								//Otherwise update GameStates
		{

			
			if (TrogWin.GetActive())						
			{

#ifdef DEBUG
				if (TrogWin.keys[VK_ESCAPE])				
				{
					done=true;			
					AppLog.WriteMessage("User Pressed Escape - Requesting Application Stop.");
				}
#endif

				if(TrogWin.GetActive())					// Update The Input/Audio/Visual Renderings
				{

					Gamepads.UpdateStates();
					MainAudio.UpdateListenerValues();
					MainState.UpdateStates();
					
				}
			}

		}
	}

	AppLog.WriteMessage("Exiting Main Game Loop.");
	// Shutdown

	CourierFont.KillFont(); //Release global Font
	AppLog.WriteMessage("Global Font Released.");
	
	
	if(argv)                //Release Python
	{
		delete argv;
		argv = NULL;
	}

	
	    
	Gamepads.FreeDirectInput(); //Release Gamepads
	AppLog.WriteMessage("DirectInput Released.");
	MainAudio.ExitOpenAL(); //Release The SOund
	AppLog.WriteMessage("OpenAL Released.");
	

#ifndef DEBUG
	Py_Finalize(); //Crashes in debug because not using debug .lib
	AppLog.WriteMessage("Python Released.");
#endif
	TrogWin.KillGLWindow();	//Release the Window  
	AppLog.WriteMessage("Window Was Released. Program Exited.");
	double result = EngineTime.CalcTimePassed();
	string Apptime = FM.Seconds_2TimeString(result);
	AppLog.WriteMessage("Engine Ran for "+Apptime);

	//Close our log files. Finalize checks to see if they exist.
	
	AppLog.Finalize();
	ErrorLog.Finalize();
	InputLog_Gamepads.Finalize();
	InputLog_Mouse.Finalize();
	InputLog_Keyboard.Finalize();
	ObjectsLog.Finalize();
	ScenesLog.Finalize();
	Log_Index.Finalize();

	return(msg.wParam);							// Exit The Program
}
