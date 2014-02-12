/*!*********************************************(C)*
+ Will Canada : DecipherOne Productions      2007  +
|--------------------------------------------------|
| This class is derived from Shape  (base object   |
| class) and is an somewhat abstract class for     |
| creating and drawind specific shapes, which      |
| will be derived from this class.                 |
|   Additional classes such as models and such     |
| will also be derived from this line of           |
| inheritance.                                     |
|__________________________________________________|
+--------------------------------------------------+*/

#include "PCHEADER.h"


bool Triangle::Draw()
{
	
	glMatrixMode(GL_MODELVIEW);	
	glPushMatrix();								// Store The Modelview Matrix
	
	//Determine the Screen Location for drawing to take place
	

	
	glTranslatef(xTranslate,yTranslate,zTranslate); 
	
	
	glRotatef(RotateAngle,xRotate,yRotate,zRotate);

	
	

	
	
	if(GetHasTexture())
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, Texture.texture[0]);		// Select Our Texture


		if(transparency&&!glow)
		{
          glEnable(GL_BLEND);
		  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		}

		else if(glow&&!transparency)
		{
			glDepthMask(false); //Disable the depth buffer.
			glEnable (GL_BLEND);  
			glBlendFunc (GL_SRC_ALPHA,GL_ONE);
		}


	}
	//Begin Drawing the Triangle
	glBegin(GL_TRIANGLES);						// Drawing Using Triangles
	
	if(GetHasTexture())
	{
		if(Texture.GetImageType() == 1)
		{
			glTexCoord2f(TexCoords[2][0],TexCoords[2][1]);
		}
		else
		{
			glTexCoord2f(TexCoords[0][0], TexCoords[0][1]);
		}
	}

	glVertex3f( Vertices[0][0], Vertices[0][1], Vertices[0][2]);// Top
	
	if(GetHasTexture())
	{
		
		glTexCoord2f(TexCoords[1][0], TexCoords[1][1]);
	}
		
	glVertex3f( Vertices[1][0], Vertices[1][1], Vertices[1][2]);// Bottom Left
	
	if(GetHasTexture())
	{

		if(Texture.GetImageType() == 1)
		{
			glTexCoord2f(TexCoords[0][0], TexCoords[0][1]);
		}

		else
		{
			glTexCoord2f(TexCoords[2][0], TexCoords[2][1]);
		}
	}

	glVertex3f( Vertices[2][0], Vertices[2][1], Vertices[2][2]);// Bottom Right

	glEnd();	
					// Finished Drawing The Triangle
	if(GetHasTexture())
	{
	
	  glDisable(GL_TEXTURE_2D);

	  if(transparency)
	  {
         glDisable(GL_BLEND);
	  }
	  else if(glow)
	  {
		  glDisable(GL_BLEND);
		  glDepthMask(true); //Enable the depth buffer.
		
	  }
	}

	
	glPopMatrix();


	return true;
}

bool Triangle::SetVerticesScales(float V1x,float V1y, 
								 float V2x, float V2y, float V3x, float V3y, 
								 float Z)
{
	Vertices[0][0] = V1x; //First Location for drawing first point
	Vertices[0][1] = V1y; //Second Location for drawing first point
	Vertices[0][2] = Z; //Third Location for drawing first point

	Vertices[1][0] = V2x; //First Location for drawing second point
	Vertices[1][1] = V2y; //Second Location for drawing second point
	Vertices[1][2] = Z; //Third Location for drawing second point

	Vertices[2][0] = V3x; //First Location for drawing third point
	Vertices[2][1] = V3y; //Second Location for drawing third point
	Vertices[2][2] = Z; //Third Location for drawing third point

	return true;
}

Triangle::Triangle():Shape()
{
	Destroy=false;
	transparency = true;
	glow=false;
	
}


Triangle::Triangle(std::string Narg) : Shape(Narg) 
{
	Destroy=false;
	transparency = true;
	glow=false;
	
	
}

Triangle::~Triangle()
{
	
}




bool Triangle::SetTexCoords(float T1x,float T1y,
		float T2x, float T2y, float T3x, float T3y ) //Gives measurements for Texturing triangle
{
	if(GetHasTexture())
	{
		TexCoords[0][0] = T1x; //First Location for drawing first point
		TexCoords[0][1] = T1y; //Second Location for drawing first point
		

		TexCoords[1][0] = T2x; //First Location for drawing second point
		TexCoords[1][1] = T2y; //Second Location for drawing second point
		

		TexCoords[2][0] = T3x; //First Location for drawing third point
		TexCoords[2][1] = T3y; //Second Location for drawing third point
		

		return true;
	}

	
		return false;
}


bool Triangle::OnScale(float x, float y, float z, Triangle &Object)
{
	glMatrixMode(GL_MODELVIEW);	
	glPushMatrix();

	glScalef(x,y,z);

	Object.Draw();

	glPopMatrix();

	return true;
}

/////////////////////////////////////////////////////////////////////////////////////

void Triangle::SetTransparency(bool arg)
{
	transparency = arg;

	if(arg) //If we are setting transparency to true, then we can't do additive blending so make sure it's turned off.
	{
		if(glow)
		{
			glow=false;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////

bool Triangle::GetTransparency()
{
	return transparency;
}

/////////////////////////////////////////////////////////////////////////////////////

void Triangle::SetGlow(bool arg)
{
	glow = arg;
	if(arg)
	{
		if(transparency) //If we do additive blending we can't do transparency, make sure it's disabled.
		{
			transparency=false;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////

bool Triangle::GetGlow()
{
	return glow;
}
