/**
*
* @file     Math3D.h
* @author   Ethan Lin
* @version  1.0
*
* @section  LICENSE
*/


#ifndef __MATRIX_VECTOR_H__
#define __MATRIX_VECTOR_H__

class Math3D
{
public:
	static const float MAX_FLOAT;
	static const float MIN_FLOAT;

	static const float P;
	static const float DegToRad;
	static const float RadToDeg;
	static float Lerp(float v1, float v2, float w);
};

class Vector2
{
public:
	static float DotProduct(const Vector2& in1, const Vector2& in2);

public:
	Vector2();
	Vector2(const Vector2& rhs);
	Vector2(float a, float b);
	~Vector2();
	float& operator[] (unsigned int index) const;
	Vector2& operator= (const Vector2& rhs);

	void SetTo(float a, float b);
	void CopyFrom(const Vector2& rhs);
	const float* GetData();

private:
	float* _vec = nullptr;
};

class Vector3
{
friend class Matrix44;

public:
	static const Vector3 X_AXIS;
	static const Vector3 Y_AXIS;
	static const Vector3 Z_AXIS;

public:
	static void GetNormalizedVector(const Vector3& input, Vector3& output);
	static float DotProduct(const Vector3& in1, const Vector3& in2);
	static void CrossProduct(const Vector3& in1, const Vector3& in2, Vector3& out);
	static bool IsSimilar(const Vector3& vec1, const Vector3& vec2);
	static bool IsInvSimilar(const Vector3& vec1, const Vector3& vec2);
	static float Distance(const Vector3& vec1, const Vector3& vec2);

public:
	Vector3();
	Vector3(const Vector3& rhs);
	Vector3(float a, float b, float c);
	~Vector3();
	float& operator[] (unsigned int index) const;
	Vector3& operator= (const Vector3& rhs);
	Vector3 operator- (const Vector3& rhs) const;

	void SetTo(float a, float b, float c);
	void CopyFrom(const Vector3& rhs);
	void Normalize();
	float GetLength();
	const float* GetData();

private:
	float* _vec = nullptr;
};

class Vector4
{
friend class Matrix44;

public:
	static float DotProduct(const Vector4& in1, const Vector4& in2);

public:
	Vector4();
	Vector4(const Vector4& rhs);
	Vector4(float a, float b, float c, float d );
	~Vector4();
	float& operator[] (unsigned int index) const;
	Vector4& operator= (const Vector4& rhs);

	void SetTo(float a, float b, float c, float d);
	void CopyFrom(const Vector4& rhs);
	const float* GetData();

private:
	float* _vec = nullptr;
};

class Matrix44
{
public:
	static const Matrix44 IDENTITY_MATRIX;

public:
	Matrix44();
	Matrix44(const Matrix44& rhs);
	~Matrix44();
	float& operator[] (int index);
	Matrix44& operator= (const Matrix44& rhs);
	//Matrix44 operator* (const Matrix44& rhs);

	void OrthoProjMatrix(float left, float right, float bottom, float top, float nearPlane, float farPlane);
	void PerspectProjMatrix(float fovDeg, float aspect, float nearPlane, float farPlane);

	void SetIdentity();
	void SetInvert();
	void SetTranspose();

	void CopyFrom(const Matrix44& rhs);
	void TransformVector(Vector3 &vec);
	void TransformPoint(Vector4 &point);

	void ApplyRotateByPYR(const Vector3& PYR, EAngleType angleType);
	void ApplyRotate(const Vector3& axis, float angle, EAngleType angleType);
	void ApplyTranslate(const Vector3& trans);
	void ApplyScale(const Vector3& scale);
	void ApplyMatrix(const Matrix44& mat);
	Matrix44 Apply(const Matrix44& mat);

	void GetScale(Vector3& scale);
	void GetRotation(Matrix44& rotMtx);
	void GetTranslation(Vector3& trans);

	const float* GetData();

private:
	float*		_matrix = nullptr;

	Vector3		_decompScale;
	Vector3		_decompTrans;
	Matrix44*	_decompRot = nullptr;
	bool		_validDecomp = false;
};

class AABB
{
public:
	void AddPoint( const Vector3& point);
	void AddAABB(const AABB& aabb);
	void SetMax( const Vector3& maxPoint );
	void SetMin( const Vector3& minPoint );
	void CopyFrom(const AABB& aabb);
	const Vector3& GetMax() { return _max; };
	const Vector3& GetMin() { return _min; };
private:
	Vector3 _min = Vector3(Math3D::MAX_FLOAT, Math3D::MAX_FLOAT, Math3D::MAX_FLOAT);
	Vector3 _max = Vector3(Math3D::MIN_FLOAT, Math3D::MIN_FLOAT, Math3D::MIN_FLOAT);
};

#endif
