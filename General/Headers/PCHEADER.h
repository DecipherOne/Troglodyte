/*!***********************************
* This header contains references   *
* to all the other headers in the   *
* App, so that I simply just have   *
* to include this header in the     *
* source files.                     *
*************************************/


#ifndef _WIN32_DCOM
#define _WIN32_DCOM 
#endif 

#ifndef _PCHEADER_
#define _PCHEADER_
#pragma warning (disable:4010) //disable single line comment continuation warnings
#pragma warning (disable:4305) //disable double to float conversion warnings
#pragma warning (disable:4244) //disable int to float or double conversion warnings
#define WIN32_LEAN_AND_MEAN

#include<python.h>    //Python Header (Must be included before standard headers)
#include<windows.h> //Standard Windows Header ( Must be before any other includes)

#include <dinput.h> //DirectInput Header
#include <dinputd.h> //DirectInput Header
#include <XInput.h> //XInput Header

#include <wbemidl.h>// Stuff to filter out XInput devices

#include<glew.h>     //OpenGL Extensions Wrangler (GLEW)
#include<gl/gl.h>      //OpeGL Library
#include<gl/glu.h>    // Opengl Utility Library
#include<glaux.h>  //Opengl Auxilarily Library
//#include<glm.hpp>  //Opengl Mathmatics Library
//#include<gtc/matrix_transform.hpp>//Opengl Mathmatics Library


#include <al.h> //OpenAl header
#include <alc.h> //OpenAl header
#include <alut.h> //OpenAl header
#include <ogg/ogg.h> //Header for Ogg files
#include <vorbis/codec.h> //Vorbis compression header
#include <vorbis/vorbisfile.h> //Vorbis compression header
#include <vorbis/vorbisenc.h>

#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<time.h>
#include<algorithm>
#include<list>
#include<climits>
#include<COMMDLG.H> //Common Dialog Header
#include<atltime.h> //Used for getting system time
#include<math.h>
#include<float.h>
#include<memory.h>


//Bill Perone's Math Library(Do to build dependencies, these must be in this order.)
#include "assert.h"
#include "utility.h"
#include "matrixn.h"
#include "vector2.h"
#include "matrix2.h"
#include "vector3.h"
#include "matrix3.h"
#include "vector4.h"
#include "matrix4.h"
#include "line2.h"
#include "line3.h"
#include "plane.h"
#include "intersect.h"



//Troglodyte Specific files
#include"GameStateFileStructs.h" //Contains the file structures for the engine.
#include"ltga.h"  //TGA LOADER HEADER
#include"TCreateWindow.h" //Window Creation Class
#include"WinEvent.h" //Windows Event Loop
#include"TrogAuxFunctions.h" //Color Selection
#include"LodePNG.h" //PNG Loading Class
#include"PBitmap.h" //used for bitmaps
#include"PBitmapfont.h" //used for bitmap fonts
#include"PTexture.h"  //used for texture creation
#include"Debug.h" //Base Debug Console Class
#include"UpdatesManager.h" //UpdatesManager header
#include"TObject.h"//Base Object Class header
#include"Camera.h" //Camera class header
#include"TConsoleKeys.h"  //Key board handling routines
#include"SettingsManager.h"//Used for the settings manager
#include"Shape.h" //Basic Shape Outline
#include"Triangle.h" //Triangle Shape class
#include"Quad.h" //Quad Shape Class

#include"TAudioSource.h" //Used for managing audio sources
#include"TAudio.h"  //Used for initializing and exiting openal and for managing the listener object
#include"Animation2D.h" //Used for 2D animations
#include"Sprite.h" // Used for creating 2D Game Sprites 
#include"TMouse.h" //Mouse Input Header for the engine(Other Mouse events for game states will be handled through immediate mode)
#include"TClock.h" //Clock Class (Realtime Timer functionality)


#include"TGameController.h" //Game pad functionality via DirectInput & XInput for 360 Controllers
#include"Gamestate.h" //Defines a default game state
#include"GS_HML.h" //Game state hidden management layer header.
#include"TScene.h" //A Scene Game State
#include"TrogLog.h" //Used for creating Log files.
//#include"TPyTwine.h"//Custom Python Interfaces for the engine.
#include"TROG_TEXT.h"//Bitmap fonts
#include "shader.h"



//Engine Externs
extern TClock EngineTime;
extern TCreateWindow TrogWin;
extern TConsoleKeys ConKeys;
extern TMouse  GMouse;
extern TAudio MainAudio;
extern GS_HML Game_Manager;
extern UpdatesManager MainState;
extern int DemoNum; //Used for showing differnet demos through the console
extern DebugConsole  DebugC1;
extern TGameController Gamepads;
extern PFonts CourierFont;
extern TrogLog AppLog;
extern TrogLog ErrorLog;
extern TrogLog InputLog_Gamepads;
extern TrogLog InputLog_Mouse;
extern TrogLog InputLog_Keyboard;
extern TrogLog ObjectsLog;
extern TrogLog ScenesLog;
extern TrogLog ResourceLog;
extern TrogLog Log_Index;
extern Shader Tex_Shade; //A shader object used for texture stuffs.
extern TrogAuxFunctions FM; //Auxilary functions manager.



/*+----------------------------------+
| Project Specific Headers & Externs |
+----------------------------------+*/

extern int GAME_MAIN();
extern int Ascend_Main();
extern int Ascend_Title();
extern int Ascend_Intro();
extern int Ascend_Options();
extern int Ascend_Pause();
extern int Ascend_Load();
extern int Ascend_Save();
extern int Ascend_Quit();
extern int Ascend_Credits();
extern int Ascend_VS();
extern int Ascend_Survival();
extern int CurrentState;
#include "gridmanager.h"
#include "character.h"
#include "HUD.h"


//Different BG LAYERS
extern int RenderBG10();
extern int RenderStaticBG();


//fleet
extern int Fleet_Main();
extern int Fleet_Title();
extern int Fleet_Intro();
extern int Fleet_Options();
extern int Fleet_Pause();
extern int Fleet_Load();
extern int Fleet_Save();
extern int Fleet_Quit();
extern int Fleet_Credits();
extern int Fleet_VS();
extern int Fleet_Survival();






#endif 
