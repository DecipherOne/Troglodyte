
/*!*********************************************(C)**
+ Will Canada : DecipherOne Productions		  2007 +
|--------------------------------------------------|
| This class must be accompanied by the console    |
| classes Debug and UpdatesManager in order to be    |
| used within a functional program.                |
|  Although if suitable replacement				   |
| functionality were rewritten (ie.) a class       |
| utilizing functionality with FillBuffers()  then |
| the classes functionality could still be         |
| utilized.                                        |
|__________________________________________________|
+--------------------------------------------------+*/

#include "PCHEADER.H"


extern UpdatesManager MainState;
extern DebugConsole DebugC1;
extern TCreateWindow TrogWin;

 


//Handles Key presses from the keyboard
 int TConsoleKeys::HandleKeyEvent()
{
	if(TrogWin.keys[VK_BACK]) //Backspace Key
	{
		if(DebugC1.GetIsActive())
		{
			//Check to see if key was already pressed and not released
				if(TrogWin.preKeys[VK_BACK])
				{
					//Allows keys to repeat after being held down for repeatspeed cycles
					Held[0] += 1;
					if(Held[0]<repeatspeed/2)
					{
						return 0;
					}

					else
					{
						Held[0] = 0;
					}
				}
			DebugC1.FillBuffers("VK_BACK");

			TrogWin.preKeys[VK_BACK]=true;
		}
		
	}

	if(TrogWin.keys[VK_TAB]) //Tab Key
	{
		if(DebugC1.GetIsActive())
		{
			//Check to see if key was already pressed and not released
				if(TrogWin.preKeys[VK_TAB])
				{
					//Allows keys to repeat after being held down for repeatspeed cycles
					Held[1] += 1;
					if(Held[1]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[1] = 0;
					}
				}
			DebugC1.FillBuffers("VK_TAB");
			TrogWin.preKeys[VK_TAB]=true;
		}
		
	}

	if(TrogWin.keys[VK_CLEAR]) //Unknown Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[2] += 1;
					if(Held[2]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[2] = 0;
					}
		
	}

	if(TrogWin.keys[VK_RETURN]) //Enter Key
	{

		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_RETURN])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[3] += 1;
					if(Held[3]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[3] = 0;
					}
			}
			DebugC1.FillBuffers("VK_RETURN");
			TrogWin.preKeys[VK_RETURN]=true;
			

		}

		//Add aditional Game State Handling
		
	}

	if(TrogWin.keys[VK_SHIFT]) //Shift Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					
	}

	if(TrogWin.keys[VK_CONTROL]) //Ctrl Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[5] += 1;
					if(Held[5]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[5] = 0;
					}
		
	}

	if(TrogWin.keys[VK_MENU]) //ALT Key
	{
		
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[6] += 1;
					if(Held[6]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[6] = 0;
					}
		
	}

	if(TrogWin.keys[VK_PAUSE]) //Pause/Break Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[7] += 1;
					if(Held[7]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[7] = 0;
					}
		if(MainState.GetPause()==false)
		{

			MainState.SetPause(true);
			

		}

		else
		{
			MainState.SetPause(false);
			
		}

		
	}

	if(TrogWin.keys[VK_CAPITAL]) //Caps Lock Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[8] += 1;
					if(Held[8]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[8] = 0;
					}
	}

	if(TrogWin.keys[VK_ESCAPE]) //Escape Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[9] += 1;
					if(Held[9]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[9] = 0;
					}
		
	}

	if(TrogWin.keys[VK_SPACE]) //Space Bar Key
	{
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_SPACE])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[10] += 1;
					if(Held[10]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[10] = 0;
					}
			}

			DebugC1.FillBuffers("SPACE");
			TrogWin.preKeys[VK_SPACE]=true;
			

		}

		
	}

	if(TrogWin.keys[VK_PRIOR]) //Page Up Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[11] += 1;
					if(Held[11]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[11] = 0;
					}
		
	}

	if(TrogWin.keys[VK_NEXT]) //Page Down Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[12] += 1;
					if(Held[12]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[12] = 0;
					}
	}

	if(TrogWin.keys[VK_END]) //End Key
	{
		//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_END])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[13] += 1;
					if(Held[13]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[13] = 0;
					}
			}

		//Key for activating & deactivating the console
		if(!DebugC1.GetIsActive())
		{
			DebugC1.SetIsActive(true);
			TrogWin.preKeys[VK_END]=true;
			
		}

		else
		{
			DebugC1.SetIsActive(false);
			TrogWin.preKeys[VK_END]=true;
			
		}
		
	}

	if(TrogWin.keys[VK_HOME]) //Home Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[14] += 1;
					if(Held[14]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[14] = 0;
					}
		
		
	}

	if(TrogWin.keys[VK_LEFT]) //LEFT arrow Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[15] += 1;
					if(Held[15]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[15] = 0;
					}
		
	}

	if(TrogWin.keys[VK_UP]) //Up arrow Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[16] += 1;
					if(Held[16]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[16] = 0;
					}
		
	}

	if(TrogWin.keys[VK_RIGHT]) //Right arrow Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[17] += 1;
					if(Held[17]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[17] = 0;
					}
		
	}

	if(TrogWin.keys[VK_DOWN]) //Down arrow Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[18] += 1;
					if(Held[18]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[18] = 0;
					}
		
	}

	if(TrogWin.keys[VK_PRINT]) //Print Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[19] += 1;
					if(Held[19]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[19] = 0;
					}
	}

	if(TrogWin.keys[VK_SNAPSHOT]) //Print Screen Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[20] += 1;
					if(Held[20]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[20] = 0;
					}
	}

	if(TrogWin.keys[VK_INSERT]) //Insert Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[21] += 1;
					if(Held[21]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[21] = 0;
					}
	}

	if(TrogWin.keys[VK_DELETE]) //Delete Key
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[22] += 1;
					if(Held[22]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[22] = 0;
					}
		
	}

	//KeyCodes for Alpha/numeric constants

	if(TrogWin.keys['1']) 
	{
		

		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['1'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[23] += 1;
					if(Held[23]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[23] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("!");
				TrogWin.preKeys['1']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("1");
				TrogWin.preKeys['1']=true;
				
			}
			
		}

		
	}

	if(TrogWin.keys['2']) 
	{

		

		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['2'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[24] += 1;
					if(Held[24]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[24] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("@");
				TrogWin.preKeys['2']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("2");
				TrogWin.preKeys['2']=true;
				
			}
		
			
		}
	}

	if(TrogWin.keys['3']) 
	{

		
		
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['3'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[25] += 1;
					if(Held[25]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[25] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("#");
				TrogWin.preKeys['3']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("3");
				TrogWin.preKeys['3']=true;
				
			}
	
			
		}
	}

	if(TrogWin.keys['4']) 
	{
		

		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['4'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[26] += 1;
					if(Held[26]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[26] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("$");
				TrogWin.preKeys['4']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("4");
				TrogWin.preKeys['4']=true;
				
			}
		
			
		}
	}

	if(TrogWin.keys['5']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['5'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[27] += 1;
					if(Held[27]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[27] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("%");
				TrogWin.preKeys['5']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("5");
				TrogWin.preKeys['5']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['6']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['6'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[28] += 1;
					if(Held[28]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[28] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("^");
				TrogWin.preKeys['6']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("6");
				TrogWin.preKeys['6']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['7']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['7'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[29] += 1;
					if(Held[29]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[29] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("&");
				TrogWin.preKeys['7']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("7");
				TrogWin.preKeys['7']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['8']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['8'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[30] += 1;
					if(Held[30]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[30] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("*");
				TrogWin.preKeys['8']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("8");
				TrogWin.preKeys['8']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['9']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['9'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[31] += 1;
					if(Held[31]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[31] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("(");
				TrogWin.preKeys['9']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("9");
				TrogWin.preKeys['9']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['0']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['0'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[32] += 1;
					if(Held[32]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[32] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers(")");
				TrogWin.preKeys['0']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("0");
				TrogWin.preKeys['0']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys[65]) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[65])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[34] += 1;
					if(Held[34]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[34] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("A");
				TrogWin.preKeys[65]=true;
				
			}
			else
			{
				DebugC1.FillBuffers("a");
				TrogWin.preKeys[65]=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
		
	}

	if(TrogWin.keys['B']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['B'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[35] += 1;
					if(Held[35]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[35] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("B");
				TrogWin.preKeys['B']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("b");
				TrogWin.preKeys['B']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['C']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['C'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[36] += 1;
					if(Held[36]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[36] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("C");
				TrogWin.preKeys['C']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("c");
				TrogWin.preKeys['C']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
	}

	if(TrogWin.keys['D']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['D'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[37] += 1;
					if(Held[37]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[37] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("D");
				TrogWin.preKeys['D']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("d");
				TrogWin.preKeys['D']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['E']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['E'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[38] += 1;
					if(Held[38]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[38] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("E");
				TrogWin.preKeys['E']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("e");
				TrogWin.preKeys['E']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['F']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['F'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[39] += 1;
					if(Held[39]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[39] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("F");
				TrogWin.preKeys['F']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("f");
				TrogWin.preKeys['F']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
	}

	if(TrogWin.keys['G']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['G'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[40] += 1;
					if(Held[40]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[40] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("G");
				TrogWin.preKeys['G']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("g");
				TrogWin.preKeys['G']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['H']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['H'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[41] += 1;
					if(Held[41]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[41] = 0;
					}
			}
			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("H");
				TrogWin.preKeys['H']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("h");
				TrogWin.preKeys['H']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
	}

	if(TrogWin.keys['I']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['I'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[42] += 1;
					if(Held[42]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[42] = 0;
					}
			}
			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("I");
				TrogWin.preKeys['I']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("i");
				TrogWin.preKeys['I']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['J']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['J'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[43] += 1;
					if(Held[43]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[43] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("J");
				TrogWin.preKeys['J']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("j");
				TrogWin.preKeys['J']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['K']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['K'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[44] += 1;
					if(Held[44]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[44] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("K");
				TrogWin.preKeys['K']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("k");
				TrogWin.preKeys['K']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['L']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['L'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[45] += 1;
					if(Held[45]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[45] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("L");
				TrogWin.preKeys['L']=true;
				
				
			}
			else
			{
				DebugC1.FillBuffers("l");
				TrogWin.preKeys['L']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['M']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['M'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[46] += 1;
					if(Held[46]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[46] = 0;
					}
			}
			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("M");
				TrogWin.preKeys['M']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("m");
				TrogWin.preKeys['M']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['N']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['N'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[47] += 1;
					if(Held[47]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[47] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("N");
				TrogWin.preKeys['N']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("n");
				TrogWin.preKeys['N']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['O']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['O'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[48] += 1;
					if(Held[48]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[48] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("O");
				TrogWin.preKeys['O']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("o");
				TrogWin.preKeys['O']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
	}

	if(TrogWin.keys['P']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['P'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[49] += 1;
					if(Held[49]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[49] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("P");
				TrogWin.preKeys['P']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("p");
				TrogWin.preKeys['P']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['Q']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['Q'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[50] += 1;
					if(Held[50]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[50] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("Q");
				TrogWin.preKeys['Q']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("q");
				TrogWin.preKeys['Q']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
	}

	if(TrogWin.keys['R']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['R'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[51] += 1;
					if(Held[51]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[51] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("R");
				TrogWin.preKeys['R']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("r");
				TrogWin.preKeys['R']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
	}

	if(TrogWin.keys['S']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['S'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[52] += 1;
					if(Held[52]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[52] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("S");
				TrogWin.preKeys['S']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("s");
				TrogWin.preKeys['S']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
		
	}

	if(TrogWin.keys['T']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['T'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[53] += 1;
					if(Held[53]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[53] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("T");
				TrogWin.preKeys['T']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("t");
				TrogWin.preKeys['T']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['U']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['U'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[54] += 1;
					if(Held[54]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[54] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("U");
				TrogWin.preKeys['U']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("u");
				TrogWin.preKeys['U']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
	}

	if(TrogWin.keys['V']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['V'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[55] += 1;
					if(Held[55]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[55] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("V");
				TrogWin.preKeys['V']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("v");
				TrogWin.preKeys['V']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['W']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['W'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[56] += 1;
					if(Held[56]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[56] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("W");
				TrogWin.preKeys['W']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("w");
				TrogWin.preKeys['W']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
		
	}

	if(TrogWin.keys['X']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['X'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[57] += 1;
					if(Held[57]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[57] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("X");
				TrogWin.preKeys['X']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("x");
				TrogWin.preKeys['X']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
	}

	if(TrogWin.keys['Y']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['Y'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[58] += 1;
					if(Held[58]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[58] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("Y");
				TrogWin.preKeys['Y']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("y");
				TrogWin.preKeys['Y']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
	}

	if(TrogWin.keys['Z']) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys['Z'])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[59] += 1;
					if(Held[59]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[59] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("Z");
				TrogWin.preKeys['Z']=true;
				
			}
			else
			{
				DebugC1.FillBuffers("z");
				TrogWin.preKeys['Z']=true;
				
			}	
			
			
		}

		//Add Aditional Game State Key Handlings
	}

	if(TrogWin.keys[VK_NUMPAD0]) //Numberpad 0 key
	{
		

		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_NUMPAD0])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[60] += 1;
					if(Held[60]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[60] = 0;
					}
			}

			DebugC1.FillBuffers("0");
			TrogWin.preKeys[VK_NUMPAD0]=true;
		}
		
	}

	if(TrogWin.keys[VK_NUMPAD1]) //Numberpad 1 key
	{
		

		if (DebugC1.GetIsActive())
		{ 

			if(TrogWin.preKeys[VK_NUMPAD1])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[61] += 1;
					if(Held[61]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[61] = 0;
					}
			}

			DebugC1.FillBuffers("1");
			TrogWin.preKeys[VK_NUMPAD1]=true;
		}
	}

	if(TrogWin.keys[VK_NUMPAD2]) //Numberpad 2 key
	{
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_NUMPAD2])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[62] += 1;
					if(Held[62]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[62] = 0;
					}
			}

			DebugC1.FillBuffers("2");
			TrogWin.preKeys[VK_NUMPAD2]=true;
		}
		
	}

	if(TrogWin.keys[VK_NUMPAD3]) //Numberpad 3 key
	{
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_NUMPAD3])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[63] += 1;
					if(Held[63]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[63] = 0;
					}
			}

			DebugC1.FillBuffers("3");
			TrogWin.preKeys[VK_NUMPAD3]=true;
		}
	}

	if(TrogWin.keys[VK_NUMPAD4]) //Numberpad 4 key
	{
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_NUMPAD4])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[64] += 1;
					if(Held[64]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[64] = 0;
					}
			}

			DebugC1.FillBuffers("4");
			TrogWin.preKeys[VK_NUMPAD4]=true;
		}
	}

	if(TrogWin.keys[VK_NUMPAD5]) //Numberpad 5 key
	{
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_NUMPAD5])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[65] += 1;
					if(Held[65]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[65] = 0;
					}
			}

			DebugC1.FillBuffers("5");
			TrogWin.preKeys[VK_NUMPAD5]=true;
		}
	}

	if(TrogWin.keys[VK_NUMPAD6]) //Numberpad 6 key
	{
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_NUMPAD6])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[66] += 1;
					if(Held[66]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[66] = 0;
					}
			}

			DebugC1.FillBuffers("6");
			TrogWin.preKeys[VK_NUMPAD6]=true;
		}
	}

	if(TrogWin.keys[VK_NUMPAD7]) //Numberpad 7 key
	{
		if (DebugC1.GetIsActive())
		{ //Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_NUMPAD7])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[67] += 1;
					if(Held[67]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[67] = 0;
					}
			}

			DebugC1.FillBuffers("7");
			TrogWin.preKeys[VK_NUMPAD7]=true;
		}
	}

	if(TrogWin.keys[VK_NUMPAD8]) //Numberpad 8 key
	{
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_NUMPAD8])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[68] += 1;
					if(Held[68]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[68] = 0;
					}
			}

			DebugC1.FillBuffers("8");
			TrogWin.preKeys[VK_NUMPAD8]=true;
		}
		
	}

	if(TrogWin.keys[VK_NUMPAD9]) //Numberpad 9 key
	{
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_NUMPAD9])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[69] += 1;
					if(Held[69]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[69] = 0;
					}
			}

			DebugC1.FillBuffers("9");
			TrogWin.preKeys[VK_NUMPAD9]=true;

			
			
		}
	}

	if(TrogWin.keys[VK_MULTIPLY]) //*! key
	{
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_MULTIPLY])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[70] += 1;
					if(Held[70]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[70] = 0;
					}
			}

			DebugC1.FillBuffers("*");
			TrogWin.preKeys[VK_MULTIPLY]=true;
		}
	}

	if(TrogWin.keys[VK_ADD]) //+ key
	{
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_ADD])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[71] += 1;
					if(Held[71]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[71] = 0;
					}
			}

			DebugC1.FillBuffers("+");
			TrogWin.preKeys[VK_ADD]=true;
		}

		
	}

	if(TrogWin.keys[VK_SUBTRACT]) // - key
	{
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_SUBTRACT])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[72] += 1;
					if(Held[72]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[72] = 0;
					}
			}

			DebugC1.FillBuffers("-");
			TrogWin.preKeys[VK_SUBTRACT]=true;

			
			
		}
	}

	if(TrogWin.keys[VK_DECIMAL]) // . key
	{
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_DECIMAL])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[73] += 1;
					if(Held[73]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[73] = 0;
					}
			}
			DebugC1.FillBuffers(".");

			TrogWin.preKeys[VK_DECIMAL]=true;
			
			
		}
	}

	if(TrogWin.keys[VK_DIVIDE]) // / key
	{
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[VK_DIVIDE])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[74] += 1;
					if(Held[74]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[74] = 0;
					}
			}

			DebugC1.FillBuffers("/");
			TrogWin.preKeys[VK_DIVIDE]=true;

			
			
		}
	}

	//Function TrogWin.keys

	if(TrogWin.keys[VK_F1]) 
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[75] += 1;
					if(Held[75]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[75] = 0;
					}
		TrogWin.preKeys[VK_F1]=true;
		
	}

	if(TrogWin.keys[VK_F2]) 
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[76] += 1;
					if(Held[76]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[76] = 0;
					}
		TrogWin.preKeys[VK_F2]=true;
	}

	if(TrogWin.keys[VK_F3]) 
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[77] += 1;
					if(Held[77]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[77] = 0;
					}
			TrogWin.preKeys[VK_F3]=true;
	}

	if(TrogWin.keys[VK_F4]) 
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[78] += 1;
					if(Held[78]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[78] = 0;
					}
		TrogWin.preKeys[VK_F4]=true;
	}

	if(TrogWin.keys[VK_F5]) 
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[79] += 1;
					if(Held[79]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[79] = 0;
					}
		TrogWin.preKeys[VK_F5]=true;
	}

	if(TrogWin.keys[VK_F6]) 
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[80] += 1;
					if(Held[80]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[80] = 0;
					}
			TrogWin.preKeys[VK_F6]=true;
	}

	if(TrogWin.keys[VK_F7]) 
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[81] += 1;
					if(Held[81]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[81] = 0;
					}

					TrogWin.preKeys[VK_F7]=true;
	}

	if(TrogWin.keys[VK_F8]) 
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[82] += 1;
					if(Held[82]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[82] = 0;
					}
				TrogWin.preKeys[VK_F8]=true;
	}

	if(TrogWin.keys[VK_F9]) 
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[83] += 1;
					if(Held[83]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[83] = 0;
					}
				TrogWin.preKeys[VK_F9]=true;
	}

	if(TrogWin.keys[VK_F10]) 
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[84] += 1;
					if(Held[84]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[84] = 0;
					}
		
					TrogWin.preKeys[VK_F10]=true;
	}

	if(TrogWin.keys[VK_F11]) 
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[85] += 1;
					if(Held[85]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[85] = 0;
					}

					TrogWin.preKeys[VK_F11]=true;
	}

	if(TrogWin.keys[VK_F12]) 
	{
		//Allows keys to repeat after being held down for repeatspeed cycles
					Held[86] += 1;
					if(Held[86]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[86] = 0;
					}
				TrogWin.preKeys[VK_F12]=true;
	}

	//Special Characters

	if(TrogWin.keys[188]) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 

			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[188])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[87] += 1;
					if(Held[87]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[87] = 0;
					}
			}
			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("<");
				TrogWin.preKeys[188]=true;
				
			}
			else
			{
				DebugC1.FillBuffers(",");
				TrogWin.preKeys[188]=true;
				
			}	
			
			
		
		}
	}

		//Add Aditional Game State Key Handlings

		if(TrogWin.keys[190]) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[190])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[88] += 1;
					if(Held[88]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[88] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers(">");
				TrogWin.preKeys[190]=true;
				
			}
			else
			{
				DebugC1.FillBuffers(".");
				TrogWin.preKeys[190]=true;
				
			}	
			
			
		}
	}

		//Add Aditional Game State Key Handlings

		if(TrogWin.keys[191]) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[191])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[89] += 1;
					if(Held[89]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[89] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("?");
				TrogWin.preKeys[191]=true;
				
			}
			else
			{
				DebugC1.FillBuffers("/");
				TrogWin.preKeys[191]=true;
				
			}	
			
			
		}
		
	}


		//Add Aditional Game State Key Handlings

		if(TrogWin.keys[219]) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[219])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[90] += 1;
					if(Held[90]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[90] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("{");
				TrogWin.preKeys[219]=true;
				
			}
			else
			{
				DebugC1.FillBuffers("[");
				TrogWin.preKeys[219]=true;
				
			}	
			
			
		}
	}

		//Add Aditional Game State Key Handlings

		if(TrogWin.keys[221]) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[221])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[91] += 1;
					if(Held[91]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[91] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("}");
				TrogWin.preKeys[221]=true;
				
			}
			else
			{
				DebugC1.FillBuffers("]");
				TrogWin.preKeys[221]=true;
				
			}	
			
			
		}
	}

		//Add Aditional Game State Key Handlings

		if(TrogWin.keys[220]) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[220])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[92] += 1;
					if(Held[92]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[92] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("|");
				TrogWin.preKeys[220]=true;
				
			}
			else
			{
				DebugC1.FillBuffers("\\");
				TrogWin.preKeys[220]=true;
			}	
			
			
		}
	}

		//Add Aditional Game State Key Handlings

	if(TrogWin.keys[192]) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[192])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[93] += 1;
					if(Held[93]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[93] = 0;
					}
			}

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("~");
				TrogWin.preKeys[192]=true;
				
			}
			else
			{
				DebugC1.FillBuffers("`");
				TrogWin.preKeys[192]=true;
				
			}	
			
			
		}
	}

		//Add Aditional Game State Key Handlings

	if(TrogWin.keys[222]) 
	{
		//Debug Console is Active
		if (DebugC1.GetIsActive())
		{ 
			//Check to see if key was already pressed and not released
			if(TrogWin.preKeys[222])
			{
				//Allows keys to repeat after being held down for repeatspeed cycles
					Held[94] += 1;
					if(Held[94]<repeatspeed)
					{
						return 0;
					}

					else
					{
						Held[94] = 0;
					}
			} 

			if(TrogWin.keys[VK_SHIFT])
			{
				DebugC1.FillBuffers("\"");
				TrogWin.preKeys[222]=true;
				
			}
			else
			{
				DebugC1.FillBuffers("'");
				TrogWin.preKeys[222]=true;
				
			}	
			
			
		}
	}

	

	return 0;
}


int TConsoleKeys::ResetKeyStates() //Resets key states after being released, for repeating keys
{

	int x = 0;

	do
	{
		Held[x]=0; //assign the zero value for number of repeats
		x += 1;    //Increment X until it reaches 255 to reset all keys

	}
	while(x<255);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////////
TConsoleKeys::TConsoleKeys(int x)
	{
		repeatspeed=x;
	}
////////////////////////////////////////////////////////////////////////////////////

TConsoleKeys::~TConsoleKeys()
{
}
/////////////////////////////////////////////////////////////////////////////////////
TConsoleKeys::TConsoleKeys()
{
}
