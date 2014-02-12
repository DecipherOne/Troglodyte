/********************************************************************
* This is the Sprite Source file for the Troglodyte Game Engine     *
*									                                *
* Author : Will Canada (DecipherOne) February 18, 2007              *
* Copyright (C) DecipherOne Productions 2007 - 2011                 *
*                                                                   *
* Modified March 2011                                               *
*********************************************************************/
/*!-------------------------------------------------------------------+
| This class brings together sound and texture functionality  and     |
| encapsulates them into a managment class that 2D Game Sprites can   |
| be created from. More specific classes for games should be derived  |
| from this class.                                                    |
+---------------------------------------------------------------------*/

#include "PCHEADER.H"



Sprite::Sprite(std::string n, int AnimNum) : Quad(n)
{
	

	if(AnimNum == 0|| AnimNum < 0)
	{
		AnimNum = 1;
	}

	NumOfAnimations = AnimNum;

	Animations = new Animation2D[AnimNum];

	NewTime = 0;
	OldTime = 0;
	

	B_Box.Neg_X = 0;
	B_Box.Neg_Y = 0;
	B_Box.Pos_X = 0;
	B_Box.Pos_Y = 0;
	B_Box.Z = 0;

	ObjectsLog.WriteMessage("Sprite : "+ n +" has been Created");
}

/////////////////////////////////////////////////////////////////////////////////////////

Sprite::~Sprite()
{
	
	if((Animations+1))
	{
		delete[] Animations;
		Animations = NULL;
	}

	else if(Animations)
	{
		delete Animations;
		Animations = NULL;
	}

	if(this->Name=="")
	{
		ObjectsLog.WriteMessage("A Sprite with no name has been released from memory.");
	}
	else
	{
		ObjectsLog.WriteMessage("Sprite: "+ this->Name +" has been released from memory.");
	}
	
}


//////////////////////////////////////////////////////////////////////////////////////////

bool Sprite::SetAnimationName_Num(int n, std::string Name,int FrameNums)
{
	if(n < 0 || n> NumOfAnimations)
	{
		MessageBox(NULL,"The animations in an instance of the Sprite class is either less \n"
			"Then zero or greater then the number of animations memory is allocated for. The Program \n"
			"Will Now Quit!","Sprite::SetAnimationName_Num Error!",MB_ICONERROR|MB_OK);

		ErrorLog.WriteMessage("The animations in an instance of the Sprite class "+ this->Name + " is either less \n"
			"Then zero or greater then the number of animations memory is allocated for. The Program \n"
			"Will Now Quit!");
		PostQuitMessage(0);
		return false;
	}


	(Animations+n)->SetName(Name);
	(Animations+n)->ConvertName();
	(Animations+n)->SetNumOfFrames(FrameNums);

	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////

bool Sprite::AnimateSprite(int num, bool reverse=false)
{

	if(reverse)
	{
		(Animations+num)->ReverseFrame();
	}
	else
	{
		(Animations+num)->AdvanceFrame();
	}

	

	int FrameNum = (Animations+num)->GetActiveFrame();

	FrameNum --; //Subtract 1 to access the correct frame data
	
	
	float x1,x2,y1,y3 = 0;
	x1 = (Animations+num)->AnimationFrames[FrameNum].x1;
	x2 = (Animations+num)->AnimationFrames[FrameNum].x2;
	y1 = (Animations+num)->AnimationFrames[FrameNum].y1;
	y3 = (Animations+num)->AnimationFrames[FrameNum].y3;
	

	SetTexCoords(x1,y1,x2,y3);




	return true;
}

/////////////////////////////////////////////////////////////////////////////////

Sprite::Sprite():Quad()
{

	Animations = NULL;
	NumOfAnimations = 0;

	NewTime = 0;
	OldTime = 0;

	B_Box.Neg_X = 0;
	B_Box.Neg_Y = 0;
	B_Box.Pos_X = 0;
	B_Box.Pos_Y = 0;
	B_Box.Z = 0;

	ObjectsLog.WriteMessage("A Sprite with no name was successfully created.");
	
}


/////////////////////////////////////////////////////////////////////////////////

void Sprite::SetNumOfAnimations(int arg)
{
	

	if(arg <= 0)
	{
		arg = 0;
		NumOfAnimations = arg;
		return;
	}

	NumOfAnimations = arg;

	if(Animations+1)
	{
		delete[] Animations;
		Animations = NULL;
	}

	else if(Animations)
	{
		delete Animations;
		Animations = NULL;
	}

	Animations = new Animation2D [arg];
	

	

}



////////////////////////////////////////////////////////////////////////////////

int Sprite::GetNumOfAnimations()
{
	return NumOfAnimations;
}


/////////////////////////////////////////////////////////////////////////////////////////////

bool Sprite::SaveSpriteData(fstream &stream)
{
	



	if(stream.is_open()) //If the file is open
	{

		//Write the size of the current memory allocation for the class Pointers that need saving


				//Set the Volatile Pointer Information

				
				int NameSize = Name.size();
		
		//Save the offset for the Pointers to be loaded later : MUST BE LOADED FIRST BEFORE STRING DATA
			
			stream.write((char *) &NameSize,sizeof(int));

			//Write the string to the file converting it to a const char * and as the actual size of the string
			stream.write(Sprite::Name.c_str(),NameSize);
			
			
			

		

		//Save the remaining Sprite Data

		

		//Loop through and write each texture coordinate
		int a,s;
		a=0;
		s=0;

		do
		{

			if(s>1)
			{
				s=0;
				a+=1;
			}

			stream.write((char *) &Sprite::TexCoords[a][s],sizeof(float));
			s+=1;
		}
		while(a<=3);


		
		//Loop through and write each Vertice coordinate
		a=0;
		s=0;

		do
		{

			if(s>2)
			{
				s=0;
				a+=1;
			}

			stream.write((char *) &Sprite::Vertices[a][s],sizeof(float));
			s+=1;
		}
		while(a<=3);



		stream.write((char *) &NumOfAnimations,sizeof(int));
		stream.write((char *) &hasTexture,sizeof(bool));
		stream.write((char *) &Destroy,sizeof(bool));
		stream.write((char *) &IsInitialized,sizeof(bool));
		stream.write((char *) &MouseIsSelected,sizeof(bool));
		stream.write((char *) &mUnitSize,sizeof(float));
		stream.write((char *) &RotateAngle,sizeof(float));
		stream.write((char *) &rUnitSize,sizeof(float));
		stream.write((char *) &SpawnCount,sizeof(int));
		stream.write((char *) &xRotate,sizeof(float));
		stream.write((char *) &xTranslate,sizeof(float));
		stream.write((char *) &yRotate,sizeof(float));
		stream.write((char *) &yTranslate,sizeof(float));
		stream.write((char *) &zRotate,sizeof(float));
		stream.write((char *) &zTranslate,sizeof(float));
		stream.write((char *) &B_Box,sizeof(BoundingBox_2D));   //Could possibly cause an error,
																//but probably won't since it's
		                                                        // not volatile information.
		
	}

	else
	{
		MessageBox(NULL,"Could not write Sprite Data to the file!","Animation2D::SaveAnimData() Error!",MB_OK);
		return false;
	}

	return true;
}


///////////////////////////////////////////////////////////////////////////////////////////


bool Sprite::LoadSpriteData(fstream &stream)
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
						MessageBox(NULL,"Sprite::NameSize is not the correct size! Application will now quit!",
							"PTexture::LoadAnimData() Error!",MB_OK);
						PostQuitMessage(0);
					}
					
				}

			

				//delete our pointer
				delete buffer;
			}

				

		//Loadthe remaining Sprite Data

		

		//Loop through and write each texture coordinate
		int a,s;
		a=0;
		s=0;

		do
		{

			if(s>1)
			{
				s=0;
				a+=1;
			}

			stream.read((char *) &Sprite::TexCoords[a][s],sizeof(float));
			s+=1;
		}
		while(a<=3);


		
		//Loop through and write each Vertice coordinate
		a=0;
		s=0;

		do
		{

			if(s>2)
			{
				s=0;
				a+=1;
			}

			stream.read((char *) &Sprite::Vertices[a][s],sizeof(float));
			s+=1;
		}
		while(a<=3);



		stream.read((char *) &NumOfAnimations,sizeof(int));
		stream.read((char *) &hasTexture,sizeof(bool));
		stream.read((char *) &Destroy,sizeof(bool));
		stream.read((char *) &IsInitialized,sizeof(bool));
		stream.read((char *) &MouseIsSelected,sizeof(bool));
		stream.read((char *) &mUnitSize,sizeof(float));
		stream.read((char *) &RotateAngle,sizeof(float));
		stream.read((char *) &rUnitSize,sizeof(float));
		stream.read((char *) &SpawnCount,sizeof(int));
		stream.read((char *) &xRotate,sizeof(float));
		stream.read((char *) &xTranslate,sizeof(float));
		stream.read((char *) &yRotate,sizeof(float));
		stream.read((char *) &yTranslate,sizeof(float));
		stream.read((char *) &zRotate,sizeof(float));
		stream.read((char *) &zTranslate,sizeof(float));
		stream.read((char *) &B_Box,sizeof(BoundingBox_2D));   //Could possibly cause an error,
																//but probably won't since it's
		                                                        // not volatile information.





		return true;

	}

	else
	{
		MessageBox(NULL,"Could not read Sprite Data from the file!","Sprite::LoadAnimData() Error!",MB_OK);
		return false;
	}

	return false;

}


/////////////////////////////////////////////////////////////////////////////////////////

void Sprite::SetDimensions(float x1,float x2,float y1,float y3)
{
	x1= FM.Pixel_2WorldSpace(x1);
	x2= FM.Pixel_2WorldSpace(x2);
	y1= FM.Pixel_2WorldSpace(y1);
	y3= FM.Pixel_2WorldSpace(y3);
	SetVerticesScales(-x1,-y1,x2,y3,0.0f);
	
}


//////////////////////////////////////////////////////////////////////////////////////////


bool Sprite::SetB_BoxDimension(float NegX,float PosX,float NegY,float PosY)
{
	B_Box.Pos_X = PosX;
	B_Box.Pos_Y = PosY;
	B_Box.Neg_X = NegX;
	B_Box.Neg_Y = NegY;
	return true;
}


///////////////////////////////////////////////////////////////////////////////////

bool Sprite::Test_2DCollide(Sprite &Object2,Sprite &Object1)
{


	
	if(Object2.GetIsCollide()&&Object1.GetIsCollide()) //Make sure the objects are collideable
	{	
		//Check to see the objects intersect.
		if( Object2.B_Box.Pos_X >= Object1.B_Box.Neg_X && 
			Object2.B_Box.Neg_X <= Object1.B_Box.Pos_X &&
			Object2.B_Box.Pos_Y >= Object1.B_Box.Neg_Y &&
			Object2.B_Box.Neg_Y <= Object1.B_Box.Pos_Y)
		{
			//A Collision happened.
			return hasCollided = true;;
		}
	}


	//No Collision
	return hasCollided = false;

}


///////////////////////////////////////////////////////////////////////////////////

bool Sprite::Test_2DCollide_Z(Sprite &Object2,Sprite &Object1)
{


	if(Object2.GetIsCollide()&&Object1.GetIsCollide()) //Make sure the objects are collideable
	{
		//Check to see the objects intersect.
		if( Object2.B_Box.Pos_X >= Object1.B_Box.Neg_X && 
			Object2.B_Box.Neg_X <= Object1.B_Box.Pos_X &&
			Object2.B_Box.Pos_Y >= Object1.B_Box.Neg_Y &&
			Object2.B_Box.Neg_Y <= Object1.B_Box.Pos_Y &&
			Object2.GetzTranslation() == Object1.GetzTranslation())
		{
			//A Collision happened.
			
			return hasCollided = true;;
		}
	}


	//No Collision
	return hasCollided = false;

}

//////////////////////////////////////////////////////////////////////////////////

void Sprite::DrawB_Box()
{
	float x = 0;
	float y = 0;
	float z = 0;
	
	FM.SetColor(140);//Set color to green.
	glPushMatrix();
	glBegin(GL_LINES);

	x = B_Box.Neg_X;
	y = B_Box.Pos_Y;
	z = GetzTranslation();

	glVertex3f(x,y,z); //Top Left

	x = B_Box.Pos_X;
	y = B_Box.Pos_Y;
									
	glVertex3f(x,y,z); //Top Right
	glVertex3f(x,y,z); //Top Right

	x = B_Box.Pos_X;
	y = B_Box.Neg_Y;
									
	glVertex3f(x,y,z); //Bottom Right															
	glVertex3f(x,y,z); //Bottom Right

	x = B_Box.Neg_X;
	y = B_Box.Neg_Y;
									
	glVertex3f(x,y,z); //Bottom Left						
	glVertex3f(x,y,z); //Bottom Left

	x = B_Box.Neg_X;
	y = B_Box.Pos_Y;

	glVertex3f(x,y,z); //Top Left


	glEnd();

	glPopMatrix();
	FM.SetColor(1);//Set Color Back to white

}

/*/////////////////////////////////////////////////////////////////////*/

bool Sprite::Anim_Map_UV(int first_frame_row, int first_frame_col,float f_width, float f_height, int numFrames, int AnimationNum)
{
	//calculate the initial uv positions 

	float initial_x = f_width/Texture.width;
	float initial_y = f_height/Texture.height;

	//How many cells rows and columns in our texture have.
	int frames_per_row = Texture.width/f_width;
	int num_of_cols = Texture.height/f_height;

	//Bounds Checks
	if(first_frame_row<1)
	{
		first_frame_row=1;
	}

	if(first_frame_col<1)
	{
		first_frame_col=1;
	}

	else if(first_frame_col>num_of_cols)
	{
		first_frame_col=num_of_cols;
	}

	//Make sure the animation exist in memory
	if(AnimationNum > GetNumOfAnimations() || AnimationNum < 0)
	{
		MessageBox(NULL," The animation you are attempting to map is not valid.",
			"Sprite::MapUV() Error!", MB_OK|MB_ICONERROR);
		return false;
	}

	int count = 0;

	//create our multipliers
	int x_m = first_frame_col;
	int y_m = first_frame_row;
	

	do
	{
		

		
		(Animations+AnimationNum)->SetFrameTexCoord(count,
		(initial_x)*(x_m-1),initial_x*x_m,initial_y*(y_m-1),initial_y*y_m);


		//If we've reached the end of the row, move down to next row, first col
		if(x_m == frames_per_row)
		{
			y_m++;
			x_m=1;
		}
		else
		{
			x_m++;
		}



			count++;
	}
	while(count<numFrames);




	return true;
}

///////////////////////////////////////////////////////////////////////////////////

bool Sprite::Static_Map_UV(int frame_row, int frame_col,float f_width,float f_height)
{

	//calculate the initial uv positions 

	float initial_x = f_width/Texture.width;
	float initial_y = f_height/Texture.height;

	//How many cells rows and columns in our texture have.
	int frames_per_row = Texture.width/f_width;
	int num_of_cols = Texture.height/f_height;

	if(frame_row<1)
	{
		frame_row=1;
	}
	if(frame_col<1)
	{
		frame_col=1;
	}

	else if(frame_col>frames_per_row)
	{
		frame_col=frames_per_row;
	}


	//create our multipliers
	int x_m = frame_col;
	int y_m = frame_row;
	

	
	if(!SetTexCoords((initial_x)*(x_m-1),initial_y*(y_m-1),initial_x*x_m,initial_y*y_m))
	{
		MessageBox(NULL,"The texture Coordinates could not be set.",
			"SPRITE::Static_Map_UV Error",MB_OK|MB_ICONERROR);
		return false;
	}


	return true;
}
////////////////////////////////////////////////////////////////////////////////////////
	
void Sprite::SetAnim_Fps(float fps, int anim_num)
{
	if(anim_num>NumOfAnimations)
	{
		MessageBox(NULL,"The Animation You are attempting to set a frame"
			"rate for is not valid. Program will exit.","SetAnim_FPS Out of Bounds Error!",
			MB_ICONERROR|MB_OK);
		PostQuitMessage(0);
		return;
	}

	(Animations+anim_num)->SetFPS(fps);
}

/////////////////////////////////////////////////////////////////////////////////////////

float Sprite::GetAnim_Fps(int anim_num)
{
	return (Animations+anim_num)->GetFPS();
}

/////////////////////////////////////////////////////////////////////////////////////////

void Sprite::UpdateB_Box(int p_x,int n_x,int p_y,int n_y)
{
	B_Box.Neg_X = GetxTranslation() - FM.Pixel_2WorldSpace(n_x);
	B_Box.Pos_X = GetxTranslation() + FM.Pixel_2WorldSpace(p_x);
	B_Box.Neg_Y = GetyTranslation() - FM.Pixel_2WorldSpace(n_y);
	B_Box.Pos_Y = GetyTranslation() + FM.Pixel_2WorldSpace(p_y);
}

/////////////////////////////////////////////////////////////////////////////////////////

void Sprite::SethasCollided(bool arg)
{
	if(arg!=1&&arg!=0)
	{ 
		arg = false;
	}

	hasCollided = arg;
}

/////////////////////////////////////////////////////////////////////////////////////////

bool Sprite::GethasCollided()
{
	return hasCollided;
}