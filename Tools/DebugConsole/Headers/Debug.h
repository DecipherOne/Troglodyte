/*!********************************************************
* This is the base debug class that text input classes   *
* with more functionality can be inherited from.		 *
* The sole purepose of this class is to get the data     *
* on the screen for the developer to use.                *
* Author: Will (DecipherOne) Canada (c) 2006             *
*********************************************************/
#ifndef _DEBUGH_
#define _DEBUGH_

class DebugConsole
{
private:


    //Default commands
	bool ShowFPS;       //!< Flag to signal if Frames Per Second should be shown on the screen
	//bool Show_Camera_Coords;
	//bool Write2Log;
	//bool OnStart_ReadFromFile;


	bool IsActive;            //!< Signals if the debug console is currently active


	
	//Three buffers used for sorting text input

	std::string ConsoleMessage; //!< Message to be displayed in the console. Set in the Debug Constructor.
	
	std::string Temp1; //!< Buffer used for sorting text input
	const char * Temp2; //!< Char array used for printing text that the user typed to the screen
	std::string Debug_Buffer; //!< Buffer used for taking text input from the screen
	
	std::string Debug_Buffer2[12]; //!< Buffers used to store previously typed commands 

public:

	
	bool SendOutput(std::string); //!< The argument is placed in the buffer array at location [1]
	bool consolegreeting; //!< Used to signal if console greeting should be loaded from file

	int FillBuffers(std::string); //<! Used to fill the Debug_Buffer[] with data passed into the function
	void SetShowFPS(bool);
	bool GetShowFPS();

	bool GetIsActive();
	void SetIsActive(bool);

	bool ProcessInput();  //!< Used to process commands currently in the active buffer
	 
    bool ProcessOutput(); //!< Used to manipulate scene behavior based on active or inactive state arguments
	bool WriteOutput();   //!< used to write output the Console screen based on buffer info
    bool DrawConsole();   //!< Draws the command console
	
	bool UpdateConsole(); //Used to update all the states of the Console(Called from Draw Console if the console if fully drawn)
	DebugConsole();
	~DebugConsole();
};

#endif