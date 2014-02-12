/*!*******************************************
* This is the header for the camera class    *
* for the Troglodyte game Engine             *
* Author : Will Canada (DecipherOne)         *
* (c)2006-2011 DecipherOne Productions       *
********************************************/
#ifndef _CAMERA_
#define _CAMERA_


class Camera : public TObject //!<Camera Class Derived from TObject
{

private:
	bool y_IsInit; //!< used for camera updates for followObject_y
	bool x_IsInit; //!< used for camera updates for followObject_x
	bool IsInit_2d; //!< used for camera updates for followObject_2d

	bool y_at_Trans; //!< used for camera updates for followObject_y
	bool x_at_Trans; //!< used for camera updates for followObject_x
	bool at_Trans_2d; //!< used for camera updates for followObject_2d


public:
	int OnLookLeft(); //!<used to make the camera look left
	int OnLookRight(); //!<used to make the camera look right
	int OnLookUp(); //!<used to make the camera look up
	int OnLookDown(); //!<used to make the camera look down
	int OnZoomIn(); //!<used to make the camera zoom in
	int OnZoomOut(); //!<used to make the camera zoom out

	int OnStrafePosY(); //!<used to move the camera and eye of the camera at the same time
	int OnStrafeNegY(); //!<used to move the camera and eye of the camera at the same time
	int OnStrafeNegX(); //!<used to move the camera and eye of the camera at the same time
	int OnStrafePosX(); //!<used to move the camera and eye of the camera at the same time
	int OnStrafeNegZ(); //!<used to move the camera and eye of the camera at the same time
	int OnStrafePosZ(); //!<used to move the camera and eye of the camera the same time
	Camera(const char * Name,float xv,float yv,float zv,
		float xt,float yt,float zt, float VuS, float MuS);//!<Constructor places and points camera according to specified units 
	void Init(const char * Name,float xv,float yv,float zv,
		float xt,float yt,float zt, float VuS, float MuS);//!<Init takes place of constructor when construct can't be used. Places and points camera according to specified units
	~Camera();
	Camera();

	bool Get_y_at_Trans(); //!< returns value of y_at_Trans
	bool Get_x_at_Trans(); //!< returns value of y_at_Trans
	bool Get_at_Trans_2d(); //!< returns value of y_at_Trans

	void UpdatePosition(TObject *Object); //!< Goes through and makes a call to update all possilbe camera translations, should be called outside of any logic checks.(Finishes moving the camera from a previous call.)
	
	float xViewTrans; //!<used to determine direction camera is aiming
	float yViewTrans; //!<used to determine direction camera is aiming
	float zViewTrans; //!<used to determine direction camera is aiming
	float ViewmUnitSize; //!<Used for the eye port movement for the camera(speed of movement)
	void FollowObject(TObject *Object); //!< Sets the transform for the camera to follow a specified object on every axis(Zooms in on the Object). Takes a reference to said object. Must be updated in a scene loop.
	void FollowObject_x(TObject *Object); //!< Sets the transform for the camera to follow a specified object on the x axis. Takes a reference to said object. Must be updated in a scene loop.
    void FollowObject_y(TObject *Object); //!< Sets the transform for the camera to follow a specified object on the y axis. Takes a reference to said object. Must be updated in a scene loop.
	void FollowObject_2D(TObject *Object); //!< Sets the transform for the camera to follow a specified object on x and y axises, sets the object as the center object on the screen. Takes a reference to said object. Must be updated in a scene loop.
	void SideScroll_Follow(TObject *Object,float left, float right); //!< This is an adaptable follow camera. Takes three arguments the object to follow and when to shift the camera in the specific direction. To change follow speed change mUnitSize of the Camera Object. Makes use of the IsInitialized variable inherited from TObject(so if this function is in use that variable can't be used else where.)

};

#endif

