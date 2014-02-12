/*!***********************************************
* This is the base Object class for the Troglodyte *
* Game Engine (c)DecipherOne Productions 2005   *
* Author: Will (DecipherOne) Canada             *
* modified January 28: 2007                     *
************************************************/

#ifndef _TObject_
#define _TObject_



class TObject //!<Object Base Class
{


protected:
	
	std::string Name; //!<The Objects Name as a string
	const char * Label; //!<Objects Label -(Name)
	float xRotate,yRotate,zRotate,RotateAngle; //!< Objects World rotation
	float xTranslate,yTranslate,zTranslate;//!<Objects World Translation
	float mUnitSize; //!<Measurement Unit used for Movement
	float rUnitSize;  //!<Measurement Unit used for Rotation
	bool  MouseIsSelected; //!< Used to signal the object has current mouse focus
	int   SpawnCount;      //!< Used to keep track of number of given Objects Created

	bool isCollide_able;    //!< Tells whether an object can be collided with for collision detection.
	float NewTime,OldTime;    //!< Used for determining whether to process an Objects logic
	float C_NewTime, C_OldTime; //!< Used for keeping time for the control timer functions.
	bool updatelogic;        //!< Relays a message to the calling function whether logic info should be updated.
	bool update_c_logic;     //!< Relays a message to the calling function whether logic info should be updated.

public:
	float OnMoveUP(); //!<Used to relay moving information
	float OnMoveDOWN(); //!<Used to relay moving information
	float OnMoveLEFT(); //!<Used to relay moving information
	float OnMoveRIGHT(); //!<Used to relay Moving info
	float OnMoveIN(); //!<Used to relay moving information
	float OnMoveOUT(); //!<Used to relay moving information
	
	float OnRotatePosX(); //!<Used to rotate on Positive X
	float OnRotateNegX(); //!<Used to rotate on Negative X
	float OnRotatePosY(); //!<Used to rotate on Positive Y
	float OnRotateNegY(); //!<Used to rotate on Negative Y
	float OnRotatePosZ(); //!<Used to rotate on Positive Z
	float OnRotateNegZ(); //!<Used to rotate on Negative Z



	bool CheckLogicTimer(float arg);       //!< Checks to see if enough time has passed in order for a Sprites Logic to be processed, arg is a float argument representing seconds. It returns a value stored in the argument updatelogic.
	bool CheckControlTimer(float arg);       //!< Checks to see if enough time has passed in order for an update to occur, limits the time frame to the specific argument for one call. Good for limiting button presses.
	std::string GetName(); //!<Used for reading the Objects name
	void SetName(std::string arg); //!<Used for writing the objects name
	bool ConString4Screen(std::string arg); //!<Used to convert string to const char * for use with PrfloatOnScreen()
	
	void SetrUnitSize(float arg); //!<Sets Rotation Movement size
	float GetrUnitSize(); //!<Returns rUnitSize
	void SetmUnitSize(float arg); //!<Sets Translation Movement size
	float GetmUnitSize(); //!<Returns mUnitSize
	

	bool OnSetTranslation(float x, float y, float z); 
	bool onSetRotation(float x, float y, float z);

	const char * GetLabel();


	float GetxRotate();
	float GetyRotate();
	float GetzRotate();

	float GetxTranslation();
	float GetyTranslation();
	float GetzTranslation();

	bool IsInitialized; //!<Used to trigger initilization code blocks for objects
	bool Destroy;      //!<Used to trigger destruction code blocks for objects

	bool GetIsSelected(); //!< Returns the MouseIsSelected value for mouse input
	void SetIsSelected(bool arg); //!< Sets the MouseIsSelected variable for mouse input

	int GetSpawnCount();   //!< Returns the Integer SpawnCount (Used for accessing pointer arrays of Objects)
	void SetSpawnCount(int);  //!< Sets the Integer SpawnCount (Used for accessing pointer arrays of Objects) 

	void SetIsCollide(bool arg); //!< Sets the protected member isCollide_able used for collision detection
	bool GetIsCollide();         //!< Returns the value stored in isCollide_able used for collision dectection
	TObject();
	~TObject();

};


#endif