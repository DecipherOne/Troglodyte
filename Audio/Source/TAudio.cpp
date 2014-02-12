/*!********************************************************
* This is the source file for the Audio Context and      *
* Listener Device Managmenet class for the Troglodyte    *
* Game Engine.                                           *
*                                                        *
* Author: Will Canada (DecipherOne)                      *
* February 19th 2007      (c) DecipherOne Productions    *
*********************************************************/


#include "PCHEADER.h"



float TAudio::GetListenerPosX()
{
	return lp.x;
}

float TAudio::GetListenerPosY()
{
	return lp.y;
}

float TAudio::GetListenerPosZ()
{
	return lp.z;
}

//////////////////////////////////////////////////////////////////////////////////////////

float TAudio::GetListenerVelX()
{
	return lv.x;
}

float TAudio::GetListenerVelY()
{
	return lv.y;
}

float TAudio::GetListenerVelZ()
{
	return lv.z;
}

/////////////////////////////////////////////////////////////////////////////////////////

float TAudio::GetListenerOrienX()
{
	return lo.x;
}

float TAudio::GetListenerOrienY()
{
	return lo.y;
}


float TAudio::GetListenerOrienZ()
{
	return lo.z;
}


float TAudio::GetListenerOrienUX()
{
	return lo.ux;
}


float TAudio::GetListenerOrienUY()
{
	return lo.uy;
}


float TAudio::GetListenerOrienUZ()
{
	return lo.uz;
}

//////////////////////////////////////////////////////////////////////////////////////////

void TAudio::SetListenerPos(float x, float y, float z)
{
	lp.x = x;
	lp.y = y;
	lp.z = z;
}

void TAudio::SetListenerVel(float x, float y, float z)
{
	lv.x = x;
	lv.y = y;
	lv.z = z;
}

void TAudio::SetListenerOrien(float x, float y, float z,
							  float ux, float uy, float uz)
{

	ListenerOri[0]=x;
	ListenerOri[1]=y;
	ListenerOri[2]=z;
	ListenerOri[3]=ux;
	ListenerOri[4]=uy;
	ListenerOri[5]=uz;
	lo.x = x;
	lo.y = y;
	lo.z = z;
	lo.ux = ux;
	lo.uy = uy;
	lo.uz = uz;
}

///////////////////////////////////////////////////////////////////////////////////////////////


void TAudio::SetListenerPos(TObject &Object)
{
	lp.x = Object.GetxTranslation();
	lp.y = Object.GetyTranslation();
	lp.z = Object.GetzTranslation();
}


////////////////////////////////////////////////////////////////////////////////////////////////

ALboolean  TAudio::InitOpenAL()
{
   

    // Get handle to device.
    pDevice = alcOpenDevice(NULL);

    // Get the device specifier.
    deviceSpecifier = alcGetString(pDevice, ALC_DEVICE_SPECIFIER);


    // Create audio context.
    pContext = alcCreateContext(pDevice, NULL);

    // Set active context.
    alcMakeContextCurrent(pContext);

    // Check for an error.
	int Error = alcGetError(pDevice);
    if (Error != ALC_NO_ERROR)
	{
		ErrorLog.WriteMessage("There was an error creating the OpenAL Context Error Number : " + to_string(long double(Error)));
        return AL_FALSE;
	}

    return AL_TRUE;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TAudio::ExitOpenAL()
{
    ALCcontext* pCurContext;
    ALCdevice* pCurDevice;

    // Get the current context.
    pCurContext = alcGetCurrentContext();

    // Get the device used by that context.
    pCurDevice = alcGetContextsDevice(pCurContext);

    // Reset the current context to NULL.
    alcMakeContextCurrent(NULL);

    // Release the context and the device.
    alcDestroyContext(pCurContext);
    alcCloseDevice(pCurDevice);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TAudio::UpdateListenerValues()
{
	
		alListener3f(AL_POSITION,lp.x,lp.y,lp.z);
		alListener3f(AL_VELOCITY,lv.x,lv.y,lv.z);
		alListenerfv(AL_ORIENTATION, ListenerOri);
	
}


