/********************************************************************
* This is the Shader class header file for the Engine Troglodyte.   *
*									                                *
* Author : Will Canada (DecipherOne) February 14, 2012              *
* Copyright (C) DecipherOne Productions 2012                        *
*********************************************************************/
#ifndef _SHADER_H_
#define _SHADER_H_

class Shader //!< Class for creating gpu shaders for graphic effects and acceleration.
{

	int infologLength; //!< Used for knowing the length of a message for the shader info log.
    int charsWritten;  //!< Used for knowing what has been written from the info log.
    GLcharARB *infoLog; //!< A handle to the shader info log.
	GLint loc; //!< Used to locate a uniform variable in a shader file and pass the info to c++.
	GLuint V_S; //!< Handle for a vertex shader.
	GLuint F_S; //!< Handle for a fragment shader.
	string shader_source; //!< Stores the source for a shader.
	void printInfoLog(GLhandleARB obj); //!< Prints results of shader compilation and linking to error file, also will print compile errors for debugging.
	bool loadshader(char* filename); //!< Gets the data from a shader file and stores it in shader_source. Autmatically called from installShaders()
public:

	GLuint shader_program; //!< Handle for a shader program object.
	Shader(); //!< Initializes our variables
	~Shader();
	unsigned long getFileLength(char * filename); //!< Returns the length of the specified file.
	int installShaders(const char *vsName,const char *fsName); //!< Loads the specified files into memory a vertex shader and fragment shader. Creates shader objects and a program object and attempts to compile and link them to the program object.
	int getUniLoc(GLhandleARB program, const GLcharARB *name); //!< Gets the location of a uniform variable in the specified program.
	
	void Start(); //Makes a call to glUseProgram(shader_program) to begin using the shader.
	void End(); //Makes a call to glUseProgram(0) to end using the shader.
	void DeleteProgram(); //Removes a shader program from memory.
};

#endif