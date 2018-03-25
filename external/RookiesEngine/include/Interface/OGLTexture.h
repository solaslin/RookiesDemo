/**
*
* @file     OGLTexture.h
* @author   Ethan Lin
* @version  1.0
*
* @section  LICENSE
*/
#ifndef __OGL_TEXTURE__
#define __OGL_TEXTURE__

class OGLTexture
{
public:
	virtual ~OGLTexture() {};
    
	virtual void UploadTexture(int width, int height, int channels, GLubyte* data, bool isCVMat = false) = 0;
    virtual GLuint GetGLTexObj() = 0;       // need to take out later...
	virtual int GetWidth() { return _width; };
	virtual int GetHeight() { return _height; };
	virtual int GetMemSize() { return _memSize; };
	virtual const char* GetName() { return _name; };

protected:
	const char*	_name;
	int			_width;
	int			_height;
	int			_memSize;
};


#endif
