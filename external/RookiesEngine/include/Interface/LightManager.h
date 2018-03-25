/**
*
* @file     LightManager.h
* @author   Ethan Lin
* @version  1.0
*
* @section  LICENSE
*/


#ifndef __LIGHT_MGR_H__
#define __LIGHT_MGR_H__

class LightManager
{
public:
	virtual ~LightManager() {};
	virtual SunLight* CreateSunLight() = 0;
	virtual SunLight* GetSunLight(int id) = 0;
	virtual void SetAmbientColor(const Vector3& amb) = 0;
	virtual void SetAmbientColor(float ambR, float ambG, float ambB) = 0;
	virtual void GetAmbientColor(Vector3& amb) = 0;
};

#endif
