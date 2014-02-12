/*!****************************************************************************************
* This is a source for initalizing   * This class makes use of the LodePNG class written *
* texture information for Troglodyte * by Lode Vandevenne and slightly modified by me.   *
* Author : Will Canada               *****************************************************
*************************************/

#include "PCHEADER.H"



#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF
 


bool PTexture::loadTexture() 
{


	float maximumAnisotropy;

		//get the value
		glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maximumAnisotropy);
	
	switch(TexType)
	{
		//Loading a Bitmap File
		case RGB_BITMAP:
			{
				PBitmap *image; 

				image = new PBitmap();
				

				if(image==NULL) 
				{
					delete image;
					image = NULL;
					return false;
				}



				//Bind Image As Texture
				if (image->loadBitmap(Name.c_str()))
				{
					glGenTextures(1, &texture[0]); 

					glBindTexture(GL_TEXTURE_2D, texture[0]);
					glTexImage2D(GL_TEXTURE_2D, 0, 3, image->width, image->height, 0, 
								GL_RGB, GL_UNSIGNED_BYTE, image->data);
					glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAX_ANISOTROPY_EXT,maximumAnisotropy);
					glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
					glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
					
					width = image->width;
					height = image->height;
				}

				else 
				{
					MessageBox(NULL,"BMP Texture could not be Created. Program will now Exit.",
						"Texture Creation Error!",MB_OK);
						delete image;
						image = NULL;
					PostQuitMessage(0);
					return false;
				}

					//Delete Temporary Image Buffer
					delete image;
					image = NULL;
					break;
			}
		////////////////////////////////////////////////////////////////////////////////

		//Loading a PNG File
		case PNG:
			{
				//load and decode
				LodePNG::Decoder * decoder;
				decoder = new LodePNG::Decoder();

				if(decoder==NULL) 
				{
					delete decoder;
					decoder = NULL;
					return false;
				}

				std::vector<unsigned char> buffer, image;
				

				

				


				if(!LodePNG::loadFile(buffer, Label)) //load the image file with given filename
				{
					MessageBox(NULL,"The Specified PNG File Could not be found. \n"
							" The Program Will Now Quit!","PNG Decoder Error!",MB_OK);
						delete decoder;
							decoder = NULL;
						PostQuitMessage(0);
						return 0;
				}

				decoder->decode(image, &buffer[0], buffer.size()); //decode the png

				if(decoder->hasError())
				{
					if(decoder->getError() !=1 || decoder->hasError()!= 0)
					{
						MessageBox(NULL,"PNG LOAD ERROR \n"
							" The Program Will Now Quit!","PNG Decoder Error!",MB_OK);
						delete decoder;
							decoder = NULL;
						PostQuitMessage(0);
						return 0;
					}
					
				}

				

				
				
				//bind texture
				glGenTextures(1, &texture[0]); 

					glBindTexture(GL_TEXTURE_2D, texture[0]);
					glTexImage2D(GL_TEXTURE_2D, 0, 4, decoder->getWidth(),decoder->getHeight(), 0, 
						GL_RGBA, GL_UNSIGNED_BYTE,&image[0]);
					glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAX_ANISOTROPY_EXT,maximumAnisotropy);
					glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
					glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

					width = decoder->getWidth();
					height = decoder->getHeight();

					delete decoder;
					decoder = NULL;
				
					


				
				break;
			}

		/////////////////////////////////////////////////////////////////////////////////
		//Loading a Targa File
		case TARGA:
			{

				LTGA *image; 

				image = new LTGA;
				

				if(image==NULL) 
				{
					delete image;
					image = NULL;
					return false;
				}


				//Bind Image As Texture
				if (image->LoadFromFile(Label))
				{
					glGenTextures(1, &texture[0]); 

					glBindTexture(GL_TEXTURE_2D, texture[0]);
					glTexImage2D(GL_TEXTURE_2D, 0, 4, image->GetImageWidth(), image->GetImageHeight(), 0, 
								GL_RGBA, GL_UNSIGNED_BYTE, image->GetPixels());
					glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAX_ANISOTROPY_EXT,maximumAnisotropy);
					glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
					glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

					width = image->GetImageWidth();
					height = image->GetImageHeight();
				}

				else 
				{
					MessageBox(NULL,"TARGA Texture could not be Created. Program will now Exit.",
						"Texture Creation Error!",MB_OK);
						delete image;
						image = NULL;
					PostQuitMessage(0);
					return false;
				}

					//Delete Temporary Image Buffer
					delete image;
					image = NULL;
				
				break;
			}

		/////////////////////////////////////////////////////////////////////////////////////////
		//FRAME BUFFER OBJECT RENDERING TO A TEXTURE
		case FBO:
			{
				// Setup our FBO
				glGenFramebuffersEXT(1, &fbo);
				glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo);

				// Create the render buffer for depth	
				glGenRenderbuffersEXT(1, &depthBuffer);
				glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, depthBuffer);
				glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT, fbo_width, fbo_height);

				// Now setup a texture to render to
				glGenTextures(1, &texture[0]);
				glBindTexture(GL_TEXTURE_2D, texture[0]);
				glTexImage2D(GL_TEXTURE_2D, 0, 4,  fbo_width, fbo_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAX_ANISOTROPY_EXT,maximumAnisotropy);

				// And attach it to the FBO so we can render to it
				glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, texture[0], 0);

				// Attach the depth render buffer to the FBO as it's depth attachment
				glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, depthBuffer);
				

				GLenum status = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
				if(status != GL_FRAMEBUFFER_COMPLETE_EXT)
					exit(1);
				
				glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);	// Unbind the FBO for now

				width = fbo_width;
				height = fbo_height;

				break;
			}
			


		default:
			{
				MessageBox(NULL,"Image Type Not Recognized, Please select either : \n"
				" 0 RGB_BITMAP \n"
				" 1 PNG \n"
				" 2 TARGA \n"
				" 3 Frame Buffer Object\n"
				" Program Will Now Quit!","loadTexture() Error!",MB_OK);
				PostQuitMessage(0);
			}

	}

			
			
		

	

	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////

void PTexture::SetTex2Load(std::string arg)
{
	SetName(arg);

}

//////////////////////////////////////////////////////////////////////////////////////////

bool PTexture::ConString4Screen(std::string arg)
{
	Label = Name.c_str();
	
	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////

std::string PTexture::GetName()
{
	return Name;
}

/////////////////////////////////////////////////////////////////////////////////////////

void PTexture::SetName(std::string arg)
{
	Name = arg;
	ConString4Screen(arg);
}

//////////////////////////////////////////////////////////////////////////////////////////

PTexture::~PTexture()
{
	if(TexType==FBO)
	{
		glDeleteFramebuffersEXT(1, &fbo);
		glDeleteRenderbuffersEXT(1, &depthBuffer);
	}
	
	glDeleteTextures(1,&texture[0]);
}

//////////////////////////////////////////////////////////////////////////////////////////

void PTexture::SetImageType(int arg)
{
	switch(arg)
	{
	case 0:
		{
			TexType = RGB_BITMAP;
			break;
		}

	case 1:
		{
			TexType = PNG;
			break;
		}

	case 2:
		{
			TexType = TARGA;
			break;
		}
	
	case 3:
		{
			TexType = FBO;
			break;
		}


	default:
		{
			if(MessageBox(NULL,"Image Type Not Recognized, Please select either : \n"
				" 0 RGB_BITMAP \n"
				" 1 PNG \n"
				" 2 TARGA \n"
				" 3 FBO \n \n"
				" Continue without loading texture?","SetImageType() Error!",MB_YESNO)==IDNO)
			{
				PostQuitMessage(0);
			}
			break;
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////

int PTexture::GetImageType()
{
	return TexType;
}
///////////////////////////////////////////////////////////////////////////////////////////


bool PTexture::SaveTextureData(fstream &stream)
{
	if(stream.is_open()) //If the file is open
	{

		//Write the size of the current memory allocation for the class Pointers that need saving


				//Set the Volatile Pointer Information

				
		int NameSize = 0;
		NameSize = Name.size();
		
		//Save the offset for the NameSize to be loaded later : MUST BE LOADED FIRST BEFORE STRING DATA
			
		stream.write((char *) &NameSize,sizeof(int));

		//Write the string to the file converting it to a const char * and as the actual size of the string
		stream.write(Name.c_str(),NameSize);
			
		

		//Save the remaining PTexture Data

		stream.write((char *) &TexType,sizeof(int));
		
		
		
	}

	else
	{
		MessageBox(NULL,"Could not write PTexture Data to the file!","PTexture::SaveAnimData() Error!",MB_OK);
		return false;
	}

	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////

bool PTexture::LoadTextureData(fstream &stream)
{

	

	if(stream.is_open())
	{
			int NameSize = 0;

			//Load the offset for the string to be loaded later : MUST BE LOADED FIRST BEFORE STRING DATA
			stream.read((char *) &NameSize,sizeof(int));

			if(NameSize>0)
			{
				char * buffer = new char [NameSize]; //Allocate memory for buffer


				//Read in each byte one at a time for the string data

				int i=0; //used for counting characters

				

				int b =0; //used for incrementing the buffer

				do
				{
					stream.read((buffer+b),sizeof(char)); //Read in the string data

					i +=1;
					b +=1;

				}
				while(i!=NameSize);

				Name = buffer;  //Convert the string data to the string in the struct


				
				int buf = strlen(buffer);     //Get the length of the string data and any extra padding

				if(strlen(buffer) != NameSize) //If the lengths don't match
				{
					if(buf>NameSize) //IF the length is too long remove padding from string
					{

						Name.erase(NameSize, buf);
					}

					else //Data has probably been corrupted.
					{
						MessageBox(NULL,"Texture::NameSize is not the correct size! Unable to Load Texture!",
							"PTexture::LoadAnimData() Error!",MB_OK);
						
					}
					
				}

			

				//delete our pointer
				if(buffer)
				{

					delete buffer;
				}
			}
			//Save the remaining PTexture Data

		stream.read((char *) &TexType,sizeof(int));


		if(NameSize>0)
		{
			//Load the texture to fill out the rest of the texture data
			SetTex2Load(Name);
			loadTexture();
		}

		return true;

	}

	else
	{
		MessageBox(NULL,"Could not read PTexture Data from the file!","PTexture::LoadAnimData() Error!",MB_OK);
		return false;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////

PTexture::PTexture(const char * filename, int arg)
{
	SetName(filename);
	SetImageType(arg);
	ConString4Screen(filename);
	loadTexture();
	fbo_width = 256;
	fbo_height = 256;
	fbo=0;
}

///////////////////////////////////////////////////////////////////////////////////////////
PTexture::PTexture()
{
	Name="temp";
	fbo_width = 256;
	fbo_height = 256;
	fbo=0;
}

///////////////////////////////////////////////////////////////////////////////////////
void PTexture::Set_fbo_w_h(int w, int h)
{

  fbo_width = w;
  fbo_height = h;

}
//////////////////////////////////////////////////////////////////////////////////////

int PTexture::Get_fbo_w()
{
	return fbo_width;
}

//////////////////////////////////////////////////////////////////////////////////////

int PTexture::Get_fbo_h()
{
	return fbo_height;
}

/////////////////////////////////////////////////////////////////////////////////////////
void PTexture::SetShader(bool arg)
{
	if(arg != 1 && arg!=0)
	{
		arg=0;
	}

	using_shader = arg;
}

/////////////////////////////////////////////////////////////////////////////////////////

bool PTexture::GetShader()
{
	return using_shader;
}