#ifndef _TCLOCKH_
#define _TCLOCKH_


/*!--------------------------------------------
   This class gets the time information from  
   the host computer and is used for sychronizing 
   things or simply displaying system time.
-------------------------------------------------
Author : Will Canada
October 23, 2007
--------------------------------------------------*/


class TClock
{
	std::string data;

	int OldTime;
	int NewTime;
	clock_t   start, finish; //! Used for determining whether to update Translation,Scaling,or Rotation on an object

	double elapsed;

public:

	double CalcTimePassed(); //!< Calculates the time that has passed since the Timer has been started. (Accumulates unless reset)
	void ResetTimer();       //!< When called resets the Timer.
	void UpdateTimer();      //!< Updates the timer, used for calculating time passed.

	std::string Get_Time();   //!< Returns a string containing the current system time.
	std::string Get_Date();	 //!< Returns a string containing the current system date.

	TClock();
	~TClock();
};

























#endif