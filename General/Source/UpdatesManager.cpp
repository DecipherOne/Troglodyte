//UpdatesManager Definitions for Troglodyte

#include "PCHEADER.H"


TConsoleKeys ConKeys(30); //Instance of ConsoleKeys Class Repeat set to 30 cycles
TMouse GMouse;    //Instance of the Global Mouse Handler
TMouse  EdMouse;          //!< Instance of  mouse class for the editor
TClock EngineTime;       //!< Instance of Global Time Handle

UpdatesManager::UpdatesManager()
{
	FindFreq();
	
}
/////////////////////////////////////////////////////////////////

void UpdatesManager::FindFreq()
{
	QueryPerformanceFrequency(&frequency);

}
////////////////////////////////////////////////////////////////

 bool UpdatesManager::UpdateStates()
{


	

	//Console Input - All Other Keyboard\\
	input should go inside the if statement for input
	ConKeys.HandleKeyEvent(); 


	double stoptime = 0.001; //Used to help keep frame rates persistant

	//Make old time the old delta time
	OldTime = deltaTime;
	
	
	//Get the start tick count
	QueryPerformanceCounter(&startcount);



	do //This do loop helps keep our frame rates persistant without limiting frame rate
	{
		//Base our updates for input on the rate of the updates.

			float s = 0;

			if(framespersec>59)
			{
				s = 1/60;
			}
			else
			{
				s = 1/30;
			}

	
			//NewTime is the total accumulator for  ticks passed
			//if enough time has passed, process input.
		if(EngineTime.CalcTimePassed() >= s)
		{ 

				//Handle Key Board input(Except for the console)
					
					//update the mouse position
					GMouse.UpdateMouse();
					NewTime = 0;

					
		}

			//Update our realtime timer for logic updates, unless the console\\
			is active, or the MainState is paused, effectively pausing logic updates.

			if(GetPause())
			{
				//Don't update the Logic timers.
			}
			else
			{
				EngineTime.UpdateTimer();
			}

	

			
			//DO Drawing

			if(!UpdateRender())
			{
				return false;
			}


			

			//Get the stop time for the end of the frame
			QueryPerformanceCounter(&endcount);

			//Get the difference of time from the start to the end
			deltaTime =  (double)(endcount.QuadPart - startcount.QuadPart)/(double)frequency.QuadPart;
	}		

	while(deltaTime < stoptime);
	
	NewTime += OldTime;
	framespersec = 1.0f / deltaTime;

	//Set the key repeat speed based on frame rate
	ConKeys.repeatspeed = framespersec * 0.575;

	return true;
}
///////////////////////////////////////////////////////////////

UpdatesManager::~UpdatesManager()
{
}

///////////////////////////////////////////////////////////////

bool UpdatesManager::UpdateRender()
{


		
	
			
		if(!TrogWin.DrawGLScene())
		{
			return false;
		}
	
		SwapBuffers(TrogWin.hDC);			// Swap Buffers (Double Buffering)
	
			
		

		

	return true;
}

////////////////////////////////////////////////////////////////
void UpdatesManager::SetPause(bool arg)
{
     pausestate = arg;
		 

}

bool UpdatesManager::GetPause()
{
	return pausestate;
}

////////////////////////////////////////////////////////////////


float UpdatesManager::GetNewTime()
{
	return NewTime;
}


/////////////////////////////////////////////////////////

float UpdatesManager::SetNewTime(float arg)
{
	
	return NewTime = arg;
}
	