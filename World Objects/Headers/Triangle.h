/*!*********************************************(C)**
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
#ifndef _TRIANGLE_
#define _TRIANGLE_

class Triangle : public Shape //!< Creates and Draws Triangles : Derived from Shape
{
	float Vertices[3][3];  //!<Used for Points on the Triangle
	float TexCoords[3][2]; //!<Texture Coordinates used for mapping
	bool transparency;     //!<Used to enable Transparency in drawing (alpha values).
	bool glow;

public:

	
	
	bool Draw();    //!< Draws the Triangle

	bool OnScale(float x, float y, float z, Triangle &Object); /*!< Used to Scale a Triangle. Takes a reference to the
															   Triangle being scaled so as to draw the object and update it
															   after a call to glScalef(). */

	bool SetVerticesScales(float V1x,float V1y,
		float V2x, float V2y,float V3x, float V3y, float Z); //!< Sets measurements for drawing triangle

	bool SetTexCoords(float T1x,float T1y,
		float T2x, float T2y,  float T3x, float T3y); //!< Sets measurements for Texturing triangle

	Triangle();                 //<! Default Constructor
	Triangle(std::string Narg); /*!< Overloaded constructor takes one argument, the readable name of the Triangle Object
								It then passes the argument to the constructor of the parent class shape
								where it is changed into a char array and stored in the inherited data member
								Label for use with Printing Text to the screen.*/
	~Triangle();

	void SetTransparency(bool arg); //!< Sets the Transparency Variable
	bool GetTransparency();         //!< Returns the Transparency Variable
	void SetGlow(bool arg);         //!< Sets the glow variable.
	bool GetGlow();                //!< Returns the value stored in glow.
};

#endif