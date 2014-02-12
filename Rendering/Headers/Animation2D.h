/********************************************************************
* This is the Animation Header file for the Troglodyte Game Engine  *
*									                                *
* Author : Will Canada (DecipherOne) March 11, 2007                 *
* Copyright (C) DecipherOne Productions 2007                        *
*********************************************************************/




#ifndef _ANIMATION2D_H
#define _ANIMATION2D_H

struct AnimFrame2D  //!< This struct is the template for a single frame of animation to be mapped to a quad
{
	std::string FrameName;  //!< The internal string name of the Frame
	const char * FrameLabel; //!< The char representation of the Name of the Frame

	int SizeOfFrameName;     //!< The Size of the frame name (used for saving and loading to file)
	float x1;                //!< The first X Texture Coordinate for mapping a Quad
	float x2;                //!< The second X Texture Coordinate for mapping a Quad
	float x3;                //!< The third X Texture Coordinate for mapping a Quad
	float x4;                //!< The fourth X Texture Coordinate for mapping a Quad

	float y1;                //!< The first y Texture Coordinate for mapping a Quad
	float y2;                //!< The second y Texture Coordinate for mapping a Quad
	float y3;                //!< The third y Texture Coordinate for mapping a Quad
	float y4;                //!< The fourth y Texture Coordinate for mapping a Quad
};


/*!-------------------------------------------------------------------+
| This class allows an animation to be defined and controlled based   |
| on a single texture loaded into memory. Other classes ,such as the  |
| sprite class, should make instances of this class so that animations|
| are better encapsulated and organized.                              |
|                                                                     |
+---------------------------------------------------------------------*/

class Animation2D  //!< This Class contains the basic functionality for a complete animation
{

protected:
	std::string NameOfAnimation; //!< The internal string name of the Animation
	const char * Label;          //!< The char representation of the Name of the Animation
	int NumOfFrames;             //!< The number of Frames in the Animation
	UpdatesManager * AnimationFPS; //!< A pointer to the MainState UpdatesManager Object, Used for Calculating the speed for frame transitions
	int ActiveFrame;             //!< Used to set which frame is the one that should be displayed on the screen

	int SizeOfAnimationName;     //!< The size of the Animations Name used for Saving and Loading to file
	int FrameAccumBuf;            //!< Animation Accumulattion Buffer : Used for Seeing how many times a frame has been shown

	bool Loop;                    //!< Signals whether the animation should loop(default setting is to loop)
	TObject AnimationTimer;       //!< Used for timing Animations
	float FramesPerSec;              //!< The number of frames to show persecond.

public:

	AnimFrame2D AnimationFrames[64]; //!< The Actual Frames of the Animation up to 64 in one animation
	const char * GetLabel();             //!< Returns the Label for the Animation
	std::string GetName();       //!< Returns the Name of the Animation

	void SetName(std::string arg); //!< Sets the name of the Animation (arg) - called from the Constructor
	void ConvertName();            //!< Converts the animation name to Label using std::string.c_str() - called from Constructor
	void SetNumOfFrames(int arg);         //!< Sets the number of Frames the Animation has.
	void SetActiveFrame(int arg);         //!< Sets the active frame so that the texture coordinates for that frame are specified and the proper frame is shown on screen
    void SetLoop(bool arg);               //!< Sets the Loop variable
	int GetNumOfFrames();                 //!< Returns the value stored in NumOfFrames
	int GetActiveFrame();                 //!< Returns the value stored in ActiveFrame
	bool GetLoop();                       //!< Returns the value stored in Loop
	bool AdvanceFrame();                  //!< Depending on which frame is active, the animation frame is counted to see how many times it has been shown, if the frame has been shown enough times AnimAccumBuf >= AnimSpeed then the next frame of the animation is shown
	bool ReverseFrame();                  //!< Does the same as AdvanceFrame, but in reverse.
	
	bool SaveAnimData( fstream &stream);     //!< Writes the animation data to a specified  file stream , a reference to the file stream to save too (NOTE - ALL FILE OPENING AND CLOSING MUST BE DONE FROM THE CALLING FUNCTION)
	bool LoadAnimData( fstream &stream);     //!< Load the animation data from the specified file stream,a reference to the file stream to load from    (NOTE - ALL FILE OPENING AND CLOSING MUST BE DONE FROM THE CALLING FUNCTION)

    void SetFrameName(int num, std::string Name);      //!< Used to set the name (Name) of the specified frame (num) - Also sets the Frames Label automatically

	void SetFrameTexCoord(int FrameNum,float x1, float x2, float y1, float y3); //!< Used to set the texture coordinates for a specified frame. FrameNum, is which frame to access, x1 is the x1 coord (x3 is the same), x2 is the x2 coord(x4 is the same), y1 is the y1 coord (y2 is the same) y3 is the y3 coord(y4 is the same)
	Animation2D();
	Animation2D(int numFrames,int AnimSpeed,std::string AnimName);       //!< Constructor used to set the how many frames the animation has (Frames), how fast the frames should transition (AnimSpeed), and the name of the animation (Name)
	~Animation2D();                                 //!< Destructor releases all dynamic memory allocated by the class
	void SetFPS(float fps);                 //!< Sets FramesPerSec for animations
	float GetFPS();                         //!< Returns value stored in FramesPerSec



};

#endif