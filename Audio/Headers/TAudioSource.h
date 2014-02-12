/********************************************************************
* This is the Audio Header file for the Troglodyte Game Engine      *
*									                                *
* Author : Will Canada (DecipherOne) February 18, 2007              *
* Copyright (C) DecipherOne Productions 2007                        *
*********************************************************************/
/*!-------------------------------------------------------------------+
| This class is meant to be used by a game object or as a music buf- |
| fer that has only one source and multiple buffers. The number of   |
| buffers is currently limited to twelve.                            |
+-------------------------------------------------------------------*/



#ifndef _TAudioSource
#define _TAudioSource

//Structs used for storing Orientation of sources and the listening Device

struct SourcePos //!< Position of the sound source in 3D space .
{
	float x,y,z;
};

                        
struct SourceVelocity //!<Velocity of the sound source in 3D space.
{
	float x,y,z;
};




/////////////////////////////////////////////////////////////////////////////////////////

//Audio Source Class



class TAudioSource //!< Class for Managing OpenAL Audio Sources and Buffers
{

	//Internal Variables used by OpenAL to setup Audio Data
	ALboolean loop; //!< Tells Whether or not the file should loop
    ALenum format; //!< Format of the file being loaded
    ALsizei size;  //!< Size of the file being loaded
    ALvoid* data;  //!< Pointer to the actual data in memory of the audio file
    ALsizei freq;  //!< The Frequency of the audio data
    

	
	//Structs for Sound Positioning
	SourcePos sp; //!< Instance of the Source position struct
	SourceVelocity sv; //!< Instance of the source velocity struct
	

	bool buffersini; //!<Used to signal the audio buffers have been generated. Stops more from being generated when already created buffers are accessed.

	std::string Name; //!< String Name of the file to load
	const char * Label; //!< Label of the file to load - Used for printing on screen or saving data to disk

	void SetName(std::string arg); //!< Sets the name of the file
	bool ConString4Screen(std::string arg); //!< Used to convert string to const char * for file loading

	enum AudioType //!< Tells What Format of Audio File to load when loadSound() is called
	{
		_WAV_,
		_OGG_,
		_MID_
		
	};

	int SoundType; //!<Used to store which Sound type to load
	
public:


	
	 bool loopOGG; //!< Signals whether to loop an OGG file
	 bool PlayBackOGG();        //!< play the OGG stream - Should be called to begin playing
     bool OGGisPlaying();         //!< check if the OGG source is playing
     bool UpdateOGG();          //!< update the OGG stream if necessary - Should be called after PlayBackOGG
	 

	bool Play;          //!< Used as a signal to play a wav file, must be set to false after playing has began (USED FOR MUSIC< NOT SOUND EFFECTS)
	bool SoundisAmbient; //!< Used to tell if Sound can be heard from anywhere(Generally used for Music)
	TAudioSource();
	~TAudioSource();
	ALuint OGGBuffer[3]; //!< Allocated memory for Three Buffers for Streaming OGG Files
	ALuint SoundBuffer[12]; //!< Allocated memory for the SoundBuffer for use with WAVE files
	unsigned int Source; //!<  The Audio Source for this Audio object(Specific to OpenAL)
	
	bool loadSound(int); //!< Loads a sound resource : Takes an argument as to which soundbuffer to access (11 is Max)
	void SetSound2Load(std::string arg); //!< Sets the path and name of Sound file 2 load
	
	std::string GetName();  //!<Returns the String Name given to the Audio Object

	bool GetLoop();        //!< Returns the bool variable loop 
	

	void SetSoundType(int); /*!< USed to set the Sound type for loading an Audio File.
							Should either be 0 For WAVE or 1 For OGG. */

	int GetSoundType(); //!< Used to access type of Sound being loaded

	float GetSourcePosX(); 
	float GetSourcePosY();
	float GetSourcePosZ();
	void SetSourcePos(TObject &Object); //!<Used to link Audio source position with an Object
	void SetSourcePos(float x,float y,float z); //!<Used to set a generic Position for the audio source
	float GetSourceVelX();
	float GetSourceVelY();
	float GetSourceVelZ();
	void SetSourceVel(float x,float y,float z); //!<Used to set a generic velocity for an Audio source
	

	bool GetBuffersini(); //!< Returns buffersini to signal if the buffers are initialized
	bool BindSource2Buff(int A); //!<Used to Bind the Source to the specified buffer (Only usable with waves)
	bool UpdateSource(float pitch, float gain, bool loopanyways); //!< Used to update the source Object Should be called after associated object drawing

	bool UnloadSounds(); //!< Cleans up memory and frees buffers and sources

	bool SaveAudioSourceData( fstream &stream); //!< Saves Audio data for an instance of the TAudioSource class. stream is the file stream to save with. (NOTE - ALL FILE OPENING AND CLOSING MUST BE DONE FROM THE CALLING FUNCTION)Only saves information for one default sound file
	bool LoadAudioSourceData( fstream &stream); //!< Loads Audio data for an instance of the TAudioSource class. stream is the file stream to load with. (NOTE - ALL FILE OPENING AND CLOSING MUST BE DONE FROM THE CALLING FUNCTION)Only loads information for one default sound file
	 

private:

	//Structs for handling OGG Vorbis files

	bool StreamOGG(ALuint buffer);   //!< Streams an OGG Buffer
     OggVorbis_File  oggStream;     //!< stream handle
     vorbis_info*    vorbisInfo;    //!< some formatting data
     vorbis_comment* vorbisComment; //!< user comments


	

};

#endif