/*!***************************************************
* This header file contains is for the TScene class  *
* which is responsible for holding and manipulating  *
* the Scene data for the Troglodyte Game Engine.     *
+----------------------------------------------------+
* Author : Will (DecipherOne) Canada                 *
*(c) 2008 - 2011 DecipherOne Productions             *
******************************************************/
#ifndef _T_SCENE_
#define _T_SCENE_


class TScene : public GAMESTATE
{
protected:

	int NumOfObjects; //!< This variable holds the number of Objects that are in the scene at any given time.
	int Level_ID;     //!< For each unique scene, a level id is assigned in order to organize data.

public:

	virtual bool Update();    //!< Called to execute the scene data. (Scene data will have to be gotten from script files.)
    void SetLevel_ID(int arg); //!< Sets the Level_ID variable to arg.
	int GetLevel_ID(); //!< Returns the value stored in Level_ID.
	virtual bool Initialize(); //!< Goes through and allocates all the Objects in a Scene.
	virtual bool Remove(); //!< Responsible for cleaning up a Scene
	vector <Sprite> SceneObjects; //!< vectors for our objects
	void Set_NumOfObjects(int arg); //!< Sets the number of Objects
	int Get_NumOfObjects();         //!< Returns the number of Objects
	TScene();
	~TScene();
};

#endif
