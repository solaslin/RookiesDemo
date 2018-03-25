/**
*
* @file     Geometry.h
* @author   Ethan Lin
* @version  1.0
*
* @section  LICENSE
*/
#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

class Geometry
{
public:
    virtual ~Geometry() {};
	virtual VertexType GetVertType() = 0;
	virtual const std::string& GetName() = 0;

	//virtual bool IsVisible() = 0;
	//virtual void SetVisible(bool flag) = 0;
	
	virtual void Draw(GLenum mode = GL_TRIANGLES) = 0;
	virtual void RefreshGeometryData() = 0;
	virtual void UploadVertexBuffer(const float *data, int vertCount, int perVertSize) = 0;
	virtual void UploadIndexBuffer(const unsigned short *data, int idxCount, int perIdxSize) = 0;
	virtual const AABB& GetLocalAABB() = 0;
};

#endif
