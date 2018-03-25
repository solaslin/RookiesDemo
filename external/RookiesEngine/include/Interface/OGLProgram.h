/**
*
* @file     OGLProgram.h
* @author   Ethan Lin
* @version  1.0
*
* @section  LICENSE
*/
#ifndef __OGL_PROGRAM__
#define __OGL_PROGRAM__

class OGLProgram
{
public:
	virtual ~OGLProgram() {};
	virtual const char* GetName() { return _name; };

protected:
	const char*		_name;
};


#endif
