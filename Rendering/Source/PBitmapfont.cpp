/*!***************************************
* Source file for Opengl bitmap Font    *
* support for the Troglodtye game engine*
****************************************/

#include "PCHEADER.H"
#include <stdarg.h>		// Header File For Variable Argument Routines	( ADD )

extern TCreateWindow TrogWin;	// Link to the main window creation instance

void PFonts::BuildFont(int fheight,bool italic, bool underline,
					   bool strikeout,const char * fontname)
{
	HFONT	font;			// Windows Font ID
	HFONT	oldfont;		// Used For Good House Keeping

	base = glGenLists(96);	// Storage For 96 Characters 

	font = CreateFont(	fheight, // Height Of Font
						  0, // Width Of Font
						  0, // Angle Of Escapement
						  0, // Orientation Angle
				   FW_NORMAL, // Font Weight
					 italic, // Italic
				  underline, // Underline
				  strikeout, // Strikeout
			   ANSI_CHARSET, // Character Set IdenTgaier
			  OUT_TT_PRECIS, // Output Precision
	    CLIP_DEFAULT_PRECIS, // Clipping Precision
		ANTIALIASED_QUALITY, // Output Quality
  FF_DONTCARE|DEFAULT_PITCH, // Family And Pitch
  fontname);			 // Font Name

	oldfont = (HFONT)SelectObject(TrogWin.hDC, font);	// Selects The Font We Want
	wglUseFontBitmaps(TrogWin.hDC, 32, 96, base);		// Builds 96 Characters Starting At Character 32
	SelectObject(TrogWin.hDC, oldfont);					// Selects The Font We Want
	DeleteObject(font);							// Delete The Font

}

void PFonts::KillFont()
{
	glDeleteLists(base, 96);				// Delete All 96 Characters 
}

void PFonts::PrintF(const char *fmt, ...)				// Custom GL "Print" Routine
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();								// Store The Modelview Matrix
	glLoadIdentity();

	char		text[1024];				// Holds Our String 
	va_list		ap;					// Pointer To List Of Arguments
	if (fmt == NULL)					// If There's No Text
		return;						// Do Nothing

	va_start(ap, fmt);					// Parses The String For Variables
	vsprintf(text, fmt, ap);				// And Converts Symbols To Actual Numbers
	va_end(ap);					// Results Are Stored In Text


	glPushAttrib(GL_LIST_BIT);				// Pushes The Display List Bits		( NEW )
	glListBase(base - 32);					// Sets The Base Character to 32

	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);	// Draws The Display List Text	( NEW )
	glPopAttrib();						// Pops The Display List Bits	( NEW )

	glPopMatrix();

}

PFonts::PFonts()
{
}

PFonts::~PFonts()
{
	KillFont();
}


void PFonts::PrintOnScreen(float x, float y, float z ,int Screenwidth, int Screenheight, 
						   const char *Text,double argument)
{
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPushMatrix();

	glLoadIdentity();							// Reset The Projection Matrix
	glOrtho(0,Screenwidth,0,Screenheight,-1,1); //Set orthographic projection based on the applications
	                                            // width and height

	if(z<-1)
	{
		z=-1;
	}

	if(z>1)
	{
		z=1;
	}

	glMatrixMode(GL_MODELVIEW);						// Select The Modelview Matrix
	glPushMatrix();								// Store The Modelview Matrix
	glLoadIdentity();

	glTranslatef(x,y,z);                   //Move to specified location on screen

	glRasterPos2f(0.0,0.0f);
	PrintF(Text,argument);

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPopMatrix();		

	glMatrixMode(GL_MODELVIEW);						// Select The Modelview Matrix
	glPopMatrix();

}

void PFonts::PrintOnScreen(float x, float y, float z, int Screenwidth, int Screenheight, 
						   const char *Text,const char *argument)
{
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPushMatrix();

	glLoadIdentity();							// Reset The Projection Matrix
	glOrtho(0,Screenwidth,0,Screenheight,-1,1); //Set orthographic projection based on the applications
	                                            // width and height

	if(z<-1)
	{
		z=-1;
	}

	if(z>1)
	{
		z=1;
	}

	glMatrixMode(GL_MODELVIEW);						// Select The Modelview Matrix
	glPushMatrix();								// Store The Modelview Matrix
	glLoadIdentity();

	glTranslatef(x,y,z);                   //Move to specified location on screen

	
	glRasterPos2f(0.0,0.0f);
	PrintF(Text,argument);

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPopMatrix();		

	glMatrixMode(GL_MODELVIEW);						// Select The Modelview Matrix
	glPopMatrix();

}


void PFonts::PrintOnScreen(float x, float y, float z, int Screenwidth, int Screenheight, 
						   const char *Text,int argument)
{
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPushMatrix();

	glLoadIdentity();							// Reset The Projection Matrix
	glOrtho(0,Screenwidth,0,Screenheight,-1,1); //Set orthographic projection based on the applications
	                                            // width and height

	if(z<-1)
	{
		z=-1;
	}

	if(z>1)
	{
		z=1;
	}

	glMatrixMode(GL_MODELVIEW);						// Select The Modelview Matrix
	glPushMatrix();								// Store The Modelview Matrix
	glLoadIdentity();

	glTranslatef(x,y,z);                   //Move to specified location on screen

	
	glRasterPos2f(0.0,0.0f);
	PrintF(Text,argument);

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPopMatrix();		

	glMatrixMode(GL_MODELVIEW);						// Select The Modelview Matrix
	glPopMatrix();

}
//////////////////////////////////////////////////////////////////////


void PFonts::PrintFile2Screen(float x, float y, float z, const char * filename,
								   int width, int hieght, int textSpacing)
{
	float y2 =0;  //variables to base height data for paragraph.
	
	
	y2 = y;

	const char * Buffer;
	std::string tempBuffer;

	if(z<-1)
	{
		z=-1;
	}

	if(z>1)
	{
		z=1;
	}

	std::ifstream stream;
	stream.open(filename);

	if(stream.is_open())
	{
		while(! stream.eof())
		{
			if(y2>=0)
			{
				getline(stream,tempBuffer);  //read line from file into tempBuffer
				Buffer = tempBuffer.c_str(); //convert string in tempbuffer to char * to store in Buffer

				
					PrintOnScreen(x,y2,z,width,hieght,Buffer,NULL); //print the text to the screen
				

				y2  = y2 - textSpacing; //move text spacing for next line
			}

			else
			{
				break;
			}
		}

		
	}

	else
	{
		MessageBox(NULL,"Could not open file to print on the screen", " File Reading Error", MB_OK);
	}

	if(stream.is_open())
	{
	
		stream.close();
	}
}







   





   
