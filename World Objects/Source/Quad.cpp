/*!*********************************************(C)**
+ Will Canada : DecipherOne Productions      2007  +
|--------------------------------------------------|
| This class is derived from Triangle (base object |
| class) and is an somewhat abstract class for     |
| creating and drawind specific shapes, which      |
| will be derived from this class.                 |
|   Additional classes such as models and such     |
| will also be derived from this line of           |
| inheritance.                                     |
|__________________________________________________|
+--------------------------------------------------+*/

#include "PCHEADER.h"



Quad::Quad(std::string arg) : Triangle(arg)
{
}

Quad::Quad() : Triangle()
{
}

Quad::~Quad()
{
	
}

bool Quad::Draw()
{
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();								// Store The Modelview Matrix
	
	//Determine the Screen Location for drawing to take place
	

	//if we've mad translation alterations update em.
	glTranslatef(xTranslate,yTranslate,zTranslate); 
	
	//same goes for rotation.
	glRotatef(RotateAngle,xRotate,yRotate,zRotate);

	
	

	
	
	if(GetHasTexture())
	{
		glEnable(GL_TEXTURE_2D);
		
		glBindTexture(GL_TEXTURE_2D, Texture.texture[0]);		// Select Our Texture

		if(GetTransparency()&&!GetGlow())
		{
          glEnable(GL_BLEND);
		  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		}
		else if(GetGlow()&&!GetTransparency())
		{
			glDepthMask(false); //Disable the depth buffer.
			glEnable (GL_BLEND);  
			glBlendFunc (GL_SRC_ALPHA,GL_ONE);
		}

	}
	//Begin Drawing the QUAD
	glBegin(GL_QUADS);						// Drawing Using Triangles
	
	if(GetHasTexture())
	{
		if(Texture.GetImageType() == 1) //If Texture's a PNG Image Reverse Tex Coords as to not be reversed
		{
			glTexCoord2f(TexCoords[3][0], TexCoords[3][1]);
		}
		
		else
		{
			glTexCoord2f(TexCoords[0][0], TexCoords[0][1]);
		}
	}

	glVertex3f( Vertices[0][0], Vertices[0][1], Vertices[0][2]);// Top Left
	
	if(GetHasTexture())
	{
		if(Texture.GetImageType() == 1) //If Texture's a PNG Image Reverse Tex Coords as to not be reversed
		{
			glTexCoord2f(TexCoords[2][0], TexCoords[2][1]);
		}
		
		else
		{
			glTexCoord2f(TexCoords[1][0], TexCoords[1][1]);
		}
	}
		
	glVertex3f( Vertices[1][0], Vertices[1][1], Vertices[1][2]);// Top Right
	
	if(GetHasTexture())
	{
		if(Texture.GetImageType() == 1) //If Texture's a PNG Image Reverse Tex Coords as to not be reversed
		{
			glTexCoord2f(TexCoords[1][0], TexCoords[1][1]);
		}
		
		else
		{
			glTexCoord2f(TexCoords[2][0], TexCoords[2][1]);
		}
	}

	glVertex3f( Vertices[2][0], Vertices[2][1], Vertices[2][2]);// Bottom Right

	if(GetHasTexture())
	{
		if(Texture.GetImageType() == 1) //If Texture's a PNG Image Reverse Tex Coords as to not be reversed
		{
			glTexCoord2f(TexCoords[0][0], TexCoords[0][1]);
		}
		
		else
		{
			glTexCoord2f(TexCoords[3][0], TexCoords[3][1]);
		}
	}

	glVertex3f( Vertices[3][0], Vertices[3][1], Vertices[3][2]);// Bottom Right


	glEnd();	
					// Finished Drawing The Quad

	if(GetHasTexture())
	{
	
		glDisable(GL_TEXTURE_2D);

		if(GetTransparency())
		{
          glDisable(GL_BLEND);
		}
		else if(GetGlow())
		{
		  glDisable(GL_BLEND);
		  glDepthMask(true); //Enable the depth buffer.
		}
	}

	
	glPopMatrix();


	return true;
}


bool Quad::SetVerticesScales(float V1x,float V1y, 
								 float V2x, float V3y,float Z)
{
	Vertices[0][0] = V1x; //First Location for drawing first point
	Vertices[0][1] = V1y; //Second Location for drawing first point
	Vertices[0][2] = Z; //Third Location for drawing first point

	Vertices[1][0] = V2x; //First Location for drawing second point
	Vertices[1][1] = V1y; //Second Location for drawing second point
	Vertices[1][2] = Z; //Third Location for drawing second point

	Vertices[2][0] = V2x; //First Location for drawing third point
	Vertices[2][1] = V3y; //Second Location for drawing third point
	Vertices[2][2] = Z; //Third Location for drawing third point

	Vertices[3][0] = V1x; //First Location for drawing fourth point
	Vertices[3][1] = V3y; //Second Location for drawing fourth point
	Vertices[3][2] = Z; //Third Location for drawing fourth point

	return true;
}


bool Quad::SetTexCoords(float T1x,float T1y,
		float T2x, float T3y) //Gives measurements for Texturing triangle
{
	if(GetHasTexture())
	{
		TexCoords[0][0] = T1x; //First Location for drawing first point
		TexCoords[0][1] = T1y; //Second Location for drawing first point
		

		TexCoords[1][0] = T2x; //First Location for drawing second point
		TexCoords[1][1] = T1y; //Second Location for drawing second point
		

		TexCoords[2][0] = T2x; //First Location for drawing third point
		TexCoords[2][1] = T3y; //Second Location for drawing third point

		TexCoords[3][0] = T1x; //First Location for drawing fourth point
		TexCoords[3][1] = T3y; //Second Location for drawing fourth point
		

		return true;
	}

	
		return false;
}

bool Quad::OnScale(float x, float y, float z, Quad &Object)
{
	
	glPushMatrix();

	glScalef(x,y,z);

	Object.Draw();

	glPopMatrix();
	
	

	return true;
}


bool Quad::Draw2D(bool front=true)
{
	

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
    glPushMatrix();                                    //Save the current Projection Matrix

	

	glLoadIdentity();		// Reset The Projection Matrix
	glOrtho(0,TrogWin.GetWidth(),0,TrogWin.GetHeight(),-1,1); //Set orthographic projection based on the applications window size

	glMatrixMode(GL_MODELVIEW);						// Select The Modelview Matrix
	glPushMatrix();								// Store The Modelview Matrix
	
	//Determine the Screen Location for drawing to take place
	
	if(front)
	{
		glTranslatef(xTranslate,yTranslate,1); 
	}
	else
	{
		glTranslatef(xTranslate,yTranslate,-1); 
	}
	glRotatef(RotateAngle,xRotate,yRotate,zRotate);

	
	if(GetHasTexture())
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, Texture.texture[0]);		// Select Our Texture
	}

	//Begin Drawing the QUAD
	glBegin(GL_QUADS);					
	
	if(GetHasTexture())
	{
		if(Texture.GetImageType() == 1) //If Texture's a PNG Image Reverse Tex Coords as to not be reversed
		{
			glTexCoord2f(TexCoords[3][0], TexCoords[3][1]);
		}
		
		else
		{
			glTexCoord2f(TexCoords[0][0], TexCoords[0][1]);
		}
	}

	glVertex2f( Vertices[0][0], Vertices[0][1]);// Top Left
	
	if(GetHasTexture())
	{
		if(Texture.GetImageType() == 1) //If Texture's a PNG Image Reverse Tex Coords as to not be reversed
		{
			glTexCoord2f(TexCoords[2][0], TexCoords[2][1]);
		}
		
		else
		{
			glTexCoord2f(TexCoords[1][0], TexCoords[1][1]);
		}
	}
		
	glVertex2f( Vertices[1][0], Vertices[1][1]);// Top Right
	
	if(GetHasTexture())
	{
		if(Texture.GetImageType() == 1) //If Texture's a PNG Image Reverse Tex Coords as to not be reversed
		{
			glTexCoord2f(TexCoords[1][0], TexCoords[1][1]);
		}
		
		else
		{
			glTexCoord2f(TexCoords[2][0], TexCoords[2][1]);
		}
	}

	glVertex2f( Vertices[2][0], Vertices[2][1]);// Bottom Right

	if(GetHasTexture())
	{
		if(Texture.GetImageType() == 1) //If Texture's a PNG Image Reverse Tex Coords as to not be reversed
		{
			glTexCoord2f(TexCoords[0][0], TexCoords[0][1]);
		}
		
		else
		{
			glTexCoord2f(TexCoords[3][0], TexCoords[3][1]);
		}
	}

	glVertex2f( Vertices[3][0], Vertices[3][1]);// Bottom Right


	glEnd();	
					// Finished Drawing The Quad
	
	if(GetHasTexture())
	{
	  glDisable(GL_TEXTURE_2D);
	}

	
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPopMatrix();	

	glMatrixMode(GL_MODELVIEW);						// Select The Modelview Matrix
	glPopMatrix();

		
	return true;
}



