/*!<*******************************************************
* This class manages the bitmap fonts for games.          *
*				                                          *
* Author : Will (DecipherOne) Canada                      *
* November 7, 2011                                        *
*---------------------------------------------------------*
* Troglodyte (c) DecipherOne Productions                  *
**********************************************************/

#include "PCHEADER.h"


void TROG_TEXT::Set_S_Spacing(float arg)
{
	if(arg<1)
	{ 
		arg=1;
	}

	Small_Spacing=arg;
}
//////////////////////////////////////////////////////////////////////////////////
float TROG_TEXT::Get_S_Spacing()
{
	return Small_Spacing;
}

//////////////////////////////////////////////////////////////////////////////////
int TROG_TEXT::GetColor()
{
	return Color;
}
//////////////////////////////////////////////////////////////////////////////////

void TROG_TEXT::SetColor(int arg)
{
	if(arg<0)
	{
		arg=0;
	}
	else if(arg>1)
	{
		arg=1;
	}

	Color=arg;
}

//////////////////////////////////////////////////////////////////////////////////

bool TROG_TEXT::Small_Draw()
{
	int count = 0;

	do
	{
		if(count>0) //Translate the current letter based on the previous
		{
			float x=0,y=0;

			//Check and see if we have reached the end of the screen.
			if((BMF+(count-1))->GetxTranslation()+FM.Pixel_2WorldSpace(Small_Spacing)>
				TrogWin.GetWidth())
			{
				y=(BMF+(count-1))->GetyTranslation()+FM.Pixel_2WorldSpace(18);
				x=BMF->GetxTranslation();
			}
			else
			{
				x= (BMF+(count-1))->GetxTranslation()+FM.Pixel_2WorldSpace(Small_Spacing);
				y= BMF->GetyTranslation();
			}

			(BMF+count)->OnSetTranslation(x,y,BMF->GetzTranslation());
		}


		(BMF+count)->Draw();
		count++;

	}
	while(count<Small_numofLetters);
	return true;
}

//////////////////////////////////////////////////////////////////////////////////

void TROG_TEXT::Small_MapFont(char arg,Sprite &Letter)
{
	//Set the quad dimensions in pixel halfwidths
	Letter.SetDimensions(8,8,8,8);
	//Assign the texture data as our already loaded texture.
	Letter.Texture = SmallFont;
	string n = "TROG_Text Letter : "+arg;
	Letter.SetName(n);

	switch(Color)
	{
	case 0:
		{//White Text

			if(arg=='!')
			{
				Letter.Static_Map_UV(1,1,16,16);
			}
			else if(arg=='"')
			{
				Letter.Static_Map_UV(1,2,16,16);
			}
			else if(arg=='#')
			{
				Letter.Static_Map_UV(1,3,16,16);
			}
			else if(arg=='$')
			{
				Letter.Static_Map_UV(1,4,16,16);
			}
			else if(arg=='%')
			{
				Letter.Static_Map_UV(1,5,16,16);
			}
			else if(arg=='&')
			{
				Letter.Static_Map_UV(1,6,16,16);
			}
			else if(arg==',')
			{
				Letter.Static_Map_UV(1,7,16,16);
			}
			else if(arg=='(')
			{
				Letter.Static_Map_UV(1,8,16,16);
			}
			else if(arg==')')
			{
				Letter.Static_Map_UV(1,9,16,16);
			}
			else if(arg=='*')
			{
				Letter.Static_Map_UV(1,10,16,16);
			}
			else if(arg=='+')
			{
				Letter.Static_Map_UV(1,11,16,16);
			}
			else if(arg=='\'')
			{
				Letter.Static_Map_UV(1,12,16,16);
			}
			else if(arg=='-')
			{
				Letter.Static_Map_UV(1,13,16,16);
			}
			else if(arg=='.')
			{
				Letter.Static_Map_UV(1,14,16,16);
			}
			else if(arg=='/')
			{
				Letter.Static_Map_UV(1,15,16,16);
			}
			else if(arg=='0')
			{
				Letter.Static_Map_UV(1,16,16,16);
			}
			else if(arg=='1')
			{
				Letter.Static_Map_UV(1,17,16,16);
			}
			else if(arg=='2')
			{
				Letter.Static_Map_UV(1,18,16,16);
			}
			else if(arg=='3')
			{
				Letter.Static_Map_UV(1,19,16,16);
			}
			else if(arg=='4')
			{
				Letter.Static_Map_UV(1,20,16,16);
			}
			else if(arg=='5')
			{
				Letter.Static_Map_UV(1,21,16,16);
			}
			else if(arg=='6')
			{
				Letter.Static_Map_UV(1,22,16,16);
			}
			else if(arg=='7')
			{
				Letter.Static_Map_UV(1,23,16,16);
			}
			else if(arg=='8')
			{
				Letter.Static_Map_UV(1,24,16,16);
			}
			else if(arg=='9')
			{
				Letter.Static_Map_UV(1,25,16,16);
			}
			else if(arg==':')
			{
				Letter.Static_Map_UV(1,26,16,16);
			}
			else if(arg==';')
			{
				Letter.Static_Map_UV(1,27,16,16);
			}
			else if(arg=='<')
			{
				Letter.Static_Map_UV(1,28,16,16);
			}
			else if(arg=='=')
			{
				Letter.Static_Map_UV(1,29,16,16);
			}
			else if(arg=='>')
			{
				Letter.Static_Map_UV(1,30,16,16);
			}
			else if(arg=='?')
			{
				Letter.Static_Map_UV(1,31,16,16);
			}
			else if(arg=='@')
			{
				Letter.Static_Map_UV(1,32,16,16);
			}
			else if(arg=='A')
			{
				Letter.Static_Map_UV(2,1,16,16);
			}
			else if(arg=='B')
			{
				Letter.Static_Map_UV(2,2,16,16);
			}
			else if(arg=='C')
			{
				Letter.Static_Map_UV(2,3,16,16);
			}
			else if(arg=='D')
			{
				Letter.Static_Map_UV(2,4,16,16);
			}
			else if(arg=='E')
			{
				Letter.Static_Map_UV(2,5,16,16);
			}
			else if(arg=='F')
			{
				Letter.Static_Map_UV(2,6,16,16);
			}
			else if(arg=='G')
			{
				Letter.Static_Map_UV(2,7,16,16);
			}
			else if(arg=='H')
			{
				Letter.Static_Map_UV(2,8,16,16);
			}
			else if(arg=='I')
			{
				Letter.Static_Map_UV(2,9,16,16);
			}
			else if(arg=='J')
			{
				Letter.Static_Map_UV(2,10,16,16);
			}
			else if(arg=='K')
			{
				Letter.Static_Map_UV(2,11,16,16);
			}
			else if(arg=='L')
			{
				Letter.Static_Map_UV(2,12,16,16);
			}
			else if(arg=='M')
			{
				Letter.Static_Map_UV(2,13,16,16);
			}
			else if(arg=='N')
			{
				Letter.Static_Map_UV(2,14,16,16);
			}
			else if(arg=='O')
			{
				Letter.Static_Map_UV(2,15,16,16);
			}
			else if(arg=='P')
			{
				Letter.Static_Map_UV(2,16,16,16);
			}
			else if(arg=='Q')
			{
				Letter.Static_Map_UV(2,17,16,16);
			}
			else if(arg=='R')
			{
				Letter.Static_Map_UV(2,18,16,16);
			}
			else if(arg=='S')
			{
				Letter.Static_Map_UV(2,19,16,16);
			}
			else if(arg=='T')
			{
				Letter.Static_Map_UV(2,20,16,16);
			}
			else if(arg=='U')
			{
				Letter.Static_Map_UV(2,21,16,16);
			}
			else if(arg=='V')
			{
				Letter.Static_Map_UV(2,22,16,16);
			}
			else if(arg=='W')
			{
				Letter.Static_Map_UV(2,23,16,16);
			}
			else if(arg=='X')
			{
				Letter.Static_Map_UV(2,24,16,16);
			}
			else if(arg=='Y')
			{
				Letter.Static_Map_UV(2,25,16,16);
			}
			else if(arg=='Z')
			{
				Letter.Static_Map_UV(2,26,16,16);
			}
			else if(arg=='[')
			{
				Letter.Static_Map_UV(2,27,16,16);
			}
			else if(arg=='\\')
			{
				Letter.Static_Map_UV(2,28,16,16);
			}
			else if(arg==']')
			{
				Letter.Static_Map_UV(2,29,16,16);
			}
			else if(arg=='^')
			{
				Letter.Static_Map_UV(2,30,16,16);
			}
			else if(arg=='_')
			{
				Letter.Static_Map_UV(2,31,16,16);
			}
			else if(arg=='`')
			{
				Letter.Static_Map_UV(2,32,16,16);
			}
			else if(arg=='a')
			{
				Letter.Static_Map_UV(3,1,16,16);
			}
			else if(arg=='b')
			{
				Letter.Static_Map_UV(3,2,16,16);
			}
			else if(arg=='c')
			{
				Letter.Static_Map_UV(3,3,16,16);
			}
			else if(arg=='d')
			{
				Letter.Static_Map_UV(3,4,16,16);
			}
			else if(arg=='e')
			{
				Letter.Static_Map_UV(3,5,16,16);
			}
			else if(arg=='f')
			{
				Letter.Static_Map_UV(3,6,16,16);
			}
			else if(arg=='g')
			{
				Letter.Static_Map_UV(3,7,16,16);
			}
			else if(arg=='h')
			{
				Letter.Static_Map_UV(3,8,16,16);
			}
			else if(arg=='i')
			{
				Letter.Static_Map_UV(3,9,16,16);
			}
			else if(arg=='j')
			{
				Letter.Static_Map_UV(3,10,16,16);
			}
			else if(arg=='k')
			{
				Letter.Static_Map_UV(3,11,16,16);
			}
			else if(arg=='l')
			{
				Letter.Static_Map_UV(3,12,16,16);
			}
			else if(arg=='m')
			{
				Letter.Static_Map_UV(3,13,16,16);
			}
			else if(arg=='n')
			{
				Letter.Static_Map_UV(3,14,16,16);
			}
			else if(arg=='o')
			{
				Letter.Static_Map_UV(3,15,16,16);
			}
			else if(arg=='p')
			{
				Letter.Static_Map_UV(3,16,16,16);
			}
			else if(arg=='q')
			{
				Letter.Static_Map_UV(3,17,16,16);
			}
			else if(arg=='r')
			{
				Letter.Static_Map_UV(3,18,16,16);
			}
			else if(arg=='s')
			{
				Letter.Static_Map_UV(3,19,16,16);
			}
			else if(arg=='t')
			{
				Letter.Static_Map_UV(3,20,16,16);
			}
			else if(arg=='u')
			{
				Letter.Static_Map_UV(3,21,16,16);
			}
			else if(arg=='V')
			{
				Letter.Static_Map_UV(3,22,16,16);
			}
			else if(arg=='w')
			{
				Letter.Static_Map_UV(3,23,16,16);
			}
			else if(arg=='x')
			{
				Letter.Static_Map_UV(3,24,16,16);
			}
			else if(arg=='y')
			{
				Letter.Static_Map_UV(3,25,16,16);
			}
			else if(arg=='z')
			{
				Letter.Static_Map_UV(3,26,16,16);
			}
			else if(arg=='{')
			{
				Letter.Static_Map_UV(3,27,16,16);
			}
			else if(arg=='|')
			{
				Letter.Static_Map_UV(3,28,16,16);
			}
			else if(arg=='}')
			{
				Letter.Static_Map_UV(3,29,16,16);
			}
			else if(arg=='~')
			{
				Letter.Static_Map_UV(3,30,16,16);
			}
			else if(arg=='"')
			{
				Letter.Static_Map_UV(3,31,16,16);
			}
			else if(arg=='™')
			{
				Letter.Static_Map_UV(4,1,16,16);
			}
			else if(arg=='©')
			{
				Letter.Static_Map_UV(4,2,16,16);
			}
			else if(arg=='®')
			{
				Letter.Static_Map_UV(4,2,16,16);
			}

			break;
		}
		


	case 1://Yellow
		{
		
			if(arg=='!')
			{
				Letter.Static_Map_UV(4,4,16,16);
			}
			else if(arg=='"')
			{
				Letter.Static_Map_UV(4,5,16,16);
			}
			else if(arg=='#')
			{
				Letter.Static_Map_UV(4,6,16,16);
			}
			else if(arg=='$')
			{
				Letter.Static_Map_UV(4,7,16,16);
			}
			else if(arg=='%')
			{
				Letter.Static_Map_UV(4,8,16,16);
			}
			else if(arg=='&')
			{
				Letter.Static_Map_UV(4,9,16,16);
			}
			else if(arg==',')
			{
				Letter.Static_Map_UV(4,10,16,16);
			}
			else if(arg=='(')
			{
				Letter.Static_Map_UV(4,11,16,16);
			}
			else if(arg==')')
			{
				Letter.Static_Map_UV(4,12,16,16);
			}
			else if(arg=='*')
			{
				Letter.Static_Map_UV(4,13,16,16);
			}
			else if(arg=='+')
			{
				Letter.Static_Map_UV(4,14,16,16);
			}
			else if(arg=='\'')
			{
				Letter.Static_Map_UV(4,15,16,16);
			}
			else if(arg=='-')
			{
				Letter.Static_Map_UV(4,16,16,16);
			}
			else if(arg=='.')
			{
				Letter.Static_Map_UV(4,17,16,16);
			}
			else if(arg=='/')
			{
				Letter.Static_Map_UV(4,18,16,16);
			}
			else if(arg=='0')
			{
				Letter.Static_Map_UV(4,19,16,16);
			}
			else if(arg=='1')
			{
				Letter.Static_Map_UV(4,20,16,16);
			}
			else if(arg=='2')
			{
				Letter.Static_Map_UV(4,21,16,16);
			}
			else if(arg=='3')
			{
				Letter.Static_Map_UV(4,22,16,16);
			}
			else if(arg=='4')
			{
				Letter.Static_Map_UV(4,23,16,16);
			}
			else if(arg=='5')
			{
				Letter.Static_Map_UV(4,24,16,16);
			}
			else if(arg=='6')
			{
				Letter.Static_Map_UV(4,25,16,16);
			}
			else if(arg=='7')
			{
				Letter.Static_Map_UV(4,26,16,16);
			}
			else if(arg=='8')
			{
				Letter.Static_Map_UV(4,27,16,16);
			}
			else if(arg=='9')
			{
				Letter.Static_Map_UV(4,28,16,16);
			}
			else if(arg==':')
			{
				Letter.Static_Map_UV(4,29,16,16);
			}
			else if(arg==';')
			{
				Letter.Static_Map_UV(4,30,16,16);
			}
			else if(arg=='<')
			{
				Letter.Static_Map_UV(4,31,16,16);
			}
			else if(arg=='=')
			{
				Letter.Static_Map_UV(4,32,16,16);
			}
			else if(arg=='>')
			{
				Letter.Static_Map_UV(5,1,16,16);
			}
			else if(arg=='?')
			{
				Letter.Static_Map_UV(5,2,16,16);
			}
			else if(arg=='@')
			{
				Letter.Static_Map_UV(5,3,16,16);
			}
			else if(arg=='A')
			{
				Letter.Static_Map_UV(5,4,16,16);
			}
			else if(arg=='B')
			{
				Letter.Static_Map_UV(5,5,16,16);
			}
			else if(arg=='C')
			{
				Letter.Static_Map_UV(5,6,16,16);
			}
			else if(arg=='D')
			{
				Letter.Static_Map_UV(5,7,16,16);
			}
			else if(arg=='E')
			{
				Letter.Static_Map_UV(5,8,16,16);
			}
			else if(arg=='F')
			{
				Letter.Static_Map_UV(5,9,16,16);
			}
			else if(arg=='G')
			{
				Letter.Static_Map_UV(5,10,16,16);
			}
			else if(arg=='H')
			{
				Letter.Static_Map_UV(5,11,16,16);
			}
			else if(arg=='I')
			{
				Letter.Static_Map_UV(5,12,16,16);
			}
			else if(arg=='J')
			{
				Letter.Static_Map_UV(5,13,16,16);
			}
			else if(arg=='K')
			{
				Letter.Static_Map_UV(5,14,16,16);
			}
			else if(arg=='L')
			{
				Letter.Static_Map_UV(5,15,16,16);
			}
			else if(arg=='M')
			{
				Letter.Static_Map_UV(5,16,16,16);
			}
			else if(arg=='N')
			{
				Letter.Static_Map_UV(5,17,16,16);
			}
			else if(arg=='O')
			{
				Letter.Static_Map_UV(5,18,16,16);
			}
			else if(arg=='P')
			{
				Letter.Static_Map_UV(5,19,16,16);
			}
			else if(arg=='Q')
			{
				Letter.Static_Map_UV(5,20,16,16);
			}
			else if(arg=='R')
			{
				Letter.Static_Map_UV(5,21,16,16);
			}
			else if(arg=='S')
			{
				Letter.Static_Map_UV(5,22,16,16);
			}
			else if(arg=='T')
			{
				Letter.Static_Map_UV(5,23,16,16);
			}
			else if(arg=='U')
			{
				Letter.Static_Map_UV(5,24,16,16);
			}
			else if(arg=='V')
			{
				Letter.Static_Map_UV(5,25,16,16);
			}
			else if(arg=='W')
			{
				Letter.Static_Map_UV(5,26,16,16);
			}
			else if(arg=='X')
			{
				Letter.Static_Map_UV(5,27,16,16);
			}
			else if(arg=='Y')
			{
				Letter.Static_Map_UV(5,28,16,16);
			}
			else if(arg=='Z')
			{
				Letter.Static_Map_UV(5,29,16,16);
			}
			else if(arg=='[')
			{
				Letter.Static_Map_UV(5,30,16,16);
			}
			else if(arg=='\\')
			{
				Letter.Static_Map_UV(5,31,16,16);
			}
			else if(arg==']')
			{
				Letter.Static_Map_UV(5,32,16,16);
			}
			else if(arg=='^')
			{
				Letter.Static_Map_UV(6,1,16,16);
			}
			else if(arg=='_')
			{
				Letter.Static_Map_UV(6,2,16,16);
			}
			else if(arg=='`')
			{
				Letter.Static_Map_UV(6,3,16,16);
			}
			else if(arg=='a')
			{
				Letter.Static_Map_UV(6,4,16,16);
			}
			else if(arg=='b')
			{
				Letter.Static_Map_UV(6,5,16,16);
			}
			else if(arg=='c')
			{
				Letter.Static_Map_UV(6,6,16,16);
			}
			else if(arg=='d')
			{
				Letter.Static_Map_UV(6,7,16,16);
			}
			else if(arg=='e')
			{
				Letter.Static_Map_UV(6,8,16,16);
			}
			else if(arg=='f')
			{
				Letter.Static_Map_UV(6,9,16,16);
			}
			else if(arg=='g')
			{
				Letter.Static_Map_UV(6,10,16,16);
			}
			else if(arg=='h')
			{
				Letter.Static_Map_UV(6,11,16,16);
			}
			else if(arg=='i')
			{
				Letter.Static_Map_UV(6,12,16,16);
			}
			else if(arg=='j')
			{
				Letter.Static_Map_UV(6,13,16,16);
			}
			else if(arg=='k')
			{
				Letter.Static_Map_UV(6,14,16,16);
			}
			else if(arg=='l')
			{
				Letter.Static_Map_UV(6,15,16,16);
			}
			else if(arg=='m')
			{
				Letter.Static_Map_UV(6,16,16,16);
			}
			else if(arg=='n')
			{
				Letter.Static_Map_UV(6,17,16,16);
			}
			else if(arg=='o')
			{
				Letter.Static_Map_UV(6,18,16,16);
			}
			else if(arg=='p')
			{
				Letter.Static_Map_UV(6,19,16,16);
			}
			else if(arg=='q')
			{
				Letter.Static_Map_UV(6,20,16,16);
			}
			else if(arg=='r')
			{
				Letter.Static_Map_UV(6,21,16,16);
			}
			else if(arg=='s')
			{
				Letter.Static_Map_UV(6,22,16,16);
			}
			else if(arg=='t')
			{
				Letter.Static_Map_UV(6,23,16,16);
			}
			else if(arg=='u')
			{
				Letter.Static_Map_UV(6,24,16,16);
			}
			else if(arg=='V')
			{
				Letter.Static_Map_UV(6,25,16,16);
			}
			else if(arg=='w')
			{
				Letter.Static_Map_UV(6,26,16,16);
			}
			else if(arg=='x')
			{
				Letter.Static_Map_UV(6,27,16,16);
			}
			else if(arg=='y')
			{
				Letter.Static_Map_UV(6,28,16,16);
			}
			else if(arg=='z')
			{
				Letter.Static_Map_UV(6,29,16,16);
			}
			else if(arg=='{')
			{
				Letter.Static_Map_UV(6,30,16,16);
			}
			else if(arg=='|')
			{
				Letter.Static_Map_UV(6,31,16,16);
			}
			else if(arg=='}')
			{
				Letter.Static_Map_UV(6,32,16,16);
			}
			else if(arg=='~')
			{
				Letter.Static_Map_UV(7,1,16,16);
			}
			else if(arg=='"')
			{
				Letter.Static_Map_UV(7,2,16,16);
			}
			else if(arg=='™')
			{
				Letter.Static_Map_UV(7,4,16,16);
			}
			else if(arg=='©')
			{
				Letter.Static_Map_UV(7,5,16,16);
			}
			else if(arg=='®')
			{
				Letter.Static_Map_UV(7,6,16,16);
			}
			break;

		}
	}
	

}
//////////////////////////////////////////////////////////////////////////////////////////

bool TROG_TEXT::Small_PrintOnScreen(std::string arg, float x, float y,float z)
{

	//See how long our string is and how many bitmap letters we need.
	Small_numofLetters = arg.size();

	if(BMF)
	{
		delete [] BMF;
		BMF=NULL;
	}

	//Allocate the memory for them.
	
	BMF = new Sprite[Small_numofLetters];

	SmallFont.SetTex2Load("Resources/Demos/TROGricade/Textures/Small_TYPE_ALL.png");
	SmallFont.SetImageType(1);
	SmallFont.loadTexture();
	

	int count = 0;

	do
	{
		if(count==0)
		{
			BMF->OnSetTranslation(x,y,z);
		}

		//extract a single letter from the string
		char t = (char) arg[count];
		
		//Send it to be mapped.
		Small_MapFont(t,(*(BMF+count)));

		count++;
	}
	while(count < Small_numofLetters);

	return true;
}
///////////////////////////////////////////////////////////////////////////////////////////
TROG_TEXT::TROG_TEXT()
{
	BMF=NULL;
	Small_numofLetters = 1;
	Large_numofLetters = 1;
	Color= 0;

	Small_Spacing=0;
	Large_Spacing=0;

	
}

///////////////////////////////////////////////////////////////////////////////////////////

TROG_TEXT::~TROG_TEXT()
{
	if((BMF+1))
	{
		delete [] BMF;
		BMF=NULL;
	}
	else
	{
		delete BMF;
		BMF=NULL;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////


void TROG_TEXT::Set_L_Spacing(float arg)
{
	if(arg<1)
	{ 
		arg=1;
	}

	Large_Spacing=arg;
}
//////////////////////////////////////////////////////////////////////////////////
float TROG_TEXT::Get_L_Spacing()
{
	return Large_Spacing;
}

//////////////////////////////////////////////////////////////////////////////////

bool TROG_TEXT::Large_Draw()
{
	int count = 0;

	do
	{
		if(count>0) //Translate the current letter based on the previous
		{
			float x=0,y=0;

			//Check and see if we have reached the end of the screen.
			if((BMF+(count-1))->GetxTranslation()+FM.Pixel_2WorldSpace(Large_Spacing)>
				TrogWin.GetWidth())
			{
				y=(BMF+(count-1))->GetyTranslation()+FM.Pixel_2WorldSpace(18);
				x=BMF->GetxTranslation();
			}
			else
			{
				x= (BMF+(count-1))->GetxTranslation()+FM.Pixel_2WorldSpace(Large_Spacing);
				y= BMF->GetyTranslation();
			}

			(BMF+count)->OnSetTranslation(x,y,BMF->GetzTranslation());
		}


		(BMF+count)->Draw();
		count++;

	}
	while(count<Large_numofLetters);
	return true;
}

//////////////////////////////////////////////////////////////////////////////////

void TROG_TEXT::Large_MapFont(char arg,Sprite &Letter)
{
	//Set the quad dimensions in pixel halfwidths
	Letter.SetDimensions(16,16,16,16);
	//Assign the texture data as our already loaded texture.
	Letter.Texture = LargeFont;
	string n = "TROG_Text Letter : "+arg;
	Letter.SetName(n);
	switch(Color)
	{
	case 0:
		{//White Text

			if(arg=='!')
			{
				Letter.Static_Map_UV(1,1,32,32);
			}
			else if(arg=='"')
			{
				Letter.Static_Map_UV(1,2,32,32);
			}
			else if(arg=='#')
			{
				Letter.Static_Map_UV(1,3,32,32);
			}
			else if(arg=='$')
			{
				Letter.Static_Map_UV(1,4,32,32);
			}
			else if(arg=='%')
			{
				Letter.Static_Map_UV(1,5,32,32);
			}
			else if(arg=='&')
			{
				Letter.Static_Map_UV(1,6,32,32);
			}
			else if(arg==',')
			{
				Letter.Static_Map_UV(1,7,32,32);
			}
			else if(arg=='(')
			{
				Letter.Static_Map_UV(1,8,32,32);
			}
			else if(arg==')')
			{
				Letter.Static_Map_UV(1,9,32,32);
			}
			else if(arg=='*')
			{
				Letter.Static_Map_UV(1,10,32,32);
			}
			else if(arg=='+')
			{
				Letter.Static_Map_UV(1,11,32,32);
			}
			else if(arg=='\'')
			{
				Letter.Static_Map_UV(1,12,32,32);
			}
			else if(arg=='-')
			{
				Letter.Static_Map_UV(1,13,32,32);
			}
			else if(arg=='.')
			{
				Letter.Static_Map_UV(1,14,32,32);
			}
			else if(arg=='/')
			{
				Letter.Static_Map_UV(1,15,32,32);
			}
			else if(arg=='0')
			{
				Letter.Static_Map_UV(1,16,32,32);
			}
			else if(arg=='1')
			{
				Letter.Static_Map_UV(2,1,32,32);
			}
			else if(arg=='2')
			{
				Letter.Static_Map_UV(2,2,32,32);
			}
			else if(arg=='3')
			{
				Letter.Static_Map_UV(2,3,32,32);
			}
			else if(arg=='4')
			{
				Letter.Static_Map_UV(2,4,32,32);
			}
			else if(arg=='5')
			{
				Letter.Static_Map_UV(2,5,32,32);
			}
			else if(arg=='6')
			{
				Letter.Static_Map_UV(2,6,32,32);
			}
			else if(arg=='7')
			{
				Letter.Static_Map_UV(2,7,32,32);
			}
			else if(arg=='8')
			{
				Letter.Static_Map_UV(2,8,32,32);
			}
			else if(arg=='9')
			{
				Letter.Static_Map_UV(2,9,32,32);
			}
			else if(arg==':')
			{
				Letter.Static_Map_UV(2,10,32,32);
			}
			else if(arg==';')
			{
				Letter.Static_Map_UV(2,11,32,32);
			}
			else if(arg=='<')
			{
				Letter.Static_Map_UV(2,12,32,32);
			}
			else if(arg=='=')
			{
				Letter.Static_Map_UV(2,13,32,32);
			}
			else if(arg=='>')
			{
				Letter.Static_Map_UV(2,14,32,32);
			}
			else if(arg=='?')
			{
				Letter.Static_Map_UV(2,15,32,32);
			}
			else if(arg=='@')
			{
				Letter.Static_Map_UV(2,16,32,32);
			}
			else if(arg=='A')
			{
				Letter.Static_Map_UV(3,1,32,32);
			}
			else if(arg=='B')
			{
				Letter.Static_Map_UV(3,2,32,32);
			}
			else if(arg=='C')
			{
				Letter.Static_Map_UV(3,3,32,32);
			}
			else if(arg=='D')
			{
				Letter.Static_Map_UV(3,4,32,32);
			}
			else if(arg=='E')
			{
				Letter.Static_Map_UV(3,5,32,32);
			}
			else if(arg=='F')
			{
				Letter.Static_Map_UV(3,6,32,32);
			}
			else if(arg=='G')
			{
				Letter.Static_Map_UV(3,7,32,32);
			}
			else if(arg=='H')
			{
				Letter.Static_Map_UV(3,8,32,32);
			}
			else if(arg=='I')
			{
				Letter.Static_Map_UV(3,9,32,32);
			}
			else if(arg=='J')
			{
				Letter.Static_Map_UV(3,10,32,32);
			}
			else if(arg=='K')
			{
				Letter.Static_Map_UV(3,11,32,32);
			}
			else if(arg=='L')
			{
				Letter.Static_Map_UV(3,12,32,32);
			}
			else if(arg=='M')
			{
				Letter.Static_Map_UV(3,13,32,32);
			}
			else if(arg=='N')
			{
				Letter.Static_Map_UV(3,14,32,32);
			}
			else if(arg=='O')
			{
				Letter.Static_Map_UV(3,15,32,32);
			}
			else if(arg=='P')
			{
				Letter.Static_Map_UV(3,16,32,32);
			}
			else if(arg=='Q')
			{
				Letter.Static_Map_UV(4,1,32,32);
			}
			else if(arg=='R')
			{
				Letter.Static_Map_UV(4,2,32,32);
			}
			else if(arg=='S')
			{
				Letter.Static_Map_UV(4,3,32,32);
			}
			else if(arg=='T')
			{
				Letter.Static_Map_UV(4,4,32,32);
			}
			else if(arg=='U')
			{
				Letter.Static_Map_UV(4,5,32,32);
			}
			else if(arg=='V')
			{
				Letter.Static_Map_UV(4,6,32,32);
			}
			else if(arg=='W')
			{
				Letter.Static_Map_UV(4,7,32,32);
			}
			else if(arg=='X')
			{
				Letter.Static_Map_UV(4,8,32,32);
			}
			else if(arg=='Y')
			{
				Letter.Static_Map_UV(4,9,32,32);
			}
			else if(arg=='Z')
			{
				Letter.Static_Map_UV(4,10,32,32);
			}
			else if(arg=='[')
			{
				Letter.Static_Map_UV(4,11,32,32);
			}
			else if(arg=='\\')
			{
				Letter.Static_Map_UV(4,12,32,32);
			}
			else if(arg==']')
			{
				Letter.Static_Map_UV(4,13,32,32);
			}
			else if(arg=='^')
			{
				Letter.Static_Map_UV(4,14,32,32);
			}
			else if(arg=='_')
			{
				Letter.Static_Map_UV(4,15,32,32);
			}
			else if(arg=='`')
			{
				Letter.Static_Map_UV(4,16,32,32);
			}
			else if(arg=='a')
			{
				Letter.Static_Map_UV(5,1,32,32);
			}
			else if(arg=='b')
			{
				Letter.Static_Map_UV(5,2,32,32);
			}
			else if(arg=='c')
			{
				Letter.Static_Map_UV(5,3,32,32);
			}
			else if(arg=='d')
			{
				Letter.Static_Map_UV(5,4,32,32);
			}
			else if(arg=='e')
			{
				Letter.Static_Map_UV(5,5,32,32);
			}
			else if(arg=='f')
			{
				Letter.Static_Map_UV(5,6,32,32);
			}
			else if(arg=='g')
			{
				Letter.Static_Map_UV(5,7,32,32);
			}
			else if(arg=='h')
			{
				Letter.Static_Map_UV(5,8,32,32);
			}
			else if(arg=='i')
			{
				Letter.Static_Map_UV(5,9,32,32);
			}
			else if(arg=='j')
			{
				Letter.Static_Map_UV(5,10,32,32);
			}
			else if(arg=='k')
			{
				Letter.Static_Map_UV(5,11,32,32);
			}
			else if(arg=='l')
			{
				Letter.Static_Map_UV(5,12,32,32);
			}
			else if(arg=='m')
			{
				Letter.Static_Map_UV(5,13,32,32);
			}
			else if(arg=='n')
			{
				Letter.Static_Map_UV(5,14,32,32);
			}
			else if(arg=='o')
			{
				Letter.Static_Map_UV(5,15,32,32);
			}
			else if(arg=='p')
			{
				Letter.Static_Map_UV(5,16,32,32);
			}
			else if(arg=='q')
			{
				Letter.Static_Map_UV(6,1,32,32);
			}
			else if(arg=='r')
			{
				Letter.Static_Map_UV(6,2,32,32);
			}
			else if(arg=='s')
			{
				Letter.Static_Map_UV(6,3,32,32);
			}
			else if(arg=='t')
			{
				Letter.Static_Map_UV(6,4,32,32);
			}
			else if(arg=='u')
			{
				Letter.Static_Map_UV(6,5,32,32);
			}
			else if(arg=='V')
			{
				Letter.Static_Map_UV(6,6,32,32);
			}
			else if(arg=='w')
			{
				Letter.Static_Map_UV(6,7,32,32);
			}
			else if(arg=='x')
			{
				Letter.Static_Map_UV(6,8,32,32);
			}
			else if(arg=='y')
			{
				Letter.Static_Map_UV(6,9,32,32);
			}
			else if(arg=='z')
			{
				Letter.Static_Map_UV(6,10,32,32);
			}
			else if(arg=='{')
			{
				Letter.Static_Map_UV(6,11,32,32);
			}
			else if(arg=='|')
			{
				Letter.Static_Map_UV(6,12,32,32);
			}
			else if(arg=='}')
			{
				Letter.Static_Map_UV(6,13,32,32);
			}
			else if(arg=='~')
			{
				Letter.Static_Map_UV(6,14,32,32);
			}

			break;
		}
		


	case 1://Yellow
		{
		
			if(arg=='!')
			{
				Letter.Static_Map_UV(6,16,32,32);
			}
			else if(arg=='"')
			{
				Letter.Static_Map_UV(7,1,32,32);
			}
			else if(arg=='#')
			{
				Letter.Static_Map_UV(7,2,32,32);
			}
			else if(arg=='$')
			{
				Letter.Static_Map_UV(7,3,32,32);
			}
			else if(arg=='%')
			{
				Letter.Static_Map_UV(7,4,32,32);
			}
			else if(arg=='&')
			{
				Letter.Static_Map_UV(7,5,32,32);
			}
			else if(arg==',')
			{
				Letter.Static_Map_UV(7,6,32,32);
			}
			else if(arg=='(')
			{
				Letter.Static_Map_UV(7,7,32,32);
			}
			else if(arg==')')
			{
				Letter.Static_Map_UV(7,8,32,32);
			}
			else if(arg=='*')
			{
				Letter.Static_Map_UV(7,9,32,32);
			}
			else if(arg=='+')
			{
				Letter.Static_Map_UV(7,10,32,32);
			}
			else if(arg=='\'')
			{
				Letter.Static_Map_UV(7,11,32,32);
			}
			else if(arg=='-')
			{
				Letter.Static_Map_UV(7,12,32,32);
			}
			else if(arg=='.')
			{
				Letter.Static_Map_UV(7,13,32,32);
			}
			else if(arg=='/')
			{
				Letter.Static_Map_UV(7,14,32,32);
			}
			else if(arg=='0')
			{
				Letter.Static_Map_UV(7,15,32,32);
			}
			else if(arg=='1')
			{
				Letter.Static_Map_UV(7,16,32,32);
			}
			else if(arg=='2')
			{
				Letter.Static_Map_UV(8,1,32,32);
			}
			else if(arg=='3')
			{
				Letter.Static_Map_UV(8,2,32,32);
			}
			else if(arg=='4')
			{
				Letter.Static_Map_UV(8,3,32,32);
			}
			else if(arg=='5')
			{
				Letter.Static_Map_UV(8,4,32,32);
			}
			else if(arg=='6')
			{
				Letter.Static_Map_UV(8,5,32,32);
			}
			else if(arg=='7')
			{
				Letter.Static_Map_UV(8,6,32,32);
			}
			else if(arg=='8')
			{
				Letter.Static_Map_UV(8,7,32,32);
			}
			else if(arg=='9')
			{
				Letter.Static_Map_UV(8,8,32,32);
			}
			else if(arg==':')
			{
				Letter.Static_Map_UV(8,9,32,32);
			}
			else if(arg==';')
			{
				Letter.Static_Map_UV(8,10,32,32);
			}
			else if(arg=='<')
			{
				Letter.Static_Map_UV(8,11,32,32);
			}
			else if(arg=='=')
			{
				Letter.Static_Map_UV(8,12,32,32);
			}
			else if(arg=='>')
			{
				Letter.Static_Map_UV(8,13,32,32);
			}
			else if(arg=='?')
			{
				Letter.Static_Map_UV(8,14,32,32);
			}
			else if(arg=='@')
			{
				Letter.Static_Map_UV(8,15,32,32);
			}
			else if(arg=='A')
			{
				Letter.Static_Map_UV(8,16,32,32);
			}
			else if(arg=='B')
			{
				Letter.Static_Map_UV(9,1,32,32);
			}
			else if(arg=='C')
			{
				Letter.Static_Map_UV(9,2,32,32);
			}
			else if(arg=='D')
			{
				Letter.Static_Map_UV(9,3,32,32);
			}
			else if(arg=='E')
			{
				Letter.Static_Map_UV(9,4,32,32);
			}
			else if(arg=='F')
			{
				Letter.Static_Map_UV(9,5,32,32);
			}
			else if(arg=='G')
			{
				Letter.Static_Map_UV(9,6,32,32);
			}
			else if(arg=='H')
			{
				Letter.Static_Map_UV(9,7,32,32);
			}
			else if(arg=='I')
			{
				Letter.Static_Map_UV(9,8,32,32);
			}
			else if(arg=='J')
			{
				Letter.Static_Map_UV(9,9,32,32);
			}
			else if(arg=='K')
			{
				Letter.Static_Map_UV(9,10,32,32);
			}
			else if(arg=='L')
			{
				Letter.Static_Map_UV(9,11,32,32);
			}
			else if(arg=='M')
			{
				Letter.Static_Map_UV(9,12,32,32);
			}
			else if(arg=='N')
			{
				Letter.Static_Map_UV(9,13,32,32);
			}
			else if(arg=='O')
			{
				Letter.Static_Map_UV(9,14,32,32);
			}
			else if(arg=='P')
			{
				Letter.Static_Map_UV(9,15,32,32);
			}
			else if(arg=='Q')
			{
				Letter.Static_Map_UV(9,16,32,32);
			}
			else if(arg=='R')
			{
				Letter.Static_Map_UV(10,1,32,32);
			}
			else if(arg=='S')
			{
				Letter.Static_Map_UV(10,2,32,32);
			}
			else if(arg=='T')
			{
				Letter.Static_Map_UV(10,3,32,32);
			}
			else if(arg=='U')
			{
				Letter.Static_Map_UV(10,4,32,32);
			}
			else if(arg=='V')
			{
				Letter.Static_Map_UV(10,5,32,32);
			}
			else if(arg=='W')
			{
				Letter.Static_Map_UV(10,6,32,32);
			}
			else if(arg=='X')
			{
				Letter.Static_Map_UV(10,7,32,32);
			}
			else if(arg=='Y')
			{
				Letter.Static_Map_UV(10,8,32,32);
			}
			else if(arg=='Z')
			{
				Letter.Static_Map_UV(10,9,32,32);
			}
			else if(arg=='[')
			{
				Letter.Static_Map_UV(10,10,32,32);
			}
			else if(arg=='\\')
			{
				Letter.Static_Map_UV(10,11,32,32);
			}
			else if(arg==']')
			{
				Letter.Static_Map_UV(10,12,32,32);
			}
			else if(arg=='^')
			{
				Letter.Static_Map_UV(10,13,32,32);
			}
			else if(arg=='_')
			{
				Letter.Static_Map_UV(10,14,32,32);
			}
			else if(arg=='`')
			{
				Letter.Static_Map_UV(10,15,32,32);
			}
			else if(arg=='a')
			{
				Letter.Static_Map_UV(10,16,32,32);
			}
			else if(arg=='b')
			{
				Letter.Static_Map_UV(11,1,32,32);
			}
			else if(arg=='c')
			{
				Letter.Static_Map_UV(11,2,32,32);
			}
			else if(arg=='d')
			{
				Letter.Static_Map_UV(11,3,32,32);
			}
			else if(arg=='e')
			{
				Letter.Static_Map_UV(11,4,32,32);
			}
			else if(arg=='f')
			{
				Letter.Static_Map_UV(11,5,32,32);
			}
			else if(arg=='g')
			{
				Letter.Static_Map_UV(11,6,32,32);
			}
			else if(arg=='h')
			{
				Letter.Static_Map_UV(11,7,32,32);
			}
			else if(arg=='i')
			{
				Letter.Static_Map_UV(11,8,32,32);
			}
			else if(arg=='j')
			{
				Letter.Static_Map_UV(11,9,32,32);
			}
			else if(arg=='k')
			{
				Letter.Static_Map_UV(11,10,32,32);
			}
			else if(arg=='l')
			{
				Letter.Static_Map_UV(11,11,32,32);
			}
			else if(arg=='m')
			{
				Letter.Static_Map_UV(11,12,32,32);
			}
			else if(arg=='n')
			{
				Letter.Static_Map_UV(11,13,32,32);
			}
			else if(arg=='o')
			{
				Letter.Static_Map_UV(11,14,32,32);
			}
			else if(arg=='p')
			{
				Letter.Static_Map_UV(11,15,32,32);
			}
			else if(arg=='q')
			{
				Letter.Static_Map_UV(11,16,32,32);
			}
			else if(arg=='r')
			{
				Letter.Static_Map_UV(12,1,32,32);
			}
			else if(arg=='s')
			{
				Letter.Static_Map_UV(12,2,32,32);
			}
			else if(arg=='t')
			{
				Letter.Static_Map_UV(12,3,32,32);
			}
			else if(arg=='u')
			{
				Letter.Static_Map_UV(12,4,32,32);
			}
			else if(arg=='V')
			{
				Letter.Static_Map_UV(12,5,32,32);
			}
			else if(arg=='w')
			{
				Letter.Static_Map_UV(12,6,32,32);
			}
			else if(arg=='x')
			{
				Letter.Static_Map_UV(12,7,32,32);
			}
			else if(arg=='y')
			{
				Letter.Static_Map_UV(12,8,32,32);
			}
			else if(arg=='z')
			{
				Letter.Static_Map_UV(12,9,32,32);
			}
			else if(arg=='{')
			{
				Letter.Static_Map_UV(12,10,32,32);
			}
			else if(arg=='|')
			{
				Letter.Static_Map_UV(12,11,32,32);
			}
			else if(arg=='}')
			{
				Letter.Static_Map_UV(12,12,32,32);
			}
			else if(arg=='~')
			{
				Letter.Static_Map_UV(12,13,32,32);
			}
			
			break;

		}
	}

}
//////////////////////////////////////////////////////////////////////////////////////////

bool TROG_TEXT::Large_PrintOnScreen(std::string arg, float x, float y,float z)
{

	//See how long our string is and how many bitmap letters we need.
	Large_numofLetters = arg.size();

	if(BMF)
	{
		delete[]BMF;
		BMF=NULL;
	}

	//Allocate the memory for them.
	BMF = new Sprite[Large_numofLetters];

	LargeFont.SetTex2Load("Resources/Demos/TROGricade/Textures/Large_TYPE_ALL.png");
	LargeFont.SetImageType(1);
	LargeFont.loadTexture();
	

	int count = 0;

	do
	{
		if(count==0)
		{
			BMF->OnSetTranslation(x,y,z);
		}

		//extract a single letter from the string
		char t = (char) arg[count];
		
		//Send it to be mapped.
		Large_MapFont(t,(*(BMF+count)));

		count++;
	}
	while(count < Large_numofLetters);

	return true;
}  