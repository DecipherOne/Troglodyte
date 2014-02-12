/*!--------------------------------------------
   This class gets the time information from  
   the host computer.
-------------------------------------------------
Author : Will Canada
October 23, 2007
--------------------------------------------------*/

#include "PCHEADER.H"

std::string TClock::Get_Time()
{
	char s[9];
	_strtime_s(s);

	data = s;

	return data;
}


std::string TClock::Get_Date()
{
	char s[9];
	_strdate_s(s,9);

	data = s;
	return data;
}




void TClock::ResetTimer()
{
	start=clock();
}



TClock::TClock()
{
	start=clock();
}

TClock::~TClock()
{
	

}

void TClock::UpdateTimer()
{
	finish=clock();
}

double TClock::CalcTimePassed()
{
	elapsed = (double)(finish - start) / CLOCKS_PER_SEC;

	return elapsed;
}


