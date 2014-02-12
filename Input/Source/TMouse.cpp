//Source file for the Engines  Mouse Input
/*!*********************************************(C)*
+ Will Canada : DeciipherOne Productions      2007 +
|--------------------------------------------------|
| This class provides default functionality for    |
| handling mouse events for the Troglodyte game    |
| engine.                                          |
|__________________________________________________|
+--------------------------------------------------+ */

#include"PCHEADER.H"


TMouse::TMouse()
{
	MouseTime = &MainState;
	MouseCursor.cbSize = sizeof(CURSORINFO);
}

/////////////////////////////////////////////////////////////////////////////////////

TMouse::~TMouse()
{
}

/////////////////////////////////////////////////////////////////////////////////////

bool TMouse::UpdateMouse()
{
	//Put Defualt Mouse handling routines in here sucka
	

	GetCursorInfo(&MouseCursor);
	GetCursorPos(&MousePoint);
	ScreenToClient(TrogWin.hWnd,&MousePoint);

	

	return true;
}

/////////////////////////////////////////////////////////////////////////////////////

int TMouse::ResetKeyStates()
{
	int x = 0;

	do
	{
		MouseKeys[x]=0; //assign the zero value for number of repeats
		PrePress [x]=0;
		x += 1;    //Increment X until it reaches 9 to reset all keys

	}
	while(x<10);

	return 0;
	
}

/////////////////////////////////////////////////////////////////////////////////////

bool TMouse::GetWorldCoord()
{

	//Store Previous Mouse Coordinates - Used with OnMoveObject();
	
	PreviousMouseCoords[0] = MousePoint.x;
	PreviousMouseCoords[1] = MousePoint.y;
	

	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
	glGetDoublev( GL_PROJECTION_MATRIX, projection );
	glGetIntegerv( GL_VIEWPORT, viewport );

	winX = (float)MousePoint.x;
	winY = (float)viewport[3] - (float)MousePoint.y;
	glReadPixels( MousePoint.x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

	gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	WorldCoords[0] = posX;
	WorldCoords[1] = posY;
	WorldCoords[2] = posZ;

	return true;
}

/////////////////////////////////////////////////////////////////////////////////////

bool TMouse::EnterSelectionMode()
{
	NameHit = 0;
	GLint viewport[4];

	

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();

	glLoadIdentity();
	glSelectBuffer(512,Selection_Buffer);
	glRenderMode(GL_SELECT);

	glGetIntegerv(GL_VIEWPORT,viewport);
	gluPickMatrix(MousePoint.x,viewport[3]-MousePoint.y,
			2,2,viewport);

	gluPerspective(45.0f,(GLfloat)TrogWin.GetWidth()/(GLfloat)TrogWin.GetHeight(),0.1f,100.0f);
	
	
	

	glMatrixMode(GL_MODELVIEW);
	glInitNames();

	return true;
}


/////////////////////////////////////////////////////////////////////////////////////

bool TMouse::ExitSelectionMode()
{

	
	// restoring the original projection matrix
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	
	glMatrixMode(GL_MODELVIEW);
	glFlush();
	
	// returning to normal rendering mode
	hits = glRenderMode(GL_RENDER);

	if(hits !=0)
	{
		TestHitBuffer(hits,Selection_Buffer);
	}

	GetWorldCoord();

	return true;
}


/////////////////////////////////////////////////////////////////////////////////////
 bool TMouse::TestHitBuffer(GLint hits, GLuint buffer[])
{
	GLint i, numberOfNames;
   GLuint names, *ptr, minZ,*ptrNames;

   names = 0;
   ptrNames = 0;
   ptr = 0;
   minZ = 0;

   ptr = (GLuint *) buffer;
   minZ = 0xffffffff;
   for (i = 0; i < hits; i++) 
   {	
      names = *ptr;
	  ptr++;

	  if (*ptr < minZ) 
	  {
		  numberOfNames = names;
		  minZ = *ptr;
		  ptrNames = ptr+2;
	  }
   }
	  
	  ptr += names+2;

	  NameHit = *ptrNames;

	  if(NameHit > 0)
	  {
		  return true;
	  }

	  return false;
	
}


 /////////////////////////////////////////////////////////////////////////////////////

 bool TMouse::OnMoveObject(Sprite &Arg)
 {


	 float x,y; //Used to store local values for Updating Translation of the Object
	 x=0;
	 y=0;



	 //Do Updating for X Coordinate


	 //Positive X Movement
	 if(MousePoint.x != PreviousMouseCoords[0])
	 {
		 //Get the translation Value of X
		 x = (MousePoint.x - PreviousMouseCoords[0]) * FM.Pixel_2WorldSpace(1);

		 //Update the Objects Translation
		 Arg.OnSetTranslation(Arg.GetxTranslation() + x, Arg.GetyTranslation(),
			 Arg.GetzTranslation());
	 }

	  


	  //Positive Y Movement
	 if(MousePoint.y != PreviousMouseCoords[1])
	 {
		 //Get the translation Value of y
		y = (MousePoint.y - PreviousMouseCoords[1]) * FM.Pixel_2WorldSpace(1);

		 //Update the Objects Translation
		 Arg.OnSetTranslation(Arg.GetxTranslation() , Arg.GetyTranslation() - y,
		 Arg.GetzTranslation());
	  }

	 return true;
 }

 //////////////////////////////////////////////////////////////////////////////////////////


 bool TMouse::CheckStateLBUTTON()
 {

	static int hold;


	 if(MouseKeys[0])
	 {
		 if(PrePress[0])
		 {
			hold+=1;
			return true;
		 }
		 else
		 {
			hold = 0;
				
		 }
		

		 PrePress[0]=true;
		 
	 }




	 return false;

}

 ////////////////////////////////////////////////////////////////////////////////////////

 bool TMouse::CheckStateRBUTTON()
 {

	static int hold;

	
	if(MouseKeys[1])
	 {
		 if(PrePress[1])
		 {
			hold+=1;
			return true;
		 }
		 else
		 {
			hold = 0;
				
		 }
		

		 PrePress[1]=true;
		 
	 }




	 return false;
 }

 ////////////////////////////////////////////////////////////////////////////////////////

 bool TMouse::CheckStateMBUTTON()
 {

	static int hold;


	if(MouseKeys[2])
	 {
		 if(PrePress[2])
		 {
			hold+=1;
			return true;
		 }
		 else
		 {
			hold = 0;
				
		 }
		

		 PrePress[2]=true;
		 
	 }




	 return false;
 }