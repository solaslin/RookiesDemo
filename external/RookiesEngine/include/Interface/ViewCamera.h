/**
*
* @file     ViewCamera.h
* @author   Ethan Lin
* @version  1.0
*
* @section  LICENSE
*/


#ifndef __CAMERA_H__
#define __CAMERA_H__

typedef enum
{
	PT_ORTHO = 0,
	PT_PERSPECT = 1
} EProjType;

class PostEffectManager;

class ViewCamera
{
public:
	virtual ~ViewCamera() {};
	virtual void SetNear(float nearP) = 0;
	virtual void SetFar(float farP) = 0;
	virtual void SetProjType(EProjType type) = 0;
	virtual void SetFov(float fovDegree) = 0;
	virtual void SetViewPort(float width, float height) = 0;
	virtual void CopyFrom(ViewCamera* srcCam) = 0;

	virtual Transform* GetTransform() = 0;
	virtual const Matrix44* GetProjectionMtx() = 0;
	virtual const Matrix44* GetViewMtx() = 0;
	virtual void GetPosition(Vector3& pos) = 0;

	virtual void SetPostEffectManager(PostEffectManager* peMgr) = 0;
	virtual PostEffectManager* GetPostEffectManager() = 0;
};

#endif
