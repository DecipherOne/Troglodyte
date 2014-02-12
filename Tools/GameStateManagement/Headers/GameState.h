/*!***************************************************
* This header file is for a generic GameState class  *
* Other specific game states will be derived from    *
* this class. Functionality includes message handling*
* from the Hidden Management Layer.                  *
+----------------------------------------------------+
* Author : Will (DecipherOne) Canada, March 16       *
*(c) 2008 DecipherOne Productions                    *
******************************************************/

#ifndef _GAMESTATE_
#define _GAMESTATE_
#include "PCHeader.h"


class GAMESTATE
{
protected:

	bool isPaused;  //!< Tells if the state is set for updating or if it is paused.
	bool isStarting; //!< Signals the state is starting and any objects should be initialized and transition effects executed.
	bool isEnding;  //!< Tells that a request to end the state has been made.
	bool hasFocus;  //!< Tells if that state is in the foreground.


	std::string StateName; //!< A string ID for the game state.
	const char * Label;    //!< A char string used for screen display.

	int State_ID;    //!< A Numeric ID for the state(Issued only by the Hidden Management Layer at runtime, when the state is active.)
	int Message_ID;  //!< A numeric ID for passing messages between the HML and the state.


	enum Message
	{
		REMOVE_STATE=1,INITIALIZE_STATE,STATE_HASFOCUS,
		STATE_REMOVEFOCUS,PAUSE_STATE,UN_PAUSE_STATE
	};



public:

	
	void Set_isPaused(bool arg); //!< Sets the variable isPaused to the value of arg
	bool Get_isPaused(); //!< Returns the value in isPaused
	void Set_isStarting(bool arg); //!< Sets the variable isStarting to the value of arg
	bool Get_isStarting(); //!< Returns the value in isStarting
	void Set_isEnding(bool arg); //!< Sets the variable isEnding to the value of arg
	bool Get_isEnding(); //!< Returns the value in isEnding
	void Set_hasFocus(bool arg); //!< Sets the variable hasFocus to the value of arg
	bool Get_hasFocus(); //!< Returns the value in hasFocus


	void Set_State_ID(int arg); //!< Sets the variable of State_ID to the value of arg
	int  Get_State_ID(); //!< Returns the value in State_ID
	void Set_Message_ID(int arg); //!< Sets the variable of Message_ID to the value of arg
	int  Get_Message_ID(); //!< Returns the value in Message_ID

	void Set_StateName(std::string arg); //!< Sets the variable StateName to the value of arg
	std::string Get_StateName(); //!< Returns the string stored in StateName.

	bool UpdateMessages(int M_ID); //!< This function calls all of the sets and gets for that individual state. It uses the data from the enumerated types Message in order to execute the updates being called from the GS HML.
	virtual bool Initialize();  //!< Initializes the GameState.
	virtual bool Remove(); //!< Frees appropriate memory for a game state.
	virtual bool Update(); //!< All Rendering,Input,Logic updates take place in this function.
	bool ADD_TO_MANAGER(bool Init,std::string Name); //!< Adds the State to the HML Game_Manager defined in Main.cpp.


	GAMESTATE();
	~GAMESTATE();

};

#endif


