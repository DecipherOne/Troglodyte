/*This is the header for the Troglodyte state manager*/

#ifndef _STATEMAN_
#define _STATEMAN_

class UpdatesManager
{
protected:

	LARGE_INTEGER startcount, endcount; //!<used to measure start and end of timer
    LARGE_INTEGER  frequency; //!<used to find computers processor speed
	float OldTime; //!<used to store time passed between calls (Rendering)
	float NewTime; //!<used to store time passed between calls (KeyUpdates)
	double deltaTime; //!<used to limit  updates to .001 seconds
	double stoptime; //!<used to signal length of time for time loop
	bool pausestate; //!<used to pause the game state logic

	string StateName; //!< Human readable form of the state name
	void FindFreq(); //!<used to find frequencey
	
public:

	void SetPause(bool); //!< Signals to stop updating Gamestate logic
	bool GetPause();     //!< Gets the pausestate variable((Game logic must be incapsulated in a check for this call.)
	virtual bool UpdateStates(); /*!< Measures the performance and time between calls to the function
								 with a high resolution timer. Calculates Frames per Second. Makes a Call
								 to UpdateRender.*/
	
	virtual bool UpdateRender(); /*!< This particular instance of the function makes a call to do double buffering and drawing 
								 of the OpenGL Context */

	
	float GetNewTime(); //!<used for returning 
	float SetNewTime(float); //!< Used to set NewTime to 0

	int framespersec; //!<used to store Frames Per Second

	UpdatesManager();
	virtual ~UpdatesManager();
};

#endif


	



