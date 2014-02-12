/*!***************************************************
* This is the Source for the TCreateWindow          *
* class for the Troglodyte Game Engine              *
* Author : Will Canada May 1 2006                   *
* Last Updated : November 16 , 2007                 *
* By : Will Canada                                  *
*****************************************************/


#include "PCHEADER.H"

DebugConsole DebugC1;

void TCreateWindow::ReSizeGLScene(GLsizei width, GLsizei height)				// Resize And Initialize The GL Window
{
	if (height==0)								// Prevent A Divide By Zero By
	{
		height=1;							// Making Height Equal One
	}

    
	
	glViewport(0, 0, width, height);					// Reset The Current Viewport
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();
	
	

	

	//Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);						// Select The Modelview Matrix
	glLoadIdentity();		                // Reset The Modelview Matrix
	
}

////////////////////////////////////////////////////////////////////////


int TCreateWindow::InitGL()								// Initial Setup For OpenGL Goes Here
{

	GLenum err = glewInit();
	if (!GLEW_VERSION_2_1)
	{
		ErrorLog.WriteMessage("OpenGL Version 2.1 is not supported on this computer. Defaulting to immediate mode.");

	}
	else
	{
		ErrorLog.WriteMessage("OpenGL 2.1 is a go!!");
	}
	
	glShadeModel(GL_SMOOTH);						// Enables Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);					// Black Background
	glClearDepth(1.0f);							// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);					// Enables Depth Testing
	
	glDepthFunc(GL_LEQUAL);								// Depth Buffer Setup
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);			// Really Nice Perspective 



	
	return true;								// Initialization Went OK
}


////////////////////////////////////////////////////////////////////////


int TCreateWindow::DrawGLScene()								
{
	
	FM.SetBGColor(119); 

	//ADD Drawing Code Here
	DebugC1.DrawConsole();
	RenderStaticBG();
	GAME_MAIN();
	return true;								// Everything Went OK
}

////////////////////////////////////////////////////////////////////////

void TCreateWindow::KillGLWindow()							// Properly Kill The Window
{

	if (fullscreen)								// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL,0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);						// Show Mouse Pointer
	}
	
	if (hRC)								// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL,NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		
		if (!wglDeleteContext(hRC))					// Are We Able To Delete The RC?
		{
			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;							// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd,hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC=NULL;							// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;							// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL",hInstance))				// Are We Able To Unregister Class
	{
		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;							// Set hInstance To NULL
	}

	
	
	
}

////////////////////////////////////////////////////////////////////////


bool TCreateWindow::CreateGLWindow(char* title, int width2, int height2,int bits, bool fullscreenflag)
{

	//Prevent the Window from being smaller then 640X480
	if(width2<640)
	{
		width2 = 640;
	}

	if(height2<480)
	{
		height2 = 480;
	}


	   this->height = height2;
	   this->width = width2;
        DWORD dwStyle;
		DWORD	dwExStyle;
		GLuint		PixelFormat;						// Holds The Results 
		WNDCLASS	wc;		
		
		// Windows Class Structure
		RECT WindowRect;							// Grabs Rectangle Upper Left / Lower Right Values
		WindowRect.left=(long)0;						// Set Left Value To 0
		WindowRect.right=(long)width2;						// Set Right Value To Requested Width
		WindowRect.top=(long)0;							// Set Top Value To 0
		WindowRect.bottom=(long)height2;	
		
		// Set Bottom Value 
		fullscreen=fullscreenflag;						// Set The Global Fullscreen 
		hInstance		= GetModuleHandle(NULL);			// Grab An Instance For Our Window
	wc.style		= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;		// Redraw On Move, And Own DC For Window
	wc.lpfnWndProc		= (WNDPROC) WndProc;				// WndProc Handles Messages
	wc.cbClsExtra		= 0;						// No Extra Window Data
	wc.cbWndExtra		= 0;						// No Extra Window Data
	wc.hInstance		= hInstance;					// Set The Instance
	wc.hIcon		= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor		= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;						// No Background Required For GL
	wc.lpszMenuName		= NULL;						// We Don't Want A Menu
	wc.lpszClassName	= "OpenGL";					// Set The Class Name


	if (!RegisterClass(&wc))						// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;							// Exit And Return FALSE
	}

	if (fullscreen)								// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;					// Device Mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));		// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth	= width2;			// Selected Screen Width
		dmScreenSettings.dmPelsHeight	= height2;			// Selected Screen Height
		dmScreenSettings.dmBitsPerPel	= bits;				// Selected Bits Per Pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		
		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{

			//ADD Handling here to have this message box displayed and offer
			//To have the configurations dialog opened or select the next available
			//Pixel format that is supported by their card for fullscreen.

			// If The Mode Fails, Offer Two Options.  Quit Or Run In A Window.
			if (MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","Troglodyte",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{

				fullscreen=FALSE;				// Select Windowed Mode (Fullscreen=FALSE)
			}
			else
			{

				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
				return FALSE;					// Exit And Return FALSE
			}
		}
	}

	if (fullscreen)								// Are We Still In Fullscreen Mode?
	{

	   	dwExStyle=WS_EX_APPWINDOW;				// Window Extended Style
		 dwStyle=WS_POPUP;						// Windows Style
		ShowCursor(FALSE);						// Hide Mouse Pointer
	}
	else
	{

		 dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE |WS_EX_STATICEDGE;			// Window Extended Style
	     dwStyle= WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX;					// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, NULL, dwExStyle);		// Adjust Window To True Requested Size

	if(!fullscreen)
	{
		if (!(hWnd=CreateWindowEx(	dwExStyle,				// Extended Style For The Window
						"OpenGL",				// Class Name
						title,					// Window Title
						WS_CLIPSIBLINGS |			// Required Window Style
						WS_CLIPCHILDREN |			// Required Window Style
						dwStyle,				// Selected Window Style
						(width2/2), (height2/2),					// Window Position
						WindowRect.right-WindowRect.left,	// Calculate Adjusted Window Width
						WindowRect.bottom-WindowRect.top,	// Calculate Adjusted Window Height
						NULL,					// No Parent Window
						NULL,					// No Menu
						hInstance,				// Instance
						NULL)))					// Don't Pass Anything 

		{
			KillGLWindow();							// Reset The Display
			MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
			return FALSE;							// Return FALSE
		}
	}
	else
	{
		
		if (!(hWnd=CreateWindowEx(	dwExStyle,				// Extended Style For The Window
						"OpenGL",				// Class Name
						title,					// Window Title
						WS_CLIPSIBLINGS |			// Required Window Style
						WS_CLIPCHILDREN |			// Required Window Style
						dwStyle,				// Selected Window Style
						0, 0,					// Window Position
						WindowRect.right-WindowRect.left,	// Calculate Adjusted Window Width
						WindowRect.bottom-WindowRect.top,	// Calculate Adjusted Window Height
						NULL,					// No Parent Window
						NULL,					// No Menu
						hInstance,				// Instance
						NULL)))					// Don't Pass Anything 

		{
			KillGLWindow();							// Reset The Display
			MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
			return FALSE;							// Return FALSE
		}
	}

	static	PIXELFORMATDESCRIPTOR pfd=					// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),					// Size Of This Pixel Format Descriptor
		1,								// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,						// Must Support Double Buffering
		PFD_TYPE_RGBA,							// Request An RGBA Format
		bits,								// Select Our Color Depth
		0, 0, 0, 0, 0, 0,						// Color Bits Ignored
		0,								// No Alpha Buffer
		0,								// Shift Bit Ignored
		0,								// No Accumulation Buffer
		0, 0, 0, 0,						// Accumulation Bits Ignored
		24,								// 24 bit Z-Buffer(Depth Buffer)
		0,								// No Stencil Buffer
		0,								// No Auxiliary Buffer
		PFD_MAIN_PLANE,					// Main Drawing Layer
		0,								// Reserved
		0, 0, 0								// Layer Masks Ignored
	};


	if (!(hDC=GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();							// Reset The Display
		MessageBox(NULL,"Can't Create A GL Device Context. The Program will now exit.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;							// Return FALSE
	}


	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))				// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();							// Reset The Display
		MessageBox(NULL,"Can't Find A Suitable PixelFormat. The Program will now exit.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;							// Return FALSE
	}

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))				// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();							// Reset The Display
		MessageBox(NULL,"Can't Set The PixelFormat. The Program will now exit.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;							// Return FALSE
	}


	if (!(hRC=wglCreateContext(hDC)))					// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();							// Reset The Display
		MessageBox(NULL,"Can't Create A GL Rendering Context. The Program will now exit.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;							// Return FALSE
	}


	if(!wglMakeCurrent(hDC,hRC))						// Try To Activate The Rendering Context
	{
		KillGLWindow();							// Reset The Display
		MessageBox(NULL,"Can't Activate The GL Rendering Context. The Program will now exit.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;							// Return FALSE
	}

	ShowWindow(hWnd,SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);								// Sets Keyboard Focus To The Window
	ReSizeGLScene(width2, height2);						// Set Up Our Perspective GL Screen


//*!*****************************************************************************************
	if (!InitGL())								// Initialize Our Newly Created GL Window
	{
		KillGLWindow();							// Reset The Display
		MessageBox(NULL,"Initialization Failed. The Program will now exit.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return false;							// Return FALSE
	}

	return true;								// Success
}

////////////////////////////////////////////////////////////////////////

 TCreateWindow::TCreateWindow ()
{
	

	
}
 ////////////////////////////////////////////////////////////////////////

TCreateWindow::~TCreateWindow()
{
	
}

////////////////////////////////////////////////////////////////////////

bool TCreateWindow::GetFullScreen()
{
	return fullscreen;
}

////////////////////////////////////////////////////////////////////////

bool TCreateWindow::SetFullScreen(bool arg)
{
	if(fullscreen==NULL)
	{
		fullscreen=false;
	}

	else
	{

	  fullscreen=arg;
	}

	return fullscreen;
}

////////////////////////////////////////////////////////////////////////

bool TCreateWindow::GetActive()
{
	return active;
}

////////////////////////////////////////////////////////////////////////

bool TCreateWindow::SetActive(bool arg)
{
	if(active==NULL)
	{
		active=true;
	}

	else
	{

	  active = arg;
	}

	return active;
}



////////////////////////////////////////////////////////////////////////


int TCreateWindow::GetWidth()
{
	return width;
}

int TCreateWindow::GetHeight()
{
	return height;
}

//////////////////////////////////////////////////////////////////////////

void TCreateWindow::SetHeight(int arg)
{
	height = arg;
}

///////////////////////////////////////////////////////////////////////////

void TCreateWindow::SetWidth(int arg)
{
	width = arg;
}