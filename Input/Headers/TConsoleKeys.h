//Header file for the In game Console Keyboard Input
/*!*********************************************(C)**
+ Will Canada : DeciipherOne Productions      2007 +
|--------------------------------------------------|
| This class must be accompanied by the console    |
| classes Debug and UpdatesManager in order to be    |
| used within a functional program.                |
|  Although if suitable replacement				   |
| functionality were rewritten (ie.) a class       |
| utilizing functionality with FillBuffers()  then |
| the classes functionality could still be         |
| utilized.                                        |
|__________________________________________________|
+--------------------------------------------------+

The classes Debug and UpdatesManager are found in the same named .cpp 
and .h files. These files are also only useful on a Windows
System although the same concepts are universal to 
any system											*/

#ifndef _TCONKEYS_
#define _TCONKEYS_

class TConsoleKeys //!< Class for Command Console Keyboard Handling 
{
private:

	int Held[256]; //!< Used for length of time the keys are being held down
	

public:

	virtual int HandleKeyEvent(); //!< Performs Messagehandling for filling the Command Console text buffers
	int ResetKeyStates(); //!< Resets the counter to illiminate wrong multiple key presses
	int repeatspeed; //!< Used for setting the key press repeat speed

	TConsoleKeys(int x); //!< Constructor takes on argument setting the repeatspeed for holding keys down
	TConsoleKeys();      //!< Default Constructor
	virtual ~TConsoleKeys();


};

#endif


