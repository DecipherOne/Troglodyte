/*!*********************************************(C)**
+ Will Canada : DecipherOne Productions      2007  +
|--------------------------------------------------|
| This class is derived from TObject(base object   |
| class) and is an somewhat abstract class for     |
| creating and drawind specific shapes, which      |
| will be derived from this class.                 |
|   Additional classes such as models and such     |
| will also be derived from this line of           |
| inheritance.                                     |
|__________________________________________________|
+--------------------------------------------------+*/

#ifndef _SHAPE_
#define _SHAPE_

class Shape : public TObject   //!< Base Shape class : Derived from TObject
{
protected:

	bool hasTexture; //!<Used to tell if the shape has a texture
	

public:


	
	void SetHasTexture(bool arg); //!<Used to set if the shape has a texture
	bool GetHasTexture(); //!<Used to see if shape has a texture
	bool LoadTexture(char * arg, int imagetype); /*!<  Function used to Load a texture into memory
												 for a shape. The Function takes 2 Arguments the first 
												 is the path and name of the file to load. The second is 
												 an integer value to pass to the PTexture function LoadTexture.

												 It should either be 0 for Bitmap, 1 For PNG, or 2 for a Targa File.
												 or 3 for FBO*/

	PTexture  Texture; //!< Texture Object for texture
	Shape(std::string Narg); /*!< Overloaded Constructor takes a string argument as the human readable
	                         form for the object. It then converts it to a char array and stores it
							 in the inherited data member Label for use with printing on the screen. */
	Shape();  //!< Default Constructor
	~Shape(); //!< Destructor : Automatically releases any textures associated with the object
};

#endif
