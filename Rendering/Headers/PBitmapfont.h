/*!*****************************************
* This file is for a bitmap font class for*
* the Troglodtye game engine. Class based *
* upon code by Jeff Molofee (NeHe) and    *
* used with permission.                   *
******************************************/
#ifndef _BITMAPFONTS_
#define _BITMAPFONTS_

#include<stdlib.h>
#include<string>

class PFonts  //!< A bitmap font class
{

public:
	unsigned int base; //!<Used for the font base display list

	PFonts(); //!<Constructor
	~PFonts();//!<Destructor

	void BuildFont(int fhieght,bool italic,bool underline,
		bool strikeout,const char * FontName); //!<Used to create the font

	void KillFont(); //!<Used to destroy the font

	void PrintF(const char *fmt, ...);   //!<Writes text in the screen

	void PrintOnScreen(float x, float y, float z, int Screenwidth, int Screenhieght,
		const char *Text,double argument); /*!<Writes text on the Screen takes a double argument to be parsed for screen display within the
										   text argument field using % character like the printf() function.
										   The float values x, y, and z are for the location that the text should appear on the screen. 
										   Screenwidth and Screenhieght should be the values of the screenwidth and height the text will
										   be printed on. */

	void PrintOnScreen(float x, float y, float z, int Screenwidth, int Screenhieght,
		const char *Text,const char * argument); /*!<Writes text on the Screen takes a string argument to be parsed for screen display within the
										   text argument field using % character like the printf() function.
										   The float values x, y, and z  are for the location that the text should appear on the screen. 
										   Screenwidth and Screenhieght should be the values of the screenwidth and height the text will
										   be printed on. */

	void PrintOnScreen(float x, float y, float z, int Screenwidth, int Screenhieght,
		const char *Text,int argument); /*!<Writes text on the Screen takes a int argument to be parsed for screen display within the
										   text argument field using % character like the printf() function.
										   The float values x, y, and z are for the location that the text should appear on the screen. 
										   Screenwidth and Screenhieght should be the values of the screenwidth and height the text will
										   be printed on. */

	void PrintFile2Screen(float x, float y, float z ,const char * filename, 
		int width, int height, int textSpacing); /*!<reads in a paragraph from a file all the arguments are the same as the other functions
												 in this class with like names, except textspacing which is used to space the lines of text out
												 vertically when printing the file to the screen.*/

	
};

#endif