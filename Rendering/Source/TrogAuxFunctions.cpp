/*------------------------------------------------------------------------+
| This is the source file for various global functions that have no class |
| to call home. These functions simply perform simple useful tasks,       |
| for the Troglodyte game engine.                                         |
| Author : Will Canada (DecipherOne)                                      |
| (c) 2006-2011 DecipherOne Productions                                   |
+-------------------------------------------------------------------------*/


#include "PCHeader.h"

using namespace std;

 bool disMessage=true; //Used to quit if right color wasn't selected
 TrogAuxFunctions::TrogAuxFunctions()
 {
 }

 TrogAuxFunctions::~TrogAuxFunctions()
 {
 }

int TrogAuxFunctions::SetColor(string color)
{

	//Variable to make sure drawing color is in known range
	float a=0.12345; 
	
	
	//Transform color argument into all uppercase lettering;
	//in order to reduce the number of calls made to check 
	//for the argument.
	std::transform(color.begin(),color.end(),color.begin(),(int(*)(int)) toupper);

	//Different Whites

	if(color=="WHITE")               //White
	{
		glColor3f(1.0f,1.0f,1.0f);
		a=0.0;
	}

    else if(color=="ANTIQUE WHITE") //Anitque White
	{
		glColor3f(0.9804f,0.9216f,0.8431);
		a=0.0;
	}

	else if(color=="AZURE") //Azure
	{
		glColor3f(0.941f,1.0f,1.0f);
		a=0.0;
	}

	else if(color=="BISQUE") //Bisque
	{
		glColor3f(1.0f,0.8941f,0.7686f);
		a=0.0;
	}

	else if(color=="BLANCHED ALMOND") //Blanched Almond
	{
		glColor3f(1.0f,0.9216f,0.8039f);
		a=0.0;
	}

	else if(color=="CORNSILK") //Cornsilk
	{
		glColor3f(1.0f,0.9725f,0.8627f);
		a=0.0;
	}

	else if(color=="EGGSHELL") //Eggshell
	{
		glColor3f(0.9900f,0.9f,0.79f);
		a=0.0;
	}

	else if(color=="FLORAL WHITE") //floral white
	{
		glColor3f(1.0f,0.9804f,0.9412f);
		a=0.0;
	}

	else if(color=="GAINSBORO") //Gainsboro
	{
		glColor3f(0.8627f,0.8627f,0.8627f);
		a=0.0;
	}

	else if(color=="GHOST WHITE") //Ghost White
	{
		glColor3f(0.9725f,0.9725f,1.0f);
		a=0.0;
	}

	else if(color=="HONEYDEW") //HoneyDew
	{
		glColor3f(0.9412f,1.0f,0.9412f);
		a=0.0;
	}

	else if(color=="IVORY") //Ivory
	{
		glColor3f(1.0f,1.0f,0.9412f);
		a=0.0;
	}
	else if(color=="LAVENDER") //Lavender
	{
		glColor3f(0.902f,0.902f,0.9804f);
		a=0.0;
	}

	else if(color=="LAVENDER BLUSH") //Lavender Blush
	{
		glColor3f(1.0f,0.9412f,0.9608f);
		a=0.0;
	}

	else if(color=="LEMON CHIFFON") //Lemon Chiffon
	{
		glColor3f(1.0f,0.9804f,0.8039f);
		a=0.0;
	}

	else if(color=="LINEN") //Linen
	{
		glColor3f(0.9804f,0.9412f,0.902f);
		a=0.0;
	}

	else if(color=="MINT CREAM") //Mint Cream
	{
		glColor3f(0.9608f,1.0f,0.9804f);
		a=0.0;
	}

	else if(color=="MISTY ROSE") //Misty Rose
	{
		glColor3f(1.0f,0.8941f,0.8824f);
		a=0.0;
	}

	else if(color=="MOCCASIN") //Moccasin
	{
		glColor3f(1.0f,0.8941f,0.7098f);
		a=0.0;
	}

	else if(color=="NAVAJO WHITE") //Navajo White
	{
		glColor3f(1.0f,0.8706f,0.6784f);
		a=0.0;
	}

	else if(color=="OLD LACE") //Old Lace
	{
		glColor3f(0.9922f,0.9608f,0.9020f);
		a=0.0;
	}

	else if(color=="PAPAYA WHIP") //Papaya Whip
	{
		glColor3f(1.0f,0.9373f,0.8353f);
		a=0.0;
	}

	else if(color=="PEACH PUFF") //Peach Puff
	{
		glColor3f(1.0f,0.8549f,0.7255f);
		a=0.0;
	}

	else if(color=="SEASHELL") //Seashell
	{
		glColor3f(1.0f,0.9608f,0.9333f);
		a=0.0;
	}

	else if(color=="SNOW") //Snow
	{
		glColor3f(1.0f,0.9804f,0.9804f);
		a=0.0;
	}

	else if(color=="THISTLE") //Thistle
	{
		glColor3f(0.8471f,0.7490f,0.8471f);
		a=0.0;
	}

	else if(color=="TITANIUM WHITE")//Titanium white
	{
		glColor3f(0.99f,1.0f,0.94f);
		a=0.0;
	}

	else if(color=="WHEAT") //Wheat
	{
		glColor3f(0.9608f,0.8706f,0.702f);
		a=0.0;
	}

	else if(color=="WHITE SMOKE")//White Smoke
	{
		glColor3f(0.9608f,0.9608f,0.9608f);
		a=0.0;
	}

	else if(color=="ZINC WHITE") //Zinc White
	{
		glColor3f(0.99f,0.97f,1.0f);
		a=0.0;
	}


  //Different Greys

	if(color=="COLD GREY") //Cold Grey
	{
		glColor3f(0.5f,0.54f,0.53f);
		a=0.0;
	}

	else if(color=="DIM GREY") //Dim Grey
	{
		glColor3f(0.4118f,0.4118f,0.4118f);
		a=0.0;
	}

	else if(color=="GREY") //Grey
	{
		glColor3f(0.7529f,0.7529f,0.7529f);
		a=0.0;
	}

	else if(color=="LIGHT GREY") //Light Grey
	{
		glColor3f(0.8275f,0.8275f,0.8275f);
		a=0.0;
	}

	else if(color=="SLATE GREY") //Slate Grey
	{
		glColor3f(0.4392f,0.502f,0.5647f);
		a=0.0;
	}

	else if(color=="DARK SLATE GREY") //Dark slate grey
	{
		glColor3f(0.1843f,0.3098f,0.3098f);
		a=0.0;
	}

	else if(color=="LIGHT SLATE GREY")  //light slate grey
	{
		glColor3f(0.4667f,0.5333f,0.6f);
		a=0.0;
	}

	else if(color=="WARM GREY") //Warm Grey
	{
		glColor3f(0.5f,0.5f,0.41f);
		a=0.0;
	}

	//Blacks

	if (color=="BLACK")         //Black
	{
		glColor3f(0,0,0);
		a=0.0;
	}

	else if (color=="IVORY BLACK") //Ivory Black
	{
		glColor3f(0.16f,0.14f,0.13f);
		a=0.0;
	}

	else if (color=="LAMP BLACK") //Lamp Black
	{
		glColor3f(0.18f,0.28f,0.23f);
		a=0.0;
	}

	//Different Reds

	if(color=="RED")            //Red
	{
		glColor3f(1.0f,0.0f,0.0f);
		a=0.0;
	}

	else if(color=="ALIZARIN CRIMSON") //Alizarin Crimson
	{
		glColor3f(0.89f,0.15f,0.21f);
		a=0.0;
	}

	else if(color=="BRICK") //Brick
	{
		glColor3f(0.61f,0.4f,0.12f);
		a=0.0;
	}

	else if(color=="CADMIUM RED") //Cadmium Red
	{
		glColor3f(0.89f,0.09f,0.05f);
		a=0.0;
	}

	else if(color=="CORAL") //Coral
	{
		glColor3f(1.0f,0.498f,0.3137f);
		a=0.0;
	}

	else if(color=="LIGHT CORAL") //Light Coral
	{
		glColor3f(0.9412f,0.502f,0.502f);
		a=0.0;
	}

	else if(color=="DEEP PINK") //DEEP PINK
	{
		glColor3f(1.0f,0.0784f,0.5765f);
		a=0.0;
	}

	else if(color=="ENGLISH RED") //ENGLISH RED
	{
		glColor3f(0.83f,0.24f,0.1f);
		a=0.0;
	}

	else if(color=="FIREBRICK") //Firebrick
	{
		glColor3f(0.698f,0.1333f,0.1333f);
		a=0.0;
	}

	else if(color=="GERANIUM LAKE") //Geranium Lake
	{
		glColor3f(0.89f,0.07f,0.19f);
		a=0.0;
	}

	else if(color=="HOT PINK") //Hot Pink
	{
		glColor3f(1.0f,0.4118f,0.7059f);
		a=0.0;
	}

	else if(color=="INDIAN RED") //Indian Red
	{
		glColor3f(0.69f,0.09f,0.12f);
		a=0.0;
	}

	else if(color=="LIGHT SALMON") //Light Salmon
	{
		glColor3f(1.0f,0.6275f,0.4784f);
		a=0.0;
	}

	else if(color=="MADDER LAKE") //Madder lake deep
	{
		glColor3f(0.89f,0.18f,0.19f);
		a=0.0;
	}

	else if(color=="MAROON") //Maroon
	{
		glColor3f(0.6902f,0.1882f,0.3765f);
		a=0.0;
	}

	else if(color=="PINK") //Pink
	{
		glColor3f(1.0f,0.7529f,0.7961f);
		a=0.0;
	}

	else if(color=="LIGHT PINK") //Light Pink
	{
		glColor3f(1.0f,0.7137f,0.7569f);
		a=0.0;
	}

	else if(color=="RASPBERRY") //Raspberry
	{
		glColor3f(0.53f,0.15f,0.34f);
		a=0.0;
	}

	else if(color=="ROSE MADDER") //Rose Madder
	{
		glColor3f(0.89f,0.21f,0.22f);
		a=0.0;
	}

	else if(color=="SALMON") //Salmon
	{
		glColor3f(0.9804f,0.502f,0.4471f);
		a=0.0;
	}

	else if(color=="TOMATO") //Tomato
	{
		glColor3f(1.0f,0.3882f,0.2784f);
		a=0.0;
	}

	else if(color=="VENETIAN RED") //Venetian Red
	{
		glColor3f(0.83f,0.10f,0.12f);
		a=0.0;
	}

	//Different Browns

	if(color=="BEIGE") //Beige
	{
		glColor3f(0.64f,0.58f,0.5f);
		a=0.0;
	}

	else if(color=="BROWN") //Brown
	{
		glColor3f(0.5f,0.1647f,0.1647f);
		a=0.0;
	}

	else if(color=="BROWN MADDER") //Brown Madder
	{
		glColor3f(0.86f,0.16f,0.16f);
		a=0.0;
	}

	else if(color=="BROWN OCHRE") //Brown Ochre
	{
		glColor3f(0.53f,0.26f,0.12f);
		a=0.0;
	}

	else if(color=="BURLYWOOD") //Burlywood
	{
		glColor3f(0.8706f,0.7216f,0.5294f);
		a=0.0;
	}

	else if(color=="BURNT SIENNA") //Burnt Sienna
	{
		glColor3f(0.54f,0.21f,0.06f);
		a=0.0;
	}

	else if(color=="BURNT UMBER") //Burnt Umber
	{
		glColor3f(0.54f,0.2f,0.14f);
		a=0.0;
	}

	else if(color=="CHOCOLATE") //Chocolate
	{
		glColor3f(0.8235f,0.4118f,0.1176f);
		a=0.0;
	}

	else if(color=="DEEP OCHRE") //Deep Ochre
	{
		glColor3f(0.45f,0.24f,0.1f);
		a=0.0;
	}

	else if(color=="FLESH") //Flesh
	{
		glColor3f(1.0f,0.49f,0.25f);
		a=0.0;
	}

	else if(color=="FLESH OCHRE") //Flesh Ochre
	{
		glColor3f(1.0f,0.34f,0.13f);
		a=0.0;
	}

	else if(color=="GOLD OCHRE") //Gold Ochre
	{
		glColor3f(0.78f,0.47f,0.15f);
		a=0.0;
	}

	else if(color=="GREENISH UMBER") //Greenish Umber
	{
		glColor3f(1.0f,0.24f,0.05f);
		a=0.0;
	}

	else if(color=="KHAKI") //Khaki
	{
		glColor3f(0.9412f,0.902f,0.549f);
		a=0.0;
	}

	else if(color=="DARK KHAKI") //Dark Khaki
	{
		glColor3f(0.7412f,0.7176f,0.4196f);
		a=0.0;
	}

	else if(color=="LIGHT BEIGE") //Light Beige
	{
		glColor3f(0.9608f,0.9608f,0.8627f);
		a=0.0;
	}

	else if(color=="PERU") //Peru
	{
		glColor3f(0.8039f,0.5216f,0.2471f);
		a=0.0;
	}

	else if(color=="ROSY BROWN") //Rosy Brown
	{
		glColor3f(0.7373f,0.5608f,0.5608f);
		a=0.0;
	}

	else if(color=="RAW SIENNA") //Raw Sienna
	{
		glColor3f(0.78f,0.38f,0.08f);
		a=0.0;
	}

	else if(color=="RAW UMBER") //Raw Umber
	{
		glColor3f(0.45f,0.29f,0.07f);
		a=0.0;
	}

	else if(color=="SEPIA") //Sepia
	{
		glColor3f(0.37f,0.15f,0.07f);
		a=0.0;
	}

	else if(color=="SIENNA") //Sienna
	{
		glColor3f(0.6275f,0.3216f,0.1765f);
		a=0.0;
	}

	else if(color=="SADDLE BROWN") //Saddle Brown
	{
		glColor3f(0.5451f,0.2706f,0.0745f);
		a=0.0;
	}

	else if(color=="SANDY BROWN") //Sandy Brown
	{
		glColor3f(0.9569f,0.6431f,0.3765f);
		a=0.0;
	}

	else if(color=="TAN") //Tan
	{
		glColor3f(0.8235f,0.7059f,0.549f);
		a=0.0;
	}

	else if(color=="VANDYKE BROWN") //Van Dyke Brown
	{
		glColor3f(0.37f,0.15f,0.02f);
		a=0.0;
	}

	//Different Oranges

	if(color=="CADMIUM ORANGE") //Cadmium Orange
	{
		glColor3f(1.0f,0.38f,0.01f);
		a=0.0;
	}

	else if(color=="CADMIUM LIGHT RED") //Cadmium Light Red
	{
		glColor3f(1.0f,0.01f,0.05f);
		a=0.0;
	}

	else if(color=="CARROT") //Carrot
	{
		glColor3f(0.93f,0.57f,0.13f);
		a=0.0;
	}

	else if(color=="DARK ORANGE") //Dark Orange
	{
		glColor3f(1.0f,0.549f,0.0f);
		a=0.0;
	}

	else if(color=="MARS ORANGE") //Mars Orange
	{
		glColor3f(0.59f,0.27f,0.08f);
		a=0.0;
	}

	else if(color=="MARS YELLOW") //Mars Yellow
	{
		glColor3f(0.89f,0.44f,0.1f);
		a=0.0;
	}

	else if(color=="ORANGE") //Orange
	{
		glColor3f(1.0f,0.5f,0.0f);
		a=0.0;
	}

	else if(color=="ORANGE RED") //Orange Red
	{
		glColor3f(1.0f,0.2706f,0.0f);
		a=0.0;
	}

	else if(color=="YELLOW OCHRE") //Yellow OCHRE
	{
		glColor3f(0.89f,0.51f,0.09f);
		a=0.0;
	}

	//Different Yellows

	if(color=="AUREOLINE YELLOW") //Aureoline Yellow
	{
		glColor3f(1.0f,0.66f,0.14f);
		a=0.0;
	}

	else if(color=="BANANA") //BANANA
	{
		glColor3f(0.89f,0.81f,0.34f);
		a=0.0;
	}

	else if(color=="CADMIUM YELLOW") //Cadmium Yellow
	{
		glColor3f(1.0f,0.6f,0.07f);
		a=0.0;
	}

	else if(color=="CADMIUM LEMON") //Cadmium Lemon
	{
		glColor3f(1.0f,0.89f,0.01f);
		a=0.0;
	}

	else if(color=="GOLD") //Gold
	{
		glColor3f(1.0f,0.8431f,0.0f);
		a=0.0;
	}

	else if(color=="GOLDENROD") //Goldenrod
	{
		glColor3f(0.8549f,0.6471f,0.1255f);
		a=0.0;
	}

	else if(color=="DARK GOLDENROD") //Dark Goldenrod
	{
		glColor3f(0.7216f,0.5255f,0.0431f);
		a=0.0;
	}

	else if(color=="LIGHT GOLDENROD") //Light Goldenrod
	{
		glColor3f(0.9804f,0.9804f,0.8235f);
		a=0.0;
	}

	else if(color=="PALE GOLDENROD") //Pale Goldenrod
	{
		glColor3f(0.9333f,0.9098f,0.6667f);
		a=0.0;
	}

	else if(color=="VERYLIGHT GOLDENROD") //Verylight Goldenrod
	{
		glColor3f(0.9333f,0.8667f,0.5098f);
		a=0.0;
	}

	else if(color=="MELON") //Melon
	{
		glColor3f(0.89f,0.66f,0.41f);
		a=0.0;
	}

	else if(color=="NAPLESYELLOWDEEP") //Naplesyellowdeep
	{
		glColor3f(1.0f,0.66f,0.07f);
		a=0.0;
	}

	else if(color=="YELLOW") //Yellow
	{
		glColor3f(1.0f,1.0f,0.0f);
		a=0.0;
	}

	else if(color=="LIGHT YELLOW") //Light Yellow
	{
		glColor3f(1.0f,1.0f,0.8784f);
		a=0.0;
	}






	//Different Blues

	if(color=="BLUE")           //Blue
	{
		glColor3f(0.0f,0.0f,1.0f);
		a=0.0;
	}

	else if(color=="ALICE BLUE") //Alice Blue
	{
		glColor3f(0.9412f,0.9725f,1.0f);
		a=0.0;
	}

	else if(color=="LIGHT BLUE") //Light Blue
	{
		glColor3f(0.6784f,0.8471f,0.902f);
		a=0.0;
	}

	else if(color=="MEDIUM BLUE") //Medium Blue
	{
		glColor3f(0.0f,0.0f,0.8039f);
		a=0.0;
	}

	else if(color=="CADET") //Cadet
	{
		glColor3f(0.3725f,0.6196,0.6275f);
		a=0.0;
	}

	else if(color=="COBALT") //Cobalt
	{
		glColor3f(0.24f,0.35f,0.67f);
		a=0.0;
	}

	else if(color=="CORNFLOWER") //Cornflower
	{
		glColor3f(0.3922f,0.5843f,0.9294f);
		a=0.0;
	}

	else if(color=="CERULEAN") //Cerulean
	{
		glColor3f(0.02f,0.72f,0.3f);
		a=0.0;
	}

	else if(color=="DODGER BLUE") //Dodger Blue
	{
		glColor3f(0.1176f,0.5647f,1.0f);
		a=0.0;
	}

	else if(color=="INDIGO") //Indigo
	{
		glColor3f(0.03f,0.18f,0.33f);
		a=0.0;
	}

	else if(color=="MANGANESE BLUE") //Manganese Blue
	{
		glColor3f(0.01f,0.66f,0.62f);
		a=0.0;
	}

	else if(color=="MIDNIGHT BLUE") //Midnight Blue
	{
		glColor3f(0.098f,0.098f,0.4392f);
		a=0.0;
	}

	else if(color=="NAVY BLUE") // Navy Blue
	{
		glColor3f(0.0f,0.0f,0.502f);
		a=0.0;
	}

	else if(color=="PEACOCK BLUE") //Peacock blue
	{
		glColor3f(0.2f,0.63f,0.79f);
		a=0.0;
	}

	else if(color=="POWEDER BLUE") //Powder Blue
	{
		glColor3f(0.6902f,0.8784f,0.902f);
		a=0.0;
	}

	else if(color=="ROYAL BLUE") //Royal Blue
	{
		glColor3f(0.2549f,0.4118f,0.8824f);
		a=0.0;
	}

	else if(color=="SLATE BLUE") //Slate Blue
	{
		glColor3f(0.4157f,0.3592f,0.8039f);
		a=0.0;
	}

	else if(color=="DARK SLATE BLUE") //Dark Slate Blue
	{
		glColor3f(0.2824f,0.2392f,0.5451f);
		a=0.0;
	}

	else if(color=="LIGHT SLATE BLUE") //Light Slate Blue
	{
		glColor3f(0.5176f, 0.4392f,1.0f);
		a=0.0;
	}

	else if(color=="MEDIUM SLATE BLUE") //Medium Slate Blue
	{
		glColor3f(0.4824f,0.4078f,0.9333f);
		a=0.0;
	}

	else if(color=="SKY BLUE") //Sky Blue
	{
		glColor3f(0.5294f,0.8078f,0.9216f);
		a=0.0;
	}

	else if(color=="DEEP SKY BLUE") //Deep Sky Blue
	{
		glColor3f(0.0f,0.7490f,1.0f);
		a=0.0;
	}

	else if(color=="LIGHT SKY BLUE") //Light Sky Blue
	{
		glColor3f(0.5294f,0.8078f,0.9804f);
		a=0.0;
	}

	else if(color=="STEEL BLUE") //Steel Blue
	{
		glColor3f(0.2745f,0.5098f,0.7059f);
		a=0.0;
	}

	else if(color=="LIGHT STEEL BLUE") //Light Steel Blue
	{
		glColor3f(0.6902f,0.7686f,0.8706f);
		a=0.0;
	}
	
	else if(color=="TURQUOISE BLUE") //Turquoise Blue
	{
		glColor3f(0.0f,0.78f,0.55f);
		a=0.0;
	}

	else if(color=="ULTRAMARINE") //Ultramarine
	{
		glColor3f(0.07f,0.04f,0.56f);
		a=0.0;
	}



	//Different Greens

	if(color=="GREEN")          //Green
	{
		glColor3f(0.0f,1.0f,0.0f);
		a=0.0;
	}

	else if(color=="CHARTREUSE") //Chartreuse
	{
		glColor3f(0.498f,1.0f,0.0f);
		a=0.0;
	}

	else if(color=="CHROMEOXIDEGREEN")
	{
		glColor3f(0.4f,0.5f,0.08f);
		a=0.0;
	}

	else if(color=="CINNABAR GREEN") //Cinnabar Green
	{
		glColor3f(0.38f,0.7f,0.16f);
		a=0.0;
	}

	else if(color=="COBALT GREEN") //Cobalt Green
	{
		glColor3f(0.24f,0.57f,0.25f);
		a=0.0;
	}

	else if(color=="EMERALD GREEN") //Emerald Green
	{
		glColor3f(0.0f,0.79f,0.34f);
		a=0.0;
	}

	else if(color=="FOREST GREEN") //Forest Green
	{
		glColor3f(0.1333f,0.5451f,0.1333f);
		a=0.0;
	}

	else if(color=="DARK GREEN") //Dark Green
	{
		glColor3f(0.0f,0.3922f,0.0f);
		a=0.0;
	}

	else if(color=="PALE GREEN") //Pale Green
	{
		glColor3f(0.5961f,0.9843f,0.5961f);
		a=0.0;
	}

	else if(color=="GREEN YELLOW") //Green Yellow
	{
		glColor3f(0.6784f,1.0f,0.1843f);
		a=0.0;
	}

	else if(color=="LAWN GREEN") //Lawn Green
	{
		glColor3f(0.4863f,0.9882f,0.0f);
		a=0.0;
	}

	else if(color=="LIME GREEN") //Lime Green
	{
		glColor3f(0.1961f,0.8039f,0.1961f);
		a=0.0;
	}

	else if(color=="MINT") //Mint
	{
		glColor3f(0.74f,0.99f,0.79f);
		a=0.0;
	}

	else if(color=="OLIVE") //Olive
	{
		glColor3f(0.23f,0.37f,0.17f);
		a=0.0;
	}

	else if(color=="OLIVE DRAB") //Olive Drab
	{
		glColor3f(0.4196f,0.5569f,0.1373f);
		a=0.0;
	}

	else if(color=="DARK OLIVE GREEN") //Dark Olive Green
	{
		glColor3f(0.3333f,0.4196f,0.1843f);
		a=0.0;
	}

	else if(color=="PERMANENT GREEN") //Permanent Green
	{
		glColor3f(0.04f,0.79f,0.17f);
		a=0.0;
	}

	else if(color=="SAP GREEN") //Sap Green
	{
		glColor3f(0.19f,0.5f,0.08f);
		a=0.0;
	}

	else if(color=="SEA GREEN") //Sea Green
	{
		glColor3f(0.1804f,0.5451f,0.3412f);
		a=0.0;
	}

	else if(color=="DARK SEA GREEN") //Dark Sea Green
	{
		glColor3f(0.5608f,0.7373f,0.5608f);
		a=0.0;
	}

	else if(color=="MEDIUM SEA GREEN")//Medium Sea Green
	{
		glColor3f(0.2353f,0.7020f,0.4432f);
		a=0.0;
	}

	else if(color=="LIGHT SEA GREEN") //Light Sea Green
	{
		glColor3f(0.1255f,0.6980f,0.6667f);
		a=0.0;
	}

	else if(color=="SPRING GREEN") //Spring Green
	{
		glColor3f(0.0f,1.0f,0.4980f);
		a=0.0;
	}

	else if(color=="MEDIUM SPRING GREEN") //Medium Spring Green
	{
		glColor3f(0.0f,0.9804f,00.6039f);
		a=0.0;
	}

	else if(color=="TERRE VERTE") //Terre Verte
	{
		glColor3f(0.22f,0.37f,0.06f);
		a=0.0;
	}

	else if(color=="LIGHT VIRIDIAN") //Light Viridian
	{
		glColor3f(0.43f,1.0f,0.44f);
		a=0.0;
	}

	else if(color=="YELLOW GREEN") //Yellow Green
	{
		glColor3f(0.6039f,0.8039f,0.1961f);
		a=0.0;
	}

	//Different Cyans

	if(color=="AQUAMARINE") //Aquamarine
	{
		glColor3f(0.498f,1.0f,0.8314f);
		a=0.0;
	}

	else if(color=="MEDIUM AQUAMARINE") //Medium Aquamarine
	{
		glColor3f(0.4f,0.8039f,0.6667f);
		a=0.0;
	}

	else if(color=="CYAN") //Cyan
	{
		glColor3f(0.0f,1.0f,1.0f);
		a=0.0;
	}

	else if(color=="WHITE CYAN") //White Cyan
	{
		glColor3f(0.8784f,1.0f,1.0f);
		a=0.0;
	}

	else if(color=="TURQUOISE") //Turquoise
	{
		glColor3f(0.251f,0.8784f,0.8157f);
		a=0.0;
	}

	else if(color=="DARK TURQUOISE") //Dark Turquise
	{
		glColor3f(0.0f,0.8078f,0.8196f);
		a=0.0;
	}

	else if(color=="MEDIUM TURQUOISE")//Medium Turquise
	{
		glColor3f(0.2824f,0.8196f,0.8f);
		a=0.0;
	}

	else if(color=="PALE TURQUOISE") //PALE TURQUISE
	{
		glColor3f(0.6863f,0.9333f,0.9333f);
		a=0.0;
	}

	//Different Magentas

	if(color=="BLUE VIOLET") //Blue Violet
	{
		glColor3f(0.5412f,0.1686f,0.8863f);
		a=0.0;
	}

	else if(color=="DEEP COBALT VIOLET") //Deep Cobalt Violet
	{
		glColor3f(0.57f,0.13f,0.62f);
		a=0.0;
	}

	else if(color=="MAGENTA") //Magenta
	{
		glColor3f(1.0f,0.0f,1.0f);
		a=0.0;
	}

	else if(color=="ORCHID") //ORCHID
	{
		glColor3f(0.8549f,0.4392f,0.8392f);
		a=0.0;
	}

	else if(color=="DARK ORCHID") //Dark Orchid
	{
		glColor3f(0.6f,0.1961f,0.8f);
		a=0.0;
	}

	else if(color=="MEDIUM ORCHID") //Medium Orchid
	{
		glColor3f(0.7294f,0.3333f,0.8275f);
		a=0.0;
	}

	else if(color=="PERMANENT VIOLET") //Permanent Violet
	{
		glColor3f(0.86f,0.15f,0.27f);
		a=0.0;
	}

	else if(color=="PLUM") //PLUM
	{
		glColor3f(0.8667f,0.6275f,0.8667f);
		a=0.0;
	}

	else if(color=="PURPLE") //Purple
	{
		glColor3f(0.6275f,0.1255f,0.9412f);
		a=0.0;
	}

	else if(color=="MEDIUM PURPLE") //Medium Purple
	{
		glColor3f(0.5765f,0.4392f,0.8588f);
		a=0.0;
	}

	else if(color=="ULTRAMARINE VIOLET") //Ultramarine Violet
	{
		glColor3f(0.36f,0.14f,0.43f);
		a=0.0;
	}

	else if(color=="VIOLET") //Violet
	{
		glColor3f(0.56f,0.37f,0.6f);
		a=0.0;
	}

	else if(color=="DARK VIOLET") //Dark Violet
	{
		glColor3f(0.5804f,0.0f,0.8275f);
		a=0.0;
	}

	else if(color=="RED VIOLET") //Red Violet
	{
		glColor3f(0.8157f,0.1255f,0.5647f);
		a=0.0;
	}

	else if(color=="MEDIUM RED VIOLET") //Medium Red Violet
	{
		glColor3f(0.7804f,0.0824f,0.5216f);
		a=0.0;
	}

	else if(color=="PALE RED VIOLET") //Pale Red Violet
	{
		glColor3f(0.8588f,0.4392f,0.5765f);
		a=0.0;
	}

	if(a!=0.0&&disMessage==true)
	{
		if(MessageBox(NULL,"You've entered an incorrect string"
			" for the SetColor(string color) function. Would like to continue"
			" with the application and default the color to white?",
			"Drawing Error : Program Hault!",MB_YESNO)==IDNO)
		{
					PostQuitMessage(0);
		}

		else
		{
			disMessage=false;
			glColor3f(1.0f,1.0f,1.0f);
		}
	}

	


	//Add more colors

	return 0;
}


//////////////////////////////////////////////////////////////////////////////////


int TrogAuxFunctions::SetColor(int color)
{
	
	

	switch(color)
	{
		//Different Whites

		case 1:               //White
		{
			glColor3f(1.0f,1.0f,1.0f);
			break;
		}

		case 2: //Anitque White
		{
			glColor3f(0.9804f,0.9216f,0.8431);
			break;
		}

		case 3: //Azure
		{
			glColor3f(0.941f,1.0f,1.0f);
			break;
		}

		case 4: //Bisque
		{
			glColor3f(1.0f,0.8941f,0.7686f);
			break;
		}

		case 5: //Blanched Almond
		{
			glColor3f(1.0f,0.9216f,0.8039f);
			break;
		}

		case 6: //Cornsilk
		{
			glColor3f(1.0f,0.9725f,0.8627f);
			break;
		}

		case 7: //Eggshell
		{
			glColor3f(0.9900f,0.9f,0.79f);
			break;
		}

		case 8: //floral white
		{
			glColor3f(1.0f,0.9804f,0.9412f);
			break;
		}

		case 9: //Gainsboro
		{
			glColor3f(0.8627f,0.8627f,0.8627f);
			break;
		}

		case 10: //Ghost White
		{
			glColor3f(0.9725f,0.9725f,1.0f);
			break;
		}

		case 11: //HoneyDew
		{
			glColor3f(0.9412f,1.0f,0.9412f);
			break;
		}

		case 12: //Ivory
		{
			glColor3f(1.0f,1.0f,0.9412f);
			break;
		}
		case 13: //Lavender
		{
			glColor3f(0.902f,0.902f,0.9804f);
			break;
		}

		case 14: //Lavender Blush
		{
			glColor3f(1.0f,0.9412f,0.9608f);
			break;
		}

		case 15: //Lemon Chiffon
		{
			glColor3f(1.0f,0.9804f,0.8039f);
			break;
		}

		case 16: //Linen
		{
			glColor3f(0.9804f,0.9412f,0.902f);
			break;
		}

		case 17: //Mint Cream
		{
			glColor3f(0.9608f,1.0f,0.9804f);
			break;
		}

		case 18: //Misty Rose
		{
			glColor3f(1.0f,0.8941f,0.8824f);
			break;
		}

		case 19: //Moccasin
		{
			glColor3f(1.0f,0.8941f,0.7098f);
			break;
		}

		case 20: //Navajo White
		{
			glColor3f(1.0f,0.8706f,0.6784f);
			break;
		}

		case 21: //Old Lace
		{
			glColor3f(0.9922f,0.9608f,0.9020f);
			break;
		}

		case 22: //Papaya Whip
		{
			glColor3f(1.0f,0.9373f,0.8353f);
			break;
		}

		case 23: //Peach Puff
		{
			glColor3f(1.0f,0.8549f,0.7255f);
			break;
		}

		case 24: //Seashell
		{
			glColor3f(1.0f,0.9608f,0.9333f);
			break;
		}

		case 25: //Snow
		{
			glColor3f(1.0f,0.9804f,0.9804f);
			break;
		}

		case 26: //Thistle
		{
			glColor3f(0.8471f,0.7490f,0.8471f);
			break;
		}

		case 27: //Titanium white
		{
			glColor3f(0.99f,1.0f,0.94f);
			break;
		}

		case 28: //Wheat
		{
			glColor3f(0.9608f,0.8706f,0.702f);
			break;
		}

		case 29: //White Smoke
		{
			glColor3f(0.9608f,0.9608f,0.9608f);
			break;
		}

		case 30: //Zinc White
		{
			glColor3f(0.99f,0.97f,1.0f);
			break;
		}


	  //Different Greys

		case 31: //Cold Grey
		{
			glColor3f(0.5f,0.54f,0.53f);
			break;
		}

		case 32: //Dim Grey
		{
			glColor3f(0.4118f,0.4118f,0.4118f);
			break;
		}

		case 33: //Grey
		{
			glColor3f(0.7529f,0.7529f,0.7529f);
			break;
		}

		case 34: //Light Grey
		{
			glColor3f(0.8275f,0.8275f,0.8275f);
			break;
		}

		case 35: //Slate Grey
		{
			glColor3f(0.4392f,0.502f,0.5647f);
			break;
		}

		case 36: //Dark slate grey
		{
			glColor3f(0.1843f,0.3098f,0.3098f);
			break;
		}

		case 37:  //light slate grey
		{
			glColor3f(0.4667f,0.5333f,0.6f);
			break;
		}

		case 38: //Warm Grey
		{
			glColor3f(0.5f,0.5f,0.41f);
			break;
		}

		//Blacks

		case 39:         //Black
		{
			glColor3f(0.0f,0.0f,0.0f);
			break;
		}

		case 40: //Ivory Black
		{
			glColor3f(0.16f,0.14f,0.13f);
			break;
		}

		case 41: //Lamp Black
		{
			glColor3f(0.18f,0.28f,0.23f);
			break;
		}

		//Different Reds

		case 42:            //Red
		{
			glColor3f(1.0f,0.0f,0.0f);
			break;
		}

		case 43: //Alizarin Crimson
		{
			glColor3f(0.89f,0.15f,0.21f);
			break;
		}

		case 44: //Brick
		{
			glColor3f(0.61f,0.4f,0.12f);
			break;
		}

		case 45: //Cadmium Red
		{
			glColor3f(0.89f,0.09f,0.05f);
			break;
		}

		case 46: //Coral
		{
			glColor3f(1.0f,0.498f,0.3137f);
			break;
		}

		case 47: //Light Coral
		{
			glColor3f(0.9412f,0.502f,0.502f);
			break;
		}

		case 48: //DEEP PINK
		{
			glColor3f(1.0f,0.0784f,0.5765f);
			break;
		}

		case 49: //ENGLISH RED
		{
			glColor3f(0.83f,0.24f,0.1f);
			break;
		}

		case 50: //Firebrick
		{
			glColor3f(0.698f,0.1333f,0.1333f);
			break;
		}

		case 51: //Geranium Lake
		{
			glColor3f(0.89f,0.07f,0.19f);
			break;
		}

		case 52: //Hot Pink
		{
			glColor3f(1.0f,0.4118f,0.7059f);
			break;
		}

		case 53: //Indian Red
		{
			glColor3f(0.69f,0.09f,0.12f);
			break;
		}

		case 54: //Light Salmon
		{
			glColor3f(1.0f,0.6275f,0.4784f);
			break;
		}

		case 55: //Madder lake deep
		{
			glColor3f(0.89f,0.18f,0.19f);
			break;
		}

		case 56: //Maroon
		{
			glColor3f(0.6902f,0.1882f,0.3765f);
			break;
		}

		case 57: //Pink
		{
			glColor3f(1.0f,0.7529f,0.7961f);
			break;
		}

		case 58: //Light Pink
		{
			glColor3f(1.0f,0.7137f,0.7569f);
			break;
		}

		case 59: //Raspberry
		{
			glColor3f(0.53f,0.15f,0.34f);
			break;
		}

		case 60: //Rose Madder
		{
			glColor3f(0.89f,0.21f,0.22f);
			break;
		}

		case 61: //Salmon
		{
			glColor3f(0.9804f,0.502f,0.4471f);
			break;
		}

		case 62: //Tomato
		{
			glColor3f(1.0f,0.3882f,0.2784f);
			break;
		}

		case 63: //Venetian Red
		{
			glColor3f(0.83f,0.10f,0.12f);
			break;
		}

		//Different Browns

		case 64: //Beige
		{
			glColor3f(0.64f,0.58f,0.5f);
			break;
		}

		case 65: //Brown
		{
			glColor3f(0.5f,0.1647f,0.1647f);
			break;
		}

		case 66: //Brown Madder
		{
			glColor3f(0.86f,0.16f,0.16f);
			break;
		}

		case 67: //Brown Ochre
		{
			glColor3f(0.53f,0.26f,0.12f);
			break;
		}

		case 68: //Burlywood
		{
			glColor3f(0.8706f,0.7216f,0.5294f);
			break;
		}

		case 69: //Burnt Sienna
		{
			glColor3f(0.54f,0.21f,0.06f);
			break;
		}

		case 70: //Burnt Umber
		{
			glColor3f(0.54f,0.2f,0.14f);
			break;
		}

		case 71: //Chocolate
		{
			glColor3f(0.8235f,0.4118f,0.1176f);
			break;
		}

		case 72: //Deep Ochre
		{
			glColor3f(0.45f,0.24f,0.1f);
			break;
		}

		case 73: //Flesh
		{
			glColor3f(1.0f,0.49f,0.25f);
			break;
		}

		case 74: //Flesh Ochre
		{
			glColor3f(1.0f,0.34f,0.13f);
			break;
		}

		case 75: //Gold Ochre
		{
			glColor3f(0.78f,0.47f,0.15f);
			break;
		}

		case 76: //Greenish Umber
		{
			glColor3f(1.0f,0.24f,0.05f);
			break;
		}

		case 77: //Khaki
		{
			glColor3f(0.9412f,0.902f,0.549f);
			break;
		}

		case 78: //Dark Khaki
		{
			glColor3f(0.7412f,0.7176f,0.4196f);
			break;
		}

		case 79: //Light Beige
		{
			glColor3f(0.9608f,0.9608f,0.8627f);
			break;
		}

		case 80: //Peru
		{
			glColor3f(0.8039f,0.5216f,0.2471f);
			break;
		}

		case 81: //Rosy Brown
		{
			glColor3f(0.7373f,0.5608f,0.5608f);
			break;
		}

		case 82: //Raw Sienna
		{
			glColor3f(0.78f,0.38f,0.08f);
			break;
		}

		case 83: //Raw Umber
		{
			glColor3f(0.45f,0.29f,0.07f);
			break;
		}

		case 84: //Sepia
		{
			glColor3f(0.37f,0.15f,0.07f);
			break;
		}

		case 85: //Sienna
		{
			glColor3f(0.6275f,0.3216f,0.1765f);
			break;
		}

		case 86: //Saddle Brown
		{
			glColor3f(0.5451f,0.2706f,0.0745f);
			break;
		}

		case 87: //Sandy Brown
		{
			glColor3f(0.9569f,0.6431f,0.3765f);
			break;
		}

		case 88: //Tan
		{
			glColor3f(0.8235f,0.7059f,0.549f);
			break;
		}

		case 89: //Van Dyke Brown
		{
			glColor3f(0.37f,0.15f,0.02f);
			break;
		}

		//Different Oranges

		case 90: //Cadmium Orange
		{
			glColor3f(1.0f,0.38f,0.01f);
			break;
		}

		case 91: //Cadmium Light Red
		{
			glColor3f(1.0f,0.01f,0.05f);
			break;
		}

		case 92: //Carrot
		{
			glColor3f(0.93f,0.57f,0.13f);
			break;
		}

		case 93: //Dark Orange
		{
			glColor3f(1.0f,0.549f,0.0f);
			break;
		}

		case 94: //Mars Orange
		{
			glColor3f(0.59f,0.27f,0.08f);
			break;
		}

		case 95: //Mars Yellow
		{
			glColor3f(0.89f,0.44f,0.1f);
			break;
		}

		case 96://Orange
		{
			glColor3f(1.0f,0.5f,0.0f);
			break;
		}

		case 97: //Orange Red
		{
			glColor3f(1.0f,0.2706f,0.0f);
			break;
		}

		case 98: //Yellow OCHRE
		{
			glColor3f(0.89f,0.51f,0.09f);
			break;
		}

		//Different Yellows

		case 99: //Aureoline Yellow
		{
			glColor3f(1.0f,0.66f,0.14f);
			break;
		}

		case 100: //BANANA
		{
			glColor3f(0.89f,0.81f,0.34f);
			break;
		}

		case 101: //Cadmium Yellow
		{
			glColor3f(1.0f,0.6f,0.07f);
			break;
		}

		case 102: //Cadmium Lemon
		{
			glColor3f(1.0f,0.89f,0.01f);
			break;
		}

		case 103: //Gold
		{
			glColor3f(1.0f,0.8431f,0.0f);
			break;
		}

		case 104: //Goldenrod
		{
			glColor3f(0.8549f,0.6471f,0.1255f);
			break;
		}

		case 105: //Dark Goldenrod
		{
			glColor3f(0.7216f,0.5255f,0.0431f);
			break;
		}

		case 106: //Light Goldenrod
		{
			glColor3f(0.9804f,0.9804f,0.8235f);
			break;
		}

		case 107: //Pale Goldenrod
		{
			glColor3f(0.9333f,0.9098f,0.6667f);
			break;
		}

		case 108: //Verylight Goldenrod
		{
			glColor3f(0.9333f,0.8667f,0.5098f);
			break;
		}

		case 109: //Melon
		{
			glColor3f(0.89f,0.66f,0.41f);
			break;
		}

		case 110: //Naplesyellowdeep
		{
			glColor3f(1.0f,0.66f,0.07f);
			break;
		}

		case 111: //Yellow
		{
			glColor3f(1.0f,1.0f,0.0f);
			break;
		}

		case 112: //Light Yellow
		{
			glColor3f(1.0f,1.0f,0.8784f);
			break;
		}


		//Different Blues

		case 113:           //Blue
		{
			glColor3f(0.0f,0.0f,1.0f);
			break;
		}

		case 114: //Alice Blue
		{
			glColor3f(0.9412f,0.9725f,1.0f);
			break;
		}

		case 115: //Light Blue
		{
			glColor3f(0.6784f,0.8471f,0.902f);
			break;
		}

		case 116: //Medium Blue
		{
			glColor3f(0.0f,0.0f,0.8039f);
			break;
		}

		case 117: //Cadet
		{
			glColor3f(0.3725f,0.6196,0.6275f);
			break;
		}

		case 118: //Cobalt
		{
			glColor3f(0.24f,0.35f,0.67f);
			break;
		}

		case 119: //Cornflower
		{
			glColor3f(0.3922f,0.5843f,0.9294f);
			break;
		}

		case 120: //Cerulean
		{
			glColor3f(0.02f,0.72f,0.3f);
			break;
		}

		case 121: //Dodger Blue
		{
			glColor3f(0.1176f,0.5647f,1.0f);
			break;
		}

		case 122: //Indigo
		{
			glColor3f(0.03f,0.18f,0.33f);
			break;
		}

		case 123: //Manganese Blue
		{
			glColor3f(0.01f,0.66f,0.62f);
			break;
		}

		case 124: //Midnight Blue
		{
			glColor3f(0.098f,0.098f,0.4392f);
			break;
		}

		case 125: // Navy Blue
		{
			glColor3f(0.0f,0.0f,0.502f);
			break;
		}

		case 126: //Peacock blue
		{
			glColor3f(0.2f,0.63f,0.79f);
			break;
		}

		case 127: //Powder Blue
		{
			glColor3f(0.6902f,0.8784f,0.902f);
			break;
		}

		case 128: //Royal Blue
		{
			glColor3f(0.2549f,0.4118f,0.8824f);
			break;
		}

		case 129: //Slate Blue
		{
			glColor3f(0.4157f,0.3592f,0.8039f);
			break;
		}

		case 130: //Dark Slate Blue
		{
			glColor3f(0.2824f,0.2392f,0.5451f);
			break;
		}

		case 131: //Light Slate Blue
		{
			glColor3f(0.5176f, 0.4392f,1.0f);
			break;
		}

		case 132: //Medium Slate Blue
		{
			glColor3f(0.4824f,0.4078f,0.9333f);
			break;
		}

		case 133: //Sky Blue
		{
			glColor3f(0.5294f,0.8078f,0.9216f);
			break;
		}

		case 134: //Deep Sky Blue
		{
			glColor3f(0.0f,0.7490f,1.0f);
			break;
		}

		case 135: //Light Sky Blue
		{
			glColor3f(0.5294f,0.8078f,0.9804f);
			break;
		}

		case 136: //Steel Blue
		{
			glColor3f(0.2745f,0.5098f,0.7059f);
			break;
		}

		case 137: //Light Steel Blue
		{
			glColor3f(0.6902f,0.7686f,0.8706f);
			break;
		}
		
		case 138: //Turquoise Blue
		{
			glColor3f(0.0f,0.78f,0.55f);
			break;
		}

		case 139: //Ultramarine
		{
			glColor3f(0.07f,0.04f,0.56f);
			break;
		}





		//Different Greens

		case 140:         //Green
		{
			glColor3f(0.0f,1.0f,0.0f);
			break;
		}

		case 141: //Chartreuse
		{
			glColor3f(0.498f,1.0f,0.0f);
			break;
		}

		case 142: //Chromeoxidegreen
		{
			glColor3f(0.4f,0.5f,0.08f);
			break;
		}

		case 143: //Cinnabar Green
		{
			glColor3f(0.38f,0.7f,0.16f);
			break;
		}

		case 144: //Cobalt Green
		{
			glColor3f(0.24f,0.57f,0.25f);
			break;
		}

		case 145: //Emerald Green
		{
			glColor3f(0.0f,0.79f,0.34f);
			break;
		}

		case 146: //Forest Green
		{
			glColor3f(0.1333f,0.5451f,0.1333f);
			break;
		}

		case 147: //Dark Green
		{
			glColor3f(0.0f,0.3922f,0.0f);
			break;
		}

		case 148: //Pale Green
		{
			glColor3f(0.5961f,0.9843f,0.5961f);
			break;
		}

		case 149: //Green Yellow
		{
			glColor3f(0.6784f,1.0f,0.1843f);
			break;
		}

		case 150: //Lawn Green
		{
			glColor3f(0.4863f,0.9882f,0.0f);
			break;
		}

		case 151: //Lime Green
		{
			glColor3f(0.1961f,0.8039f,0.1961f);
			break;
		}

		case 152: //Mint
		{
			glColor3f(0.74f,0.99f,0.79f);
			break;
		}

		case 153: //Olive
		{
			glColor3f(0.23f,0.37f,0.17f);
			break;
		}

		case 154: //Olive Drab
		{
			glColor3f(0.4196f,0.5569f,0.1373f);
			break;
		}

		case 155: //Dark Olive Green
		{
			glColor3f(0.3333f,0.4196f,0.1843f);
			break;
		}

		case 156: //Permanent Green
		{
			glColor3f(0.04f,0.79f,0.17f);
			break;
		}

		case 157: //Sap Green
		{
			glColor3f(0.19f,0.5f,0.08f);
			break;
		}

		case 158: //Sea Green
		{
			glColor3f(0.1804f,0.5451f,0.3412f);
			break;
		}

		case 159: //Dark Sea Green
		{
			glColor3f(0.5608f,0.7373f,0.5608f);
			break;
		}

		case 160: //Medium Sea Green
		{
			glColor3f(0.2353f,0.7020f,0.4432f);
			break;
		}

		case 161: //Light Sea Green
		{
			glColor3f(0.1255f,0.6980f,0.6667f);
			break;
		}

		case 162: //Spring Green
		{
			glColor3f(0.0f,1.0f,0.4980f);
			break;
		}

		case 163: //Medium Spring Green
		{
			glColor3f(0.0f,0.9804f,00.6039f);
			break;
		}

		case 164: //Terre Verte
		{
			glColor3f(0.22f,0.37f,0.06f);
			break;
		}

		case 165: //Light Viridian
		{
			glColor3f(0.43f,1.0f,0.44f);
			break;
		}

		case 166: //Yellow Green
		{
			glColor3f(0.6039f,0.8039f,0.1961f);
			break;
		}

		//Different Cyans

		case 167: //Aquamarine
		{
			glColor3f(0.498f,1.0f,0.8314f);
			break;
		}

		case 168: //Medium Aquamarine
		{
			glColor3f(0.4f,0.8039f,0.6667f);
			break;
		}

		case 169: //Cyan
		{
			glColor3f(0.0f,1.0f,1.0f);
			break;
		}

		case 170: //White Cyan
		{
			glColor3f(0.8784f,1.0f,1.0f);
			break;
		}

		case 171: //Turquoise
		{
			glColor3f(0.251f,0.8784f,0.8157f);
			break;
		}

		case 172: //Dark Turquoise
		{
			glColor3f(0.0f,0.8078f,0.8196f);
			break;
		}

		case 173: //Medium Turquoise
		{
			glColor3f(0.2824f,0.8196f,0.8f);
			break;
		}

		case 174: //PALE TURQUISE
		{
			glColor3f(0.6863f,0.9333f,0.9333f);
			break;
		}

		//Different Magentas

		case 175: //Blue Violet
		{
			glColor3f(0.5412f,0.1686f,0.8863f);
			break;
		}

		case 176: //Deep Cobalt Violet
		{
			glColor3f(0.57f,0.13f,0.62f);
			break;
		}

		case 177: //Magenta
		{
			glColor3f(1.0f,0.0f,1.0f);
			break;
		}

		case 178: //ORCHID
		{
			glColor3f(0.8549f,0.4392f,0.8392f);
			break;
		}

		case 179: //Dark Orchid
		{
			glColor3f(0.6f,0.1961f,0.8f);
			break;
		}

		case 180: //Medium Orchid
		{
			glColor3f(0.7294f,0.3333f,0.8275f);
			break;
		}

		case 181: //Permanent Violet
		{
			glColor3f(0.86f,0.15f,0.27f);
			break;
		}

		case 182: //PLUM
		{
			glColor3f(0.8667f,0.6275f,0.8667f);
			break;
		}

		case 183: //Purple
		{
			glColor3f(0.6275f,0.1255f,0.9412f);
			break;
		}

		case 184: //Medium Purple
		{
			glColor3f(0.5765f,0.4392f,0.8588f);
			break;
		}

		case 185: //Ultramarine Violet
		{
			glColor3f(0.36f,0.14f,0.43f);
			break;
		}

		case 186: //Violet
		{
			glColor3f(0.56f,0.37f,0.6f);
			break;
		}

		case 187: //Dark Violet
		{
			glColor3f(0.5804f,0.0f,0.8275f);
			break;
		}

		case 188: //Red Violet
		{
			glColor3f(0.8157f,0.1255f,0.5647f);
			break;
		}

		case 189: //Medium Red Violet
		{
			glColor3f(0.7804f,0.0824f,0.5216f);
			break;
		}

		case 190: //Pale Red Violet
		{
			glColor3f(0.8588f,0.4392f,0.5765f);
			break;
		}

		default: //default to white
			{
				glColor3f(1.0f,1.0f,1.0f);
				break;
			}




	}

	//Add more colors

	return 0;
}


/////////////////////////////////////////////////////////////////////////////////
 

int TrogAuxFunctions::ColorSelect()
{
	
	int one;
	
		//Generate a number to pick the color
		one=rand () % 190 +1;
		SetColor(one);
	

	return 0;
}



/////////////////////////////////////////////////////////////////////////////////


int TrogAuxFunctions::SetBGColor(string color)
{

	//Variable to make sure drawing color is in known range
	float a=0.12345; 
	
	
	//Transform color argument into all uppercase lettering;
	//in order to reduce the number of calls made to check 
	//for the argument.
	transform(color.begin(),color.end(),color.begin(),(int(*)(int)) toupper);

	//Different Whites

	if(color=="WHITE")               //White
	{
		glClearColor(1.0f,1.0f,1.0f,0);
		a=0.0;
	}

    else if(color=="ANTIQUE WHITE") //Anitque White
	{
		glClearColor(0.9804f,0.9216f,0.8431l,0);
		a=0.0;
	}

	else if(color=="AZURE") //Azure
	{
		glClearColor(0.941f,1.0f,1.0f,0);
		a=0.0;
	}

	else if(color=="BISQUE") //Bisque
	{
		glClearColor(1.0f,0.8941f,0.7686f,0);
		a=0.0;
	}

	else if(color=="BLANCHED ALMOND") //Blanched Almond
	{
		glClearColor(1.0f,0.9216f,0.8039f,0);
		a=0.0;
	}

	else if(color=="CORNSILK") //Cornsilk
	{
		glClearColor(1.0f,0.9725f,0.8627f,0);
		a=0.0;
	}

	else if(color=="EGGSHELL") //Eggshell
	{
		glClearColor(0.9900f,0.9f,0.79f,0);
		a=0.0;
	}

	else if(color=="FLORAL WHITE") //floral white
	{
		glClearColor(1.0f,0.9804f,0.9412f,0);
		a=0.0;
	}

	else if(color=="GAINSBORO") //Gainsboro
	{
		glClearColor(0.8627f,0.8627f,0.8627f,0);
		a=0.0;
	}

	else if(color=="GHOST WHITE") //Ghost White
	{
		glClearColor(0.9725f,0.9725f,1.0f,0);
		a=0.0;
	}

	else if(color=="HONEYDEW") //HoneyDew
	{
		glClearColor(0.9412f,1.0f,0.9412f,0);
		a=0.0;
	}

	else if(color=="IVORY") //Ivory
	{
		glClearColor(1.0f,1.0f,0.9412f,0);
		a=0.0;
	}
	else if(color=="LAVENDER") //Lavender
	{
		glClearColor(0.902f,0.902f,0.9804f,0);
		a=0.0;
	}

	else if(color=="LAVENDER BLUSH") //Lavender Blush
	{
		glClearColor(1.0f,0.9412f,0.9608f,0);
		a=0.0;
	}

	else if(color=="LEMON CHIFFON") //Lemon Chiffon
	{
		glClearColor(1.0f,0.9804f,0.8039f,0);
		a=0.0;
	}

	else if(color=="LINEN") //Linen
	{
		glClearColor(0.9804f,0.9412f,0.902f,0);
		a=0.0;
	}

	else if(color=="MINT CREAM") //Mint Cream
	{
		glClearColor(0.9608f,1.0f,0.9804f,0);
		a=0.0;
	}

	else if(color=="MISTY ROSE") //Misty Rose
	{
		glClearColor(1.0f,0.8941f,0.8824f,0);
		a=0.0;
	}

	else if(color=="MOCCASIN") //Moccasin
	{
		glClearColor(1.0f,0.8941f,0.7098f,0);
		a=0.0;
	}

	else if(color=="NAVAJO WHITE") //Navajo White
	{
		glClearColor(1.0f,0.8706f,0.6784f,0);
		a=0.0;
	}

	else if(color=="OLD LACE") //Old Lace
	{
		glClearColor(0.9922f,0.9608f,0.9020f,0);
		a=0.0;
	}

	else if(color=="PAPAYA WHIP") //Papaya Whip
	{
		glClearColor(1.0f,0.9373f,0.8353f,0);
		a=0.0;
	}

	else if(color=="PEACH PUFF") //Peach Puff
	{
		glClearColor(1.0f,0.8549f,0.7255f,0);
		a=0.0;
	}

	else if(color=="SEASHELL") //Seashell
	{
		glClearColor(1.0f,0.9608f,0.9333f,0);
		a=0.0;
	}

	else if(color=="SNOW") //Snow
	{
		glClearColor(1.0f,0.9804f,0.9804f,0);
		a=0.0;
	}

	else if(color=="THISTLE") //Thistle
	{
		glClearColor(0.8471f,0.7490f,0.8471f,0);
		a=0.0;
	}

	else if(color=="TITANIUM WHITE")//Titanium white
	{
		glClearColor(0.99f,1.0f,0.94f,0);
		a=0.0;
	}

	else if(color=="WHEAT") //Wheat
	{
		glClearColor(0.9608f,0.8706f,0.702f,0);
		a=0.0;
	}

	else if(color=="WHITE SMOKE")//White Smoke
	{
		glClearColor(0.9608f,0.9608f,0.9608f,0);
		a=0.0;
	}

	else if(color=="ZINC WHITE") //Zinc White
	{
		glClearColor(0.99f,0.97f,1.0f,0);
		a=0.0;
	}


  //Different Greys

	if(color=="COLD GREY") //Cold Grey
	{
		glClearColor(0.5f,0.54f,0.53f,0);
		a=0.0;
	}

	else if(color=="DIM GREY") //Dim Grey
	{
		glClearColor(0.4118f,0.4118f,0.4118f,0);
		a=0.0;
	}

	else if(color=="GREY") //Grey
	{
		glClearColor(0.7529f,0.7529f,0.7529f,0);
		a=0.0;
	}

	else if(color=="LIGHT GREY") //Light Grey
	{
		glClearColor(0.8275f,0.8275f,0.8275f,0);
		a=0.0;
	}

	else if(color=="SLATE GREY") //Slate Grey
	{
		glClearColor(0.4392f,0.502f,0.5647f,0);
		a=0.0;
	}

	else if(color=="DARK SLATE GREY") //Dark slate grey
	{
		glClearColor(0.1843f,0.3098f,0.3098f,0);
		a=0.0;
	}

	else if(color=="LIGHT SLATE GREY")  //light slate grey
	{
		glClearColor(0.4667f,0.5333f,0.6f,0);
		a=0.0;
	}

	else if(color=="WARM GREY") //Warm Grey
	{
		glClearColor(0.5f,0.5f,0.41f,0);
		a=0.0;
	}

	//Blacks

	if (color=="BLACK")         //Black
	{
		glClearColor(0,0,0,0);
		a=0.0;
	}

	else if (color=="IVORY BLACK") //Ivory Black
	{
		glClearColor(0.16f,0.14f,0.13f,0);
		a=0.0;
	}

	else if (color=="LAMP BLACK") //Lamp Black
	{
		glClearColor(0.18f,0.28f,0.23f,0);
		a=0.0;
	}

	//Different Reds

	if(color=="RED")            //Red
	{
		glClearColor(1.0f,0.0f,0.0f,0);
		a=0.0;
	}

	else if(color=="ALIZARIN CRIMSON") //Alizarin Crimson
	{
		glClearColor(0.89f,0.15f,0.21f,0);
		a=0.0;
	}

	else if(color=="BRICK") //Brick
	{
		glClearColor(0.61f,0.4f,0.12f,0);
		a=0.0;
	}

	else if(color=="CADMIUM RED") //Cadmium Red
	{
		glClearColor(0.89f,0.09f,0.05f,0);
		a=0.0;
	}

	else if(color=="CORAL") //Coral
	{
		glClearColor(1.0f,0.498f,0.3137f,0);
		a=0.0;
	}

	else if(color=="LIGHT CORAL") //Light Coral
	{
		glClearColor(0.9412f,0.502f,0.502f,0);
		a=0.0;
	}

	else if(color=="DEEP PINK") //DEEP PINK
	{
		glClearColor(1.0f,0.0784f,0.5765f,0);
		a=0.0;
	}

	else if(color=="ENGLISH RED") //ENGLISH RED
	{
		glClearColor(0.83f,0.24f,0.1f,0);
		a=0.0;
	}

	else if(color=="FIREBRICK") //Firebrick
	{
		glClearColor(0.698f,0.1333f,0.1333f,0);
		a=0.0;
	}

	else if(color=="GERANIUM LAKE") //Geranium Lake
	{
		glClearColor(0.89f,0.07f,0.19f,0);
		a=0.0;
	}

	else if(color=="HOT PINK") //Hot Pink
	{
		glClearColor(1.0f,0.4118f,0.7059f,0);
		a=0.0;
	}

	else if(color=="INDIAN RED") //Indian Red
	{
		glClearColor(0.69f,0.09f,0.12f,0);
		a=0.0;
	}

	else if(color=="LIGHT SALMON") //Light Salmon
	{
		glClearColor(1.0f,0.6275f,0.4784f,0);
		a=0.0;
	}

	else if(color=="MADDER LAKE") //Madder lake deep
	{
		glClearColor(0.89f,0.18f,0.19f,0);
		a=0.0;
	}

	else if(color=="MAROON") //Maroon
	{
		glClearColor(0.6902f,0.1882f,0.3765f,0);
		a=0.0;
	}

	else if(color=="PINK") //Pink
	{
		glClearColor(1.0f,0.7529f,0.7961f,0);
		a=0.0;
	}

	else if(color=="LIGHT PINK") //Light Pink
	{
		glClearColor(1.0f,0.7137f,0.7569f,0);
		a=0.0;
	}

	else if(color=="RASPBERRY") //Raspberry
	{
		glClearColor(0.53f,0.15f,0.34f,0);
		a=0.0;
	}

	else if(color=="ROSE MADDER") //Rose Madder
	{
		glClearColor(0.89f,0.21f,0.22f,0);
		a=0.0;
	}

	else if(color=="SALMON") //Salmon
	{
		glClearColor(0.9804f,0.502f,0.4471f,0);
		a=0.0;
	}

	else if(color=="TOMATO") //Tomato
	{
		glClearColor(1.0f,0.3882f,0.2784f,0);
		a=0.0;
	}

	else if(color=="VENETIAN RED") //Venetian Red
	{
		glClearColor(0.83f,0.10f,0.12f,0);
		a=0.0;
	}

	//Different Browns

	if(color=="BEIGE") //Beige
	{
		glClearColor(0.64f,0.58f,0.5f,0);
		a=0.0;
	}

	else if(color=="BROWN") //Brown
	{
		glClearColor(0.5f,0.1647f,0.1647f,0);
		a=0.0;
	}

	else if(color=="BROWN MADDER") //Brown Madder
	{
		glClearColor(0.86f,0.16f,0.16f,0);
		a=0.0;
	}

	else if(color=="BROWN OCHRE") //Brown Ochre
	{
		glClearColor(0.53f,0.26f,0.12f,0);
		a=0.0;
	}

	else if(color=="BURLYWOOD") //Burlywood
	{
		glClearColor(0.8706f,0.7216f,0.5294f,0);
		a=0.0;
	}

	else if(color=="BURNT SIENNA") //Burnt Sienna
	{
		glClearColor(0.54f,0.21f,0.06f,0);
		a=0.0;
	}

	else if(color=="BURNT UMBER") //Burnt Umber
	{
		glClearColor(0.54f,0.2f,0.14f,0);
		a=0.0;
	}

	else if(color=="CHOCOLATE") //Chocolate
	{
		glClearColor(0.8235f,0.4118f,0.1176f,0);
		a=0.0;
	}

	else if(color=="DEEP OCHRE") //Deep Ochre
	{
		glClearColor(0.45f,0.24f,0.1f,0);
		a=0.0;
	}

	else if(color=="FLESH") //Flesh
	{
		glClearColor(1.0f,0.49f,0.25f,0);
		a=0.0;
	}

	else if(color=="FLESH OCHRE") //Flesh Ochre
	{
		glClearColor(1.0f,0.34f,0.13f,0);
		a=0.0;
	}

	else if(color=="GOLD OCHRE") //Gold Ochre
	{
		glClearColor(0.78f,0.47f,0.15f,0);
		a=0.0;
	}

	else if(color=="GREENISH UMBER") //Greenish Umber
	{
		glClearColor(1.0f,0.24f,0.05f,0);
		a=0.0;
	}

	else if(color=="KHAKI") //Khaki
	{
		glClearColor(0.9412f,0.902f,0.549f,0);
		a=0.0;
	}

	else if(color=="DARK KHAKI") //Dark Khaki
	{
		glClearColor(0.7412f,0.7176f,0.4196f,0);
		a=0.0;
	}

	else if(color=="LIGHT BEIGE") //Light Beige
	{
		glClearColor(0.9608f,0.9608f,0.8627f,0);
		a=0.0;
	}

	else if(color=="PERU") //Peru
	{
		glClearColor(0.8039f,0.5216f,0.2471f,0);
		a=0.0;
	}

	else if(color=="ROSY BROWN") //Rosy Brown
	{
		glClearColor(0.7373f,0.5608f,0.5608f,0);
		a=0.0;
	}

	else if(color=="RAW SIENNA") //Raw Sienna
	{
		glClearColor(0.78f,0.38f,0.08f,0);
		a=0.0;
	}

	else if(color=="RAW UMBER") //Raw Umber
	{
		glClearColor(0.45f,0.29f,0.07f,0);
		a=0.0;
	}

	else if(color=="SEPIA") //Sepia
	{
		glClearColor(0.37f,0.15f,0.07f,0);
		a=0.0;
	}

	else if(color=="SIENNA") //Sienna
	{
		glClearColor(0.6275f,0.3216f,0.1765f,0);
		a=0.0;
	}

	else if(color=="SADDLE BROWN") //Saddle Brown
	{
		glClearColor(0.5451f,0.2706f,0.0745f,0);
		a=0.0;
	}

	else if(color=="SANDY BROWN") //Sandy Brown
	{
		glClearColor(0.9569f,0.6431f,0.3765f,0);
		a=0.0;
	}

	else if(color=="TAN") //Tan
	{
		glClearColor(0.8235f,0.7059f,0.549f,0);
		a=0.0;
	}

	else if(color=="VANDYKE BROWN") //Van Dyke Brown
	{
		glClearColor(0.37f,0.15f,0.02f,0);
		a=0.0;
	}

	//Different Oranges

	if(color=="CADMIUM ORANGE") //Cadmium Orange
	{
		glClearColor(1.0f,0.38f,0.01f,0);
		a=0.0;
	}

	else if(color=="CADMIUM LIGHT RED") //Cadmium Light Red
	{
		glClearColor(1.0f,0.01f,0.05f,0);
		a=0.0;
	}

	else if(color=="CARROT") //Carrot
	{
		glClearColor(0.93f,0.57f,0.13f,0);
		a=0.0;
	}

	else if(color=="DARK ORANGE") //Dark Orange
	{
		glClearColor(1.0f,0.549f,0.0f,0);
		a=0.0;
	}

	else if(color=="MARS ORANGE") //Mars Orange
	{
		glClearColor(0.59f,0.27f,0.08f,0);
		a=0.0;
	}

	else if(color=="MARS YELLOW") //Mars Yellow
	{
		glClearColor(0.89f,0.44f,0.1f,0);
		a=0.0;
	}

	else if(color=="ORANGE") //Orange
	{
		glClearColor(1.0f,0.5f,0.0f,0);
		a=0.0;
	}

	else if(color=="ORANGE RED") //Orange Red
	{
		glClearColor(1.0f,0.2706f,0.0f,0);
		a=0.0;
	}

	else if(color=="YELLOW OCHRE") //Yellow OCHRE
	{
		glClearColor(0.89f,0.51f,0.09f,0);
		a=0.0;
	}

	//Different Yellows

	if(color=="AUREOLINE YELLOW") //Aureoline Yellow
	{
		glClearColor(1.0f,0.66f,0.14f,0);
		a=0.0;
	}

	else if(color=="BANANA") //BANANA
	{
		glClearColor(0.89f,0.81f,0.34f,0);
		a=0.0;
	}

	else if(color=="CADMIUM YELLOW") //Cadmium Yellow
	{
		glClearColor(1.0f,0.6f,0.07f,0);
		a=0.0;
	}

	else if(color=="CADMIUM LEMON") //Cadmium Lemon
	{
		glClearColor(1.0f,0.89f,0.01f,0);
		a=0.0;
	}

	else if(color=="GOLD") //Gold
	{
		glClearColor(1.0f,0.8431f,0.0f,0);
		a=0.0;
	}

	else if(color=="GOLDENROD") //Goldenrod
	{
		glClearColor(0.8549f,0.6471f,0.1255f,0);
		a=0.0;
	}

	else if(color=="DARK GOLDENROD") //Dark Goldenrod
	{
		glClearColor(0.7216f,0.5255f,0.0431f,0);
		a=0.0;
	}

	else if(color=="LIGHT GOLDENROD") //Light Goldenrod
	{
		glClearColor(0.9804f,0.9804f,0.8235f,0);
		a=0.0;
	}

	else if(color=="PALE GOLDENROD") //Pale Goldenrod
	{
		glClearColor(0.9333f,0.9098f,0.6667f,0);
		a=0.0;
	}

	else if(color=="VERYLIGHT GOLDENROD") //Verylight Goldenrod
	{
		glClearColor(0.9333f,0.8667f,0.5098f,0);
		a=0.0;
	}

	else if(color=="MELON") //Melon
	{
		glClearColor(0.89f,0.66f,0.41f,0);
		a=0.0;
	}

	else if(color=="NAPLESYELLOWDEEP") //Naplesyellowdeep
	{
		glClearColor(1.0f,0.66f,0.07f,0);
		a=0.0;
	}

	else if(color=="YELLOW") //Yellow
	{
		glClearColor(1.0f,1.0f,0.0f,0);
		a=0.0;
	}

	else if(color=="LIGHT YELLOW") //Light Yellow
	{
		glClearColor(1.0f,1.0f,0.8784f,0);
		a=0.0;
	}






	//Different Blues

	if(color=="BLUE")           //Blue
	{
		glClearColor(0.0f,0.0f,1.0f,0);
		a=0.0;
	}

	else if(color=="ALICE BLUE") //Alice Blue
	{
		glClearColor(0.9412f,0.9725f,1.0f,0);
		a=0.0;
	}

	else if(color=="LIGHT BLUE") //Light Blue
	{
		glClearColor(0.6784f,0.8471f,0.902f,0);
		a=0.0;
	}

	else if(color=="MEDIUM BLUE") //Medium Blue
	{
		glClearColor(0.0f,0.0f,0.8039f,0);
		a=0.0;
	}

	else if(color=="CADET") //Cadet
	{
		glClearColor(0.3725f,0.6196,0.6275f,0);
		a=0.0;
	}

	else if(color=="COBALT") //Cobalt
	{
		glClearColor(0.24f,0.35f,0.67f,0);
		a=0.0;
	}

	else if(color=="CORNFLOWER") //Cornflower
	{
		glClearColor(0.3922f,0.5843f,0.9294f,0);
		a=0.0;
	}

	else if(color=="CERULEAN") //Cerulean
	{
		glClearColor(0.02f,0.72f,0.3f,0);
		a=0.0;
	}

	else if(color=="DODGER BLUE") //Dodger Blue
	{
		glClearColor(0.1176f,0.5647f,1.0f,0);
		a=0.0;
	}

	else if(color=="INDIGO") //Indigo
	{
		glClearColor(0.03f,0.18f,0.33f,0);
		a=0.0;
	}

	else if(color=="MANGANESE BLUE") //Manganese Blue
	{
		glClearColor(0.01f,0.66f,0.62f,0);
		a=0.0;
	}

	else if(color=="MIDNIGHT BLUE") //Midnight Blue
	{
		glClearColor(0.098f,0.098f,0.4392f,0);
		a=0.0;
	}

	else if(color=="NAVY BLUE") // Navy Blue
	{
		glClearColor(0.0f,0.0f,0.502f,0);
		a=0.0;
	}

	else if(color=="PEACOCK BLUE") //Peacock blue
	{
		glClearColor(0.2f,0.63f,0.79f,0);
		a=0.0;
	}

	else if(color=="POWEDER BLUE") //Powder Blue
	{
		glClearColor(0.6902f,0.8784f,0.902f,0);
		a=0.0;
	}

	else if(color=="ROYAL BLUE") //Royal Blue
	{
		glClearColor(0.2549f,0.4118f,0.8824f,0);
		a=0.0;
	}

	else if(color=="SLATE BLUE") //Slate Blue
	{
		glClearColor(0.4157f,0.3592f,0.8039f,0);
		a=0.0;
	}

	else if(color=="DARK SLATE BLUE") //Dark Slate Blue
	{
		glClearColor(0.2824f,0.2392f,0.5451f,0);
		a=0.0;
	}

	else if(color=="LIGHT SLATE BLUE") //Light Slate Blue
	{
		glClearColor(0.5176f, 0.4392f,1.0f,0);
		a=0.0;
	}

	else if(color=="MEIUM SLATE BLUE") //Medium Slate Blue
	{
		glClearColor(0.4824f,0.4078f,0.9333f,0);
		a=0.0;
	}

	else if(color=="SKY BLUE") //Sky Blue
	{
		glClearColor(0.5294f,0.8078f,0.9216f,0);
		a=0.0;
	}

	else if(color=="DEEP SKY BLUE") //Deep Sky Blue
	{
		glClearColor(0.0f,0.7490f,1.0f,0);
		a=0.0;
	}

	else if(color=="LIGHT SKY BLUE") //Light Sky Blue
	{
		glClearColor(0.5294f,0.8078f,0.9804f,0);
		a=0.0;
	}

	else if(color=="STEEL BLUE") //Steel Blue
	{
		glClearColor(0.2745f,0.5098f,0.7059f,0);
		a=0.0;
	}

	else if(color=="LIGHT STEEL BLUE") //Light Steel Blue
	{
		glClearColor(0.6902f,0.7686f,0.8706f,0);
		a=0.0;
	}
	
	else if(color=="TURQUOISE BLUE") //Turquoise Blue
	{
		glClearColor(0.0f,0.78f,0.55f,0);
		a=0.0;
	}

	else if(color=="ULTRAMARINE") //Ultramarine
	{
		glClearColor(0.07f,0.04f,0.56f,0);
		a=0.0;
	}



	//Different Greens

	if(color=="GREEN")          //Green
	{
		glClearColor(0.0f,1.0f,0.0f,0);
		a=0.0;
	}

	else if(color=="CHARTREUSE") //Chartreuse
	{
		glClearColor(0.498f,1.0f,0.0f,0);
		a=0.0;
	}

	else if(color=="CHROMEOXIDEGREEN")
	{
		glClearColor(0.4f,0.5f,0.08f,0);
		a=0.0;
	}

	else if(color=="CINNABAR GREEN") //Cinnabar Green
	{
		glClearColor(0.38f,0.7f,0.16f,0);
		a=0.0;
	}

	else if(color=="COBALT GREEN") //Cobalt Green
	{
		glClearColor(0.24f,0.57f,0.25f,0);
		a=0.0;
	}

	else if(color=="EMERALD GREEN") //Emerald Green
	{
		glClearColor(0.0f,0.79f,0.34f,0);
		a=0.0;
	}

	else if(color=="FOREST GREEN") //Forest Green
	{
		glClearColor(0.1333f,0.5451f,0.1333f,0);
		a=0.0;
	}

	else if(color=="DARK GREEN") //Dark Green
	{
		glClearColor(0.0f,0.3922f,0.0f,0);
		a=0.0;
	}

	else if(color=="PALE GREEN") //Pale Green
	{
		glClearColor(0.5961f,0.9843f,0.5961f,0);
		a=0.0;
	}

	else if(color=="GREEN YELLOW") //Green Yellow
	{
		glClearColor(0.6784f,1.0f,0.1843f,0);
		a=0.0;
	}

	else if(color=="LAWN GREEN") //Lawn Green
	{
		glClearColor(0.4863f,0.9882f,0.0f,0);
		a=0.0;
	}

	else if(color=="LIME GREEN") //Lime Green
	{
		glClearColor(0.1961f,0.8039f,0.1961f,0);
		a=0.0;
	}

	else if(color=="MINT") //Mint
	{
		glClearColor(0.74f,0.99f,0.79f,0);
		a=0.0;
	}

	else if(color=="OLIVE") //Olive
	{
		glClearColor(0.23f,0.37f,0.17f,0);
		a=0.0;
	}

	else if(color=="OLIVE DRAB") //Olive Drab
	{
		glClearColor(0.4196f,0.5569f,0.1373f,0);
		a=0.0;
	}

	else if(color=="DARK OLIVE GREEN") //Dark Olive Green
	{
		glClearColor(0.3333f,0.4196f,0.1843f,0);
		a=0.0;
	}

	else if(color=="PERMANENT GREEN") //Permanent Green
	{
		glClearColor(0.04f,0.79f,0.17f,0);
		a=0.0;
	}

	else if(color=="SAP GREEN") //Sap Green
	{
		glClearColor(0.19f,0.5f,0.08f,0);
		a=0.0;
	}

	else if(color=="SEA GREEN") //Sea Green
	{
		glClearColor(0.1804f,0.5451f,0.3412f,0);
		a=0.0;
	}

	else if(color=="DARK SEA GREEN") //Dark Sea Green
	{
		glClearColor(0.5608f,0.7373f,0.5608f,0);
		a=0.0;
	}

	else if(color=="MEDIUM SEA GREEN")//Medium Sea Green
	{
		glClearColor(0.2353f,0.7020f,0.4432f,0);
		a=0.0;
	}

	else if(color=="LIGHT SEA GREEN") //Light Sea Green
	{
		glClearColor(0.1255f,0.6980f,0.6667f,0);
		a=0.0;
	}

	else if(color=="SPRING GREEN") //Spring Green
	{
		glClearColor(0.0f,1.0f,0.4980f,0);
		a=0.0;
	}

	else if(color=="MEDIUM SPRING GREEN") //Medium Spring Green
	{
		glClearColor(0.0f,0.9804f,00.6039f,0);
		a=0.0;
	}

	else if(color=="TERRE VERTE") //Terre Verte
	{
		glClearColor(0.22f,0.37f,0.06f,0);
		a=0.0;
	}

	else if(color=="LIGHT VIRIDIAN") //Light Viridian
	{
		glClearColor(0.43f,1.0f,0.44f,0);
		a=0.0;
	}

	else if(color=="YELLOW GREEN") //Yellow Green
	{
		glClearColor(0.6039f,0.8039f,0.1961f,0);
		a=0.0;
	}

	//Different Cyans

	if(color=="AQUAMARINE") //Aquamarine
	{
		glClearColor(0.498f,1.0f,0.8314f,0);
		a=0.0;
	}

	else if(color=="MEDIUM AQUAMARINE") //Medium Aquamarine
	{
		glClearColor(0.4f,0.8039f,0.6667f,0);
		a=0.0;
	}

	else if(color=="CYAN") //Cyan
	{
		glClearColor(0.0f,1.0f,1.0f,0);
		a=0.0;
	}

	else if(color=="WHITE CYAN") //White Cyan
	{
		glClearColor(0.8784f,1.0f,1.0f,0);
		a=0.0;
	}

	else if(color=="TURQUOISE") //Turquoise
	{
		glClearColor(0.251f,0.8784f,0.8157f,0);
		a=0.0;
	}

	else if(color=="DARK TURQUOISE") //Dark Turquise
	{
		glClearColor(0.0f,0.8078f,0.8196f,0);
		a=0.0;
	}

	else if(color=="MEDIUM TURQUOISE")//Medium Turquise
	{
		glClearColor(0.2824f,0.8196f,0.8f,0);
		a=0.0;
	}

	else if(color=="PALE TURQUOISE") //PALE TURQUISE
	{
		glClearColor(0.6863f,0.9333f,0.9333f,0);
		a=0.0;
	}

	//Different Magentas

	if(color=="BLUE VIOLET") //Blue Violet
	{
		glClearColor(0.5412f,0.1686f,0.8863f,0);
		a=0.0;
	}

	else if(color=="DEEP COBALT VIOLET") //Deep Cobalt Violet
	{
		glClearColor(0.57f,0.13f,0.62f,0);
		a=0.0;
	}

	else if(color=="MAGENTA") //Magenta
	{
		glClearColor(1.0f,0.0f,1.0f,0);
		a=0.0;
	}

	else if(color=="ORCHID") //ORCHID
	{
		glClearColor(0.8549f,0.4392f,0.8392f,0);
		a=0.0;
	}

	else if(color=="DARK ORCHID") //Dark Orchid
	{
		glClearColor(0.6f,0.1961f,0.8f,0);
		a=0.0;
	}

	else if(color=="MEDIUM ORCHID") //Medium Orchid
	{
		glClearColor(0.7294f,0.3333f,0.8275f,0);
		a=0.0;
	}

	else if(color=="PERMANENT VIOLET") //Permanent Violet
	{
		glClearColor(0.86f,0.15f,0.27f,0);
		a=0.0;
	}

	else if(color=="PLUM") //PLUM
	{
		glClearColor(0.8667f,0.6275f,0.8667f,0);
		a=0.0;
	}

	else if(color=="PURPLE") //Purple
	{
		glClearColor(0.6275f,0.1255f,0.9412f,0);
		a=0.0;
	}

	else if(color=="MEDIUM PURPLE") //Medium Purple
	{
		glClearColor(0.5765f,0.4392f,0.8588f,0);
		a=0.0;
	}

	else if(color=="ULTRAMARINE VIOLET") //Ultramarine Violet
	{
		glClearColor(0.36f,0.14f,0.43f,0);
		a=0.0;
	}

	else if(color=="VIOLET") //Violet
	{
		glClearColor(0.56f,0.37f,0.6f,0);
		a=0.0;
	}

	else if(color=="DARK VIOLET") //Dark Violet
	{
		glClearColor(0.5804f,0.0f,0.8275f,0);
		a=0.0;
	}

	else if(color=="RED VIOLET") //Red Violet
	{
		glClearColor(0.8157f,0.1255f,0.5647f,0);
		a=0.0;
	}

	else if(color=="MEDIUM RED VIOLET") //Medium Red Violet
	{
		glClearColor(0.7804f,0.0824f,0.5216f,0);
		a=0.0;
	}

	else if(color=="PALE RED VIOLET") //Pale Red Violet
	{
		glClearColor(0.8588f,0.4392f,0.5765f,0);
		a=0.0;
	}

	if(a!=0.0&&disMessage==true)
	{
		if(MessageBox(NULL,"You've entered an incorrect string"
			" for the SetColor(string color) function. Would like to continue"
			" with the application and default the color to white?",
			"Drawing Error : Program Hault!",MB_YESNO)==IDNO)
		{
					PostQuitMessage(0);
		}

		else
		{
			disMessage=false;
			glClearColor(1.0f,1.0f,1.0f,0);
		}
	}


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glLoadIdentity();

	


	//Add more colors

	return 0;
}



///////////////////////////////////////////////////////////////////////////////////

int TrogAuxFunctions::SetBGColor(int color)
{
	
	

	switch(color)
	{
		//Different Whites

		case 1:               //White
		{
			glClearColor(1.0f,1.0f,1.0f,0);
			break;
		}

		case 2: //Anitque White
		{
			glClearColor(0.9804f,0.9216f,0.8431,0);
			break;
		}

		case 3: //Azure
		{
			glClearColor(0.941f,1.0f,1.0f,0);
			break;
		}

		case 4: //Bisque
		{
			glClearColor(1.0f,0.8941f,0.7686f,0);
			break;
		}

		case 5: //Blanched Almond
		{
			glClearColor(1.0f,0.9216f,0.8039f,0);
			break;
		}

		case 6: //Cornsilk
		{
			glClearColor(1.0f,0.9725f,0.8627f,0);
			break;
		}

		case 7: //Eggshell
		{
			glClearColor(0.9900f,0.9f,0.79f,0);
			break;
		}

		case 8: //floral white
		{
			glClearColor(1.0f,0.9804f,0.9412f,0);
			break;
		}

		case 9: //Gainsboro
		{
			glClearColor(0.8627f,0.8627f,0.8627f,0);
			break;
		}

		case 10: //Ghost White
		{
			glClearColor(0.9725f,0.9725f,1.0f,0);
			break;
		}

		case 11: //HoneyDew
		{
			glClearColor(0.9412f,1.0f,0.9412f,0);
			break;
		}

		case 12: //Ivory
		{
			glClearColor(1.0f,1.0f,0.9412f,0);
			break;
		}
		case 13: //Lavender
		{
			glClearColor(0.902f,0.902f,0.9804f,0);
			break;
		}

		case 14: //Lavender Blush
		{
			glClearColor(1.0f,0.9412f,0.9608f,0);
			break;
		}

		case 15: //Lemon Chiffon
		{
			glClearColor(1.0f,0.9804f,0.8039f,0);
			break;
		}

		case 16: //Linen
		{
			glClearColor(0.9804f,0.9412f,0.902f,0);
			break;
		}

		case 17: //Mint Cream
		{
			glClearColor(0.9608f,1.0f,0.9804f,0);
			break;
		}

		case 18: //Misty Rose
		{
			glClearColor(1.0f,0.8941f,0.8824f,0);
			break;
		}

		case 19: //Moccasin
		{
			glClearColor(1.0f,0.8941f,0.7098f,0);
			break;
		}

		case 20: //Navajo White
		{
			glClearColor(1.0f,0.8706f,0.6784f,0);
			break;
		}

		case 21: //Old Lace
		{
			glClearColor(0.9922f,0.9608f,0.9020f,0);
			break;
		}

		case 22: //Papaya Whip
		{
			glClearColor(1.0f,0.9373f,0.8353f,0);
			break;
		}

		case 23: //Peach Puff
		{
			glClearColor(1.0f,0.8549f,0.7255f,0);
			break;
		}

		case 24: //Seashell
		{
			glClearColor(1.0f,0.9608f,0.9333f,0);
			break;
		}

		case 25: //Snow
		{
			glClearColor(1.0f,0.9804f,0.9804f,0);
			break;
		}

		case 26: //Thistle
		{
			glClearColor(0.8471f,0.7490f,0.8471f,0);
			break;
		}

		case 27: //Titanium white
		{
			glClearColor(0.99f,1.0f,0.94f,0);
			break;
		}

		case 28: //Wheat
		{
			glClearColor(0.9608f,0.8706f,0.702f,0);
			break;
		}

		case 29: //White Smoke
		{
			glClearColor(0.9608f,0.9608f,0.9608f,0);
			break;
		}

		case 30: //Zinc White
		{
			glClearColor(0.99f,0.97f,1.0f,0);
			break;
		}


	  //Different Greys

		case 31: //Cold Grey
		{
			glClearColor(0.5f,0.54f,0.53f,0);
			break;
		}

		case 32: //Dim Grey
		{
			glClearColor(0.4118f,0.4118f,0.4118f,0);
			break;
		}

		case 33: //Grey
		{
			glClearColor(0.7529f,0.7529f,0.7529f,0);
			break;
		}

		case 34: //Light Grey
		{
			glClearColor(0.8275f,0.8275f,0.8275f,0);
			break;
		}

		case 35: //Slate Grey
		{
			glClearColor(0.4392f,0.502f,0.5647f,0);
			break;
		}

		case 36: //Dark slate grey
		{
			glClearColor(0.1843f,0.3098f,0.3098f,0);
			break;
		}

		case 37:  //light slate grey
		{
			glClearColor(0.4667f,0.5333f,0.6f,0);
			break;
		}

		case 38: //Warm Grey
		{
			glClearColor(0.5f,0.5f,0.41f,0);
			break;
		}

		//Blacks

		case 39:         //Black
		{
			glClearColor(0,0,0,0);
			break;
		}

		case 40: //Ivory Black
		{
			glClearColor(0.16f,0.14f,0.13f,0);
			break;
		}

		case 41: //Lamp Black
		{
			glClearColor(0.18f,0.28f,0.23f,0);
			break;
		}

		//Different Reds

		case 42:            //Red
		{
			glClearColor(1.0f,0.0f,0.0f,0);
			break;
		}

		case 43: //Alizarin Crimson
		{
			glClearColor(0.89f,0.15f,0.21f,0);
			break;
		}

		case 44: //Brick
		{
			glClearColor(0.61f,0.4f,0.12f,0);
			break;
		}

		case 45: //Cadmium Red
		{
			glClearColor(0.89f,0.09f,0.05f,0);
			break;
		}

		case 46: //Coral
		{
			glClearColor(1.0f,0.498f,0.3137f,0);
			break;
		}

		case 47: //Light Coral
		{
			glClearColor(0.9412f,0.502f,0.502f,0);
			break;
		}

		case 48: //DEEP PINK
		{
			glClearColor(1.0f,0.0784f,0.5765f,0);
			break;
		}

		case 49: //ENGLISH RED
		{
			glClearColor(0.83f,0.24f,0.1f,0);
			break;
		}

		case 50: //Firebrick
		{
			glClearColor(0.698f,0.1333f,0.1333f,0);
			break;
		}

		case 51: //Geranium Lake
		{
			glClearColor(0.89f,0.07f,0.19f,0);
			break;
		}

		case 52: //Hot Pink
		{
			glClearColor(1.0f,0.4118f,0.7059f,0);
			break;
		}

		case 53: //Indian Red
		{
			glClearColor(0.69f,0.09f,0.12f,0);
			break;
		}

		case 54: //Light Salmon
		{
			glClearColor(1.0f,0.6275f,0.4784f,0);
			break;
		}

		case 55: //Madder lake deep
		{
			glClearColor(0.89f,0.18f,0.19f,0);
			break;
		}

		case 56: //Maroon
		{
			glClearColor(0.6902f,0.1882f,0.3765f,0);
			break;
		}

		case 57: //Pink
		{
			glClearColor(1.0f,0.7529f,0.7961f,0);
			break;
		}

		case 58: //Light Pink
		{
			glClearColor(1.0f,0.7137f,0.7569f,0);
			break;
		}

		case 59: //Raspberry
		{
			glClearColor(0.53f,0.15f,0.34f,0);
			break;
		}

		case 60: //Rose Madder
		{
			glClearColor(0.89f,0.21f,0.22f,0);
			break;
		}

		case 61: //Salmon
		{
			glClearColor(0.9804f,0.502f,0.4471f,0);
			break;
		}

		case 62: //Tomato
		{
			glClearColor(1.0f,0.3882f,0.2784f,0);
			break;
		}

		case 63: //Venetian Red
		{
			glClearColor(0.83f,0.10f,0.12f,0);
			break;
		}

		//Different Browns

		case 64: //Beige
		{
			glClearColor(0.64f,0.58f,0.5f,0);
			break;
		}

		case 65: //Brown
		{
			glClearColor(0.5f,0.1647f,0.1647f,0);
			break;
		}

		case 66: //Brown Madder
		{
			glClearColor(0.86f,0.16f,0.16f,0);
			break;
		}

		case 67: //Brown Ochre
		{
			glClearColor(0.53f,0.26f,0.12f,0);
			break;
		}

		case 68: //Burlywood
		{
			glClearColor(0.8706f,0.7216f,0.5294f,0);
			break;
		}

		case 69: //Burnt Sienna
		{
			glClearColor(0.54f,0.21f,0.06f,0);
			break;
		}

		case 70: //Burnt Umber
		{
			glClearColor(0.54f,0.2f,0.14f,0);
			break;
		}

		case 71: //Chocolate
		{
			glClearColor(0.8235f,0.4118f,0.1176f,0);
			break;
		}

		case 72: //Deep Ochre
		{
			glClearColor(0.45f,0.24f,0.1f,0);
			break;
		}

		case 73: //Flesh
		{
			glClearColor(1.0f,0.49f,0.25f,0);
			break;
		}

		case 74: //Flesh Ochre
		{
			glClearColor(1.0f,0.34f,0.13f,0);
			break;
		}

		case 75: //Gold Ochre
		{
			glClearColor(0.78f,0.47f,0.15f,0);
			break;
		}

		case 76: //Greenish Umber
		{
			glClearColor(1.0f,0.24f,0.05f,0);
			break;
		}

		case 77: //Khaki
		{
			glClearColor(0.9412f,0.902f,0.549f,0);
			break;
		}

		case 78: //Dark Khaki
		{
			glClearColor(0.7412f,0.7176f,0.4196f,0);
			break;
		}

		case 79: //Light Beige
		{
			glClearColor(0.9608f,0.9608f,0.8627f,0);
			break;
		}

		case 80: //Peru
		{
			glClearColor(0.8039f,0.5216f,0.2471f,0);
			break;
		}

		case 81: //Rosy Brown
		{
			glClearColor(0.7373f,0.5608f,0.5608f,0);
			break;
		}

		case 82: //Raw Sienna
		{
			glClearColor(0.78f,0.38f,0.08f,0);
			break;
		}

		case 83: //Raw Umber
		{
			glClearColor(0.45f,0.29f,0.07f,0);
			break;
		}

		case 84: //Sepia
		{
			glClearColor(0.37f,0.15f,0.07f,0);
			break;
		}

		case 85: //Sienna
		{
			glClearColor(0.6275f,0.3216f,0.1765f,0);
			break;
		}

		case 86: //Saddle Brown
		{
			glClearColor(0.5451f,0.2706f,0.0745f,0);
			break;
		}

		case 87: //Sandy Brown
		{
			glClearColor(0.9569f,0.6431f,0.3765f,0);
			break;
		}

		case 88: //Tan
		{
			glClearColor(0.8235f,0.7059f,0.549f,0);
			break;
		}

		case 89: //Van Dyke Brown
		{
			glClearColor(0.37f,0.15f,0.02f,0);
			break;
		}

		//Different Oranges

		case 90: //Cadmium Orange
		{
			glClearColor(1.0f,0.38f,0.01f,0);
			break;
		}

		case 91: //Cadmium Light Red
		{
			glClearColor(1.0f,0.01f,0.05f,0);
			break;
		}

		case 92: //Carrot
		{
			glClearColor(0.93f,0.57f,0.13f,0);
			break;
		}

		case 93: //Dark Orange
		{
			glClearColor(1.0f,0.549f,0.0f,0);
			break;
		}

		case 94: //Mars Orange
		{
			glClearColor(0.59f,0.27f,0.08f,0);
			break;
		}

		case 95: //Mars Yellow
		{
			glClearColor(0.89f,0.44f,0.1f,0);
			break;
		}

		case 96://Orange
		{
			glClearColor(1.0f,0.5f,0.0f,0);
			break;
		}

		case 97: //Orange Red
		{
			glClearColor(1.0f,0.2706f,0.0f,0);
			break;
		}

		case 98: //Yellow OCHRE
		{
			glClearColor(0.89f,0.51f,0.09f,0);
			break;
		}

		//Different Yellows

		case 99: //Aureoline Yellow
		{
			glClearColor(1.0f,0.66f,0.14f,0);
			break;
		}

		case 100: //BANANA
		{
			glClearColor(0.89f,0.81f,0.34f,0);
			break;
		}

		case 101: //Cadmium Yellow
		{
			glClearColor(1.0f,0.6f,0.07f,0);
			break;
		}

		case 102: //Cadmium Lemon
		{
			glClearColor(1.0f,0.89f,0.01f,0);
			break;
		}

		case 103: //Gold
		{
			glClearColor(1.0f,0.8431f,0.0f,0);
			break;
		}

		case 104: //Goldenrod
		{
			glClearColor(0.8549f,0.6471f,0.1255f,0);
			break;
		}

		case 105: //Dark Goldenrod
		{
			glClearColor(0.7216f,0.5255f,0.0431f,0);
			break;
		}

		case 106: //Light Goldenrod
		{
			glClearColor(0.9804f,0.9804f,0.8235f,0);
			break;
		}

		case 107: //Pale Goldenrod
		{
			glClearColor(0.9333f,0.9098f,0.6667f,0);
			break;
		}

		case 108: //Verylight Goldenrod
		{
			glClearColor(0.9333f,0.8667f,0.5098f,0);
			break;
		}

		case 109: //Melon
		{
			glClearColor(0.89f,0.66f,0.41f,0);
			break;
		}

		case 110: //Naplesyellowdeep
		{
			glClearColor(1.0f,0.66f,0.07f,0);
			break;
		}

		case 111: //Yellow
		{
			glClearColor(1.0f,1.0f,0.0f,0);
			break;
		}

		case 112: //Light Yellow
		{
			glClearColor(1.0f,1.0f,0.8784f,0);
			break;
		}


		//Different Blues

		case 113:           //Blue
		{
			glClearColor(0.0f,0.0f,1.0f,0);
			break;
		}

		case 114: //Alice Blue
		{
			glClearColor(0.9412f,0.9725f,1.0f,0);
			break;
		}

		case 115: //Light Blue
		{
			glClearColor(0.6784f,0.8471f,0.902f,0);
			break;
		}

		case 116: //Medium Blue
		{
			glClearColor(0.0f,0.0f,0.8039f,0);
			break;
		}

		case 117: //Cadet
		{
			glClearColor(0.3725f,0.6196,0.6275f,0);
			break;
		}

		case 118: //Cobalt
		{
			glClearColor(0.24f,0.35f,0.67f,0);
			break;
		}

		case 119: //Cornflower
		{
			glClearColor(0.3922f,0.5843f,0.9294f,0);
			break;
		}

		case 120: //Cerulean
		{
			glClearColor(0.02f,0.72f,0.3f,0);
			break;
		}

		case 121: //Dodger Blue
		{
			glClearColor(0.1176f,0.5647f,1.0f,0);
			break;
		}

		case 122: //Indigo
		{
			glClearColor(0.03f,0.18f,0.33f,0);
			break;
		}

		case 123: //Manganese Blue
		{
			glClearColor(0.01f,0.66f,0.62f,0);
			break;
		}

		case 124: //Midnight Blue
		{
			glClearColor(0.098f,0.098f,0.4392f,0);
			break;
		}

		case 125: // Navy Blue
		{
			glClearColor(0.0f,0.0f,0.502f,0);
			break;
		}

		case 126: //Peacock blue
		{
			glClearColor(0.2f,0.63f,0.79f,0);
			break;
		}

		case 127: //Powder Blue
		{
			glClearColor(0.6902f,0.8784f,0.902f,0);
			break;
		}

		case 128: //Royal Blue
		{
			glClearColor(0.2549f,0.4118f,0.8824f,0);
			break;
		}

		case 129: //Slate Blue
		{
			glClearColor(0.4157f,0.3592f,0.8039f,0);
			break;
		}

		case 130: //Dark Slate Blue
		{
			glClearColor(0.2824f,0.2392f,0.5451f,0);
			break;
		}

		case 131: //Light Slate Blue
		{
			glClearColor(0.5176f, 0.4392f,1.0f,0);
			break;
		}

		case 132: //Medium Slate Blue
		{
			glClearColor(0.4824f,0.4078f,0.9333f,0);
			break;
		}

		case 133: //Sky Blue
		{
			glClearColor(0.5294f,0.8078f,0.9216f,0);
			break;
		}

		case 134: //Deep Sky Blue
		{
			glClearColor(0.0f,0.7490f,1.0f,0);
			break;
		}

		case 135: //Light Sky Blue
		{
			glClearColor(0.5294f,0.8078f,0.9804f,0);
			break;
		}

		case 136: //Steel Blue
		{
			glClearColor(0.2745f,0.5098f,0.7059f,0);
			break;
		}

		case 137: //Light Steel Blue
		{
			glClearColor(0.6902f,0.7686f,0.8706f,0);
			break;
		}
		
		case 138: //Turquoise Blue
		{
			glClearColor(0.0f,0.78f,0.55f,0);
			break;
		}

		case 139: //Ultramarine
		{
			glClearColor(0.07f,0.04f,0.56f,0);
			break;
		}





		//Different Greens

		case 140:         //Green
		{
			glClearColor(0.0f,1.0f,0.0f,0);
			break;
		}

		case 141: //Chartreuse
		{
			glClearColor(0.498f,1.0f,0.0f,0);
			break;
		}

		case 142: //Chromeoxidegreen
		{
			glClearColor(0.4f,0.5f,0.08f,0);
			break;
		}

		case 143: //Cinnabar Green
		{
			glClearColor(0.38f,0.7f,0.16f,0);
			break;
		}

		case 144: //Cobalt Green
		{
			glClearColor(0.24f,0.57f,0.25f,0);
			break;
		}

		case 145: //Emerald Green
		{
			glClearColor(0.0f,0.79f,0.34f,0);
			break;
		}

		case 146: //Forest Green
		{
			glClearColor(0.1333f,0.5451f,0.1333f,0);
			break;
		}

		case 147: //Dark Green
		{
			glClearColor(0.0f,0.3922f,0.0f,0);
			break;
		}

		case 148: //Pale Green
		{
			glClearColor(0.5961f,0.9843f,0.5961f,0);
			break;
		}

		case 149: //Green Yellow
		{
			glClearColor(0.6784f,1.0f,0.1843f,0);
			break;
		}

		case 150: //Lawn Green
		{
			glClearColor(0.4863f,0.9882f,0.0f,0);
			break;
		}

		case 151: //Lime Green
		{
			glClearColor(0.1961f,0.8039f,0.1961f,0);
			break;
		}

		case 152: //Mint
		{
			glClearColor(0.74f,0.99f,0.79f,0);
			break;
		}

		case 153: //Olive
		{
			glClearColor(0.23f,0.37f,0.17f,0);
			break;
		}

		case 154: //Olive Drab
		{
			glClearColor(0.4196f,0.5569f,0.1373f,0);
			break;
		}

		case 155: //Dark Olive Green
		{
			glClearColor(0.3333f,0.4196f,0.1843f,0);
			break;
		}

		case 156: //Permanent Green
		{
			glClearColor(0.04f,0.79f,0.17f,0);
			break;
		}

		case 157: //Sap Green
		{
			glClearColor(0.19f,0.5f,0.08f,0);
			break;
		}

		case 158: //Sea Green
		{
			glClearColor(0.1804f,0.5451f,0.3412f,0);
			break;
		}

		case 159: //Dark Sea Green
		{
			glClearColor(0.5608f,0.7373f,0.5608f,0);
			break;
		}

		case 160: //Medium Sea Green
		{
			glClearColor(0.2353f,0.7020f,0.4432f,0);
			break;
		}

		case 161: //Light Sea Green
		{
			glClearColor(0.1255f,0.6980f,0.6667f,0);
			break;
		}

		case 162: //Spring Green
		{
			glClearColor(0.0f,1.0f,0.4980f,0);
			break;
		}

		case 163: //Medium Spring Green
		{
			glClearColor(0.0f,0.9804f,00.6039f,0);
			break;
		}

		case 164: //Terre Verte
		{
			glClearColor(0.22f,0.37f,0.06f,0);
			break;
		}

		case 165: //Light Viridian
		{
			glClearColor(0.43f,1.0f,0.44f,0);
			break;
		}

		case 166: //Yellow Green
		{
			glClearColor(0.6039f,0.8039f,0.1961f,0);
			break;
		}

		//Different Cyans

		case 167: //Aquamarine
		{
			glClearColor(0.498f,1.0f,0.8314f,0);
			break;
		}

		case 168: //Medium Aquamarine
		{
			glClearColor(0.4f,0.8039f,0.6667f,0);
			break;
		}

		case 169: //Cyan
		{
			glClearColor(0.0f,1.0f,1.0f,0);
			break;
		}

		case 170: //White Cyan
		{
			glClearColor(0.8784f,1.0f,1.0f,0);
			break;
		}

		case 171: //Turquoise
		{
			glClearColor(0.251f,0.8784f,0.8157f,0);
			break;
		}

		case 172: //Dark Turquoise
		{
			glClearColor(0.0f,0.8078f,0.8196f,0);
			break;
		}

		case 173: //Medium Turquoise
		{
			glClearColor(0.2824f,0.8196f,0.8f,0);
			break;
		}

		case 174: //PALE TURQUISE
		{
			glClearColor(0.6863f,0.9333f,0.9333f,0);
			break;
		}

		//Different Magentas

		case 175: //Blue Violet
		{
			glClearColor(0.5412f,0.1686f,0.8863f,0);
			break;
		}

		case 176: //Deep Cobalt Violet
		{
			glClearColor(0.57f,0.13f,0.62f,0);
			break;
		}

		case 177: //Magenta
		{
			glClearColor(1.0f,0.0f,1.0f,0);
			break;
		}

		case 178: //ORCHID
		{
			glClearColor(0.8549f,0.4392f,0.8392f,0);
			break;
		}

		case 179: //Dark Orchid
		{
			glClearColor(0.6f,0.1961f,0.8f,0);
			break;
		}

		case 180: //Medium Orchid
		{
			glClearColor(0.7294f,0.3333f,0.8275f,0);
			break;
		}

		case 181: //Permanent Violet
		{
			glClearColor(0.86f,0.15f,0.27f,0);
			break;
		}

		case 182: //PLUM
		{
			glClearColor(0.8667f,0.6275f,0.8667f,0);
			break;
		}

		case 183: //Purple
		{
			glClearColor(0.6275f,0.1255f,0.9412f,0);
			break;
		}

		case 184: //Medium Purple
		{
			glClearColor(0.5765f,0.4392f,0.8588f,0);
			break;
		}

		case 185: //Ultramarine Violet
		{
			glClearColor(0.36f,0.14f,0.43f,0);
			break;
		}

		case 186: //Violet
		{
			glClearColor(0.56f,0.37f,0.6f,0);
			break;
		}

		case 187: //Dark Violet
		{
			glClearColor(0.5804f,0.0f,0.8275f,0);
			break;
		}

		case 188: //Red Violet
		{
			glClearColor(0.8157f,0.1255f,0.5647f,0);
			break;
		}

		case 189: //Medium Red Violet
		{
			glClearColor(0.7804f,0.0824f,0.5216f,0);
			break;
		}

		case 190: //Pale Red Violet
		{
			glClearColor(0.8588f,0.4392f,0.5765f,0);
			break;
		}

		default: //default to white
			{
				glClearColor(1.0f,1.0f,1.0f,0);
				break;
			}




	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glLoadIdentity();

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////

float TrogAuxFunctions::PreventZeroVector(float v)
{
  	if(v <0 && v > -1)
	{
		 v= -1;
	}
	else if(v < 1 && v > 0 || v == 0)
	{
		 v=1;
	}


	return v;

}

//////////////////////////////////////////////////////////////////////////////////////

float TrogAuxFunctions::Pixel_2WorldSpace(float arg)
{
	//Look for fullscreen to make adjustments for extra window padding.
	float width = (float)TrogWin.GetWidth();
	float height =(float) TrogWin.GetHeight();
	
 float par = height/width;

	par=par/100;
	
	return (arg*par);
}

///////////////////////////////////////////////////////////////////////////////////////

std::string TrogAuxFunctions::Seconds_2TimeString(double Insecs)
{
	std::string Time;

	int seconds=60;
	int minutes=60;
	int hours=24;
	int days=0;

	seconds = (int) Insecs % 60;
	int Inminutes = Insecs/60;
	minutes = Inminutes%60;
	int Inhours = Inminutes / 60;
	hours = Inhours % 24;
	days = Inhours/24;

	Time= to_string((long double)days)+" : Days, " ;
	Time +=  to_string((long double)hours)+" : Hours, ";
	Time +=  to_string((long double)minutes)+" : Minutes, ";
	Time +=  to_string((long double)seconds)+" : Seconds ";

	return Time;
}

/////////////////////////////////////////////////////////////////////////////////////


int TrogAuxFunctions::GetRandRange(int min,int max)
{
   return(rand()%(max-min)+min);
}
