/*!***************************************************
* This file is for the GAMESTATE class.              *
+----------------------------------------------------+
* Author : Will (DecipherOne) Canada, April 3, 2008  *
*(c) 2008 DecipherOne Productions                    *
******************************************************/



#include"PCHEADER.h"


void GAMESTATE::Set_isPaused(bool arg)
{
	isPaused = arg;
}
//////////////////////////////////////////////////////////////////////////////////

bool GAMESTATE::Get_isPaused()
{
	return isPaused;
}

//////////////////////////////////////////////////////////////////////////////////

void GAMESTATE::Set_isStarting(bool arg)
{
	isStarting = arg;
}

///////////////////////////////////////////////////////////////////////////////////

bool GAMESTATE::Get_isStarting()
{
	return isStarting;
}

///////////////////////////////////////////////////////////////////////////////////

void GAMESTATE::Set_isEnding(bool arg)
{
	isEnding = arg;
}

///////////////////////////////////////////////////////////////////////////////////

bool GAMESTATE::Get_isEnding()
{
	return isEnding;
}

///////////////////////////////////////////////////////////////////////////////////

void GAMESTATE::Set_hasFocus(bool arg)
{
	hasFocus = arg;
}

///////////////////////////////////////////////////////////////////////////////////

bool GAMESTATE::Get_hasFocus()
{
	return hasFocus;
}

///////////////////////////////////////////////////////////////////////////////////

void GAMESTATE::Set_State_ID(int arg)
{
	//Prevent the state id from being out of range.
	if(arg < 1 || arg > 27)
	{
		MessageBox(NULL,"You are trying to set a state ID outside the specified range \n"
			"of 1 to 27. This will need to be corrected. The program will now quit.",
			"GAMESTATE::Set_State_ID() ERROR!",MB_OK);

		PostQuitMessage(0);
		return;
	}


	State_ID = arg;
}

///////////////////////////////////////////////////////////////////////////////////

int GAMESTATE::Get_State_ID()
{
	return State_ID;
}
///////////////////////////////////////////////////////////////////////////////////

void GAMESTATE::Set_Message_ID(int arg)
{
	//Prevent the message id from being out of range.
	if(arg < 0 || arg > 7)
	{
		MessageBox(NULL,"You are trying to set a Message ID outside the specified range \n"
			"of 0 to 7. This will need to be corrected. The program will now quit.",
			"GAMESTATE::Set_Message_ID() ERROR!",MB_OK);

		PostQuitMessage(0);
		return;
	}

	Message_ID = arg;
}

///////////////////////////////////////////////////////////////////////////////////

int GAMESTATE::Get_Message_ID()
{
	return Message_ID;
}


///////////////////////////////////////////////////////////////////////////////////

GAMESTATE::GAMESTATE()
{
}

///////////////////////////////////////////////////////////////////////////////////

GAMESTATE::~GAMESTATE()
{
}

///////////////////////////////////////////////////////////////////////////////////

void GAMESTATE::Set_StateName(std::string arg)
{
	StateName = arg;
	Label = arg.c_str();
}

//////////////////////////////////////////////////////////////////////////////////

std::string GAMESTATE::Get_StateName()
{
	return StateName;
}

//////////////////////////////////////////////////////////////////////////////////

bool GAMESTATE::UpdateMessages(int M) //CODE ME
{

	switch(M)
	{
	case REMOVE_STATE:
		{
			Remove();
			break;
		}
	
	case INITIALIZE_STATE:
		{
			Initialize();
			break;
		}
	case STATE_HASFOCUS:
		{
			hasFocus=true;
			break;
		}
	case STATE_REMOVEFOCUS:
		{
			hasFocus=false;
			break;
		}
	
	case PAUSE_STATE:
		{
			isPaused=true;
			break;
		}
	case UN_PAUSE_STATE:
		{
			isPaused=false;
			break;
		}

	}

	if(Update())
	{
		return true;
	}

	return false;

}

///////////////////////////////////////////////////////////////////////////////////

bool GAMESTATE::Initialize()
{
    //More specific initialization code to be added for derived states.
	isStarting = 1;

	return true;
}

///////////////////////////////////////////////////////////////////////////////////

bool GAMESTATE::Remove()
{
	//Simply Put eveything for the state back an unitialized stae.

	isPaused=0;
	isStarting=0; 
	isEnding=0;  
	hasFocus=0;  
	StateName=""; 
	Label="";    
	State_ID=0;    
	Message_ID=0;  


	return true;
}

///////////////////////////////////////////////////////////////////////////////////

bool GAMESTATE::Update()
{
	//Leaving this abstract and empty 
	return true;
}

///////////////////////////////////////////////////////////////////////////////////

bool GAMESTATE::ADD_TO_MANAGER(bool Init,std::string Name)
{
	StateName = Name;
	Label = StateName.c_str();

	if(!Game_Manager.ADDSTATE(this,Init))
	{
		return false;
	}

	return true;
}