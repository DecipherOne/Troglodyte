/*!********************************************************
* This is the base debug class.                          *
* The sole purepose of this class is to get the data     *
* on the screen for the developer to use.                *
* Author: Will (DecipherOne) Canada (c) 2007             *
*********************************************************/

#include "PCHEADER.H"


PFonts * DebugFont;   //Font Used for writing Debug Info to the screen
TCreateWindow * Main; //Pointer to CreateWindow Class

int DemoNum;    //Used for initializing demos through the console

DebugConsole::DebugConsole()
{
	DebugFont = &CourierFont;
	//set Window Pointer to point to main instance

#ifdef DEBUG
	ShowFPS=true;
#else
	ShowFPS=false;
#endif 


	Main = &TrogWin;
	Temp2=0;
	IsActive=false;

	ifstream stream;
	stream.open("Resources/console.ini");

	if(stream.is_open())
	{
		getline(stream,ConsoleMessage);
		stream.close();
	}

	else
	{
		ConsoleMessage ="		>> Troglodyte ~ Problem Loading Console Message ~ <<";
	}

	

	DemoNum=3; //2 For Barricade
}

//*!****************************************************************************

DebugConsole::~DebugConsole()
{
	
}


void DebugConsole::SetIsActive(bool arg)
{
	IsActive = arg;

	if(arg)
	{
		MainState.SetPause(true); //Pause our logic updates when the console is active
	}
	else
	{
		MainState.SetPause(false); //Unpause logic updates
	}

}
//*!****************************************************************************
bool DebugConsole::GetIsActive()
{
	return IsActive;
}
		
//*!****************************************************************************

void DebugConsole::SetShowFPS(bool arg)
{

	//set Show FPS to the argument
	ShowFPS = arg;
	if(ShowFPS != true && ShowFPS != false)
	{
		MessageBox(NULL,"The Argument for ShowFPS has an incorrect value defaulted to false", "ERROR",MB_OK);
		ShowFPS = false;
	}
	

	//Handle Errors
}

//*!****************************************************************************
bool DebugConsole::GetShowFPS()
{
	return ShowFPS;

}

//*!****************************************************************************


//*!****************************************************************************


bool DebugConsole::DrawConsole()
{

	static int tempHeight; //Used for animating console lowering and retraction

	
	int  width;
	int  height;



	width = Main->GetWidth(); //Get the lenght of the app window
	height = Main->GetHeight() ;//Get the height of the app window

	//If COnsole isn't active and Showfps is true draw fps

	if(ShowFPS == true&&!GetIsActive())
	{
		float tempwidth = (float) Main->GetWidth();
		float tempheight = (float) Main->GetHeight(); 

		int width = Main->GetWidth();
		int height = Main->GetHeight();

		FM.SetColor(42);
		DebugFont->PrintOnScreen(tempwidth*0.85,tempheight*0.9775,1,
		width,height,"FPS : %i",MainState.framespersec);
	}

	//Console is Active

	if(IsActive)
	{
		if(tempHeight < height)
		{
			
				tempHeight += 10; //Add one for every ten frames to animate
			
		}
	}

	else if(!IsActive&&tempHeight>=0)
	{
	
			tempHeight -= 10; //Subtract one for every ten frames to animate
		
	}

	else
	{
		return false;  //return to the calling function before drawing
	}

	//Start Drawing Console
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
    glPushMatrix();                                    //Save the current Projection Matrix

	

	glLoadIdentity();							// Reset The Projection Matrix
	glOrtho(0,width,0,tempHeight,-1,1); //Set orthographic projection based on the applications window size

	glMatrixMode(GL_MODELVIEW);						// Select The Modelview Matrix
	glPushMatrix();								// Store The Modelview Matrix

    glTranslatef(0,height,1); 
 

	//Draw the Command Console

	int h = Main->GetHeight() * 0.325;
	glBegin(GL_QUADS);	
	glColor4f(1.0f,0.5f,0.0f,1.0f);					
		glVertex3f(-width, h, 0.0f);				
		glVertex3f( width, h, 0.0f);				
		glVertex3f( width,-h, 0.0f);				
		glVertex3f(-width,-h, 0.0f);				
	glEnd();		


	

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPopMatrix();		

	glMatrixMode(GL_MODELVIEW);						// Select The Modelview Matrix
	glPopMatrix();

  

	if(tempHeight >= height)
	{
		UpdateConsole();
	}


	return true;
}

////////////////////////////////////////////////////////////////////////////////////

bool DebugConsole::UpdateConsole()
{
	ProcessOutput();
	return true;
}

///////////////////////////////////////////////////////////////////////////////////

bool DebugConsole::ProcessOutput()
{
    
	 
	//Check if ConsoleDrawing is currently active 
	//Do Standard Console Output
	
	
	if(GetIsActive())
	{

		//write console message from file console.ini

		int h = Main->GetHeight() * .0265;
		h = Main->GetHeight() - h;
		FM.SetColor(3);

			//Console Message from console.ini file 

			DebugFont->PrintOnScreen(Main->GetWidth() /95,h,1,Main->GetWidth(),
				Main->GetHeight()," %s",ConsoleMessage.c_str());
		
	}
	
	
	WriteOutput();

	return true;
}

///////////////////////////////////////////////////////////////////////////////

bool DebugConsole::WriteOutput()
{
	if(IsActive)
	{
		
		static float tempHeight;
		static float previousHeight; //Used for moving text up console screen
	
		int z=1; //used for printing the string array
		const char * AnoTemp; //used for transfering string data to constant char
		                  // data for use with printonscreen


		//Change the rendering color to grey
		FM.SetColor(117);

		//if the height isn't right for displaying console output reset it
		if(previousHeight<tempHeight||previousHeight> Main->GetHeight() - 14)
		{
			previousHeight = tempHeight;
		}

		//Print the Debug Console Buffer

		
		do
		{
			AnoTemp = Debug_Buffer2[z].c_str(); //Copy the string into a constant char *
			tempHeight += TrogWin.GetHeight() * 0.0275; //Move drawing height up 
			DebugFont->PrintOnScreen(Main->GetWidth()/95, tempHeight,1,Main->GetWidth(),
			Main->GetHeight(),AnoTemp,NULL);
			z+=1;
		}
		while(z <= 10);


		tempHeight = Main->GetHeight() * .320;
		tempHeight = Main->GetHeight() - tempHeight;
		FM.SetColor(39);
		
		//Print the current Typed Text
		DebugFont->PrintOnScreen(Main->GetWidth()/95, tempHeight,1,Main->GetWidth(),
			Main->GetHeight(),Temp2,NULL);

		 
	}
	return true;
}

////////////////////////////////////////////////////////////////

int DebugConsole::FillBuffers(std::string   arg)
{
	
    Temp1 = arg;
	
	if(Temp1=="VK_RETURN")
	{
		//Debug_Buffer2->erase(Debug_Buffer2->begin(), Debug_Buffer2->end());
		Debug_Buffer2[0] = Debug_Buffer;
		//Realign Page Buffer

		int count=11;

		do
		{		
				Debug_Buffer2[count]=Debug_Buffer2[count-1];
				count--;
		}
		while(count>=1);


		ProcessInput();
		//Reset buffers
		Debug_Buffer.erase(Debug_Buffer.begin(),Debug_Buffer.end());
		return 0;
		
	}


	//If KeyStroke is the Space Key
	if(arg == "SPACE")
	{

		Debug_Buffer.append(" ");
		Temp2=Debug_Buffer.c_str();
	}
	
	else if(arg =="VK_BACK")//Backspace Key
	{
		if(Debug_Buffer =="")
		{
			return 0;
		}

		Debug_Buffer.erase(Debug_Buffer.end() - 1, Debug_Buffer.end());
		Temp2=Debug_Buffer.c_str();
	}

	else if(arg=="VK_TAB")//Tab Key
	{
		Debug_Buffer.append("    ");
		Temp2=Debug_Buffer.c_str();
	}

	else
	{
		
			Debug_Buffer.append(arg);
			Temp2=Debug_Buffer.c_str();
			return 0;
		
	}

	return 0;

}
///////////////////////////////////////////////////////////////

bool DebugConsole::ProcessInput()
{
	//Take Input from the console and match up using if statements

	
	transform(Debug_Buffer.begin(),Debug_Buffer.end(),Debug_Buffer.begin(),
		(int(*)(int)) toupper);

	////////////////////////////////////////////////////////////////////////
	// Single Word Commands

	//Show Frames Per Second?
		if (Debug_Buffer =="SHOWFPS")
		{
			if(!GetShowFPS())
			{
				SetShowFPS(true);
				Debug_Buffer2[1].append(" ->.Frames Per Second Will Be Shown.<-");
				return true;
			}

			else
			{
				SetShowFPS(false);
				Debug_Buffer2[1].append(" ->.Frames Per Second Will NOT Be Shown.<-");
				return true;
			}
			
		}

	//Pause the Game?
		else if(Debug_Buffer =="PAUSE")
		{
			if(MainState.GetPause() !=true)
			{
				MainState.SetPause(true);
				Debug_Buffer2[1].append(" ->.All Game States Paused.<-");
				return true;
			}

			else
			{
				MainState.SetPause(false);
				Debug_Buffer2[1].append(" ->.All Game States UNPaused.<-");
				return true;
			}
		}

		
	////////////////////////////////////////////////////////////////////////
	// Enable the Editor : Scribe the current Built in Game Editor        //
	///////////////////////////////////////////////////////////////////////
		

		


	//ADD MORE ARGUMENTS

		

		else if(Debug_Buffer=="2")
		{
			if(DemoNum==2)
			{
				Debug_Buffer2[1].append(" ->.Demo - Barricade Level - Already Running.<-");
			}
			else
			{

				DemoNum = 2;
				Debug_Buffer2[1].append(" ->.Demo - Barricade Level - is being Loaded.<-");
			}

			return true;
		}

		else if(Debug_Buffer=="SHOWCURSOR")
		{
			//Only one instance of the mouse exists at one time, there fore this only works in fullscreen.
			if(GMouse.MouseCursor.flags != CURSOR_SHOWING)//Show the cursor
			{
				ShowCursor(true);
				Debug_Buffer2[1].append(" ->.The mouse cursor will be shown.<-");
			}

			else if(!TrogWin.GetFullScreen())
			{
				ShowCursor(true);
				Debug_Buffer2[1].append(" ->.The mouse cursor will be shown.<-");
			}

			
			return true;
		}

		else if(Debug_Buffer=="QUIT")
		{ 
			PostQuitMessage(0);
		}



		else
		{
			
			Debug_Buffer2[1].append(" ->.Command Not Recognized.<-");
		}

		ProcessOutput();
		
	return true;
}

/////////////////////////////////////////////////////////////////////////////////////
bool DebugConsole::SendOutput(std::string arg)
{
	Debug_Buffer2[1]=arg;
	FillBuffers("VK_RETURN");
	return true;
}