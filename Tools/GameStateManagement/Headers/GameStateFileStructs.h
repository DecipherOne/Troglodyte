/*!***************************************************
* This header file contains the file structures for  *
* the various file formats used for the Troglodyte   *
* Game Engine & Editor Scribe.                       *
+----------------------------------------------------+
* Author : Will (DecipherOne) Canada, March 16       *
*(c) 2008 DecipherOne Productions                    *
******************************************************/



#ifndef _GameStateStructs_
#define _GameStateStructs_


//!< This struct is for helping to determine what should be saved and loaded for a Troglodyte Object File (.TOF)

struct ObjectFileArgs
{
	bool isAnimate;   //!< Says if the object is capable of moving in the game world or if it's stationary
	bool useDialog;   //!< Signals if the object is capable of using a Dialog Script for simulating conversations
	bool useScripts;  //!< Signals if the object is capable of using Python Scripts
	bool isChangable; //!< Signals if the Objects scene properties are changeable
	bool hasTexture;  //!< used to mark if the object being saved or loaded has a texture to load or save
	int Scene_ID;     //!< A unique Value used for Identification of Multiple Objects in a Scene.
};

///////////////////////////////////////////////////////////////////////////////////////

//!< This struct is for helping to determine what should be saved and loaded for a Troglodyte Scene File (.TSF)
struct SceneFileArgs
{
	int NumOfObjects; //!< The number of Objects the Scene Contains
	int Level_ID;      //!< A unique Value used for Identification of Multiple Scenes in a level.
};


/////////////////////////////////////////////////////////////////////////////////////


//!< This struct is for helping to determine what should be saved and loaded for a Troglodyte Level File (.TLF)
struct LevelFileArgs
{
	int Project_ID; //!< A unique Value used for Identification for Mulitple Levels within a project.
	int NumOfScenes; //!< The number of Scenes in the Level

};

/////////////////////////////////////////////////////////////////////////////////////



//!< This struct is for helping to determine what should be saved and loaded for a Troglodyte Project File (.TPF)
struct ProjectFileArgs
{
	int NumOfLevels; //!< Tells how many levels there are in the project.
	int NumOfScenes; //!< Tells how many Scenes there are in the project.
	int NumOfObjects; //!< Tells total amount of Objects in a project.

	//Should have the date and time the project file was last saved. 
};


///////////////////////////////////////////////////////////////////////////////////







#endif