/*!************************************
* This is a header for initalizing   *
* texture information for Troglodyte *
* Author : Will Canada               *
*************************************/
#ifndef _PTEXTURE_
#define _PTEXTURE_
#pragma once


class PTexture //!< Texture class loads and stores a texture in memory
{
protected:
	std::string Name; //!< String Name of the Texture (Should be the path and name of the texture file.)
	const char * Label; //!< Label for printing Name on Screen

	enum ImageType //!< Tells What type of image to load when loadTexture is called
	{
		RGB_BITMAP,
		PNG,
		TARGA,
		FBO       //FBO - Frame Buffer Object for Rendering to a texture.
		
	};

	int TexType; //!< Used to specify which texture type to load

	int fbo_width, fbo_height; //!< Dimensions for the FBO Texture to be rendered to in pixles. Defaults to 256 if not explicity set.
	bool using_shader; //!< Signals we are using the texture in a shader.
public:

	float width,height;       //!< Used to store width and height info for passing data to other functons
	PTexture();             //!< Default Constructor
	PTexture(const char *,int arg);  //!< Overloaded constructor takes the file path and name of a default texture and the type of texture.
	~PTexture();
	unsigned int texture[1]; //!< Allocate space for the texture
	unsigned int fbo;					//!< Our handle to the FBO
    unsigned int depthBuffer;			//!< Our handle to the depth render buffer
	bool ConString4Screen(std::string arg); //!< Used to convert string to const char * for use with PrintOnScreen()
	bool loadTexture(); //!< Loads the specified texture : SHould be called after SetTex2Load and SetImageType
	void SetTex2Load(std::string arg); //!< Sets the path and name of texture 2 load
	void SetName(std::string arg); //!< sets the name of the texture
	std::string GetName();

	void SetImageType(int); /*!< USed to set the image type for loading a texture
							Should be either 0 for BITMAP, 1 for PNG, or 2 for TARGA */

	int GetImageType(); //!< Used to access type of image being loaded

	void Set_fbo_w_h(int w, int h); //!< Sets the width and height for the texture being rendered to.
	int Get_fbo_w(); //!< Returns the fbo width
	int Get_fbo_h(); //!< Returns the fbo height

	bool SaveTextureData(fstream &stream); //!< Used to save a texture to a file. stream is the file stream to save with. (NOTE - ALL FILE OPENING AND CLOSING MUST BE DONE FROM THE CALLING FUNCTION)
	bool LoadTextureData(fstream &stream); //!< Used to load a texture from a file. stream is the file stream to Load with. (NOTE - ALL FILE OPENING AND CLOSING MUST BE DONE FROM THE CALLING FUNCTION)
	void SetShader(bool arg);  //!< Sets the value shader to the value of arg.
	bool GetShader(); //!< Returns the value stored in shader.

	


};
#endif