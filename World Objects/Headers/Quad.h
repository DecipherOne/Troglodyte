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

#ifndef _QUAD_H
#define _QUAD_H

class Quad : public Triangle //!< Class for creating Quads in OpenGL
{
public:
	
	float Vertices[4][3];   //!< Coordinates for each quad point
	float TexCoords[4][2]; //!< Coordinate for each texture point

	bool Draw();         //!< Draws the Quad
	bool Draw2D(bool front);       //!< Draws a Quad in 2D (Designed for use in orthogonal view). Argument says to draw on top or behind scene.
	bool OnScale(float x, float y, float z, Quad &Object); //!< Scales the quad Drawing call takes place inside of function.
	bool SetVerticesScales(float V1x,float V1y,float V2x,float V3y, float Z); //Gives measurements for drawing Quad
	bool SetTexCoords(float T1x,float T1y,float T2x,float T3y); //Gives measurements for Texturing Quad T1x lefthand, T2x right hand, T1y bottom, T3y Top
	Quad(std::string arg);
	Quad();
    ~Quad();
};




#endif