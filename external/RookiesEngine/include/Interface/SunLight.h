/**
*
* @file     SunLight.h
* @author   Ethan Lin
* @version  1.0
*
* @section  LICENSE
*/


#ifndef __SUNLIGHT_H__
#define __SUNLIGHT_H__

class SunLight
{
public:
	virtual ~SunLight() {};
	virtual void SetColor(const Vector3& color) = 0;
	virtual void SetColor(float R, float G, float B) = 0;
	virtual void SetDirection(const Vector3& dir) = 0;
	virtual void SetDirection(float dirX, float dirY, float dirZ) = 0;
	virtual void SetIntensity(float intense) = 0;

	virtual void GetColor(Vector3& color) = 0;
	virtual void GetDirection(Vector3& dir) = 0;
	virtual float GetIntensity() = 0;
};

#endif
