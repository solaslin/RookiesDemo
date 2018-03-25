/**
*
* @file     RenderTarget.h
* @author   Ethan Lin
* @version  1.0
*
* @section  LICENSE
*/
#ifndef __RENDERTARGET_H__
#define __RENDERTARGET_H__

class RenderTarget
{
public:
    virtual ~RenderTarget() {};
    virtual void SetClearColor(float r, float g, float b, float a) = 0;
	virtual void SetClearColor(const Vector4& color) = 0;
	virtual OGLTexture* GetColorTexture() = 0;
	virtual void SetCamera(ViewCamera* cam) = 0;
	virtual ViewCamera* GetCamera() = 0;
	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;
};


#endif
