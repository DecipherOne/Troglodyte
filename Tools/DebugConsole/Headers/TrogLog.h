/**********************************************************
* This is an event logging system for the Troglodyte      *
* game engine.                                            *
* Author : Will (DecipherOne) Canada                      *
* July 28,2011                                            *
*---------------------------------------------------------*
* Troglodyte (c) DecipherOne Productions                  *
**********************************************************/

#ifndef _TROGLOG_
#define _TROGLOG_

class TrogLog
{	
	bool isEnabled;              //!< Flag to signal that the log should be writing.
	bool newlog;                 //!< flag to set for a new log to be created.
	std::string OutputDirectory; //!< The directory for the file to be written.
	std::string filename;        //!< The name of the file to be written to/created.
public:

	bool Send2Console; //!< Flag to signal if messages should be echoed in the debug console.
	int row_count; //!< Used for signaling different colors for table in output.
	TrogLog(std::string fname, std::string Directory); //!< Constructor sets the filename and directory for writing.
	bool WriteMessage(std::string Message); //!< Writes the specified message to the output file.
	bool SendMail(std::string Address,std::string Subject);//!< Sends the log file in an attachment to the specified address.
	void Finalize(); //!< Creates our closing tags and adds them to the log file.
	TrogLog();  //!< Default Constructor
	~TrogLog(); //!< Destructor 
	void SetisEnabled(bool arg); //!< Sets whether the log should be writing.
	bool GetisEnabled();         //!< Returns the value stored in isEnabled.
};

#endif