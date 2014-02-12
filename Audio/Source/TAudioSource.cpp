/*!*******************************************************************
* This is the Audio source file for the Troglodyte Game Engine      *
*									                                *
* Author : Will Canada (DecipherOne) February 18, 2007              *
* Copyright (C) DecipherOne Productions 2007                        *
*********************************************************************/


#include "PCHEADER.H"
#define BUFFER_SIZE (4096 * 24)

bool TAudioSource::loadSound(int arg) 
{

	 int A = arg; //used for incrementing the SoundBuffers

	 if(A < 0)
	 {
		 A=0;
	 }

	if(A > 11|| A < 0)//Do Saftey Check for memory access
	{
		MessageBox(NULL,"Memory out of Bounds. Either increase number of buffers, or check\n"
			"The memory location you are trying to access. The Program \n"
			"will now Quit.","loadSound() Memory Access Violation!",MB_ICONERROR|MB_OK);

		ErrorLog.WriteMessage("Memory out of Bounds. Either increase number of buffers, or check\n"
			"The memory location you are trying to access. The Program \n"
			"will now Quit.");
		PostQuitMessage(0);
		return false;
	}

	
	switch(SoundType)
	{
		//Loading an WAVE File
		case _WAV_:
			{
				
				//Generate the specified number of sound buffers

				alGetError();
				if(buffersini==false)
				{
					
					alGenBuffers(12,SoundBuffer);
				}
				

				//Get error message and clear the error bit
				int ErrorNum = alGetError();

				//Check for an error message
				switch (ErrorNum)
				{
				case AL_INVALID_NAME:
					{
						MessageBox(NULL,"AL_INVALID_NAME a bad name (ID)\n"
							"\t was passed to alGenBuffers() in loadSound().","OPENAL ERROR",MB_OK);
						ErrorLog.WriteMessage("AL_INVALID_NAME a bad name (ID)\n"
							"\t was passed to alGenBuffers() in loadSound().");
						break;
					}
				case AL_INVALID_ENUM:
					{
						MessageBox(NULL,"AL_INVALID_ENUM an invalid enum \n"
							"\t was passed to alGenBuffers() in loadSound().","OPENAL ERROR",MB_OK);
						ErrorLog.WriteMessage("AL_INVALID_ENUM an invalid enum \n"
							"\t was passed to alGenBuffers() in loadSound().");
						break;
					}

				case AL_INVALID_VALUE:
					{
						MessageBox(NULL,"AL_INVALID_VALUE an invalid value  \n"
							"\t was passed to alGenBuffers() in loadSound().","OPENAL ERROR",MB_OK);
						ErrorLog.WriteMessage("AL_INVALID_VALUE an invalid value  \n"
							"\t was passed to alGenBuffers() in loadSound().");
						break;
					}

				case AL_INVALID_OPERATION :
					{
						MessageBox(NULL,"AL_INVALID_OPERATION the requested operation is not valid.  \n"
							"\t Error in alGenBuffers() in loadSound().","OPENAL ERROR",MB_OK);
						ErrorLog.WriteMessage("AL_INVALID_OPERATION the requested operation is not valid.  \n"
							"\t Error in alGenBuffers() in loadSound().");
						break;
					}

				case AL_OUT_OF_MEMORY :
					{
						MessageBox(NULL,"AL_OUT_OF_MEMORY the requested operation resulted in OpenAL running out of memory.  \n"
							"\t Error in alGenBuffers() in loadSound().","OPENAL ERROR",MB_OK);
						ErrorLog.WriteMessage("AL_OUT_OF_MEMORY the requested operation resulted in OpenAL running out of memory.  \n"
							"\t Error in alGenBuffers() in loadSound().");
						break;
					}
				}

					
		         std::string err_s = Label;
				if (alGetError() != AL_NO_ERROR)
				{
					ErrorLog.WriteMessage("An OpenAL WAV Resource "+ err_s +" failed to load");
					return AL_FALSE;
				}

			
				
				// Load wav data into a buffer.

				alutLoadWAVFile(Label, &format, &data, &size, &freq, &loop);
					

				alBufferData(SoundBuffer[A], format, data, size, freq);
			
				
				alutUnloadWAV(format, data, size, freq);



				ErrorNum= alGetError();
				err_s = Label;
				std::string err_n = to_string(long double (ErrorNum));
				if (ErrorNum != AL_NO_ERROR)
				{
					ErrorLog.WriteMessage("An OpenAL WAV Resource "+ err_s +" failed to load"
						" with Error Number : "+err_n);
					return AL_FALSE;
				}

					buffersini = true;
			
							
					break;
			}
		////////////////////////////////////////////////////////////////////////////////

		//Loading a OGG File
		case _OGG_:
			{
				FILE * oggFile = NULL;

				
				//Attempt to open the specified File
				int result;

				if(buffersini==false)
				{
					
					alGenBuffers(3,OGGBuffer);
				}

    	
				
				if(!(oggFile = fopen(Label, "rb")))
				{
					MessageBox(NULL,"Could Not Open the OGG file. Check the path/n"
						" or file name. Program Will Now Quit!"," TAudioSource::loadSound() Error!",MB_OK);
					ErrorLog.WriteMessage("Could Not Open the OGG file. Check the path/n"
						" or file name. Program Will Now Quit!");

					PostQuitMessage(0);
					return false;
				}


				

			 
				//Attempt to create a stream with the data
				if((result = ov_open(oggFile, &oggStream, NULL, 0))< 0) 
				{
					fclose(oggFile);
			 
					MessageBox(NULL,"Could Not Open the OGG Stream. Program Will Now Quit!",
						" TAudioSource::loadSound() Error!",MB_OK);
					ErrorLog.WriteMessage("Could Not Open the OGG Stream. Program Will Now Quit!");

					PostQuitMessage(0);
					return false;
				}

				//Read in information from the file
				vorbisInfo = ov_info(&oggStream, -1);
				vorbisComment = ov_comment(&oggStream, -1);
			 
				if(vorbisInfo->channels == 1)
				{
					format = AL_FORMAT_MONO16;
				}

				else
				{
					format = AL_FORMAT_STEREO16;
				}

				alGetError();
				alGenSources(1,&Source);
				buffersini = true; //signal buffers have been initialized
				break;
			}

		/////////////////////////////////////////////////////////////////////////////////
		//Loading a MIDI File
		case _MID_:
			{
				break;
			}

		/////////////////////////////////////////////////////////////////////////////////////////
		


		default:
			{
				MessageBox(NULL,"Audio Format Not Recognized, Please select either : \n"
				" 0 _WAV_ \n"
				" 1 _OGG_ \n"
				"\n"
				" Program Will Now Quit!","TAudioSource::loadSound() Error!",MB_OK);
				ErrorLog.WriteMessage("Audio Format Not Recognized, Please select either : \n"
				" 0 _WAV_ \n"
				" 1 _OGG_ \n"
				"\n"
				" Program Will Now Quit!");
				PostQuitMessage(0);
			}

	}

			
			
		

	
	ResourceLog.WriteMessage("SoundFile - "+ Name +" successfully loaded.");
	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////

void TAudioSource::SetSound2Load(std::string arg)
{
	SetName(arg);
	ConString4Screen(Name);


}

//////////////////////////////////////////////////////////////////////////////////////////

bool TAudioSource::ConString4Screen(std::string arg)
{
	Label = Name.c_str();
	
	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////

std::string TAudioSource::GetName()
{
	return Name;
}

/////////////////////////////////////////////////////////////////////////////////////////

void TAudioSource::SetName(std::string arg)
{
	Name = arg;
}

//////////////////////////////////////////////////////////////////////////////////////////






///////////////////////////////////////////////////////////////////////////////////////////
void TAudioSource::SetSoundType(int arg)
{
	switch(arg)
	{
	case 0:
		{
			SoundType = _WAV_;
			break;
		}

	case 1:
		{
			SoundType = _OGG_;
			break;
		}

	case 2:
		{
			SoundType = _MID_;
			break;
		}


	default:
		{
			MessageBox(NULL,"Audio Format Not Recognized, Please select either : \n"
				" 0 _WAV_ \n"
				" 1 _OGG_ \n"
				" 2 _MID_ \n"
				" \n"
				" Program Will Now Quit!","SetSoundType() Error!",MB_OK);
			PostQuitMessage(0);
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////

int TAudioSource::GetSoundType()
{
	return SoundType;
}
//////////////////////////////////////////////////////////////////////////////////////////

float TAudioSource::GetSourcePosX()
{
	return sp.x;
}

float TAudioSource::GetSourcePosY()
{
	return sp.y;
}

float TAudioSource::GetSourcePosZ()
{
	return sp.z;
}

/////////////////////////////////////////////////////////////////////////////////////////

float TAudioSource::GetSourceVelX()
{
	return sv.x;
}

float TAudioSource::GetSourceVelY()
{
	return sv.y;
}

float TAudioSource::GetSourceVelZ()
{
	return sv.z;
}

////////////////////////////////////////////////////////////////////////////////////////

void TAudioSource::SetSourcePos(TObject &Object)
{
	sp.x = Object.GetxTranslation();
	sp.y = Object.GetyTranslation();
	sp.z = Object.GetzTranslation();
}

void TAudioSource::SetSourcePos(float x,float y, float z)
{
	sp.x = x;
	sp.y = y;
	sp.z = z;
}

void TAudioSource::SetSourceVel(float x, float y, float z)
{
	sv.x = x;
	sv.y = y;
	sv.z = z;
}

///////////////////////////////////////////////////////////////////////////////////////////////
bool TAudioSource::GetLoop()
{
	return loop;
}

///////////////////////////////////////////////////////////////////////////////////////////////

TAudioSource::~TAudioSource()
{

	//Sources must be deleted before buffers
	UnloadSounds();
	
}


//////////////////////////////////////////////////////////////////////////////////////////

TAudioSource::TAudioSource()
{
	SetSourcePos(0.0,0.0,-1.0); //Initially set the position of the source at the center of the screen and one unit back.
	SetSourceVel(0.0,0.0,0.0); //Set a generic Stationary Velocity
	buffersini = false;
	SoundisAmbient = false;
	loopOGG = false;
	vorbisInfo = NULL;
	vorbisComment = NULL;
}


//////////////////////////////////////////////////////////////////////////////////////////
/*! This function binds the Source Object to the specified buffer in SoundBuffer */

bool TAudioSource::BindSource2Buff(int A)
{

	if(SoundType==_OGG_)
	{
		MessageBox(NULL,"You are attempting to bind a Source to an individual buffer.\n"
			" The audio type is currently set to OGG for this source. You should use \n"
			" the OGG playing functions for using ques. Program Will Now Quit!","TAudioSource::BindSource2Buff() Error!",MB_OK);
		
		ErrorLog.WriteMessage("You are attempting to bind a Source to an individual buffer.\n"
			" The audio type is currently set to OGG for this source. You should use \n"
			" the OGG playing functions for using ques. Program Will Now Quit!");
		PostQuitMessage(0);
		return false;
	}


	if(A < 0)
	 {
		 A=0;
		 ErrorLog.WriteMessage("A sound buffer was attempted to be setup for out of"
			"bounds access. Defaulting to buffer 0.");
	 }
	else if(A>11)
	{
		A=11;
		ErrorLog.WriteMessage("A sound buffer was attempted to be setup for out of"
			"bounds access. Defaulting to buffer 11.");
	}

	
	alGetError();
	// Bind buffer with a source.
	alGenSources(1, &Source);

	int	ErrorNum = alGetError();
	

	if (ErrorNum != AL_NO_ERROR)
	{
		std::string err_n= to_string(long double(ErrorNum));
		ErrorLog.WriteMessage("OpenAL Error - Binding a source to a buffer, Error Number : " +
			err_n);
			return AL_FALSE;
	}

	alSourcei (Source, AL_BUFFER,SoundBuffer[A]);

	ErrorNum = alGetError();
					
	if (ErrorNum != AL_NO_ERROR)
	{
		std::string err_n= to_string(long double(ErrorNum));
		ErrorLog.WriteMessage("OpenAL Error - Binding a source to a buffer, Error Number : " +
			err_n);
		return AL_FALSE;
	}

	return AL_TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////
/*! This function Updates the properties of the Source object. */

bool TAudioSource::UpdateSource(float pitch, float gain, bool loopanyways)
{

	
	int	ErrorNum = alGetError();
	alSourcef (Source, AL_PITCH, pitch);
	alSourcef (Source, AL_GAIN, gain);
	alSource3f(Source, AL_POSITION, sp.x,sp.y,sp.z);
	alSource3f(Source, AL_VELOCITY, sv.x,sv.y,sv.z);
	alSourcei (Source, AL_LOOPING,loopanyways);

	if(SoundisAmbient == true)
	{
		alSourcef (Source, AL_ROLLOFF_FACTOR,  0.0); //Set the rolloff factor to zero so that the file can be heard regardless of 
				                                             //The source or listeners positions
	    alSourcei (Source, AL_SOURCE_RELATIVE, AL_TRUE);
	}

	 ErrorNum = alGetError();
	if (ErrorNum != AL_NO_ERROR)
	{
		std::string err_n= to_string(long double(ErrorNum));
		ErrorLog.WriteMessage("OpenAL Error - Updating the Source, Error Number : " +
			err_n);
		return AL_FALSE;
	}

	if(SoundType==_OGG_)
	{
		PlayBackOGG();
		UpdateOGG(); 
	}

					return true;
}
///////////////////////////////////////////////////////////////////////////////////////////

bool TAudioSource::UnloadSounds()
{

	switch(SoundType)
	{
	case _WAV_:
		{
			//Buffers must be released from source before source can successfully be deleted
			alSourcei (Source, AL_BUFFER,0);//Detach Buffers from source
			alDeleteSources(1, &Source);
			alDeleteBuffers(12,SoundBuffer);
			ResourceLog.WriteMessage("Sound Resource - WAV : "+Name+" has been freed from memory.");
			break;
		}

	case _OGG_:
		{
			alSourceStop(Source); //Stop the source

			//Empty the Que
			int queued;
    
			alGetSourcei(Source, AL_BUFFERS_QUEUED, &queued);
		    
			while(queued--)
			{
				ALuint buffer;
		    
				alSourceUnqueueBuffers(Source, 1, &buffer);
				alGetError();
			}

			//////////////////////////////////////////

			alDeleteSources(1, &Source);
			alDeleteBuffers(3,OGGBuffer);
			ov_clear(&oggStream); //Release the hold on the file stream
			ResourceLog.WriteMessage("Sound Resource - OGG : "+Name+" has been freed from memory.");
			break;
		}

	case _MID_:
		{
			break;
		}
	}

	buffersini=false;

	return true;
}
					
//////////////////////////////////////////////////////////////////////////////////////////

bool TAudioSource::UpdateOGG()
{
	ALint processed=0;
	
    bool active = true;
 
	alGetError();
    alGetSourcei(Source, AL_BUFFERS_PROCESSED, &processed);

	
    while(processed--)
    {
        ALuint buffer;
        
        alSourceUnqueueBuffers(Source, 1, &buffer);
        alGetError();
 
        active = StreamOGG(buffer);
 
        alSourceQueueBuffers(Source, 1, &buffer);
		alGetError();
        
    }

	
 
    return active;
}

//////////////////////////////////////////////////////////////////////////////////////////

bool TAudioSource::OGGisPlaying()
{
	ALenum state;
    
    alGetSourcei(Source, AL_SOURCE_STATE, &state);
    
	return (state == AL_PLAYING);
}

//////////////////////////////////////////////////////////////////////////////////////////

bool TAudioSource::PlayBackOGG()
{
	if(OGGisPlaying())
	{
        return true;
	}
        
    if(!StreamOGG(OGGBuffer[0]))
	{
        return false;
	}
 
    if(!StreamOGG(OGGBuffer[1]))
	{
        return false;
	}

	if(!StreamOGG(OGGBuffer[2]))
	{
		return false;
	}

    
    alSourceQueueBuffers(Source, 3, OGGBuffer);
    alSourcePlay(Source);
    
    return true;
}

//////////////////////////////////////////////////////////////////////////////////////////

bool TAudioSource::StreamOGG(ALuint buffer)
{


	char data[BUFFER_SIZE];
    int  size = 0;
    int  section = 0;
    int  result = 0;
 
	
    while(size < BUFFER_SIZE)
    {
        result = ov_read(&oggStream, data + size, BUFFER_SIZE - size, 0, 2, 1, & section);
    
        if(result > 0)
		{
            size += result;
		}

        else
		{
			
            if(result < 0)
			{
				MessageBox(NULL,"Error with the OGG Stream. Look into this!","TAudioSource::StreamOGG() Error!",MB_OK);
				ErrorLog.WriteMessage("Error with OGG Stream for file "+Name);
				return false;
			}
            else
			{
				if(loopOGG == true)
				{
					ov_raw_seek(&oggStream,0);
				}
				else
				{
					break;
				}
			}
		}
    }
    
    if(size == 0)
	{
        return false;
	}
 
    alBufferData(buffer, format, data, size, vorbisInfo->rate);
    alGetError();
 
    return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////

bool TAudioSource::GetBuffersini()
{
	return buffersini;
}

/////////////////////////////////////////////////////////////////////////////////////////////

bool TAudioSource::SaveAudioSourceData( fstream &stream)
{

	if(stream.is_open()) //If the file is open
	{

		//Write the size of the current memory allocation for the class Pointers that need saving


				//Set the Volatile Pointer Information

				
			int NameSize = Name.size();
		
		//Save the offset for the NameSize to be loaded later : MUST BE LOADED FIRST BEFORE STRING DATA
			
			stream.write((char *) &NameSize,sizeof(int));

			//Write the string to the file converting it to a const char * and as the actual size of the string
			stream.write(Name.c_str(),NameSize);
			
			
			

		

		//Save the remaining TAudioSource Data

		stream.write((char *) &sp.x,sizeof(float));
		stream.write((char *) &sp.y,sizeof(float));
		stream.write((char *) &sp.z,sizeof(float));
		stream.write((char *) &sv.x,sizeof(float));
		stream.write((char *) &sv.y,sizeof(float));
		stream.write((char *) &sv.z,sizeof(float));
		stream.write((char *) &SoundType,sizeof(int));
		stream.write((char *) &loopOGG,sizeof(bool));
		stream.write((char *) &Play,sizeof(bool));
		stream.write((char *) &SoundisAmbient,sizeof(bool));
		
		
		
	}

	else
	{
		MessageBox(NULL,"Could not write TAudioSource Data to the file!","TAudioSource::SaveAnimData() Error!",MB_OK);
		return false;
	}

	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////

bool TAudioSource::LoadAudioSourceData(fstream &stream)
{


	if(stream.is_open())
	{
			int NameSize = 0;

			//Load the offset for the string to be loaded later : MUST BE LOADED FIRST BEFORE STRING DATA
			stream.read((char *) &NameSize,sizeof(int));
			//if any of the file path/names are too long prevent the file from being loaded.
			if(NameSize > 255)
			{

				MessageBox(NULL,"The file path and name for a Sprite is too long./n" 
					"This means one or more files that are trying to be loaded are corrupt. The file(s) will not be loaded.", "Memory Managment Error!",MB_ICONERROR | MB_OK);
				stream.close();
				return false;
			}


			if(NameSize>0)
			{

				char * buffer = new char [NameSize]; //Allocate memory for buffer


				//Read in each byte one at a time for the string data

				int i=0; //used for counting characters

				

				int b =0; //used for incrementing the buffer

				do
				{
					stream.read((buffer+b),sizeof(char)); //Read in the string data

					i +=1;
					b +=1;

				}
				while(i!=NameSize);

				Name = buffer;  //Convert the string data to the string in the struct


				
				int buf = strlen(buffer);     //Get the length of the string data and any extra padding

				if(strlen(buffer) != NameSize) //If the lengths don't match
				{
					if(buf>NameSize) //IF the length is too long remove padding from string
					{

						Name.erase(NameSize, buf);
					}

					else //Data has probably been corrupted.
					{
						MessageBox(NULL,"TAudioSource::NameSize is not the correct size! Application will now quit!",
							"TAudioSource::LoadAudioSource() Error!",MB_OK);
						PostQuitMessage(0);
					}
					
				}

			

				//delete our pointer

				if(buffer)
				{

					delete buffer;
				}
			}

			

		//Load the remaining TAudioSource Data

		stream.read((char *) &sp.x,sizeof(float));
		stream.read((char *) &sp.y,sizeof(float));
		stream.read((char *) &sp.z,sizeof(float));
		stream.read((char *) &sv.x,sizeof(float));
		stream.read((char *) &sv.y,sizeof(float));
		stream.read((char *) &sv.z,sizeof(float));
		stream.read((char *) &SoundType,sizeof(int));
		stream.read((char *) &loopOGG,sizeof(bool));
		stream.read((char *) &Play,sizeof(bool));
		stream.read((char *) &SoundisAmbient,sizeof(bool));

		//Load the Sound File to fill out the rest of the texture data

		if(NameSize>0)
		{
			SetSound2Load(Name);
			loadSound(1);
			BindSource2Buff(1);
		}

		

		return true;

	}

	else
	{
		MessageBox(NULL,"Could not read AudioSource Data from the file!","TAudioSource::LoadAudioSourceData() Error!",MB_OK);
		return false;
	}

	return false;
}