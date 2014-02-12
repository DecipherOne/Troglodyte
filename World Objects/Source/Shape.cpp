/*!*********************************************(C)**
+ Will Canada : DeciipherOne Productions      2007 +
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

#include "PCHEADER.h"

void Shape::SetHasTexture(bool arg)
{
	hasTexture = arg;
}
/////////////////////////////////////////////////////////////////////////////////////////
bool Shape::GetHasTexture()
{
	return hasTexture;
}


/////////////////////////////////////////////////////////////////////////////////////////
Shape::Shape()
{
	hasTexture=true;
}

//////////////////////////////////////////////////////////////////////////////////////////
Shape::Shape(std::string Narg): TObject()
{
	Name = Narg;
	Label = Name.c_str();
	hasTexture=true;
}


//////////////////////////////////////////////////////////////////////////////////////////
Shape::~Shape()
{
	
}

//////////////////////////////////////////////////////////////////////////////////////////
bool Shape::LoadTexture(char * arg, int imagetype)
{
	
	if(!GetHasTexture())
	{
		SetHasTexture(true);
	}

	Texture.SetImageType(imagetype);
	if(imagetype != 3)//Rendering to FBO can't be loaded from disk.
	{
		Texture.SetTex2Load(arg);
	}
		
	Texture.loadTexture();
	

	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////	