/*!***************************************************
* This file is for the TScene class.                 *
+----------------------------------------------------+
* Author : Will (DecipherOne) Canada,February 1,2011 *
*(c) 2008-2011 DecipherOne Productions               *
******************************************************/

#include "PCHEADER.h"

TScene::TScene()
{
	NumOfObjects = 1;
	//SceneObjects = NULL;
}

/////////////////////////////////////////////////////////////////////////////////

TScene::~TScene()
{
}

////////////////////////////////////////////////////////////////////////////////

bool TScene::Initialize()
{
	//This is pseudo-code for now.

	isStarting = true;

	if(NumOfObjects == 1)
	{
		SceneObjects.reserve(2);
	}
	else
	{

		SceneObjects.reserve(NumOfObjects); //Create Our Objects 
	}

	int c = 0;

	do
	{

	//Load Image data

	//Load Initial Orientation data

	//Load Sound data

	//Load script data

		c++;
	}
	while(c<=NumOfObjects);



	return true;
}

//////////////////////////////////////////////////////////////////////////////////

bool TScene::Remove()
{

	SceneObjects.clear();
	SceneObjects.resize(1);

	return true;

}

///////////////////////////////////////////////////////////////////////////////

bool TScene::Update()
{
	//update user input
	//update audio data
	//update scripts
	//update rendering

	return true;
}

////////////////////////////////////////////////////////////////////////////////

int TScene::GetLevel_ID()
{
	return Level_ID;
}

////////////////////////////////////////////////////////////////////////////////

void TScene::SetLevel_ID(int arg)
{
	Level_ID = arg;
}

////////////////////////////////////////////////////////////////////////////////

int TScene::Get_NumOfObjects()
{
	return NumOfObjects;
}

////////////////////////////////////////////////////////////////////////////////

void TScene::Set_NumOfObjects(int arg)
{
	NumOfObjects = arg;
}
