/*!*****************************************
* Header for bitmap class Phoenix Game    *
* Engine                                  *
******************************************/

#ifndef _BITMAP_H
#define _BITMAP_H

// Original code by Mark Bernard ( e-mail: mark.bernard@rogers.com )

// modified by David Henry ( e-mail: strad1238@hotmail.com )

// Copyright 2003



#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const short BITMAP_MAGIC_NUMBER = 19778;
const int RGB_BYTE_SIZE = 3;

#pragma pack(push, bitmap_data, 1)

// these structures make the class less platform dependent

//------------------------------------------

typedef struct tagRGBQuad 
{
	char rgbBlue;
	char rgbGreen;
	char rgbRed;
	char rgbReserved;
} RGBQuad;


//------------------------------------------

typedef struct tagBitmapFileHeader 
{
	unsigned short bfType;
	unsigned int bfSize;
	unsigned short bfReserved1;
	unsigned short bfReserved2;
	unsigned int bfOffBits;
} BitmapFileHeader;


//------------------------------------------

typedef struct tagBitmapInfoHeader 
{
	unsigned int biSize;
	int biWidth;
	int biHeight;
	unsigned short biPlanes;
	unsigned short biBitCount;
	unsigned int biCompression;
	unsigned int biSizeImage;
	int biXPelsPerMeter;
	int biYPelsPerMeter;
	unsigned int biClrUsed;
	unsigned int biClrImportant;
} BitmapInfoHeader;


//------------------------------------------


#pragma pack(pop, bitmap_data)

//--------------------------------------------------------------------------------------

class PBitmap //!< Class used for Loading Bitmap Files
{
public:
    PBitmap();
    PBitmap(char *fileName, ostream& logFile);
    ~PBitmap();

    bool loadBitmap(const char * fileName);

    RGBQuad *colours;						//!< the color pallete for 8-bit bitmaps

    char *data;								//!<Here is the BMP data

    bool loaded;							//!< loaded or not

    int width;								//!< width and height

	int height;	
    unsigned short bpp;						//!< bits per pixel

    string error;							//!< a field for error message

	

private:
	
	void init();							//!<initializes the main data fields
    void reset();							//!<resets all data in object

    bool convert24(char *tempData);			//!< convert to 24bit RGB bottom up data

    bool convert8(char *tempData);			//!< convert to 24bit RGB bottom up data

	//void writeLog(ostream& OS, char *fileName);		// write log to file


    BitmapFileHeader bmfh;					//!< file header

    BitmapInfoHeader bmih;					//!< information header

    int byteWidth;							//!< the width in bytes of the image

    int padWidth;							//!< the width in bytes of the padded image

    unsigned int dataSize;					//!< size of the data in the file

};

//--------------------------------------------------------------------------------------



#endif //_BITMAP_H