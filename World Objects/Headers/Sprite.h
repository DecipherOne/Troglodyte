/********************************************************************
* This is the Sprite Header file for the Troglodyte Game Engine     *
*									                                *
* Author : Will Canada (DecipherOne) February 18, 2007              *
* Copyright (C) DecipherOne Productions 2007                        *
*********************************************************************/
/*!-------------------------------------------------------------------+
| This class brings together sound and texture functionality  and     |
| encapsulates them into a managment class that 2D Game Sprites can   |
| be created from. More specifc classes for games should be derived   |
| from this class.                                                    |
+---------------------------------------------------------------------*/



#ifndef _SPRITE_H
#define _SPRITE_H

  

struct BoundingBox_2D   //!< This struct contains the vertices positions to create a bounding box used for collision detection. Although it contains a Z coordinate it is simply the depth coordinate that all the Vertices lie on.
{
	float Neg_X;   //!< The Negative x  Position of the bounding box.
	float Neg_Y;   //!< The Negative y Position  of the bounding box.
	float Pos_X;   //!< The Positive x position  of the bounding box.
	float Pos_Y;   //!< The Positive y position  of the bounding box.
	float Z;      //!< The Z coordinate for which all the vertices lie. Optional.
};


class Sprite : public Quad //!< This class brings together sound and texture functionality
{

protected:
	
	int NumOfAnimations;      //!< This is number of Animations the Sprite will have - used to initalize animations
	bool hasCollided;         //!< Used to signal a collision;
	
public:


	BoundingBox_2D B_Box;                  //!< Instance of a BoundingBox struct used to store the coordinates of a bounding box for a sprite.
	virtual bool SetB_BoxDimension(float NegX,float PosX,float NegY,float PosY);       //!< Used to set the Bounding Box Dimensions for a sprite (IMPORTANT NOTE! Should Be called after the sprites translation has been initially set, otherwise it will contain invalid information.)
	void SetDimensions(float x1,float x2,float y1,float y3);             //!< Used to set Sprite Dimension - Calls Pixel_2WorldSpace Args are dimensions for a cell on the sprite sheet example 40X40px sprite on a 64X64 cell,args should be 64X64. 
	bool SaveSpriteData(fstream &stream);  //!< Used to save a sprite to a file. stream is the file stream to save with. (NOTE - ALL FILE OPENING AND CLOSING MUST BE DONE FROM THE CALLING FUNCTION)
	bool LoadSpriteData(fstream &stream);  //!< Used to load a sprite from a file. stream is the file stream to Load with. (NOTE - ALL FILE OPENING AND CLOSING MUST BE DONE FROM THE CALLING FUNCTION)
	TAudioSource  pAudioSource; //!< An Instance of TAudioSource. 
	Animation2D * Animations; //!< Pointer to some dynamic instances of the Animation2D class - to be initialized through the constructor - Names for the animations must be explicity set through the SetName function of Animation2D
	bool SetAnimationName_Num(int n, std::string Name, int FrameNums); //!< Used to set the name of the Animations the sprite class makes use of. First argument is which animation in the dynamic array to access, second is the name of the animation, third is how many Frames the animation has
	void SetNumOfAnimations(int arg); //!< Sets the number of animations the sprite class has and initializes memory for them
	int GetNumOfAnimations();      //!< Returns the number of Animations
	bool AnimateSprite(int num,bool reverse); //!< Runs the specified animation. Argument num used to specificy which animation in the array to animate, reverse is whether to reverse the animation.
	Sprite(std::string, int AnimNum);  //!< Initializing Constructor the first argument is is the name of the sprite  The second  is the number of animations 
	Sprite(); //!< Default Constructor
	~Sprite();    //!< Destructor

	bool Anim_Map_UV(int first_frame_row, int first_frame_col,float f_width,float f_height, int numFrames,int AnimationNum); /*!< Automatically maps pixel to uv coords based upon the size of the texture, 
																					  the location of the first cell of animation, and the number of the frames. 
																					  The specific animation number must be specified.
																					  first_frame row&col are the row and column where the first animation frame is located.
																					  f width& height a single frames width and height on the sprite sheet */
	
	bool Static_Map_UV(int frame_row, int frame_col,float f_width,float f_height);/*!< Automatically maps pixel to uv coords based upon the size of the texture,
																							 this version is for static images so no animation info is required.*/


	bool Test_2DCollide(Sprite &Object2,Sprite &Object1); //!< This function takes two references to Sprite Objects and tests them for collison on the X and Y planes only.
	bool Test_2DCollide_Z(Sprite &Object2,Sprite &Object1); //!< This function takes two references to Sprite Objects and tests them for collison on the X and Y planes also making sure that the objects have the same Z location.
	void DrawB_Box(); //!< Draws the bounding box.
	void SetAnim_Fps(float fps, int anim_num); //Sets the specified animations frames per second.
	float GetAnim_Fps(int anim_num); //Returns the Specified animations FPS.
	void UpdateB_Box(int p_x,int n_x,int p_y,int n_y); //Updates the bbox location upon call.
	void SethasCollided(bool arg); //!< Sets hasCollided
	bool GethasCollided();         //!< Gets has Collided
};




#endif