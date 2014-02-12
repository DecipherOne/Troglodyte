#include "pcheader.h"

Shader::Shader()
{
	infologLength = 0;
	charsWritten = 0;
	shader_source="";
}

//////////////////////////////////////////////////////////////////////////

Shader::~Shader()
{
	glDetachShader(shader_program, F_S); // Detach the fragment shader
    glDetachShader(shader_program, V_S); // Detach the vertex shader
    
    glDeleteShader(F_S); // Delete the fragment shader
    glDeleteShader(V_S); // Delete the vertex shader
    glDeleteProgram(shader_program); // Delete the shader program
}

//////////////////////////////////////////////////////////////////////////

void Shader::printInfoLog(GLhandleARB obj)
{

   

	int e = glGetError();
	
	if(e != 0) //If there is an error print it out.
	{
		string err = to_string((long long)e);
		ErrorLog.WriteMessage("Shader Error : "+err+" ");
	}

    glGetObjectParameterivARB(obj, GL_OBJECT_INFO_LOG_LENGTH_ARB, &infologLength);

	e = glGetError();

	if(e != 0) //If there is an error print it out.
	{
		string err = to_string((long long)e);
		ErrorLog.WriteMessage("Shader Error : "+err+" ");
	}

	if (infologLength > 0)
    {

        infoLog = (GLcharARB*)malloc(infologLength);

        if (infoLog == NULL)
        {

		  MessageBox(NULL,"ERROR: Could not allocate InfoLog buffer.","SHADER - INFOLOG ERROR",MB_OK);
		  exit(1);

        }

        glGetInfoLogARB(obj, infologLength, &charsWritten, infoLog);
		string info = infoLog;
		ErrorLog.WriteMessage("Shader Info Log Dump : "+info+" ");

        free(infoLog);

    }

    

}

///////////////////////////////////////////////////////////////////////////////

int Shader::getUniLoc(GLhandleARB program, const GLcharARB *name)
{

    loc = glGetUniformLocationARB(program, name);

	string n =name;

    if (loc == -1)
	{

		ErrorLog.WriteMessage("Shader Error : No such uniform named "+n+" .");
	}


    return loc;

}

///////////////////////////////////////////////////////////////////////////////

int Shader::installShaders(const char *vsName,const char *fsName)
{

    GLint       vertCompiled, fragCompiled;    // status values

    GLint       linked;

    // Create a vertex shader object and a fragment shader object

    V_S = glCreateShader(GL_VERTEX_SHADER);

    F_S = glCreateShader(GL_FRAGMENT_SHADER);

	//Create a program object
	shader_program = glCreateProgram();

    // Load source code strings into shaders
	loadshader((char *)vsName);
	const char * temp = shader_source.c_str();
	glShaderSource(V_S, 1,&temp, NULL);
	loadshader((char *)fsName);
	temp = shader_source.c_str();
	glShaderSource(F_S, 1,&temp, NULL);

    // Compile the brick vertex shader and print out

    // the compiler log file.
    glCompileShader(V_S);

	 glGetShaderiv(V_S, GL_COMPILE_STATUS, &vertCompiled);

    printInfoLog(V_S);
	// Compile the brick vertex shader and print out
	// the compiler log file.
    glCompileShader(F_S);


   glGetShaderiv(F_S, GL_COMPILE_STATUS, &fragCompiled);

   printInfoLog(F_S);

    if (!vertCompiled || !fragCompiled)
	{
		ErrorLog.WriteMessage("Both Shaders failed to successfully compile. No link was attempted.");
		return 0;
	}


    glAttachShader(shader_program,V_S);

    glAttachShader(shader_program,F_S);

    // Link the program object and print out the info log
    glLinkProgram(shader_program);

    glGetProgramiv(shader_program, GL_LINK_STATUS, &linked);

    printInfoLog(shader_program);

    if (!linked)
	{
		MessageBox(NULL, "Shader not linked","Doh",MB_OK);
		ErrorLog.WriteMessage("Shader(s) Failed to Link.");

		glDeleteShader(V_S);
		glDeleteShader(F_S);

		return 0;
	}

	glDeleteShader(V_S);
	glDeleteShader(F_S);

    return 1;
}



///////////////////////////////////////////////////////////////////////////////

bool Shader::loadshader(char* filename)
{
   fstream file;
   file.open(filename, ios::in); 
   string final="";
   shader_source ="";

   if(file.is_open())
   {
	   
	   char  a_line[255];
	   
	   do
	   {
	  
			file.getline(a_line,254);    // get a line from the file.
			shader_source += a_line;
	

	   }
	   while(!file.eof());
    
	   file.close();

	  
   }
   else
   {
	   string fname;
	   fname += filename;

	   MessageBox(NULL,"File Does Not Exist. Executing in Immediate Mode.","Shader "
		   "Load Error. ",MB_OK);
	   ErrorLog.WriteMessage(" The File : | "+ fname + " does not exist. /n"
		   " Program will execute in immediate mode.");
   }


	 if(shader_source != "")
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }

}

///////////////////////////////////////////////////////////////////////////////

unsigned long Shader::getFileLength(char * filename)
{
	fstream file;
	file.open(filename);
    if(!file.good())
	{
		return 0;
	}
    
    unsigned long pos=file.tellg();
    file.seekg(0,ios::end);
    unsigned long len = file.tellg();
    file.seekg(ios::beg);

	file.close();
    
    return len;
}

//////////////////////////////////////////////////////////////////////////////////

void Shader::Start()
{
	glUseProgram(shader_program);
}

//////////////////////////////////////////////////////////////////////////////////

void Shader::End()
{
	glUseProgram(0);
}

//////////////////////////////////////////////////////////////////////////////////

void Shader::DeleteProgram()
{
	End();
	glDeleteProgram(shader_program);
}
