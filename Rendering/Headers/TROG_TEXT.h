/*!<*******************************************************
* This class manages the bitmap fonts for games.          *
*										                  *
* Author : Will (DecipherOne) Canada                      *
* November 7, 2011                                        *
*---------------------------------------------------------*
* Troglodyte (c) DecipherOne Productions                  *
**********************************************************/
#include "PCHeader.h"

#ifndef _TROG_TEXT_
#define _TROG_TEXT_



class TROG_TEXT 
{

	int Large_numofLetters; //Number of Large Letters
	int Small_numofLetters; //Number of Small Letters

	int Color;  //!< 0=white,1=yellow

	Sprite * BMF;   //!< Pointers of the Sprites for each letter.

	float Small_Spacing; //!< The distance between each letter.
	float Large_Spacing; //!< The distance between each letter.

	PTexture LargeFont;
	PTexture SmallFont;

	void Small_MapFont(char arg,Sprite &Letter); //!< Takes the single char and maps the texture to the correct letter.
	void Large_MapFont(char arg,Sprite &Letter); //!< Takes the single char and maps the texture to the correct letter.

public:

	bool Large_PrintOnScreen(std::string arg,float x, float y,float z); //Takes arg and converts each character into the corrisponding bitmap, maps them to a quad and then translates to the x,y coords and prints them on the screen, Ortho-style. This should be called durring initialization and then subsequent draw calls made in the update loop.
	bool Small_PrintOnScreen(std::string arg,float x, float y,float z); //Takes arg and converts each character into the corrisponding bitmap, maps them to a quad and then translates to the x,y coords and prints them on the screen, Ortho-style. This should be called durring initialization and then subsequent draw calls made in the update loop.
	bool Small_Draw(); //!< Custom draw loop that prints all the letters, must be called in update loop.
	bool Large_Draw(); //!< Custom draw loop that prints all the letters, must be called in update loop.

	void SetColor(int arg); //!< Sets variable color
	int GetColor();         //!< Returns the value of color.
	void Set_S_Spacing(float arg); //!< Sets variable Small_Spacing
	float Get_S_Spacing();         //!< Returns Small_Spacing
	void Set_L_Spacing(float arg); //!< Sets variable Large_Spacing
	float Get_L_Spacing();         //!< Returns Large_Spacing
	TROG_TEXT();
	~TROG_TEXT();


};



#endif