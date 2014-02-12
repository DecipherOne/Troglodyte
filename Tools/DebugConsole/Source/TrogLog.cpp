/**********************************************************
* This is an event logging system for the Troglodyte      *
* game engine.                                            *
* Author : Will (DecipherOne) Canada                      *
* July 28,2011                                            *
*---------------------------------------------------------*
* Troglodyte (c) DecipherOne Productions                  *
**********************************************************/
#include "PCHEADER.h"

TrogLog::TrogLog(std::string fname, std::string Directory)
{
	filename = fname+".html";
	CreateDirectory(Directory.c_str(),NULL); //Windows specific
	OutputDirectory=Directory+'/' + filename;
	newlog=true;
	row_count=0;
	Send2Console=false;
	isEnabled = false;
}

/////////////////////////////////////////////////////////////////////////////////////

bool TrogLog::WriteMessage(std::string Message)
{
	if(isEnabled)
	{
		string previousMessages;
		   //Begin File checks before saving
		//---------------------------------------------------

		fstream stream; //Open a stream

		//Check to see if the specified file already exists
		stream.open(OutputDirectory.c_str(),ios::in);

		if(!stream.is_open()||newlog) //If it doesn't
		{
			if(stream.is_open())
			{
				stream.close();
			}

			//Create it.
			stream.open(OutputDirectory.c_str(),ios::out); 

			if(stream.is_open())
			{
				//Create formatting for our file.
				stream<< "<html>\n<body bgColor='#00000'>\n <center>\n";
				stream<< "<h2><font color='#615E3F'><br />";
				stream<< filename;
				stream<<"</font></h2>";
				//Place an index of all the files generated in all the files, except for the index.
				if(filename!="Index.html")
				{
					stream<<"<iframe width='35%' src='index.html'></iframe><hr />";
				}
				
				Log_Index.WriteMessage("<a href='"+ filename +" 'target='_parent' >"+ filename+"</a>");

				//Build our table
				stream<<"<table width='80%'><th bgColor='#EEE685' >Date</th><th bgColor='#EEE685'>Time</th><th bgColor='#EEE685'>Message</th>";
				stream<<"<tr bgColor='#E0DfDB'><td>";
				row_count=0;
				stream<< EngineTime.Get_Date();
				stream<< "</td><td>  ";
				stream<< EngineTime.Get_Time();
				stream<<"</td><td>  ";
				stream<< Message.c_str();
				stream<< "</td><br />";
				if(Send2Console)
				{
					DebugC1.SendOutput(Message);
				}
				stream.flush();
				stream.close();

				newlog=false;

				return true;
			}
		}
		else
		{   
		
			stream.close(); //close the file

			//Open our file for saving
			stream.open(OutputDirectory.c_str(),ios::out|ios::app); 
			if(row_count==0)
			{
				stream<<"<tr bgColor='#EEE685'><td>";
				row_count=1;
			}
			else
			{
				stream<<"<tr bgColor='#E0DfDB'><td>";
				row_count=0;
			}

			stream<< EngineTime.Get_Date();
			stream<< "</td><td>  ";
			stream<< EngineTime.Get_Time();
			stream<<"</td><td>  ";
			stream<< Message.c_str();
			stream<< "</td>";
			if(Send2Console)
			{
				DebugC1.SendOutput(Message);
			}
			stream.flush();
			stream.close();
			return true;
		
		}
	}

	return false;
}
///////////////////////////////////////////////////////////////////////////////////////

TrogLog::TrogLog()
{
	newlog=true;
	row_count=0;
	Send2Console=false;
	isEnabled = false;
}
///////////////////////////////////////////////////////////////////////////////////////

TrogLog::~TrogLog()
{
}
////////////////////////////////////////////////////////////////////////////////////////

void TrogLog::Finalize()
{
	if(isEnabled)
	{
		fstream stream;

		stream.open(OutputDirectory.c_str(),ios::out|ios::app); 

		if(stream.is_open())
		{
			stream<< "\n</table></center>\n</body>\n</html>";
		}
	}
}
//////////////////////////////////////////////////////////////////////////////

void TrogLog::SetisEnabled(bool arg)
{	
	
	if(arg != true && arg != false)
	{
		arg=false;
	}
	
	if(arg==false)
	{
		this->WriteMessage("Logging for this log was disabled.");
	}
	
	isEnabled = arg;

	if(arg==true)
	{
		this->WriteMessage("Logging for this log was enabled.");
	}
		
}

///////////////////////////////////////////////////////////////////////////////

bool TrogLog::GetisEnabled()
{
	return isEnabled;
}

