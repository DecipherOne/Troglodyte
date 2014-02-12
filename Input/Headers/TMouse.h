//Header file for the Engines  Mouse Input
/*!*********************************************(C)*
+ Will Canada : DeciipherOne Productions      2007 +
|--------------------------------------------------|
| This class provides default functionality for    |
| handling mouse events for the Troglodyte game    |
| engine.                                          |
|__________________________________________________|
+--------------------------------------------------+ */

#ifndef _TMOUSE_
#define _TMOUSE_


class TMouse //!< This class is the default Mouse Input Class for the Troglodyte Game Engine
{

	UpdatesManager * MouseTime;

	

public:



	unsigned int Selection_Buffer[512]; //! Used for memory for selectable objects, for use with picking

	int hits;    
	int NameHit; //!< The number value for the closet object that was selected used for picking
	POINT MousePoint;      //!< a Point Struct used for getting the location of the mouse cursor with GetMousePos()
	bool UpdateMouse(); //!< Called in a the MainState UpdatesManager Updates Mouse posistions for OpenGL and The Screen
	bool MouseKeys[10];       //!< Array holding values for Mouse Key Presses
	int ResetKeyStates();   //!< Resets the keystates when the buttons are released (So Late Messages aren't sent after the user has released the buttons)

	bool GetWorldCoord();    //!< Changes the Mouse Screen Coordinates into Opengl Coordinates For use with event handling(Must be called after visual render loop, for Mouse handling routines)
	float WorldCoords[3];   //!< Array for the x,y,z world coordinates
	float PreviousMouseCoords[3]; //!< Array used for moving objects with the mouse holds previous world coordinates

	bool OnMoveObject(Sprite &Arg); //!< Does the processing for moving an Object with the mouse - This should only be called from a structure if the Object is currently selected. The Argument, Arg, is a pointer to the Object, if type is other then sprite, it must be cast.
	bool EnterSelectionMode(); //!< Used for entering into selection mode for use with picking 
	bool ExitSelectionMode(); //!< Used for exiting selection mode for picking, in order to do a visual render of the objects 

	bool TestHitBuffer(GLint hits, GLuint buffer[]);  //!< Resets the varable Selection_Buffer so hits aren't constantly recorded


	bool PrePress[10];            //!< Used with CheckState calls for mouse input
	bool CheckStateLBUTTON(); //!< Checks the press state of Left mouse button in an attempt to isolate multiple key presses, returns true if it's time to update
	bool CheckStateRBUTTON(); //!< Checks the press state of Right mouse button in an attempt to isolate multiple key presses, returns true if it's time to update
	bool CheckStateMBUTTON(); //!< Checks the press state of Middle mouse button in an attempt to isolate multiple key presses, returns true if it's time to update
	TMouse(); //!< Default Constructor
	~TMouse(); //!< Default Destructor

	
	CURSORINFO MouseCursor; //!< a reference to the mouse cursor to check for visablility through out the application.
};










#endif

