/**
*
* @file     Transform.h
* @author   Ethan Lin
* @version  1.0
*
* @section  LICENSE
*/


#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

class Transform
{
public:
	virtual ~Transform() {};

	virtual void SetParent(Transform* parent, bool stayWorldPos = true) = 0;
	//virtual void IgnoreParentScale(bool ignoreS) = 0;

	//
	// operate local transformation 
	// if is not attached, this is the same as "world"
	//
	// translation / position
	virtual void LocalTranslateDelta(float x, float y, float z) = 0;
	virtual void LocalTranslateDelta(const Vector3& trans) = 0;
	virtual void LocalTranslateDeltaX(float value) = 0;
	virtual void LocalTranslateDeltaY(float value) = 0;
	virtual void LocalTranslateDeltaZ(float value) = 0;

	virtual void SetLocalPosition(float x, float y, float z) = 0;
	virtual void SetLocalPosition(const Vector3& pos) = 0;
	virtual void SetLocalPositionX(float value) = 0;
	virtual void SetLocalPositionY(float value) = 0;
	virtual void SetLocalPositionZ(float value) = 0;

	virtual void GetLocalPosition(Vector3& pos) = 0;
	virtual float GetLocalPositionX() = 0;
	virtual float GetLocalPositionY() = 0;
	virtual float GetLocalPositionZ() = 0;
	
	// rotation
	virtual void LocalRotateDeltaXYZ(float pitch, float yaw, float roll, EAngleType angleType = EAngleType::AT_DEGREE) = 0;
	virtual void LocalRotateDeltaXYZ(const Vector3& PYR, EAngleType angleType = EAngleType::AT_DEGREE) = 0;
	virtual void LocalRotateDeltaAroundX(float angle, EAngleType angleType = EAngleType::AT_DEGREE) = 0;
	virtual void LocalRotateDeltaAroundY(float angle, EAngleType angleType = EAngleType::AT_DEGREE) = 0;
	virtual void LocalRotateDeltaAroundZ(float angle, EAngleType angleType = EAngleType::AT_DEGREE) = 0;

	virtual void SetLocalRotationXYZ(float pitch, float yaw, float roll, EAngleType angleType = EAngleType::AT_DEGREE) = 0;
	virtual void SetLocalRotationXYZ(const Vector3& PYR, EAngleType angleType = EAngleType::AT_DEGREE) = 0;
	virtual void SetLocalRotationMtx(const Matrix44& rotMtx) = 0;

	// scale
	virtual void SetLocalScale(float x, float y, float z) = 0;
	virtual void SetLocalScale(const Vector3& scale) = 0;
	virtual void SetLocalScaleX(float value) = 0;
	virtual void SetLocalScaleY(float value) = 0;
	virtual void SetLocalScaleZ(float value) = 0;
	
	virtual void GetLocalScale(Vector3& scale) = 0;
	virtual float GetLocalScaleX() = 0;
	virtual float GetLocalScaleY() = 0;
	virtual float GetLocalScaleZ() = 0;


	//
	// operate world transformation
	//
	// translation / position
	virtual void WorldTranslateDelta(float x, float y, float z) = 0;
	virtual void WorldTranslateDelta(const Vector3& trans) = 0;
	virtual void WorldTranslateDeltaX(float value) = 0;
	virtual void WorldTranslateDeltaY(float value) = 0;
	virtual void WorldTranslateDeltaZ(float value) = 0;
	
	virtual void WorldTranslateDeltaRUF(float right, float up, float fwd) = 0;
	virtual void WorldTranslateDeltaRUF(const Vector3& trans) = 0;
	virtual void WorldTranslateDeltaRight(float value) = 0;
	virtual void WorldTranslateDeltaUp(float value) = 0;
	virtual void WorldTranslateDeltaForward(float value) = 0;

	virtual void SetWorldPosition(float x, float y, float z) = 0;
	virtual void SetWorldPosition(const Vector3& pos) = 0;
	virtual void SetWorldPositionX(float value) = 0;
	virtual void SetWorldPositionY(float value) = 0;
	virtual void SetWorldPositionZ(float value) = 0;

	virtual void GetWorldPosition(Vector3& pos) = 0;
	virtual float GetWorldPositionX() = 0;
	virtual float GetWorldPositionY() = 0;
	virtual float GetWorldPositionZ() = 0;

	// rotation
	virtual void WorldRotateDeltaXYZ(float pitch, float yaw, float roll, EAngleType angleType = EAngleType::AT_DEGREE) = 0;
	virtual void WorldRotateDeltaXYZ(const Vector3& PYR, EAngleType angleType = EAngleType::AT_DEGREE) = 0;
	virtual void WorldRotateDeltaAroundX(float angle, EAngleType angleType = EAngleType::AT_DEGREE) = 0;
	virtual void WorldRotateDeltaAroundY(float angle, EAngleType angleType = EAngleType::AT_DEGREE) = 0;
	virtual void WorldRotateDeltaAroundZ(float angle, EAngleType angleType = EAngleType::AT_DEGREE) = 0;

	virtual void WorldRotateDeltaAroundRight(float angle, EAngleType angleType = EAngleType::AT_DEGREE) = 0;
	virtual void WorldRotateDeltaAroundUp(float angle, EAngleType angleType = EAngleType::AT_DEGREE) = 0;
	virtual void WorldRotateDeltaAroundFwd(float angle, EAngleType angleType = EAngleType::AT_DEGREE) = 0;
	
	virtual void SetWorldRotationXYZ(float pitch, float yaw, float roll, EAngleType angleType = EAngleType::AT_DEGREE) = 0;
	virtual void SetWorldRotationXYZ(const Vector3& PYR, EAngleType angleType = EAngleType::AT_DEGREE) = 0;
	virtual void SetWorldRotationMtx(const Matrix44& rotMtx) = 0;
	virtual void GetWorldRotationMtx(Matrix44& rotMtx) = 0;
	
	// scale: if is not attached, this is the same as "local", if is attached, only getters 
	// scale: test
	virtual void SetWorldScale(float x, float y, float z) = 0;
	virtual void SetWorldScale(const Vector3& scale) = 0;
	virtual void SetWorldScaleX(float value) = 0;
	virtual void SetWorldScaleY(float value) = 0;
	virtual void SetWorldScaleZ(float value) = 0;

	virtual void GetWorldScale(Vector3& scale) = 0;
	virtual float GetWorldScaleX() = 0;
	virtual float GetWorldScaleY() = 0;
	virtual float GetWorldScaleZ() = 0;

	virtual void GetRightVector(Vector3& right) = 0;
	virtual void GetUpVector(Vector3& up) = 0;
	virtual void GetLookVector(Vector3& look) = 0;
	virtual void SetLookVector(const Vector3& lookDir) = 0;
	virtual void SetLookVector(float x, float y, float z) = 0;

	virtual void GetWorldMatrix(Matrix44& mat) = 0;
};

#endif
