/*!*****************************************
* Source for bitmap class Troglodyte Game *
* Engine                                  *
******************************************/

#include "PCHEADER.h"

// Original code by Mark Bernard ( e-mail: mark.bernard@rogers.com )

// modified by David Henry ( e-mail: strad1238@hotmail.com )

// Modified by Will Canada(Aka DecipherOne e-mail: decipherone@gmail.com)

// Copyright 2003





////////////////////////////////////////////////////////////////////////////////////

PBitmap::PBitmap()					// basic constructor

{
    init();
}


////////////////////////////////////////////////////////////////////////////////////

PBitmap::PBitmap(char *file, ostream& logFile)	// constructor loads the bitmap

{
	init();
    loadBitmap(file);
}


////////////////////////////////////////////////////////////////////////////////////

PBitmap::~PBitmap()					// destructor

{
    reset();
}


////////////////////////////////////////////////////////////////////////////////////

bool PBitmap::loadBitmap(const char *fileName) 	// loads a bitmap into memory

{
	FILE *in;					    // file stream for reading

    char *tempData;					// temp storage for image data

    int numColours;					// total available colours


    loaded = false;					// bitmap is not loaded yet

    
    in = fopen(fileName, "rb");			// open the file for reading in binary mode


    if(in == NULL) 					// if the file does not exist return in error

    {
		error = "File not found";
		MessageBox(NULL,"The path or filename for a Bitmap is Incorrect. \n"
			" The program will now exit.","Bitmap Load Error!", MB_OK);
		PostQuitMessage(0);
        fclose(in);
        return false;
    }


	//==========	read in the BITMAPFILEHEADER      ==========//


    fread(&bmfh, sizeof(BitmapFileHeader), 1, in);
  
    if(bmfh.bfType != BITMAP_MAGIC_NUMBER) 	// check magic number that says this is a bitmap

	{
		error = "File is not in DIB format";
		MessageBox(NULL,"The file attempting to be loaded is not a bitmap file. \n"
			" Please check the file extension, path, or name. \n"
			"The Program will now Quit!","Bitmap Load Error!",MB_OK);
		PostQuitMessage(0);
        fclose(in);
        return false;
    }

	//==========     read in the BITMAPINFOHEADER     =========//


    fread(&bmih, sizeof(BitmapInfoHeader), 1, in);

	//writeLog(logFile, fileName);			// write data to file



    width = bmih.biWidth;					// set object data fields

    height = bmih.biHeight;
    bpp = bmih.biBitCount;

    if(bpp < 8) 							// test for correct bit-per-pixel depth

    {
		error = "File is not 8 or 24 bits per pixel";
        fclose(in);
        return false;
    }
											// calculate the size of image data + padding

    dataSize = (width * height * (unsigned int)(bpp / 8.0) );

    if(bpp == 8) 							// load the color palette for 8 bits per pixel

	{
		numColours = 1 << bpp;				// calculate the number of available colours

		colours = new RGBQuad[numColours];					
    	fread(colours, sizeof(RGBQuad), numColours, in);	// read in the color palette

    }

    tempData = new char[dataSize];			// set up the temporary buffer for the image data


    if(tempData == NULL) 					// exit if there is not enough memory

	{
		error = "Not enough memory to allocate a temporary buffer";
        fclose(in);
        return false;
    }

    fread(tempData, sizeof(char), dataSize, in);	// read in the entire image


    fclose(in);								// close the file now that we have all the info


							// set both values to the byte total of the file, without padding

    byteWidth = padWidth = (int)( (float)width * (float)bpp / 8.0 );

    while(padWidth % 4 != 0) 				// adjust the width for padding as necessary

	{
		padWidth++;
    }

    if(bpp == 8) 							// change format from GBR to RGB

    {
		loaded = convert8(tempData);
   	}
    else if(bpp == 24) 
	{
    	loaded = convert24(tempData);
   	}

    delete [] tempData;	
	tempData = NULL;              // clean up memory


    error = "Bitmap loaded";			// bitmap is now loaded


    return loaded;						// return success

}


////////////////////////////////////////////////////////////////////////////////////

void PBitmap::init(void) 				// function to set the inital values

{
	loaded = false;
    colours = 0;
    data = 0;
    error = "";
}


////////////////////////////////////////////////////////////////////////////////////

void PBitmap::reset(void)
{
    if(colours)							// clear the color pallete if required

	{	
        delete [] colours;
		colours = NULL;
    }

    if(data)							// clear the data if required

	{
        delete [] data;
		data = NULL;
    }

	loaded = false;
    error = "";
}


////////////////////////////////////////////////////////////////////////////////////

bool PBitmap::convert24(char* tempData) 
{
	int offset;							// padding between data

	int dataSize;						// the size of the bitmap data


	dataSize = abs(width * height * RGB_BYTE_SIZE);
    
    data = new char[dataSize];			// allocate the buffer for the final image data


    if(data == NULL) 					// exit if there is not enough memory

    {
		error = "Not enough memory to allocate an image buffer";
		MessageBox(NULL,"Not Enough Memory to Allocate an image Buffer."
			"\n Program will now Quit!", "Bitmap Load Error!",MB_OK);
		PostQuitMessage(0);
        delete [] data;
		data =NULL;
        return false;
    }

    if(height > 0) 
	{
        offset = padWidth - byteWidth;			// find the difference

        
        for(int i = 0; i < dataSize; i += 3)	// count backwards until at front of image

        {
            if((i+1) % padWidth == 0)			// jump over the padding

			{
				i += offset;
            }
    
            *(data+i+2) = *(tempData+i);        // transfer the data in reverse order

            *(data+i+1) = *(tempData+i+1);		// in 3-color blocks of RGB

            *(data+i) = *(tempData+i+2);
        }
    }

    else										// image parser for a forward image

	{
        offset = padWidth - byteWidth;
        int j = dataSize - 3;

        for(int i = 0; i < dataSize; i += 3, j -= 3) 
		{
            if((i+1) % padWidth == 0)			// jump over padding

			{
                i += offset;
            }

            *(data+j+2) = *(tempData+i);		// transfer the data ||NOTE||

            *(data+j+1) = *(tempData+i+1);		// that final data is stored backwards now

            *(data+j) = *(tempData+i+2);		// due to the difference of i and j

        }
    }

    return true;
}


////////////////////////////////////////////////////////////////////////////////////

bool PBitmap::convert8(char* tempData) 
{
	int offset;							// padding between data

	int dataSize;						// the size of the bitmap data


	dataSize = abs(width * height * RGB_BYTE_SIZE);		// total memory required

    
    data = new char[dataSize];			// allocate the buffer for the final image data


    if(data == NULL)					// exit if there is not enough memory

	{
        error = "Not enough memory to allocate an image buffer";
		MessageBox(NULL,"Not Enough Memory to Allocate an image Buffer."
			"\n Program will now Quit!", "Bitmap Load Error!",MB_OK);
		PostQuitMessage(0);
        delete [] data;
		data = NULL;
        return false;
    }

    if(height > 0) 
	{
        offset = padWidth - byteWidth;
        int j = 0;
										//count backwards so you start at the front of the image

        for(int i = 0; i < dataSize * RGB_BYTE_SIZE; i += 3, j++) 
		{
            if((i+1) % padWidth == 0)						// jump over padding

			{
                i += offset;
            }

            *(data+i) = colours[*(tempData+j)].rgbRed;		// transfer the data

            *(data+i+1) = colours[*(tempData+j)].rgbGreen;
            *(data+i+2) = colours[*(tempData+j)].rgbBlue;
        }
    }

    else										// image parser for a forward image

	{
        offset = padWidth - byteWidth;
        int j = dataSize - 1;

										//count backwards until start at front of image

        for(int i = 0; i < dataSize * RGB_BYTE_SIZE; i += 3, j--) 
		{ 
            if((i+1) % padWidth == 0)						// jump over padding

			{
                i += offset;
            }

            *(data+i) = colours[*(tempData+j)].rgbRed;		// transfer the data,

            *(data+i+1) = colours[*(tempData+j)].rgbGreen;	// this time getting it

            *(data+i+2) = colours[*(tempData+j)].rgbBlue;	// from the color table

        }
    }
    return true;
}


////////////////////////////////////////////////////////////////////////////////////

/*!void Bitmap::writeLog(ostream& OS, char* fileName)				// write log to file

{
	OS << "name of file    = " << fileName << endl;
	OS << "FileHeader Size = " << sizeof(BitmapFileHeader) << endl;
	OS << "InfoHeader Size = " << sizeof(BitmapInfoHeader) << endl;
	OS << "Size            = " << bmih.biSize << endl;
	OS << "Width           = " << bmih.biWidth << endl;
	OS << "Height          = " << bmih.biHeight << endl;
	OS << "Planes          = " << bmih.biPlanes << endl;
	OS << "BitCount        = " << bmih.biBitCount << endl;
	OS << "Compression     = " << bmih.biCompression << endl;
	OS << "ClrImportant    = " << bmih.biClrImportant << endl;
	OS << "ClrUsed         = " << bmih.biClrUsed << endl;
	OS << "SizeImage       = " << bmih.biSizeImage << endl;
	OS << "PixelsPerMeter  = " << bmih.biXPelsPerMeter << endl;
	OS << "PixelsPerMeter  = " << bmih.biYPelsPerMeter << endl;
	OS << endl;
}*/