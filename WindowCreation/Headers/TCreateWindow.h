/*!***************************************************
* This is the header for the Window creation for    *
* the Troglodyte Game Engine                        *
* Author : Will Canada May 1 2006                   *
*****************************************************/

#ifndef _TCreateWindow_
#define _TCreateWindow_



class TCreateWindow //!< Window Creation and Initialization Class Also handles OpenGL Context
{
private:


	bool fullscreen; //!<Signals if the program is in full screen
	bool active; //!< Signals if the program is active

	int width; //!<Used to pass width info
	int height; //!<Used to pass hieght info

	


public:

	HGLRC  hRC; //!< Permanent Rendering Context
	HDC    hDC; //!< Private GDI Device Context
	HWND  hWnd; //!< Holds Our Window Handle
	HINSTANCE hInstance; //!< Holds The Instance 

	bool keys[256];	//!< Array Used For The Keyboard Routine
	bool preKeys[256]; //!<Array used for keyboard response(Key was previously Held down)
    
	bool GetActive();
	bool SetActive(bool arg);
	bool GetFullScreen();  //!<Used to get the fullscreen state flag
	bool SetFullScreen(bool arg);  //!<Used to set the fullscreen state flag

	void SetWidth(int);
	void SetHeight(int);

	int GetWidth();
	int GetHeight();

	TCreateWindow();  //!<Constructor
	~TCreateWindow(); //!<Destructor
    void ReSizeGLScene(GLsizei width, GLsizei height);	//!< Resize And Initialize The GL Window
	int InitGL();								//!< All Setup For OpenGL Goes Here
	int DrawGLScene();								//!< Here's Where We Do All The Drawing
    void KillGLWindow();							//!< Properly Kill The Window
	bool CreateGLWindow(char* title, int width, int height,int bits, bool fullscreenflag); //!<Setup the Window

};

#endif

	