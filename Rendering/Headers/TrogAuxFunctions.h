/*!************************************
* This is the header file for various*
* Global functions that have no class*
* to call home. These functions      *
* simply perform simple useful tasks,*
* for the Phoenix game engine.       *
* Author : Will Canada (DecipherOne) *
* (c)2006 DecipherOne Productions    *
*************************************/
#include <stdlib.h>
#include <string>

using namespace std;

class TrogAuxFunctions
{
public:

int SetColor(string color); //!< Used to set the opengl color takes string argument
int SetColor(int color);  //!< Used to set opengl color except takes int argument
int ColorSelect();  //!< Used to pic a random color to draw with 
bool disMessage; //!< Used to quit if right color wasn't selected

int SetBGColor(int color); //!< Used to set the opengl clear color(Background color) takes an integer value as an argument
int SetBGColor(string color); //!< Used to set the opengl clear color(Background color) takes a string value as an argument, name of the color
float PreventZeroVector(float v); //!< Does a quick check to make sure that v isn't a zero vector, if it is, it corrects it.
float Pixel_2WorldSpace(float arg); //!< Returns the world space coords for the pixel equivelant based on the size of the window
std::string Seconds_2TimeString(double Insecs); //!< Converts seconds into a string containing Days, Hours, Minutes, & Seconds
int GetRandRange(int min,int max);  //!< Generates a random number between min and max.
int GetHalfWidth(int val); //Returns the half width of val;
TrogAuxFunctions();
~TrogAuxFunctions();

};
