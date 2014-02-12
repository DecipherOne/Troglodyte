

#include "PCHEADER.h"



bool GS_HML::LoadObject(const std::string &filename,Sprite &arg,ObjectFileArgs &OFA)
{
	  
	
	   //Begin File checks before saving
	//---------------------------------------------------

	fstream stream; //Open a stream

	//Check to see if the specified file already exists


	stream.open(filename.c_str(),ios::in|ios::binary|ios::_Nocreate);
		
	if(stream.is_open())
	{

	

			 //First Load the Arguments for the file type. (These Are set when the Object is Saved.)
		//------------------------------------------------

			stream.read((char *) &OFA.hasTexture,sizeof(bool));
			stream.read((char *) &OFA.isAnimate,sizeof(bool));
			stream.read((char *) &OFA.isChangable,sizeof(bool));
			stream.read((char *) &OFA.useDialog,sizeof(bool));
			stream.read((char *) &OFA.useScripts,sizeof(bool));
			stream.read((char *) &OFA.Scene_ID,sizeof(int));
			


			//Begin Loading the various data for the given Sprite Object 
		//--------------------------------------------------------------


		if(OFA.hasTexture)
		{
			if(!arg.Texture.LoadTextureData(stream))
			{
				stream.flush();
				stream.close();
				return false;
			}
		}

		if(!arg.pAudioSource.LoadAudioSourceData(stream))
		{

			stream.flush();
			stream.close();
			return false;
		}

		if(OFA.isAnimate)
		{
			if(!arg.Animations->LoadAnimData(stream))
			{

				stream.flush();
				stream.close();
				return false;
			}
		}

		if(!arg.LoadSpriteData(stream))
		{

			stream.flush();
			stream.close();
			return false;
		}





			//Flush and Close our File
		//------------------------------------------

		stream.flush();
		stream.close();

		return true;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////


bool GS_HML::SaveObject(const std::string &filename,Sprite arg, ObjectFileArgs &OFA)
{
	  
	
	   //Begin File checks before saving
	//---------------------------------------------------

	fstream stream; //Open a stream

		//Setup our file structure variables to signal whether certain things should be saved for that file

	OFA.hasTexture = arg.GetHasTexture();  

	if(arg.GetNumOfAnimations()>0)
	{

		OFA.isAnimate = true;
	}


	//Check to see if the specified file already exists
	stream.open(filename.c_str(),ios::in|ios::binary);

	if(stream.is_open())
	{
		
			//If it does prompt the user to save over the file
			if(MessageBox(NULL,"The file already exist. Would you like to save anyways?",
				"Attention : File Already Exists!",MB_YESNO|MB_ICONQUESTION)==IDNO)
			{
				stream.close();
				return false;
			}

		stream.close();
	}

		


	//If the file didn't exist or the user decided to save over the current file,  
	//Open our file for saving

	stream.open(filename.c_str(),ios::out|ios::binary|ios::beg); 

	if(stream.is_open())
	{

	

			 //First Save the Arguments for the file type. (These Are set when the SaveObject Dialog GUI is called from the Editor)
		//------------------------------------------------


			stream.write((char *) &OFA.hasTexture,sizeof(bool));
			stream.write((char *) &OFA.isAnimate,sizeof(bool));
			stream.write((char *) &OFA.isChangable,sizeof(bool));
			stream.write((char *) &OFA.useDialog,sizeof(bool));
			stream.write((char *) &OFA.useScripts,sizeof(bool));
			stream.write((char *) &OFA.Scene_ID,sizeof(int));
			
			


			//Begin Saving the various data for the given Sprite Object 
		//--------------------------------------------------------------


		if(OFA.hasTexture)
		{
			if(!arg.Texture.SaveTextureData(stream))
			{
				stream.flush();
				stream.close();
				return false;
			}
		}

		if(!arg.pAudioSource.SaveAudioSourceData(stream))
		{

			stream.flush();
			stream.close();
			return false;
		}

		if(OFA.isAnimate)
		{

			if(!arg.Animations->SaveAnimData(stream))
			{
				stream.flush();
				stream.close();
				return false;
			}
		}

		if(!arg.SaveSpriteData(stream))
		{

			stream.flush();
			stream.close();
			return false;
		}



			//Flush and Close our File
		//------------------------------------------

		stream.flush();
		stream.close();

		return true;
	}



	return false;
}


//////////////////////////////////////////////////////////////////////////////////////////


GS_HML::GS_HML()
{
	ID_REF_COUNT = 0;
	ActiveState_ID = 0;
	PreviousState_ID = 0;
}

//////////////////////////////////////////////////////////////////////////////////

GS_HML::~GS_HML()
{
}

//////////////////////////////////////////////////////////////////////////////////


bool GS_HML::ADDSTATE(GAMESTATE * const  State,bool Init)
{

	

	
	//Make sure that there are not too many active states. Limit to MAX_NUM_OF_STATES.

	if(ID_REF_COUNT >= MAX_NUM_OF_STATES)
	{
		MessageBox(NULL,"There are too many Active Game States. You must \n"
			" Remove one from memory before adding a new one. Add Game state aborted.",
			"GAMESTATE OVERFLOW!",MB_OK|MB_ICONERROR);

		return false;
	}

	else
	{
		ID_REF_COUNT += 1;  //ADD 1 to our reference count.
	}

	

	int b = 0; //Set the counter variable to one to access first scene cache location.
	//Check to see if the current location is empty.
	do
	{
		if(StateCache[b].Get_StateName() == "") 
		{
			//Set the Active Level State Information
			StateCache[b] = *State; //Store the values of the State reference into our empty location
			StateCache[b].Set_State_ID(ID_REF_COUNT); //Set the states ID for referencing
		

			if(Init) //Should we set the state as the lead one?
			{
						StateCache[b].Set_isStarting(true);    
						StateCache[b].Set_hasFocus(true);
						StateCache[b].Set_isPaused(false);
						break;
			}

			else   //Otherwise don't
			{
					StateCache[b].Set_isStarting(false);    
					StateCache[b].Set_hasFocus(false);
					break;
			}
		}

		else
		{
			b+=1;

			if(b>=(MAX_NUM_OF_STATES))
			{
				//ADD A MESSAGE OF STATE COULD NOT BE ADDED TO
				//BE DISPLAYED USING CUSTOM MESSAGE FUNCTION
				//ONCE GUI IS FINISHED.

				MessageBox(NULL,"The State could not be added. Current States being managed are full.",
					" State Addition Error",MB_OK||MB_ICONERROR);

				return false;
			}
		}
	}
	while(b<=(MAX_NUM_OF_STATES - 1));

		
	return true;

}

/////////////////////////////////////////////////////////////////////////////////////


bool GS_HML::REMOVESTATE(int STATE_ID)
{
	
 
	// remove state.
		StateCache[STATE_ID].Remove();
		ID_REF_COUNT --;


	return true;
}



/////////////////////////////////////////////////////////////////////////////////////

bool GS_HML::ResolveMessage(int STATE_ID, int MESSAGE)
{

	if(STATE_ID < 0 || STATE_ID > ID_REF_COUNT) //The Id isn't valid.
	{
		MessageBox(NULL, "The STATE_ID is not valid. Please make sure it \n"
			" is in the appropriate range. The program will continue but \n"
			" the attempted state command could not be carried out.",
			" GS_HML::ResolveMessage() Error!",MB_OK||MB_ICONEXCLAMATION);
		return false;
	}

	//ID is valid, make sure message is valid.

	if(MESSAGE < 0 || MESSAGE > 9)
	{
		MessageBox(NULL, "The Message is not valid. Please make sure it \n"
			" is in the appropriate range. The program will continue but \n"
			" the attempted state command could not be carried out.",
			" GS_HML::ResolveMessage() Error!",MB_OK||MB_ICONEXCLAMATION);
		return false;
	}
	else
	{
		HML_DispatchMessage(STATE_ID,MESSAGE);
		return true;
	}

	return false;
}

/////////////////////////////////////////////////////////////////////////////////////

bool GS_HML::ResolveMessage(std::string StateName, std::string MESSAGE)
{
 
	

	int g=0;
	int StateID=0;
	int MessageID=0;

	//Go through all the current game states and find the one with the qaulifing state name
	do
	{
		if(StateCache[g].Get_StateName() == StateName)
		{
			StateID = g;
			break;
		}
		if(g > 26)
		{
			MessageBox(NULL,"The specified state could not be found. \n"
				" Make sure the spelling of the state name and the message are correct. \n"
				" The program will continue but no action will be performed by the state.",
				"GL_HML::ResloveMessage() Error",MB_OK||MB_ICONEXCLAMATION);
			return false;
			break;
		}
	}
    while(StateID==0);


    //Find the corrisponding Message

	transform(MESSAGE.begin(),MESSAGE.end(),MESSAGE.begin(),
		(int(*)(int)) toupper);
	
	if(MESSAGE=="INITIALIZE")
	{
		HML_DispatchMessage(StateID,INITIALIZE_STATE);
		return true;
	}

	else if(MESSAGE=="REMOVE")
	{
		HML_DispatchMessage(StateID,REMOVE_STATE);
		return true;
	}

	else if(MESSAGE=="SETFOCUS")
	{
		HML_DispatchMessage(StateID,STATE_HASFOCUS);
		return true;
	}

	else if(MESSAGE=="REMOVEFOCUS")
	{
		HML_DispatchMessage(StateID,STATE_REMOVEFOCUS);
		return true;
	}

	else if(MESSAGE=="PAUSE")
	{
		HML_DispatchMessage(StateID,PAUSE_STATE);
		return true;
	}
	else if(MESSAGE=="UNPAUSE")
	{
		HML_DispatchMessage(StateID,UN_PAUSE_STATE);
		return true;
	}

	return false;
}

/////////////////////////////////////////////////////////////////////////////////////

int GS_HML::HML_DispatchMessage(int STATE_ID, int MESSAGE)
{
	if(MESSAGE==REMOVE_STATE)
	{
		REMOVESTATE(STATE_ID);
	}

	else if(StateCache[STATE_ID].UpdateMessages(MESSAGE))
	{
		return 1;
	}

   return 0;
}

//////////////////////////////////////////////////////////////////////////////////////

bool GS_HML::Push_State(int STATE_ID)
{
	StateCache[STATE_ID].Set_hasFocus(false);
	return false;
}

//////////////////////////////////////////////////////////////////////////////////////
bool GS_HML::Pop_State(int STATE_ID)
{	
	StateCache[STATE_ID].Set_hasFocus(true);
	return true;
}