
struct ListenerPos //!<The position of the listener 
{
	float x,y,z;
};

struct ListenerVelocity //!<Velocity of the Listener
{
	float x,y,z;
};

struct ListenerOrientation //!<The direction in which the listener is positioned. 
{
	float x,y,z;      //!<at vectors
	float ux,uy,uz;   //!<up vectors
	
};

class TAudio        //!< Class for managing the OpenAL Audio Context and Listener Object
{
	ListenerPos lp;   //!< Instance of struct ListenerPos - Used for Setting and Getting the listener's Position
	ListenerVelocity lv; //!< Instance of struct ListenerVelocity - Used for Setting and Getting the listener's Velocity
	ListenerOrientation lo; //!< Instance of struct ListenerOrientation - Used for Setting and Getting the listener's Orientation


public:

	ALCdevice* pDevice;  //!< Pointer to the Hardware Device Initialized by the sound.
    ALCcontext* pContext; //!< Pointer to the sound context
	const char * deviceSpecifier; //!< Pointer to the Name of the device being used

	void ExitOpenAL();   //!< Function used to close out OpenAL (RELEASES MEMORY) MUST BE CALLED AT THE END OF APPLICATION
	ALboolean InitOpenAL(); //!< Function used to Initialize OpenAL (MUST BE CALLED AT THE START OF THE APPLICATION)
	void UpdateListenerValues(); //!< Updates the Listener Objects Values Should be called in the main game loop

	bool suspendAudio; //!< Tells whether the Audio context should be suspended.(Used for stoping Audio playback when app is minimized).

	ALfloat ListenerOri[6];//!< Orientation of the listener. (first 3 elements are "at", second 3 are "up"

	float GetListenerPosX(); 
	float GetListenerPosY(); 
	float GetListenerPosZ(); 
	void SetListenerPos(float x,float y,float z); //!< Used to Set a generic Position for the Listener
	void SetListenerPos(TObject &Object); //!< Used to Link the Position of the Listener with an Object (Most Likely a camera)
	float GetListenerVelX();
	float GetListenerVelY();
	float GetListenerVelZ();
	void SetListenerVel(float x,float y,float z);//!< Used to set a generic velocity for the listener
	
	float GetListenerOrienX();
	float GetListenerOrienY();
	float GetListenerOrienZ();
	float GetListenerOrienUX();
	float GetListenerOrienUY();
	float GetListenerOrienUZ();
	ALfloat GetListenerOri();
	void SetListenerOrien(float x, float y, float z,
		float ux, float uy, float uz);          //!<Used to set a generic orientation for the listener

	//!<WRITE THIS AFTER CAMERA CLASS IS COMPLETE TO PASS A CAMERA OBJECT BY REFERENCE
	//!<void SetListenerOrien(Object &x, Object &y, Object &z,
	//!<Object &ux, Object &uy, Object &uz);    //Used to link the orientation of the listener with a specific object (Most Likely a camera)
};