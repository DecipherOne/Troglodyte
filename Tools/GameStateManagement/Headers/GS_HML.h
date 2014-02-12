/*!***************************************************
* This header file is for the Game State Hidden      *
* Management Layer. This Layer Oversees messaging    *
* between game states and various other management   *
* functionality.                                     *
+----------------------------------------------------+
* Author : Will (DecipherOne) Canada, March 16       *
*(c) 2008 - 2011 DecipherOne Productions             *
*                                                    *
* Continued on January 15, 2011                      *
******************************************************/

#ifndef _GS_HML_
#define _GS_HML_

#define MAX_NUM_OF_STATES 27 //The number of states in the state cache.


class GS_HML
{
	//These values should only be used by the Hidden Management Layer

	int ID_REF_COUNT; //!< This is a count of how many states are active and used to assign ID numbers to states.
	int HML_DispatchMessage(int STATE_ID,int MESSAGE);   //!< Sends a Message to the specified state using the state_ID. Should be called from ResolveMessage().

	int ActiveState_ID; //!< This is the numeric ID of the state that currently has focus.
	int PreviousState_ID; //!< This is the numeric ID for the state that previously had focus.
	int LEVEL_REF_COUNT; //!< A refcount of levels (used to limit the number of levels in the cache to 2.

	GAMESTATE StateCache[MAX_NUM_OF_STATES]; //!< This is the array of GameStates that the engine uses.

	
	
	bool REMOVESTATE(int STATE_ID);  //!< Looks at the ID_REF_COUNT and de-increments it. It then removes the state from the management pool. Also MESSAGE is used for passing any messages to the state itself, such as REMOVESTATE, so the memory can be freed.
	bool Push_State(int STATE_ID); //!< Pushes the State into the background, This allows for things like layered menu's and or cutscenes.
	bool Pop_State(int STATE_ID);  //!< Pops the state restoring it to be active.



public:


	enum Message
	{
		REMOVE_STATE=1,INITIALIZE_STATE,STATE_HASFOCUS,
		STATE_REMOVEFOCUS,PAUSE_STATE,UN_PAUSE_STATE
	};


	bool SaveObject(const std::string &filename,Sprite arg,ObjectFileArgs &OFA); //!< Saves a Troglodyte Object file (.TOF) Argument, filename, is the path and filename to save as, arg is the Sprite Object to create an object file from, and OFA is a reference to file arguments for the Object.
	bool SaveScene(const std::string &filename);  //!< Saves a Troglodyte Scene file (.TSF) Argument, filename, is the path and filename to save as.
	bool SaveLevel(const std::string &filename);  //!< Saves a Troglodtye Level File (.TLF) Argument, filename, is the path and filename to save as.

	bool LoadObject(const std::string &filename, Sprite  &arg,ObjectFileArgs &OFA); //!< Loads a Troglodyte Object file(.TOF) Argument, filename, is the path and filename to load from, and OFA is a reference to file arguments for the Object.
	bool LoadScene(std::string filename); //!< Loads a Troglodyte Scene file(.TSF) Argument, filename, is the path and filename to load from.
	bool LoadLevel(std::string filename); //!< Loads a Troglodyte Level file(.TLF) Argument, filename, is the path and filename to load from.

	bool ResolveMessage(std::string StateName, std::string MESSAGE); //!< Translates StateName from a string into a State_ID, as well as the string Message into a numerical version to be sent to a state. It then sends it to the state using DispatchMessage() (This version of this function is ideal for text interfaces such as the command console.) RETURNS FALSE IF EITHER ARGUMENT CAN NOT BE RESOLVED
	bool ResolveMessage(int STATE_ID, int MESSAGE); //!< This version of the function makes sure the STATE_ID and MESSAGE are valid and then sends it the specified state, via HML_DispatchMessage(). RETURNS FALSE IF EITHER ARGUMENT CAN'T BE Resolved. (IDeal for GUI interaction).

    bool ADDSTATE(GAMESTATE * const  State,bool Init);   //!< Looks at the ID_REF_COUNT and increments it, assigning the number to the State being referenced, State_ID. It then adds the values from the reference to variable in the array, then adds it to the management pool. Also Init tells the state whether to initialize itself or not. States can't be managed until added to the pool, there fore this function must be public. It's the only function for the HML who's functionality isn't handled by ResolveMessage().
	
	GS_HML();
	~GS_HML();
};


#endif