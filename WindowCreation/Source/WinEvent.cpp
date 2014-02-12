

#include "PCHEADER.H"



LRESULT CALLBACK WndProc( HWND	hWnd,					// Handle For This Window
				UINT	uMsg,					// Message For This Window
				WPARAM	wParam,					// Additional Message Information
				LPARAM	lParam)					// Additional Message Information
{


	switch (uMsg)								// Check For Windows Messages
	{

		case WM_ACTIVATE:						// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))					// Check Minimization State
			{
				TrogWin.SetActive(true);					// Program Is Active
			}
			else
			{
				TrogWin.SetActive(false);					// Program Is No Longer Active
			}

			break;						// Return To The Message Loop
		}

		case WM_ACTIVATEAPP:
        {
            if(wParam) 
            {
                // App is now active, so re-enable XInput
                XInputEnable(true);
				
            }
            else
            {
                // App is now inactive, so disable XInput to prevent
                // user input from effecting application and to 
                // disable rumble. 
                XInputEnable(false);
				
            }
            break;
        }

		case WM_SYSCOMMAND:						// Intercept System Commands
		{
			switch (wParam)						// Check System Calls
			{
				case SC_SCREENSAVE:				// Screensaver Trying To Start?
				case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
				return 0;					// Prevent From Happening
			}
			break;							// Exit
		}

		case WM_CLOSE:							// Did We Receive A Close Message?
		{
			PostQuitMessage(0);					// Send A Quit Message
			return 0;						// Jump Back
		}

		case WM_KEYDOWN:						// Is A Key Being Held Down?
		{
			TrogWin.keys[wParam] = true;	// If So, Mark It As TRUE
			break;
		}

		case WM_KEYUP:							// Has A Key Been Released?
		{
			TrogWin.keys[wParam] =0;					// If So, Mark It As FALSE
			TrogWin.preKeys[wParam]=0;
			ConKeys.ResetKeyStates();
			break;						

		}
		case WM_ENTERSIZEMOVE:                 //User is draging the window
		{
			MainAudio.suspendAudio = true;
			break;
		}
		
		case WM_EXITSIZEMOVE:
		{
			break;
		}


		case WM_SIZE:							// Resize The OpenGL Window
		{
			switch(wParam)
			{
			case SIZE_MINIMIZED:
				{
					MainAudio.suspendAudio = true;
					break;
				}

			case SIZE_RESTORED:
				{
					
					TrogWin.SetWidth(LOWORD(lParam));
					TrogWin.SetHeight(HIWORD(lParam));
					TrogWin.ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));		// LoWord=Width, HiWord=Height
					MainAudio.suspendAudio = false; //Resume Audio
					break;
				}

				


			default:
				{

					
					
					TrogWin.ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));		// LoWord=Width, HiWord=Height
					//Change our Window class settings to adjust opengl drawing of menus and other things
					TrogWin.SetWidth(LOWORD(lParam));
					TrogWin.SetHeight(HIWORD(lParam));


					return 0;						
				}
			}
		}

		//Mouse events
		
		case WM_MOUSEMOVE:
			{
				GMouse.MousePoint.x = LOWORD(lParam);
				GMouse.MousePoint.y = HIWORD(lParam);
				break;
			}

		case WM_LBUTTONDOWN:
			{
	
				
				GMouse.MouseKeys[0] = true;
				break;
			}

		case WM_LBUTTONUP:
		
			{
				
				GMouse.MouseKeys[0] = false;
				GMouse.PrePress[0] = false;
				break;
			}

		case WM_RBUTTONDOWN:
			{
				
				GMouse.MouseKeys[1] = true;
				break;
			}

		case WM_RBUTTONUP:
			{
				GMouse.MouseKeys[1] = false;
				GMouse.PrePress[1] = false;
				break;
			}

		case WM_MBUTTONDOWN:
			{
				GMouse.MouseKeys[2] = true;
				break;
			}

		case WM_MBUTTONUP:
			{
				GMouse.MouseKeys[2] = false;
				GMouse.PrePress[2] = false;
				break;
			}

			//ADD MORE BUTTONS FOR MOUSE EVENTS
		
		
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}


