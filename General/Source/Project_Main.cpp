#include "PCHEADER.H"

//Troglodyte should be added to visual studio as a seperate project from the actual game.
// This file should be the entry point for actual game content.
//Overall, system state management can be handled from this file.
//----------------------------------------


int GAME_MAIN();
enum States {Intro,Title,Credits,Options,Quit,Pause,MainLoop,Save,Load,VS,Survival};


TrogLog GameLog("FleetGame","Logs");
//Controls which state will be shown.
int CurrentState=6;


int GAME_MAIN()
{


	switch(CurrentState)
	{
	case Intro:
		{
			Ascend_Intro();
			//Fleet_Intro();
			break;
		}
	case Title:
		{
			Ascend_Title();
			//Fleet_Title();
			break;
		}
	case Credits:
		{
			Ascend_Credits();
			//Fleet_Credits();
			break;
		}
	case Options:
		{
			Ascend_Options();
			//Fleet_Options();
			break;
		}
	case Quit:
		{
			Ascend_Quit();
			//Fleet_Quit();
			break;
		}
	case Pause:
		{
			Ascend_Pause();
			//Fleet_Pause();
			break;
		}

	case MainLoop:
		{
			//Fleet_Main();
			Ascend_Main();
			break;
		}
	case Save:
		{
			Ascend_Save();
			//Fleet_Save();
			break;
		}

	case Load:
		{
			Ascend_Load();
			//Fleet_Load();
			break;
		}
	case VS:
		{

			break;
		}
	case Survival:
		{
			break;
		}
	}

	
	return 0;
}