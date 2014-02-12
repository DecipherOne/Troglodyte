/********************************************************************
* This is the Animation Source file for the Troglodyte Game Engine  *
*									                                *
* Author : Will Canada (DecipherOne) March 11, 2007                 *
* Copyright (C) DecipherOne Productions 2007                        *
*********************************************************************/

#include "PCHEADER.h"


const char * Animation2D::GetLabel()
{
	return Label;
}

//////////////////////////////////////////////////////////////////////////////////////////

std::string Animation2D::GetName()
{
	return NameOfAnimation;
}

//////////////////////////////////////////////////////////////////////////////////////////

void Animation2D::SetName(std::string arg)
{
	NameOfAnimation = arg;
}

//////////////////////////////////////////////////////////////////////////////////////////

bool Animation2D::GetLoop()
{
	return Loop;
}

//////////////////////////////////////////////////////////////////////////////////////////

void Animation2D::SetLoop(bool arg)
{
	Loop = arg;
}

///////////////////////////////////////////////////////////////////////////////////////////

void Animation2D::ConvertName()
{
	Label = NameOfAnimation.c_str();
}

//////////////////////////////////////////////////////////////////////////////////////////

void Animation2D::SetNumOfFrames(int arg)
{

	
	if(arg>63)
	{
		MessageBox(NULL," You are trying to specify more frames then currently allocated memory. \n"
			" Each animation is limited to 64 frames. If you were to contniue the program would \n"
			" throw an exception and memory would become corrupt. Automatically resizing the animation \n"
			" you will need to change this to not generate this error.",
			" Animation2D::SetNumOfFrames() Error!", MB_ICONERROR|MB_OK);
		
		arg=63;
	}

	if(arg< 1)
	{
		arg = 1;
	}

	NumOfFrames = arg;
}


//////////////////////////////////////////////////////////////////////////////////////////

void Animation2D::SetActiveFrame(int arg)
{
	ActiveFrame = arg;
}



///////////////////////////////////////////////////////////////////////////////////////////

int Animation2D::GetActiveFrame()
{
	return ActiveFrame;
}

///////////////////////////////////////////////////////////////////////////////////////////

int Animation2D::GetNumOfFrames()
{
	return NumOfFrames;
}

///////////////////////////////////////////////////////////////////////////////////////////

bool Animation2D::AdvanceFrame()
{

	float time = 1/FramesPerSec;
	if(AnimationTimer.CheckLogicTimer(time)) //This helps keep the animation timing consistant and not linked to updates
	{


			ActiveFrame +=1;
            
			if(Loop) //Start this animation over once it reaches the end?
			{
				//if the activeFrame is greater then the number of frames , the active frame is reset to 1
				if(ActiveFrame > NumOfFrames)
				{
					ActiveFrame = 1;
				}
			}

			else
			{
				if(ActiveFrame > NumOfFrames)
				{
					ActiveFrame=NumOfFrames;
				}
			}
	}

	
	return true;
}


///////////////////////////////////////////////////////////////////////////////////////////

bool Animation2D::ReverseFrame()
{

	float time = 1/FramesPerSec;
	if(AnimationTimer.CheckLogicTimer(time)) //This helps keep the animation timing consistant and not linked to updates
	{


			ActiveFrame -=1;
            
			if(Loop) //Start this animation over once it reaches the end?
			{
				//if the activeFrame is greater then the number of frames , the active frame is reset to 1
				if(ActiveFrame< 1)
				{
					ActiveFrame =NumOfFrames;
				}
			}

			else
			{
				if(ActiveFrame < 1)
				{
					ActiveFrame=1;
				}
			}
	}

	
	return true;
}


//////////////////////////////////////////////////////////////////////////////////////////
Animation2D::Animation2D(int numFrames,int AnimSpeed, std::string AnimName)
{
	NameOfAnimation = AnimName;   //Set the animations name
	ConvertName();                //Convert the string name to a const char * for screen printing (if needed)
	SetNumOfFrames(numFrames);      // Set the number of complete frames for the animation
    Loop=1;
	ActiveFrame = 1;                                //Set the active frame to the first frame
	FrameAccumBuf = 0;
	AnimationFPS = &MainState;  //Assign the pointer to UpdatesManager to point to the MainState instance
	FramesPerSec=12;
}

//////////////////////////////////////////////////////////////////////////////////////////


Animation2D::~Animation2D()
{

	
}

///////////////////////////////////////////////////////////////////////////////////////////

void Animation2D::SetFrameName(int num, std::string Name)
{
	AnimationFrames[num].FrameName = Name;

	AnimationFrames[num].FrameLabel = AnimationFrames[num].FrameName.c_str();

	
}

///////////////////////////////////////////////////////////////////////////////////////////

Animation2D::Animation2D()
{
	FramesPerSec=12;
	Loop =1;
	NameOfAnimation ="";
	ActiveFrame = 1;                                //Set the active frame to the first frame
	FrameAccumBuf = 0;
	AnimationFPS = &MainState;  //Assign the pointer to UpdatesManager to point to the MainState instance
}

/////////////////////////////////////////////////////////////////////////////////////////////

bool Animation2D::SaveAnimData( fstream &stream)
{
	int count = 0; // used for cycling through things for saving.

	if(stream.is_open()) //If the file is open
	{

		//Write the individual frame data, stop after all 64 frames have been written

		//Get the size of the current memory allocation for the string FrameName for each frame
		do
		{
				
			AnimationFrames[count].SizeOfFrameName = AnimationFrames[count].FrameName.size();


			//if any of the file path/names are too long prevent the file from being written.
			if(AnimationFrames[count].SizeOfFrameName > 255)
			{

				MessageBox(NULL,"The file path and name for Animation Frames is too long./n The file will not be saved.", "Memory Managment Error!",MB_ICONERROR | MB_OK);
				stream.close();
				return false;
			}

			//Save the offset for the string to be loaded later : MUST BE LOADED FIRST BEFORE STRING DATA
			stream.write((char *) & AnimationFrames[count].SizeOfFrameName,sizeof(AnimationFrames[count].SizeOfFrameName));

			//Write the string to the file converting it to a const char * and as the actual size of the string
			stream.write(AnimationFrames[count].FrameName.c_str(),AnimationFrames[count].SizeOfFrameName);

			stream.write((char *) &AnimationFrames[count].x1,sizeof(float));
			stream.write((char *) &AnimationFrames[count].x2,sizeof(float));
			stream.write((char *) &AnimationFrames[count].x3,sizeof(float));
			stream.write((char *) &AnimationFrames[count].x4,sizeof(float));

			stream.write((char *) &AnimationFrames[count].y1,sizeof(float));
			stream.write((char *) &AnimationFrames[count].y2,sizeof(float));
			stream.write((char *) &AnimationFrames[count].y3,sizeof(float));
			stream.write((char *) &AnimationFrames[count].y4,sizeof(float));
			

			count += 1; //Increase the count
		}
		while(count<=63); //Exit after the 64 Frame is reached

		//Get the size of the memory allocation for the string NameOfAnimation
		SizeOfAnimationName = NameOfAnimation.size();

		//if any of the file path/names are too long prevent the file from being written.
		if(SizeOfAnimationName > 255)
		{

			MessageBox(NULL,"The file path and name for Animations is too long./n The file will not be saved..", "Memory Managment Error!",MB_ICONERROR | MB_OK);
			stream.close();
			return false;
		}
		//Save the size
		stream.write((char *) &SizeOfAnimationName,sizeof(SizeOfAnimationName));

		//Save the actual data stored in NameOfAnimation
		stream.write(NameOfAnimation.c_str(),SizeOfAnimationName);

		//Save the remaining Animation Data

		stream.write((char *) &NumOfFrames,sizeof(int));

		//stream.flush();
		
	}

	else
	{
		MessageBox(NULL,"Could not write Animation Data to file!","Animation2D::SaveAnimData() Error!",MB_OK);
		return false;
	}

	return true;
}


/////////////////////////////////////////////////////////////////////////////////////////////

bool Animation2D::LoadAnimData(fstream &stream)
{

   int count = 0;

	if(stream.is_open())
	{

		//Load the FrameData

		//Get the size of the current memory allocation for the string FrameName for each frame
		do
		{
				

			//Load the offset for the string to be loaded later : MUST BE LOADED FIRST BEFORE STRING DATA
			stream.read((char *) &AnimationFrames[count].SizeOfFrameName,sizeof(AnimationFrames[count].SizeOfFrameName));
				
			//if any of the file path/names are too long prevent the file from being loaded.
			if(AnimationFrames[count].SizeOfFrameName > 255)
			{

				MessageBox(NULL,"The file path and name for Animation Frames is too long./n"
					"This means one or more files that are trying to be loaded are corrupt. The file(s) will not be loaded.", "Memory Managment Error!",MB_ICONERROR | MB_OK);
				stream.close();
				return false;
			}

			if(AnimationFrames[count].SizeOfFrameName>0)
			{
				char * buffer = new char [AnimationFrames[count].SizeOfFrameName]; //Allocate memory for buffer

				if(AnimationFrames[count].SizeOfFrameName>0)
				{

					//Read in each byte one at a time for the string data

					int i=0; //used for counting characters

					

					int b =0; //used for incrementing the buffer

					do
					{
						stream.read((buffer+b),sizeof(char)); //Read in the string data

						i +=1;
						b +=1;

					}
					while(i!=AnimationFrames[count].SizeOfFrameName);

					AnimationFrames[count].FrameName = buffer;  //Convert the string data to the string in the struct


					
					int buf = strlen(buffer);     //Get the length of the string data and any extra padding

					if(strlen(buffer) != AnimationFrames[count].SizeOfFrameName) //If the lengths don't match
					{
						if(buf>AnimationFrames[count].SizeOfFrameName) //IF the length is too long remove padding from string
						{

							AnimationFrames[count].FrameName.erase(AnimationFrames[count].SizeOfFrameName, buf);
						}

						else //Data has probably been corrupted.
						{
							MessageBox(NULL,"AnimationFrames[].SizeOfFrameName is not the correct size! \\n The animation frame data can not be loaded!",
								"Animation2D::LoadAnimData() Error!",MB_OK);

							//delete our pointer
							if(buffer)
							{

								delete buffer;
								buffer= NULL;
							}
							return false;
						}
						
					}

				

					//delete our pointer
					if(buffer)
					{

						delete buffer;
						buffer= NULL;
					}
				}
			}


			stream.read((char *) &AnimationFrames[count].x1,sizeof(float));
			stream.read((char *) &AnimationFrames[count].x2,sizeof(float));
			stream.read((char *) &AnimationFrames[count].x3,sizeof(float));
			stream.read((char *) &AnimationFrames[count].x4,sizeof(float));

			stream.read((char *) &AnimationFrames[count].y1,sizeof(float));
			stream.read((char *) &AnimationFrames[count].y2,sizeof(float));
			stream.read((char *) &AnimationFrames[count].y3,sizeof(float));
			stream.read((char *) &AnimationFrames[count].y4,sizeof(float));
			

			count += 1; //Increase the count
		}
		while(count<=63); //Exit after the 64 Frame is reached



		//Load the Animation Data

		//Load the offset for the string to be loaded later : MUST BE LOADED FIRST BEFORE STRING DATA
			stream.read((char *) &SizeOfAnimationName,sizeof(int));
			//if any of the file path/names are too long prevent the file from being written.
			if(SizeOfAnimationName > 255)
			{

				MessageBox(NULL,"The file path and name for Animations is too long./n" 
					"This means one or more files that are trying to be loaded are corrupt. The file(s) will not be loaded.", "Memory Managment Error!",MB_ICONERROR | MB_OK);
				stream.close();
				return false;
			}

			if(SizeOfAnimationName>0)
			{

				char * buffer = new char [SizeOfAnimationName]; //Allocate memory for buffer


				//Read in each byte one at a time for the string data

				int i=0; //used for counting characters

				

				int b =0; //used for incrementing the buffer

				do
				{
					stream.read((buffer+b),sizeof(char)); //Read in the string data

					i +=1;
					b +=1;

				}
				while(i!=SizeOfAnimationName);

				NameOfAnimation = buffer;  //Convert the string data to the string in the struct


				
				int buf = strlen(buffer);     //Get the length of the string data and any extra padding

				if(strlen(buffer) != SizeOfAnimationName) //If the lengths don't match
				{
					if(buf>SizeOfAnimationName) //IF the length is too long remove padding from string
					{

						NameOfAnimation.erase(SizeOfAnimationName, buf);
					}

					else //Data has probably been corrupted.
					{
						MessageBox(NULL,"SizeOfAnimationName is not the correct size! The Animation data can not be loaded!",
							"Animation2D::LoadAnimData() Error!",MB_OK);
						//delete our pointer
						if(buffer)
						{

							delete buffer;
							buffer= NULL;
						}
						return false;
					}
					
				}

			

				   //delete our pointer
					if(buffer)
					{

						delete buffer;
						buffer= NULL;
					}

				//Load the rest of the Animation Data
			}

			
		stream.read((char *) &NumOfFrames,sizeof(int));


	}

	else
	{
		MessageBox(NULL,"Could not Load Animation Data from file!","Animation2D::LoadAnimData() Error!",MB_OK);
		return false;
		
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////

void Animation2D::SetFrameTexCoord(int FrameNum, float x1, float x2, float y1, float y3)
{

	if(FrameNum > 63 || FrameNum < 0)
	{
		MessageBox(NULL,"You are attempting to access an out of bounds memory location for"
			" the AnimationFrames array. Please check and make sure FrameNum is correctly set between 0 and 63."
			" The Program Will Now Quit.",
			"Animation2D::SetFrameTexCoord() Error!",MB_OK);
		PostQuitMessage(0);
	}

	AnimationFrames[FrameNum].x1 = x1;
	AnimationFrames[FrameNum].x4 = x1;
	AnimationFrames[FrameNum].x2 = x2;
	AnimationFrames[FrameNum].x3 = x2;
	AnimationFrames[FrameNum].y1 = y1;
	AnimationFrames[FrameNum].y2 = y1;
	AnimationFrames[FrameNum].y3 = y3;
	AnimationFrames[FrameNum].y4 = y3;
}

//////////////////////////////////////////////////////////////////////////////////

void Animation2D::SetFPS(float arg)
{
	if(arg<1)
	{
		arg=1;
	}
	else if(arg>60)
	{
		arg=60;
	}

	FramesPerSec=arg;
}

/////////////////////////////////////////////////////////////////////////////////////

float Animation2D::GetFPS()
{
	return FramesPerSec;
}




			




	
	