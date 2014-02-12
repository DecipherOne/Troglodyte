#include "PCHEADER.H"




Camera::Camera()
{
}

int Camera::OnLookDown()
{
	yViewTrans -= ViewmUnitSize;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		xViewTrans,0 ,1,0);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////

int Camera::OnLookUp()
{
	
	yViewTrans += ViewmUnitSize;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		xViewTrans,0 ,1,0);
	
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
int Camera::OnLookLeft()
{
	
	xViewTrans -= ViewmUnitSize;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		xViewTrans,0 ,1,0);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////

int Camera::OnLookRight()
{
	
	xViewTrans += ViewmUnitSize;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		xViewTrans,0 ,1,0);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////

int Camera::OnZoomIn()
{
	
	zViewTrans -= ViewmUnitSize;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		xViewTrans,0 ,1,0);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////

int Camera::OnZoomOut()
{
	
	zViewTrans +=ViewmUnitSize;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		xViewTrans,0 ,1,0);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////

Camera::Camera(const char * Name, float xv, float yv, float zv,
			   float xt, float yt, float zt, float VuS, float MuS)

{
	
	Label = Name;
	ViewmUnitSize = VuS;
	mUnitSize = MuS;
	xTranslate = xt;
	yTranslate = yt;
	zTranslate = zt;
	xViewTrans = xv;
	yViewTrans = yv;
	zViewTrans = zv;

	y_IsInit=false; 
	x_IsInit=false; 
    IsInit_2d=false; 

	 y_at_Trans=true; 
	 x_at_Trans=true; 
	 at_Trans_2d=true;

	//Make our camera points where we initialized it.
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		xViewTrans,0 ,1,0);

}

////////////////////////////////////////////////////////////////////////////////////////

void Camera::Init(const char * Name, float xv, float yv, float zv,
			   float xt, float yt, float zt, float VuS, float MuS)

{
	
	Label = Name;
	ViewmUnitSize = VuS;
	mUnitSize = MuS;
	xTranslate = xt;
	yTranslate = yt;
	zTranslate = zt;
	xViewTrans = xv;
	yViewTrans = yv;
	zViewTrans = zv;

	y_IsInit=false; 
	x_IsInit=false; 
    IsInit_2d=false; 

	 y_at_Trans=true; 
	 x_at_Trans=true; 
	 at_Trans_2d=true;

	//Make our camera points where we initialized it.
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		xViewTrans,0 ,1,0);

}

////////////////////////////////////////////////////////////////////////////////////////

Camera::~Camera() 
{
}

////////////////////////////////////////////////////////////////////////////////////////
int Camera::OnStrafePosY()//float &MovY, float &ViewY)

{
	//Make both camera translation and 
	//camera view translation based upon the 
	//same unit so that strafing occurs
	//even if the view measurment and
	//translation measurement for the camera instance are different
	
	yTranslate += mUnitSize;
	yViewTrans += mUnitSize;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		xViewTrans,0 ,1,0);
	
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
int Camera::OnStrafeNegY()
{
	//Make both camera translation and 
	//camera view translation based upon the 
	//same unit so that strafing occurs
	//even if the view measurment and
	//translation measurement for the camera instance are different
	
	yTranslate -= mUnitSize;
	yViewTrans -= mUnitSize;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		xViewTrans,0 ,1,0);
	
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
int Camera::OnStrafePosX()
{
	//Make both camera translation and 
	//camera view translation based upon the 
	//same unit so that strafing occurs
	//even if the view measurment and
	//translation measurement for the camera instance are different

	
	xTranslate += mUnitSize;
	xViewTrans += mUnitSize;

		
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		xViewTrans,0 ,1,0);
	
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////

int Camera::OnStrafeNegX()
{
	//Make both camera translation and 
	//camera view translation based upon the 
	//same unit so that strafing occurs
	//even if the view measurment and
	//translation measurement for the camera instance are different

	
	xTranslate -= mUnitSize;
	xViewTrans -= mUnitSize;

		
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		xViewTrans,0 ,1,0);
	
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
int Camera::OnStrafeNegZ()
{
	
	zTranslate -= mUnitSize;
	zViewTrans -= mUnitSize;

		
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		xViewTrans,0 ,1,0);
	
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
int Camera::OnStrafePosZ()
{
	zTranslate += mUnitSize;
	zViewTrans += mUnitSize;

		
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		xViewTrans,0 ,1,0);
	
	
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////

void Camera::FollowObject(TObject *Object)
{
	
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(Object->GetxTranslation(),Object->GetyTranslation(),
		Object->GetzTranslation() + 2.25,Object->GetxTranslation(),Object->GetyTranslation(),
		Object->GetzTranslation() + 1.25,0 ,1,0);
	

}

////////////////////////////////////////////////////////////////////////////////////////

void Camera::FollowObject_2D(TObject *Object)
{
	
	FollowObject_x(Object);
	FollowObject_y(Object);


}

////////////////////////////////////////////////////////////////////////////////////////

void Camera::FollowObject_x(TObject *Object)
{
	
	
	static float CameraTarget;
	float dp;
	static vector2f n_v;

	//follow our object on the x axis
	if(Object->GetxTranslation() != xTranslate)
	{


			x_at_Trans=false;
			vector2f v1, v2;

			v1.x = xTranslate;
			v1.y = yTranslate;

			if(v1.x==0) //Prevent Divide by zero
			{
				v1.x=1;
				v1.y=1;
			}


			v1.normalize();

			v2.x= Object->GetxTranslation();
			v2.y= Object->GetyTranslation();

			dp = v1*v2;

			dp=FM.PreventZeroVector(dp);

			//assign our new coordinates that we will add each loop
			n_v.x = dp*v2.x;
			n_v.y = dp*v2.y;

			

			n_v.normalize(); //normalize our new vector

		 //Prevent zero vector
			n_v.x = FM.PreventZeroVector(n_v.x);
			n_v.y = FM.PreventZeroVector(n_v.y);
				
			x_IsInit = true;
			vector2f c(Object->GetxTranslation(),Object->GetyTranslation());
			CameraTarget = FM.PreventZeroVector(c.x);
				
	


			
	}

		 
			
		    
		//Modify the variables for the camera based upon the current 
		//translation of the object and the camera


	if(!x_at_Trans)
	{
				

		if(CameraTarget >= xTranslate)
		{	
				
			if(n_v.x < 0)
			{
				
				xTranslate -= n_v.x* mUnitSize;
				xViewTrans -= n_v.x* mUnitSize;
			}
				
			else
			{
				xTranslate += n_v.x* mUnitSize;
				xViewTrans += n_v.x* mUnitSize;
			}

			if(xTranslate >= CameraTarget) //Camera is at or past the target stop it
			{
				xTranslate=CameraTarget;
				xViewTrans=CameraTarget;
				x_IsInit = false;
				x_at_Trans = true;
			}
		 }

		else if(CameraTarget <= xTranslate)
		{	

			if(n_v.x < 0)
			{

				xTranslate += n_v.x*mUnitSize;
				xViewTrans += n_v.x*mUnitSize;
			}
			else
			{
				xTranslate -= n_v.x*mUnitSize;
				xViewTrans -= n_v.x*mUnitSize;

			}

			if(xTranslate <= CameraTarget) //Camera is at or past the target stop it
			{
				xTranslate=CameraTarget;
				xViewTrans=CameraTarget;
				x_IsInit = false;
				x_at_Trans = true;
			}
		}

		else
		{
			yTranslate=CameraTarget;
			yViewTrans=CameraTarget;
			x_IsInit = false;
			x_at_Trans = true;
		}
				
	}
		

	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		zViewTrans,0 ,1,0);
	

	

}

////////////////////////////////////////////////////////////////////////////////////////

void Camera::FollowObject_y(TObject *Object)
{
	
		static float CameraTarget;
		float dp;
		static vector2f n_v;
		float offset = FM.Pixel_2WorldSpace(TrogWin.GetHeight()/2); //Makes sure camera doesn't move until character is moving off current screen.

		//follow our object on the y axis
		if(Object->GetyTranslation() >yTranslate+offset||
			Object->GetyTranslation()<yTranslate-offset)
		{


			
				y_at_Trans=false;
				vector2f v1, v2;

				v1.x = xTranslate;
				v1.y = yTranslate;

				if(v1.x==0) //Prevent Divide by zero
				{
					v1.x=1;
					v1.y=1;
				}


				v1.normalize();

				v2.x= Object->GetxTranslation();
				v2.y= Object->GetyTranslation();

				dp = v1*v2;

				dp=FM.PreventZeroVector(dp);

				//assign our new coordinates that we will add each loop
				n_v.x = dp*v2.x;
				n_v.y = dp*v2.y;

			

				 n_v.normalize(); //normalize our new vector

				 //Prevent zero vector
				n_v.x = FM.PreventZeroVector(n_v.x);
				n_v.y = FM.PreventZeroVector(n_v.y);
				
				y_IsInit = true;
				vector2f c(Object->GetxTranslation(),Object->GetyTranslation());
				CameraTarget = FM.PreventZeroVector(c.y);
				CameraTarget += FM.Pixel_2WorldSpace(125);
				
			
			
		}

		 
			
		    
			//Modify the variables for the camera based upon the current 
			//translation of the object and the camera


		if(!y_at_Trans)
		{
				

			if(CameraTarget >= yTranslate)
			{	
				
				if(n_v.y < 0)
				{
				
					yTranslate -= n_v.y* mUnitSize;
					yViewTrans -= n_v.y* mUnitSize;
				}
				
				else
				{
					yTranslate += n_v.y* mUnitSize;
					yViewTrans += n_v.y* mUnitSize;
				}

				if(yTranslate >= CameraTarget) //Camera is at or past the target stop it
				{
					yTranslate=CameraTarget;
					yViewTrans=CameraTarget;
					y_IsInit = false;
					y_at_Trans = true;
				}
			 }

			else if(CameraTarget <= yTranslate)
			{	

				if(n_v.y < 0)
				{

					yTranslate += n_v.y*mUnitSize;
					yViewTrans += n_v.y*mUnitSize;
				}
				else
				{
					yTranslate -= n_v.y*mUnitSize;
					yViewTrans -= n_v.y*mUnitSize;

				}

				if(yTranslate <= CameraTarget) //Camera is at or past the target stop it
				{
					yTranslate=CameraTarget;
					yViewTrans=CameraTarget;
					y_IsInit = false;
					y_at_Trans = true;
				}
			}

			else
			{
				yTranslate=CameraTarget;
				yViewTrans=CameraTarget;
				y_IsInit = false;
				y_at_Trans = true;
			}
				
		}
	

	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		zViewTrans,0 ,1,0);


	

}

////////////////////////////////////////////////////////////////////////////////////////

void Camera::SideScroll_Follow(TObject *Object,float left=2.35,float right=1.75)
{
	

		static bool at_translation;
		static float CameraTarget;
		float dp;
		static vector2f n_v;

		//follow our object on the x axis
		if(Object->GetxTranslation()- right > xTranslate ||
			Object->GetxTranslation()+ left< xTranslate)
		{


			
				at_translation=false;
				vector2f v1, v2;

				v1.x = xTranslate;
				v1.y = yTranslate;

				if(v1.x==0) //Prevent Divide by zero
				{
					v1.x=1;
					v1.y=1;
				}


				v1.normalize();

				v2.x= Object->GetxTranslation();
				v2.y= Object->GetyTranslation();

				dp = v1*v2;

				dp=FM.PreventZeroVector(dp);

				//assign our new coordinates that we will add each loop
				n_v.x = dp*v2.x;
				n_v.y = dp*v2.y;
				n_v.normalize(); //normalize our new vector

				 //Prevent zero vector
				n_v.x = FM.PreventZeroVector(n_v.x);
				n_v.y = FM.PreventZeroVector(n_v.y);
				

				IsInitialized = true;
				vector2f c(Object->GetxTranslation(),Object->GetyTranslation());
				CameraTarget = FM.PreventZeroVector(c.x);
			
		}

		 
			
		    
			//Modify the variables for the camera based upon the current 
			//translation of the object and the camera


		if(!at_translation)
		{
				

			if(CameraTarget >= xTranslate)
			{	
				
				if(n_v.x < 0)
				{
				
					xTranslate -= n_v.x* mUnitSize;
					xViewTrans -= n_v.x* mUnitSize;
				}
				
				else
				{
					xTranslate += n_v.x* mUnitSize;
					xViewTrans += n_v.x* mUnitSize;
				}

				if(xTranslate >= CameraTarget) //Camera is at or past the target stop it
				{
					xTranslate=CameraTarget;
					xViewTrans=CameraTarget;
					IsInitialized = false;
					at_translation = true;
				}
			 }

			else if(CameraTarget <= xTranslate)
			{	

				if(n_v.x < 0)
				{

					xTranslate += n_v.x*mUnitSize;
					xViewTrans += n_v.x*mUnitSize;
				}
				else
				{
					xTranslate -= n_v.x*mUnitSize;
					xViewTrans -= n_v.x*mUnitSize;

				}

				if(xTranslate <= CameraTarget) //Camera is at or past the target stop it
				{
					xTranslate=CameraTarget;
					xViewTrans=CameraTarget;
					IsInitialized = false;
					at_translation = true;
				}
			}

			else
			{
				xTranslate=CameraTarget;
				xViewTrans=CameraTarget;
				IsInitialized = false;
				at_translation = true;
			}
				
		}


	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xTranslate,yTranslate,zTranslate,xViewTrans,yViewTrans,
		zViewTrans,0 ,1,0);


	

}

////////////////////////////////////////////////////////////////////////////////////////

bool Camera::Get_y_at_Trans()
{
	return y_at_Trans;
}

////////////////////////////////////////////////////////////////////////////////////////

bool Camera::Get_x_at_Trans()
{
	return x_at_Trans;
}

////////////////////////////////////////////////////////////////////////////////////////

bool Camera::Get_at_Trans_2d()
{
	return at_Trans_2d;
}

////////////////////////////////////////////////////////////////////////////////////////

void Camera::UpdatePosition(TObject *Object)
{
  if(!Get_y_at_Trans())
  {
	FollowObject_y(Object);
  }

  if(!Get_x_at_Trans())
  {
	FollowObject_x(Object);
  }

  if(!Get_at_Trans_2d())
  {
	FollowObject_2D(Object);
  }

}
