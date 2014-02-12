//Settings manager definitions for  Troglodyte
/*!*********************************************(C)**
+ Will Canada : DeciipherOne Productions      2007 +
|--------------------------------------------------|
|This class is used for loading all the Graphic    |
|,Audio, and other settings for initalizing the    |
|game settings.                                    |
|__________________________________________________|
+--------------------------------------------------+*/

#ifndef _SETTINGSMANAGER_
#define _SETTINGSMANAGER_

#include<fstream>




//width, height, and color depth for window creation and appnamesize

struct VideoConfig //!< Struct for saving video initialization data 
{
	std::string AppName; //!<Name that shows up at top of Window

int width, height, CBits, AppNameSize;

bool fullscreen; //!< FullSCreen flag, for full screen or windowed mode



};


class SettingsManager //!< Struct for saving and loading engine initialization settings.
{
public:



	VideoConfig V_Settings; //!< Instance of the video settings

	int Load_V_Settings(); //!< Loads video settings from config.ini
	int Save_V_Settings(); //!< Saves video settings to config.ini

	SettingsManager();
	~SettingsManager();
};


#endif