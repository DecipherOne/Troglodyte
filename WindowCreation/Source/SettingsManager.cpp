//Settings manager definitions for  Troglodyte
/*!*********************************************(C)**
+ Will Canada : DecipherOne Productions      2007  +
|--------------------------------------------------|
|This class is used for loading all the Graphic    |
|,Audio, and other settings for initalizing the    |
|game settings.                                    |
|__________________________________________________|
+--------------------------------------------------+*/

#include "PCHEADER.H"

using namespace std;
int SettingsManager::Load_V_Settings()
{
	fstream stream;

	

    stream.open("config.ini",ios::in|ios::binary);
	if(stream.is_open())
	{
		

		//Load the AppNameSize to set up buffer size for string data
		stream.read((char *) &V_Settings.AppNameSize, sizeof(V_Settings.AppNameSize));
		//Setup a char buffer for string data

		char * buffer = new char [V_Settings.AppNameSize]; //Allocate memory for buffer


		//Read in each byte one at a time for the string data

		int i=0; //used for counting characters

		

		int b =0; //used for incrementing the buffer

		do
		{
			stream.read((buffer+b),sizeof(char)); //Read in the string data

			i +=1;
			b +=1;

		}
		while(i!=V_Settings.AppNameSize);

		V_Settings.AppName = buffer;  //Convert the string data to the string in the struct


		
		int buf = strlen(buffer);     //Get the length of the string data and any extra padding

		if(strlen(buffer) != V_Settings.AppNameSize) //If the lengths don't match
		{
			if(buf>V_Settings.AppNameSize) //IF the length is too long remove padding from string
			{

				V_Settings.AppName.erase(V_Settings.AppNameSize, buf);
			}

			else //Data has probably been corrupted.
			{
				MessageBox(NULL,"V_Settings.AppNameSize is not the correct size! Application will now quit!",
				"Settings Load Error",MB_OK);
				PostQuitMessage(0);
				return -1;
			}
			
		}

		

		//delete our pointer
		delete buffer;

		//read the remaining config settings
		
		
		stream.read((char *) &V_Settings.CBits,sizeof(V_Settings.CBits));
		stream.read((char *) &V_Settings.fullscreen,sizeof(V_Settings.fullscreen));
		stream.read((char *) &V_Settings.height,sizeof(V_Settings.height));
		stream.read((char *) &V_Settings.width,sizeof(V_Settings.width));


		
		stream.close();
	}

	else
	{
		MessageBox(NULL,"Could not Load settings file!","Settings Load Error",MB_OK);
		return -1;
		
	}

	return 0;
}

int SettingsManager::Save_V_Settings ()
{

	
	fstream stream;
	stream.open("config.ini",ios::out|ios::binary);
	if(stream.is_open())
	{

		//Get the offset of our string object
		 V_Settings.AppNameSize = V_Settings.AppName.size();

		//Check to make sure the offset is correct
		if(V_Settings.AppName.size() != V_Settings.AppNameSize) 
		{
			MessageBox(NULL,"V_Settings.AppName is not the correct size! Application will now quit!",
				"Settings Save Error",MB_OK);
			PostQuitMessage(0);
		}

		//Save the offset for the string to be loaded later : MUST BE LOADED FIRST BEFORE STRING DATA
		stream.write((char *) & V_Settings.AppNameSize,sizeof(V_Settings.AppNameSize));

		//Write the string to the file converting it to a const char * and as the actual size of the string
		stream.write(V_Settings.AppName.c_str(),V_Settings.AppNameSize); 
		
		
		//write the additional config settings

		stream.write((char *) &V_Settings.CBits,sizeof(V_Settings.CBits));
		stream.write((char *) &V_Settings.fullscreen,sizeof(V_Settings.fullscreen));
		stream.write((char *) &V_Settings.height,sizeof(V_Settings.height));
		stream.write((char *) &V_Settings.width,sizeof(V_Settings.width));
		

		stream.flush();

		stream.close();
	}

	else
	{
		MessageBox(NULL,"Could not save settings file!","Settings Save Error",MB_OK);
	}


	return 0;
}

SettingsManager::SettingsManager()
{
	V_Settings.AppName.reserve(255);
}

SettingsManager::~SettingsManager()
{
}