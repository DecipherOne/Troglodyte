
/*!*******************************************************
* Modified for use with the Troglodyte Game Engine API  *
* By Will Canada (DecipherOne) February 7, 2007         *
*********************************************************


LodePNG version 20070203

Copyright (c) 2005-2007 Lode Vandevenne
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list of 
  conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright notice, 
  this list of conditions and the following disclaimer in the documentation and/
  or other materials provided with the distribution.
  * Neither the name of Lode Vandevenne nor the names of his contributors may be 
  used to endorse or promote products derived from this software without specific 
  prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY 
WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef LODEPNG_H
#define LODEPNG_H



namespace LodePNG
{

/*global functions allowing to load and save a file from/to harddisk*/
bool loadFile(std::vector<unsigned char>& buffer, const std::string& filename);
void saveFile(const std::vector<unsigned char>& buffer, const std::string& filename);



struct Info  //!<information used for both raw and PNG images
{
  /*header (IHDR)*/
  unsigned long colorType; //!<color type
  unsigned long bitDepth;  //!<bits per sample

  /*palette (PLTE)*/
  unsigned long palette_size() const; //!<number of colors in the palette
  unsigned char palette_get(unsigned long index, unsigned long channel) const; //!<precondition: index < palette_size, channel < 4
  void          palette_resize(unsigned long size);
  void          palette_set(unsigned char value, unsigned long index, unsigned long channel); //!<precondition: index < palette_size, channel < 4
  
  /*transparent color key (tRNS)*/
  bool          color_key_defined; //!<is a transparent color key given?
  unsigned long color_key_r;       //!<red/greyscale component of color key
  unsigned long color_key_g;       //!<green component of color key
  unsigned long color_key_b;       //!<blue component of color key
  
  /*additional color info*/
  unsigned long getBpp() const;      //!<bits per pixel
  unsigned long getChannels() const; //!<amount of channels
  bool          isGreyscaleType() const; //!<is it a greyscale type? (colorType 0 or 4)
  bool          isAlphaType() const;     //!<has it an alpha channel? (colorType 2 or 6)
  
  Info();
  
  private:
  std::vector<unsigned char> palette; //!<palette in RGBARGBA... order
};

struct InfoPng : public Info //!<information about the PNG image
{
  InfoPng();
  
  /*header (IHDR)*/
  unsigned long width;             //!<width of the image in pixels
  unsigned long height;            //!<height of the image in pixels
  unsigned long compressionMethod; //!<compression method of the original file
  unsigned long filterMethod;      //!<filter method of the original file
  unsigned long interlaceMethod;   //!<interlace method of the original file
  
  /*suggested background color (bKGD)*/
  bool          background_defined; //!<is a suggested background color given?
  unsigned long background_r;       //!<red component of sugg. background color
  unsigned long background_g;       //!<green component of sugg. background color
  unsigned long background_b;       //!<blue component of sugg. background color
  
  /*text chunks (tEXt)*/
  unsigned long text_size() const;
  const char*   text_key(unsigned long index) const; //!<precondition: index < text_size
  const char*   text_string(unsigned long index) const; //!<precondition: index < text_size
  void          text_clear();
  void          text_add(const char* key, const char* str);
  
  private:
  std::vector<std::string> text_keys; //!<the key word of a text chunk (e.g. "Comment")
  std::vector<std::string> text_strings; //!<the actual text
};

struct InfoRaw : public Info //!<contains user-chosen information about the raw image data, which is independent of the PNG image
{
};

class Decoder
{
  public:
  Decoder();
  
  /*decoding functions*/
  void decode(std::vector<unsigned char>& out, const unsigned char* in, unsigned long size);
  void decode(std::vector<unsigned char>& out, const std::vector<unsigned char>& in);
  
  void inspect(const unsigned char* in, unsigned long size);
  void inspect(const std::vector<unsigned char>& in);
  
  /*error checking after decoding*/
  bool hasError() const;
  int getError() const;
  
  /*get image size after decoding*/
  unsigned long getWidth() const; //!<the width in pixels
  unsigned long getHeight() const; //!<the height in pixels
  
  struct Settings
  {
    bool color_convert;
    
    bool readTextChunks;
    bool ignoreCrc;
    bool ignoreAdler32;
    
    Settings();
  };

  void setSettings(const Settings& settings);
  const Settings& getSettings() const;
  Settings& getSettings();
 
  //!<other image info after decoding
  const InfoPng& getInfoPng() const;
  
  void setInfoRaw(const InfoRaw& infoRaw);
  const InfoRaw& getInfoRaw() const;
  InfoRaw& getInfoRaw();

  private:
  InfoPng infoPng;
  InfoRaw infoRaw;
  Settings settings;

  int error; //!<the error value of the decode attempt

  void readPngHeader(const unsigned char* in, size_t inlength);
  void unFilterScanline(unsigned char* recon, const unsigned char* scanline, const unsigned char* precon, size_t bytewidth, unsigned long filterType, size_t length);
  void adam7Pass(unsigned char* out, unsigned char* scanlinen, unsigned char* scanlineo, const unsigned char* in, unsigned long w, size_t bytewidth, size_t passleft, size_t passtop, size_t spacex, size_t spacey, size_t passw, size_t passh, unsigned long bpp);
  void resetParameters();
  void decodeGeneric(std::vector<unsigned char>& out, const unsigned char* in, unsigned long size);
};

class Encoder
{
  public:
  
  struct Settings
  {
    bool autoLeaveOutAlphaChannel; //!<automatically use color type without alpha instead of given one, if given image is opaque

    /*LZ77 related settings*/
    unsigned long btype; //!<the block type for LZ
    bool useLZ77; //!<whether or not to use LZ77
    unsigned long windowSize; //!<the maximum is 32768
    
    Settings();
  };
  
  void encode(std::vector<unsigned char>& out, const unsigned char* image, unsigned long w, unsigned long h);
  void encode(std::vector<unsigned char>& out, const std::vector<unsigned char>& image, unsigned long w, unsigned long h);
  
  void setSettings(const Settings& settings);
  const Settings& getSettings() const;
  Settings& getSettings();
  
  void setInfoPng(const InfoPng& info);
  const InfoPng& getInfoPng() const;
  InfoPng& getInfoPng(); //!<get and set the info
  
  void setInfoRaw(const InfoRaw& infoRaw);
  const InfoRaw& getInfoRaw() const;
  InfoRaw& getInfoRaw();
  
  bool hasError() const;
  int getError() const;
  
  Encoder();
  
  private:
  InfoPng user_infoPng; //!<the info specified by the user may not be changed by the encoder. The encoder will try to generate a PNG close to the given info.
  InfoPng infoPng; //!<the info used by the encoder, generated out of user_infoPng
  Settings settings; //!<the settings specified by the user may not be changed by the encoder
  InfoRaw infoRaw;
  int error;

  void resetParameters();
  void addChunk(std::vector<unsigned char>& out, const std::string& chunkName, unsigned char* data, size_t length);
  void writeSignature(std::vector<unsigned char>& out);
  void writeChunk_tEXt(std::vector<unsigned char>& out, const std::string& keyword, const std::string& textstring);
  void writeChunk_IHDR(std::vector<unsigned char>& out, unsigned long w, unsigned long h, unsigned long bitDepth, unsigned long colorType);
  void writeChunk_IDAT(std::vector<unsigned char>& out, const std::vector<unsigned char>& data);
  void writeChunk_IEND(std::vector<unsigned char>& out);
  void filterScanline(unsigned char* out, const unsigned char* scanline, const unsigned char* prevline, size_t length, size_t bytewidth, int filterType);
  void filter(std::vector<unsigned char>& out, const unsigned char* image, unsigned long size, unsigned long w, unsigned long h); //!<will filter scanline per scanline and add filter type in front
  void dontFilter(std::vector<unsigned char>& out, const unsigned char* image, unsigned long size, unsigned long w, unsigned long h);
};


} //end of namespace

/*!
TODO:
[X] errors for the encoder
[ ] new huffman tree representation
[ ] encoding with dynamic huffman tree
[ ] faster LZ77 encoder
[ ] encoding image with palette
[X] converting to greyscale and greyscale with alpha
[ ] converting to 16-bit types
[ ] add option to store ignored chunks in InfoPng
[ ] Editor class
[ ] Generating PNGs with Adam7 interlace
[X] add "inspect" to decoder, which reads only header information
[X] the spec requires the length of a PNG chunk to be <= (2^31)-1, treat this as error in decoder
[ ] make sure encoder generates no chunks with size > (2^31)-1
[ ] partial decoding
[ ] let the "isFullyOpaque" function check color keys too
*/

#endif


/*!
LodePNG Documentation
---------------------

0. table of contents
--------------------

  1. about
   1.1. supported features
   1.2. features not supported
  2. decoder
  3. encoder
  4. color conversions
  5. info values
  6. error values
  7. file IO
  8. compiling
  9. examples
   9.1. decoder example
   9.2. SDL example
   9.3. encoder example
   9.4. greyscale example
  10. changes
  11. contact information

1. about
--------

PNG is a file format to store raster images losslessly with good compression,
supporting different color types. It can be implemented in a patent-free way.

LodePNG is a PNG codec according to the Portable Network Graphics (PNG)
Specification (Second Edition) - W3C Recommendation 10 November 2003.

The specifications used are:

*) Portable Network Graphics (PNG) Specification (Second Edition):
     http://!<www.w3.org/TR/2003/REC-PNG-20031110
*) RFC 1950 ZLIB Compressed Data Format version 3.3:
     http://!<www.gzip.org/zlib/rfc-zlib.html
*) RFC 1951 DEFLATE Compressed Data Format Specification ver 1.3:
     http://!<www.gzip.org/zlib/rfc-deflate.html

The most recent version of LodePNG can currently be found at
http://!<student.kuleuven.be/~m0216922/pngloader/
However, this location is temporary and won't exist anymore in 2007.

LodePNG exists out of the source code files lodepng.cpp and lodepng.h

LodePNG is simple but only supports the basic requirements. In the tradeoff
between functionality and simplicity, LodePNG is on the side of simplicity.
To achieve this simplicity, the following design choices were made: There
are no dependencies on any external library. To decode PNGs, there's a Decoder
class that can convert any PNG file data into an RGBA image buffer with a single
function call. To encode PNGs, there's an Encoder class that can convert image
data into PNG file data with a single function call. To read and write files, a
simple File class was added.

This all makes LodePNG suitable for loading textures in games, raytracers,
intros, or for loading images into programs that require them only for simple
usage. It's less suitable for full fledged image editors, loading PNGs over
network (since this decoder requires all the image data to be available before
the decoding can begin), life-critical systems, ... Even though it contains
a conformant decoder and encoder, it's still not a conformant editor,
because unknown chunks are discarded.

Because LodePNG is BSD licensed, it's allowed to use these source files in any
project, as long as you include the above copyright message and conditions
somewhere in the release of your program.

Originally the .cpp file was less than 1000 lines of code, the header file
contained only 2 functions, and the decoder wasn't a C++ class, but due to all
the possible settings and the encoder added, it became bigger. I've made sure
that the usage is still as simple as before though, the image is still decoded
with a single function call, and the default settings still show very reasonable
behaviour for usage in games (automatically converting the result to 32-bit).

1.1. supported features
-----------------------

The following features are supported by the decoder:

*) decoding of PNGs with any color type, bit depth and interlace mode
*) (auto) conversion of color types, from any color type, to 24-bit, 32-bit, ...
*) loading the image from harddisk or decoding it from a buffer
*) support for translucent PNG's, including translucent palettes and color key
*) zlib decompression (inflate)
*) encoding of PNGs, with 24-bit, 32-bit color or greyscale
*) zlib compression (deflate), but no dynamic huffman, and rather slow
*) the following chunks are interpreted by the decoder:
    IHDR (header information)
    PLTE (color palette)
    IDAT (pixel data)
    IEND (the final chunk)
    tRNS (transparency for palettized images)
    bKGD (suggested background color)
    tEXt (textual information)

1.2. features not supported
---------------------------

The following features are _not_ supported:

*) editing a PNG image (unless you use the decoder, then edit it, then use the
    encoder, but ignored chunks will then be gone from the original image)
*) encoding PNGs with a palette
*) partial loading. All data must be available and is processed in one call.
*) The following optional chunks are ignored and discarded by the decoder:
    cHRM (device independent color info)
    gAMA (device independent color info)
    iCCP (device independent color info)
    sRGB (device independent color info)
    sBIT (original number of significant bits)
    zTXt (compressed textual information)
    iTXt (international textual information)
    hIST (palette histogram)
    pHYs (physical pixel dimensions)
    sPLT (suggested reduced palette)
    tIME (last image modification time)


2. decoder
----------

The Decoder class can be used to convert a PNG image to a raw image.

You have to give the decoder the contents of a PNG file, as an unsigned char*
buffer. The result is stored in a given std::vector.

The parameters of the decode function are:
*) out: this vector will be filled with the raw image pixels
*) in: pointer to the PNG image data or vector with the data
*) size: the size of the PNG image data (this parameter not needed for vector)

There's also a function "inspect". It has the same parameters as decode except
the "out" parameter. This function will read _only_ the header chunk of the PNG
image, and store the information from it in the InfoPng (see below). This allows
knowing information about the image without decoding it. Only the header (IHDR)
information is read by this, not text chunks, not the palette, ...

During the decoding it's possible that an error can happen, for example if the
PNG image was corrupted. To check if an error happened during the last decoding,
use hasError(). To get the value of the error, use getError(). The error codes
are explained in another section.

The Decoder contains 3 components:
*) InfoPng: it stores information about the PNG (the input) in an InfoPng struct
*) Settings: you can specify a few other settings for the decoder to use
*) InfoRaw: here you can say what type of raw image (the output) you want to get

Each of these 3 components can be set and gotten with getters and setters,
except InfoPng which, in the case of the Decoder, can only be read from.

=InfoPng=

This contains information such as the original color type of the PNG image, text
comments, suggested background color, etc... More details about the InfoPng struct
are in another section. Because the dimensions of the image are important, there
are shortcuts to get them: use getWidth() and getHeight(), or the width and
height properties of the InfoPng struct.

=InfoRaw=

In the InfoRaw struct of the Decoder, you can specify which color type you want
the resulting raw image to be. If this is different from the colorType of the
PNG, then the decoder will automatically convert the result to your InfoRaw
settings. Currently the following options are supported to convert to:
-colorType 6, bitDepth 8: 32-bit RGBA
-colorType 2, bitDepth 8: 24-bit RGB
-other color types if it's exactly the same as that in the PNG image

Palette and color key of InfoRaw are not used by the Decoder. If the setting
color_convert is false then InfoRaw is ignored.

By default, 32-bit color is used for the result.

=Settings=

The Settings can be used to ignore the errors created by invalid CRC and Adler32
chunks, and to disable the decoding of tEXt chunks.

There's also a setting color_convert, true by default. If false, no conversion
is done, the resulting data will be as it was in the PNG (after decompression)
and you'll have to puzzle the colors of the pixels together yourself using the
color type information in the InfoPng.


3. encoder
----------

The Encoder class can be used to convert raw image data into a PNG image.

The PNG part of the encoder is working good, but the zlib compression part isn't
the greatest. Still it can be useful due to its simplicity.

The raw image given to the encoder is an unsigned char* buffer. You also have to
specify the width and height of the raw image. The result is stored in a given
std::vector.

The parameters of the encode function are:
*) out: in this vector the PNG file data will be stored
*) in: vector of or pointer to a buffer containing the raw image
*) w and h: the width and height of the raw image in pixels

Make sure that the in buffer you provide, is big enough to contain w * h pixels
of the color type specified by the InfoRaw.

The encoder generates some errors but not for everything, because, unlike when
decoding a PNG, when encoding one there aren't so much parameters of the input
that can be corrupted. It's the responsibility of the user to make sure that all
preconditions are satesfied, such as giving a correct window size, giving an
existing btype, making sure the given buffer is large enough to contain an image
with the given width and height and colortype, ... The encoder can generate
some errors, see the section with the explanations of errors for those.

Like the Decoder, the Encoder has 3 components:
*) InfoRaw: here you say what color type of the raw image (the input) has
*) Settings: you can specify a few settings for the encoder to use
*) InfoPng: the same InfoPng struct as created by the Decoder. For the encoder,
with this you specify how you want the PNG (the output) to be.

Each of these can be gotten and set with getters and setters.

=InfoPng=

The Decoder class stores information about the PNG image in an InfoPng object. With
the Encoder you can do the opposite: you give it an InfoPng object, and it'll try
to match the InfoPng you give as close as possible in the PNG it encodes. For
example in the InfoPng you can specify the color type you want to use, possible
tEXt chunks you want the PNG to contain, etc... For an explanation of all the
values in InfoPng see a further section. Not all PNG color types are supported
by the Encoder.

Note that the encoder will only TRY to match the InfoPng struct you give. A lot of
things are ignored by the encoder, such as the palette and suggested background
color. And the width and height of InfoPng are ignored as well, because instead the
width and height of the raw image you give in the input are used, for obvious
reasons. In fact the encoder currently uses only the following settings from it:
-colorType: it only supports "2" and "6".
-text chunks, that you can add to the InfoPng with "text_add"

=InfoRaw=

You specify the color type of the raw image that you give to the input here,
including a possible transparent color key and palette you happen to be using in
your raw image data.

By default, 32-bit color is assumed, meaning your input has to be in RGBA
format with 4 bytes (unsigned chars) per pixel.

=Settings=

The following settings are supported:
*) autoLeaveOutAlphaChannel: when this option is enabled, when you specify a PNG
color type with alpha channel (not to be confused with the color type of the raw
image you specify!!), but the encoder detects that all pixels of the given image
are opaque, then it'll automatically use the corresponding type without alpha
channel, resulting in a smaller PNG image.
*) btype: the block type for LZ77. Currently the types 0 = uncompressed, and 1 = fixed huffman tree, are supported.
*) useLZ77: whether or not to use LZ77 for compressed block types
*) windowSize: the window size used by the LZ77 encoder, the minimum is 1, the maximum is 32768


4. color conversions
--------------------

=PNG color types=

A PNG image can have many color types, ranging from 1-bit color to 64-bit color,
as well as palettized color modes. After the zlib decompression and unfiltering
in the PNG image is done, the raw pixel data will have that color type and thus
a certain amount of bits per pixel. If you want the output raw image after
decoding to have another color type, a conversion is done by LodePNG.

The PNG specification mentions the following color types:

0: greyscale, bit depths 1, 2, 4, 8, 16
2: RGB, bit depths 8 and 16
3: palette, bit depths 1, 2, 4 and 8
4: greyscale with alpha, bit depths 8 and 16
6: RGBA, bit depths 8 and 16

Bit depth is the amount of bits per color channel.

=Default Behaviour=

By default, the Decoder will convert the data from the PNG to 32-bit RGBA color,
no matter what color type the PNG has, so that the result can be used directly
as a texture in OpenGL etc... without worries about what color type the PNG
image has.

The Encoder assumes by default that the raw input you give it is a 32-bit RGBA
buffer and will store the PNG as either 32 bit or 24 bit depending on whether
or not any translucent were detected in it.

To get the default behaviour, don't change the values of InfoRaw and InfoPng of
the encoder, and don't change the values of InfoRaw of the decoder.

=Color Conversions=

As explained in the sections about the Encoder and Decoder, you can specify
color types and bit depths in InfoPng and InfoRaw, to change the default behaviour
explained above. (for the Decoder you can only specify the InfoRaw, because the
InfoPng contains what the PNG file has).

To avoid some confusion:
-the Decoder converts from PNG to raw image
-the Encoder converts from raw image to PNG
-the color type and bit depth in InfoRaw, are those of the raw image
-the color type and bit depth in InfoPng, are those of the PNG
-if the color type of the InfoRaw and PNG image aren't the same, a conversion
between the color types is done by the Encoder or Decoder, if the color type is
supported

Supported color types:
-Both encoder and decoder use the same converter. So both encoder and decoder
suport the same color types at the input and the output. But for the encoder
the input is the raw image and the output the PNG image, while for the decoder
the input is the PNG image and the output the raw image. So the decoder supports
any type of PNG image, while the encoder supports any type of raw data but only
certain color types for the output PNG.
-The converter can convert from _any_ input color type, to 24-bit RGB or 32-bit RGBA
-The converter can convert from greyscale input color type, to 8-bit greyscale or greyscale with alpha
-If both color types are the same, conversion from anything to anything is possible
-Color types that are invalid according to the PNG specification are not allowed
-When converting from a type with alpha channel to one without, the alpha channel information is discarded
-When converting from a type without alpha channel to one with, the result will be opaque except pixels that have the same color as the color key of the input if one was given
-When converting from 16-bit bitDepth to 8-bit bitDepth, the 16-bit precision information is lost, only the most significant byte is taken
-Converting from color to greyscale is not supported on purpose: choosing what kind of color to greyscale conversion to do is not a decision a PNG coded should make
-Converting from/to a palette type, only keeps the indices, it ignores the colors defined in the palette

No conversion needed...:
-If the color type of the PNG image and raw image are the same, then no
conversion is done, and all color types are supported.
-In the encoder, you can make it save a PNG with any color type except
palettized color, by giving the InfoRaw and InfoPng the same color type.
-In the decoder, you can make it store the pixel data in the same color type
as the PNG has, by setting the color_convert setting to false


5. info values
--------------

Both the encoder and decoder use a variables of type InfoPng and InfoRaw. Here's
a list of each of the values stored in them:

*) info from the PNG header:

width:             width of the image in pixels
height:            height of the image in pixels
colorType:         color type of the original PNG file
bitDepth:          bits per sample
compressionMethod: compression method of the original file
filterMethod:      filter method of the original file
interlaceMethod:   interlace method of the original file

*) palette:

palette_size:   number of RGBA colors in the palette
palette_get:    function used to get a certain palette color channel. Precondition: index < palette_size, channel < 4
palette_resize: function to resize the palette
palette_set:    function used to set a certain palette color channel. Precondition: index < palette_size, channel < 4

Note that the palette information from the tRNS chunk is also already included.

*) transparent color key

color_key_defined: is a transparent color key given?
color_key_r:       red/greyscale component of color key
color_key_g:       green component of color key
color_key_b:       blue component of color key

This color is 8-bit for 8-bit PNGs, 16-bit for 16-bit PNGs.

*) suggested background color

background_defined: is a suggested background color given?
background_r:       red component of sugg. background color
background_g:       green component of sugg. background color
background_b:       blue component of sugg. background color

This color is 8-bit for 8-bit PNGs, 16-bit for 16-bit PNGs

The decoder pretty much ignores this background color, after all if you make a
PNG translucent normally you intend it to be used against any background, on
websites, as translucent textures in games, ... But you can get the color this
way if needed.

*) text chunks

Each text chunk has a key and a string. The key can for example be "Author" or "Comment", the string can be "Vincent van Gogh" or "Encoded by ...".

text_size:   get the amount of text chunks that were in the PNG image
text_key:    function to get a certain text key. Precondition: index < text_size
text_string: function to get a certain text string. Precondition: index < text_size
text_clear:  function to clear all texts. After this, text_size will be 0.
text_add:    function used to add a text key and string to the InfoPng, which the Encoder can store in the PNG

*) additional color info

getBpp():          bits per pixel of the PNG image
getChannels():     amount of color channels of the PNG image
isGreyscaleType(): it's color type 0 or 4
isAlphaType():     it's color type 2 or 6

These values are calculated out of color type and bit depth.

The difference between bits per pixel and bit depth is that bit depth is the
number of bits per color channel, while a pixel can have multiple channels.


6. error values
---------------

The meanings of the LodePNG error values (encoder and decoder errors mixed
through each other):

*) 0: no error, everything went ok
*) 1: the Encoder/Decoder has done nothing yet, so error checking makes no sense yetz
*) 10: while huffman decoding: end of input memory reached without endcode
*) 11: while huffman decoding: error in code tree made it jump outside of tree
*) 13: problem while processing dynamic deflate block
*) 14: problem while processing dynamic deflate block
*) 15: problem while processing dynamic deflate block
*) 16: unexisting code while processing dynamic deflate block
*) 17: while inflating: end of out buffer memory reached
*) 18: while inflating: invalid distance code
*) 19: while inflating: end of out buffer memory reached
*) 20: invalid deflate block BTYPE encountered
*) 21: NLEN is not ones complement of LEN in a deflate block
*) 22: while inflating: end of out buffer memory reached.
   This can happen if the inflated deflate data is longer than the amount of bytes required to fill up
   all the pixels of the image, given the color depth and image dimensions. Something that doesn't
   happen in a normal, well encoded, PNG image.
*) 23: while inflating: end of in buffer memory reached
*) 24: invalid FCHECK in zlib header
*) 25: invalid compression method in zlib header
*) 26: FDICT encountered in zlib header while it's not used for PNG
*) 27: PNG file is smaller than a PNG header
*) 28: incorrect PNG signature (the first 8 bytes of the PNG file)
   Maybe it's not a PNG, or a PNG file that got corrupted so that the header indicates the corruption.
*) 29: first chunk is not the header chunk
*) 30: chunk length too large, chunk broken off at end of file
*) 31: illegal PNG color type
*) 32: illegal PNG compression method
*) 33: illegal PNG filter method
*) 34: illegal PNG interlace method
*) 35: chunk length of a chunk is too large or the chunk too small
*) 36: illegal PNG filter type encountered
*) 37: illegal bit depth for this color type given
*) 38: the palette is too big (more than 256 colors)
*) 39: more palette alpha values given in tRNS, than there are colors in the palette
*) 40: tRNS chunk has wrong size for greyscale image
*) 41: tRNS chunk has wrong size for RGB image
*) 42: tRNS chunk appeared while it was not allowed for this color type
*) 43: bKGD chunk has wrong size for palette image
*) 44: bKGD chunk has wrong size for greyscale image
*) 45: bKGD chunk has wrong size for RGB image
*) 46: value encountered in indexed image is larger than the palette size (bitdepth == 8)
*) 47: value encountered in indexed image is larger than the palette size (bitdepth < 8)
*) 48: the input data is empty. Maybe a PNG file you tried to load doesn't exist or is in the wrong path.
*) 49: jumped past memory while generating dynamic huffman tree
*) 50: jumped past memory while generating dynamic huffman tree
*) 51: jumped past memory while inflating huffman block
*) 52: jumped past memory while inflating
*) 53: size of zlib data too small
*) 54: CHAR_BITS is smaller than 8 on this platform, an 8-bit datatype is needed to store the file and pixel data
*) 55: jumped past tree while generating huffman tree, this could be when the code
       lengths are not of an optimal tree, which causes there to be more nodes than
       the arrays used can support (e.g. if there are 19 codes a tree has 18 nodes,
       but if all 19 code lengths are 7, there will be much more nodes), this may be a
       BUG that has to be fixed by using a better tree representation, but I've never
       encountered a PNG with this problem in practice.
*) 56: given output image colorType or bitDepth not supported for color conversion
*) 57: invalid CRC encountered (checking CRC can be disabled)
*) 58: invalid ADLER32 encountered (checking ADLER32 can be disabled)
*) 59: conversion to unexisting or unsupported color type or bit depth requested by encoder or decoder
*) 60: invalid window size given in the settings of the encoder (must be 0-32768)
*) 61: invalid or unsupported btype given in the settings of the encoder (0 and 1 are supported, 2 not yet)
*) 62: conversion from non-greyscale color to greyscale color requested by encoder or decoder. LodePNG
       leaves the choice of RGB to greyscale conversion formula to the user.
*) 63: length of a chunk too long, max allowed for PNG is 2147483647 bytes per chunk (2^31-1)


7. file IO
----------

For cases where you want to load the PNG image from a file, you can use your own
file loading code, or the file loading and saving functions provided with
LodePNG. These use the same unsigned char format used by the Decoder and Encoder.

The loadFile function fills the given std::vector up with the file from harddisk
with the given name.

The saveFile function saves the contents of the given buffer to the file
with given name. Warning: this overwrites the contents that were previously in
the file if it already existed, without warning.

Note that you don't have to decode a PNG image from a file, you can as well
retrieve the buffer another way in your code, because the decode function takes
a buffer as parameter, not a filename.


8. compiling
------------

LodePNG is designed for standard C++. Some old compilers that do not correctly
support standard C++ may not be able to compile LodePNG correctly. Please use
a compiler that supports the current standard.

No libraries other than the standard C++ library are needed to compile LodePNG.
Add lodepng.cpp and lodepng.h to the collection of source code files of your
project, #include the lodepng.h header where needed, and your program can
decode PNG files.

Letting the compiler use optimization makes the PNG decoder significantly
faster than without optimization, and the encoder even more. In g++, use
the -O1, -O2 or -O3 option. Most IDEs provide options for enabling
optimization.

Especially for the encoder: Use Optimization!

std::vectors are used in the interface. Therefore, make sure that LodePNG is
compiled with the same compiler, with the same version and settings, as the code
that uses LodePNG, or the interfaces can be incompatible resulting in bad things.


9. examples
-----------

These examples demonstrate the usage of LodePNG and can be used as test. Place
the example code in a new .cpp file, and compile together with lodepng.cpp and
lodepng.h, with optimization.

The first example decodes the image and displays the information in the console.
The second example will decode the image and show the image in an SDL window,
provided this library (Simple DirectMedia Layer) is available on the system.
The third will encode a PNG image and save it to the given filename. The fourth
shows some other features.

Run the example executables from command line with the filename as parameter.


9.1. console example
--------------------

//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<
//!< LodePNG console example
//!< This example decodes a PNG file and displays its size in the console
//!< g++ *.cpp -O3
//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<

#include <iostream>
#include "lodepng.h"

int main(int argc, char *argv[])
{
  const char* filename = argc > 1 ? argv[1] : "test.png";
  
  //!<load and decode
  std::vector<unsigned char> buffer, image;
  LodePNG::loadFile(buffer, filename); //!<load the image file with given filename
  LodePNG::Decoder decoder;
  decoder.decode(image, &buffer[0], buffer.size()); //!<decode the png
  
  //!<if there's an error, display it, otherwise display information about the image
  if(decoder.hasError()) std::cout << "error: " << decoder.getError() << std::endl;
  else
  { 
    std::cout << "\n" <<
      "w: " << decoder.getWidth() << "\n" <<
      "h: " << decoder.getHeight() << "\n" <<
      "bitDepth: " << decoder.getInfoPng().bitDepth << "\n" <<
      "bpp: " << decoder.getInfoPng().getBpp() << "\n" <<
      "colorChannels: " << decoder.getInfoPng().getChannels() << "\n" <<
      "paletteSize: " << decoder.getInfoPng().palette_size() << "\n" <<
      "colorType: " << decoder.getInfoPng().colorType << "\n" <<
      "compressionMethod: " << decoder.getInfoPng().compressionMethod << "\n" <<
      "filterMethod: " << decoder.getInfoPng().filterMethod << "\n" <<
      "interlaceMethod: " << decoder.getInfoPng().interlaceMethod << "\n";
    for(size_t i = 0; i < decoder.getInfoPng().text_size(); i++)
      std::cout << decoder.getInfoPng().text_key(i) << ": " << decoder.getInfoPng().text_string(i) << "\n";
  }
  
  return 0;
}
//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<


9.2. SDL example
----------------

//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<
//!< LodePNG SDL example
//!< This example displays a PNG with a checkerboard pattern to show tranparency
//!< It requires the SDL library to compile and run
//!< g++ *.cpp -lSDL -O3
//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<

#include <vector>
#include <iostream>
#include <SDL/SDL.h> //!<requires SDL
#include "lodepng.h"

int main(int argc, char *argv[])
{
  const char* filename = argc > 1 ? argv[1] : "test.png";
  
  std::vector<unsigned char> buffer, image;
  LodePNG::loadFile(buffer, filename); //!<load the image file with given filename
  LodePNG::Decoder decoder;
  decoder.decode(image, &buffer[0], buffer.size()); //!<decode the png
  
  //!<get width, height and pixels
  unsigned long w = decoder.getWidth(), h =  decoder.getHeight();

  //!<stop if there is an error
  if(decoder.hasError())
  {
    std::cout << "error: " <<  decoder.getError() << std::endl;
    return -1;
  }
  
  //!<avoid too large window size by downscaling large image
  unsigned long jump = 1;
  if(w / 1024 >= jump) jump = w / 1024 + 1;
  if(h / 1024 >= jump) jump = h / 1024 + 1;
  
  //!<init SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0) return -1;
  SDL_Surface* scr = SDL_SetVideoMode(w / jump, h / jump, 32, SDL_HWSURFACE);
  if(!scr) return -1;
  SDL_WM_SetCaption(filename, NULL); //!<set window caption
  
  //!<plot the pixels of the PNG file
  for(unsigned long y = 0; y + jump - 1 < h; y += jump)
  for(unsigned long x = 0; x + jump - 1 < w; x += jump)
  {
    //!<get RGBA components
    Uint32 r = image[4 * y * w + 4 * x + 0]; //!<red
    Uint32 g = image[4 * y * w + 4 * x + 1]; //!<green
    Uint32 b = image[4 * y * w + 4 * x + 2]; //!<blue
    Uint32 a = image[4 * y * w + 4 * x + 3]; //!<alpha
    
    //!<make translucency visible by placing checkerboard pattern behind image
    int checkerColor = 191 + 64 * (((x / 16) % 2) == ((y / 16) % 2));
    r = (a * r + (255 - a) * checkerColor) / 255;
    g = (a * g + (255 - a) * checkerColor) / 255;
    b = (a * b + (255 - a) * checkerColor) / 255;
    
    //!<give the color value to the pixel of the screenbuffer
    Uint32* bufp;
    bufp = (Uint32 *)scr->pixels + (y * scr->pitch / 4) / jump + (x / jump);
    *bufp = 65536 * r + 256 * g + b;
  }
  
  //!<pause until you press escape and meanwhile redraw screen
  SDL_Event event;
  int done = 0;
  while(done == 0)
  {
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT) done = 1;
      if(SDL_GetKeyState(NULL)[SDLK_ESCAPE]) done = 1;
    }
    SDL_UpdateRect(scr, 0, 0, 0, 0); //!<redraw screen
    SDL_Delay(5); //!<pause 5 ms so it consumes less processing power
  }
  
  SDL_Quit();
  return 0;
}
//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<


9.3. encoder example
--------------------

//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<
//!< LodePNG Encoder example
//!< This example encodes a PNG containing a generated texture
//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<

#include <vector>
#include <iostream>
#include <cmath>
#include "lodepng.h"

int main(int argc, char *argv[])
{
  //!<check if user gave a filename
  if(argc <= 1)
  {
    std::cout << "please provide a filename to save to\n";
    return 0;
  }
  
  //!<generate some image
  const int w = 512;
  const int h = 512;
  std::vector<unsigned char> image;
  image.resize(w * h * 4);
  for(int y = 0; y < h; y++)
  for(int x = 0; x < w; x++)
  {
    //!<pattern 1
    image[4 * w * y + 4 * x + 0] = int(127 * (1 + std::sin((                    x * x +                     y * y) / (w * h / 8.0))));
    image[4 * w * y + 4 * x + 1] = int(127 * (1 + std::sin(((w - x - 1) * (w - x - 1) +                     y * y) / (w * h / 8.0))));
    image[4 * w * y + 4 * x + 2] = int(127 * (1 + std::sin((                    x * x + (h - y - 1) * (h - y - 1)) / (w * h / 8.0))));
    image[4 * w * y + 4 * x + 3] = int(127 * (1 + std::sin(((w - x - 1) * (w - x - 1) + (h - y - 1) * (h - y - 1)) / (w * h / 8.0))));
    
    //!<pattern 2
    //!<image[4 * w * y + 4 * x + 0] = 255 * !(x & y);
    //!<image[4 * w * y + 4 * x + 1] = x ^ y;
    //!<image[4 * w * y + 4 * x + 2] = x | y;
    //!<image[4 * w * y + 4 * x + 3] = 255;
  }
  
  //!<make some settings (optional)
  LodePNG::Encoder::Settings settings;
  settings.windowSize = 2048;
  
  //!<create encoder and set settings and info (optional)
  LodePNG::Encoder encoder;
  encoder.getInfoPng().text_add("Comment", "Created with LodePNG");
  encoder.setSettings(settings);

  //!<encode and save
  std::vector<unsigned char> buffer;
  encoder.encode(buffer, &image[0], w, h);
  LodePNG::saveFile(buffer, argv[1]);
}

//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<


9.4 greyscale example
---------------------

This example show a bit about inspecting a PNG beforehand to find out its color
type, if it's greyscale, decode directly as greyscale, otherwise convert to
greyscale by taking the average of R, G and B of each pixel.

//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<
//!< LodePNG greyscale example
//!< Load a PNG directly as greyscale if it's greyscale, convert otherwise
//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<

#include <iostream>
#include "lodepng.h"

int main(int argc, char *argv[])
{
  const char* filename = argc > 1 ? argv[1] : "test.png";
  
  //!<load and decode
  std::vector<unsigned char> buffer; //!<the file
  LodePNG::loadFile(buffer, filename); //!<load the image file with given filename
  LodePNG::Decoder decoder;
  
  std::vector<unsigned char> grey; //!<in here the greyscale image will be stored
  
  decoder.inspect(buffer); //!<get information from the header, to see if it's greyscale
  
  if(!decoder.hasError())
  if(decoder.getInfoPng().isGreyscaleType()) //!<only if the PNG image is greyscale, can the output be converted to greyscale by LodePNG
  {
    std::cout << "it's a greyscale PNG\n";
    decoder.getInfoRaw().colorType = 0; //!<set color type "greyscale" for the output
    decoder.decode(grey, buffer);
  }
  else //!<else you have to do color math to convert to greyscale
  {
    std::cout << "it's a color PNG\n";
    decoder.getInfoRaw().colorType = 2; //!<set color type "RGB" for the output
    std::vector<unsigned char> rgb; //!<temporary rgb image
    decoder.decode(rgb, buffer);
    
    grey.resize(rgb.size() / 3);
    for(size_t i = 0; i < grey.size(); i++) grey[i] = (rgb[i * 3 + 0] + rgb[i * 3 + 1] + rgb[i * 3 + 2]) / 3; //!<rgb to greyscale by taking average
  }
  
  if(decoder.hasError()) std::cout << "error: " <<  decoder.getError() << std::endl;
  else std::cout << "read " << grey.size() << " greyscale pixels\n";
  
  return 0;
}
//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<//!<

10. changes
-----------

The version number of LodePNG is the date of the change given in the format
yyyymmdd. Multiple changes on the same date may have the same version number.
Minor changes aren't mentioned here but may still have a different version 
number.

Some changes aren't backwards compatible. Those are indicated with a (!)
symbol. Those changes may require you to change your code when upgrading
from an older version. They are usually for the better.

*) 03 feb 2007: Just some internal changes
*) 27 jan 2007: The Adler-32 implementation wasn't so fast, which made LodePNG
    slower ever since the CRC and Adler-32 checks were added. But I now made the
    Adler-32 checksum test "5550 times" faster so that timewaste is gone.
*) 24 jan 2007: gave encoder an error interface. Added color conversion from any
    greyscale type to 8-bit greyscale with or without alpha.
*) 21 jan 2007: (!) Totally changed the interface. It allows more color types
    to convert to and is more uniform. See the manual for how it works now.
*) 07 jan 2007: Some cleanup & fixes, and a few changes over the last days:
    -encode custom tEXt chunks, and decode tEXt chunks
    -zlib, inflator and deflator have been put in their own classes
    -At last made the decoder check Adler32 and Crc and return errors about it.
*) 01 jan 2007: Fixed bug with encoding PNGs with less than 8 bits per channel.
*) 29 dec 2006: Added support for encoding images without alpha channel, and
    cleaned out code as well as making certain parts faster.
*) 28 dec 2006: Added "Settings" to the encoder.
*) 26 dec 2006: The encoder now does LZ77 encoding and produces much smaller files now.
    Removed some code duplication in the decoder. Fixed little bug in an example.
*) 09 dec 2006: (!) Placed output parameters of public functions as first parameter.
    Fixed a bug of the decoder with 16-bit per color.
*) 15 okt 2006: Changed documentation structure
*) 09 okt 2006: Encoder class added. It encodes a valid PNG image from the
    given image buffer, however for now it's not compressed.
*) 08 sep 2006: (!) Changed to interface with a Decoder class
*) 30 jul 2006: (!) InfoPng , width and height are now retrieved in different
    way. Renamed decodePNG to decodePNGGeneric.
*) 29 jul 2006: (!) Changed the interface: image info is now returned as a
    struct of type LodePNG::Info, instead of a vector, which was a bit clumsy.
*) 28 jul 2006: Cleaned the code and added new error checks.
    Corrected terminology "deflate" into "inflate".
*) 23 jun 2006: Added SDL example in the documentation in the header, this
    example allows easy debugging by displaying the PNG and its transparency.
*) 22 jun 2006: (!) Changed way to obtain error value. Added
    loadFile function for convenience. Made decodePNG32 faster.
*) 21 jun 2006: (!) Changed type of info vector to unsigned long.
    Changed position of palette in info vector. Fixed an important bug that
    happened on PNGs with an uncompressed block.
*) 16 jun 2006: Internally changed int into unsigned long where
    needed, and performed some optimizations.
*) 07 jun 2006: (!) Renamed functions to decodePNG and placed them
    in LodePNG namespace. Changed the order of the parameters. Rewrote the
    documentation in the header. Renamed files to lodepng.cpp and lodepng.h
*) 22 apr 2006: Optimized and improved some code
*) 07 sep 2005: (!) Changed to std::vector interface
*) 12 aug 2005: Initial release


11. contact information
-----------------------

Feel free to contact me with suggestions, problems, comments, ... concerning 
LodePNG. If you encounter a PNG image that doesn't work properly with this
decoder, feel free to send it and I'll use it to find and fix the problem.

My email address is (puzzle the account and domain together with an @ symbol):
Domain: gmail dot com.
Account: lode dot vandevenne.


Copyright (c) 2005-2006 Lode Vandevenne
*/