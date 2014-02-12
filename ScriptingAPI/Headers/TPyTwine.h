/********************************************************************
* Wrapper for custom python embedding.                              *
*									                                *
* Author : Will Canada (DecipherOne) March 9, 2011                  *
* Copyright (C) DecipherOne Productions 2011                        *
*********************************************************************/
/*!-------------------------------------------------------------------+
| This file is responsible for initalizing and loading the Python     |
| function tables created specifically for the Troglodyte Game Engine.|
|                                                                     |
+---------------------------------------------------------------------+*/
#ifndef _TPYTWINE_
#define _TPYTWINE_

#include "Pcheader.h"

////////////////////////////////////////////////////////////////////////////////////////
//          Begin Custom Python Interfaces for the Sprite Class                       //
////////////////////////////////////////////////////////////////////////////////////////
extern PyObject * SetB_BoxDimensions(PyObject * pSelf, PyObject * pParams,Sprite &py_Sprite);
extern PyObject * SetDimensions(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetDimensions(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * SetAnimationName_Num(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * SetNumOfAnimations(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetNumOfAnimations(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * AnimateSprite(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * Create(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * Destroy(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * Test_2DCollide(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * Test_2DCollide_Z(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
//Inherited From Quad Class
extern PyObject * Draw(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * Draw_Ortho(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * SetVerticesScales(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * SetTextureCoords(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * OnScale(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
//Inherited From Triangle Class
extern PyObject * GetTransparency(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * SetTransparency(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
//Inherited From Shape Class
extern PyObject * SetHasTexture(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetHasTexture(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * LoadTexture(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
//Inherited From TObject
extern PyObject * OnMoveUP(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * OnMoveDOWN(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * OnMoveLEFT(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * OnMoveRIGHT(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * OnMoveIN(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * OnMoveOUT(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * OnRotatePosX(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * OnRotatePosY(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * OnRotatePosZ(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * OnRotateNegX(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * OnRotateNegY(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * OnRotateNegZ(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * CheckLogicTimer(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetName(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * SetName(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * ConString4Screen(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * SetrUnitSize(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetrUnitSize(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * SetmUnitSize(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetmUnitSize(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * OnSetTranslation(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * OnSetRotation(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetLabel(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetxRotate(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetyRotate(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetzRotate(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetxTranslation(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetyTranslation(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetzTranslation(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetIsSelected(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * SetIsSelected(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetSpawnCount(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * SetSpawnCount(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * GetIsCollide(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);
extern PyObject * SetIsCollide(PyObject * pSelf, PyObject * pParam, Sprite &py_Sprite);

//Sprite Class Function Table Definition
PyMethodDef  PyTwine_Sprite[] = 
		{ {"SetB_BoxDimensions",SetB_BoxDimensions, METH_VARARGS, NULL}, 
		  {"SetDimensions",SetDimensions, METH_VARARGS, NULL},
		  {"GetDimensions",GetDimensions, METH_VARARGS, NULL},
		  {"SetAnimationName_Num",SetAnimationName_Num, METH_VARARGS, NULL},
		  {"SetNumOfAnimations",SetNumOfAnimations, METH_VARARGS, NULL},
		  {"GetNumOfAnimations",GetNumOfAnimations, METH_VARARGS, NULL},
		  {"AnimateSprite",AnimateSprite, METH_VARARGS, NULL},
		  {"Create",Create, METH_VARARGS, NULL},
		  {"Destroy",Destroy, METH_VARARGS, NULL},
		  {"Test_2DCollide",Test_2DCollide, METH_VARARGS, NULL},
		  {"Test_2DCollide_Z",Test_2DCollide_Z, METH_VARARGS, NULL},
		  {"Draw",Draw, METH_VARARGS, NULL},
		  {"Draw_Ortho",Draw_Ortho, METH_VARARGS, NULL},
		  {"OnScale",OnScale, METH_VARARGS, NULL},
		  {"SetVerticesScales",SetVerticesScales, METH_VARARGS, NULL},
		  {"SetTextureCoords",SetTextureCoords, METH_VARARGS, NULL},
		  {"OnMoveUP",OnMoveUP, METH_VARARGS, NULL},
		  {"OnMoveDOWN",OnMoveDOWN, METH_VARARGS, NULL},
		  {"OnMoveLEFT",OnMoveLEFT, METH_VARARGS, NULL},
		  {"OnMoveRIGHT",OnMoveRIGHT, METH_VARARGS, NULL},
		  {"GetTransparency",GetTransparency, METH_VARARGS, NULL},
		  {"SetTransparency",SetTransparency, METH_VARARGS, NULL},
		  {"OnMoveIN",OnMoveIN, METH_VARARGS, NULL},
		  {"OnMoveOUT",OnMoveOUT, METH_VARARGS, NULL},
		  {"OnRotatePosX",OnRotatePosX, METH_VARARGS, NULL},
		  {"OnRotatePosY",OnRotatePosY, METH_VARARGS, NULL},
		  {"OnRotatePosZ",OnRotatePosZ, METH_VARARGS, NULL},
		  {"OnRotateNegX",OnRotateNegX, METH_VARARGS, NULL},
		  {"OnRotateNegY",OnRotateNegY, METH_VARARGS, NULL},
		  {"OnRotateNegZ",OnRotateNegZ, METH_VARARGS, NULL},
		  {"CheckLogicTimer",CheckLogicTimer, METH_VARARGS, NULL},
		  {"GetName",GetName, METH_VARARGS, NULL},
		  {"SetName",SetName, METH_VARARGS, NULL},
		  {"ConString4Screen",ConString4Screen, METH_VARARGS, NULL},
		  {"SetrUnitSize",SetrUnitSize, METH_VARARGS, NULL},
		  {"GetrUnitSize",GetrUnitSize, METH_VARARGS, NULL},
		  {"SetmUnitSize",SetmUnitSize, METH_VARARGS, NULL},
		  {"GetmUnitSize",GetmUnitSize, METH_VARARGS, NULL},
		  {"OnSetTranslation",OnSetTranslation, METH_VARARGS, NULL},
		  {"OnSetRotation",OnSetRotation, METH_VARARGS, NULL},
		  {"GetLabel",GetLabel, METH_VARARGS, NULL},
		  {"GetxRotate",GetxRotate, METH_VARARGS, NULL},
		  {"GetyRotate",GetyRotate, METH_VARARGS, NULL},
		  {"GetzRotate",GetzRotate, METH_VARARGS, NULL},
		  {"GetxTranslation",GetxTranslation, METH_VARARGS, NULL},
		  {"GetyTranslation",GetyTranslation, METH_VARARGS, NULL},
		  {"GetzTranslation",GetzTranslation, METH_VARARGS, NULL},
		  {"GetIsSelected",GetIsSelected, METH_VARARGS, NULL},
		  {"SetIsSelected",SetIsSelected, METH_VARARGS, NULL},
		  {"GetSpawnCount",GetSpawnCount, METH_VARARGS, NULL},
		  {"SetSpawnCount",SetSpawnCount, METH_VARARGS, NULL},
		  {"GetHasTexture",GetHasTexture, METH_VARARGS, NULL},
		  {"SetHasTexture",SetHasTexture, METH_VARARGS, NULL},
		  {"LoadTexture",LoadTexture, METH_VARARGS, NULL},
		  {"GetIsCollide",GetIsCollide, METH_VARARGS, NULL},
		  {"SetIsCollide",SetIsCollide, METH_VARARGS, NULL},
		  {NULL, NULL, NULL, NULL }
		};

////////////////////////////////////////////////////////////////////////////////////////
//            End Sprite Class Python Interfaces                                      //
////////////////////////////////////////////////////////////////////////////////////////

#endif