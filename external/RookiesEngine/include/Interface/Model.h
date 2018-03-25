/**
*
* @file     Model.h
* @author   Ethan Lin
* @version  1.0
*
* @section  LICENSE
*/


#ifndef __MODEL__
#define __MODEL__

class Model
{

public:
	virtual ~Model() {};

	// FIXME: need to set a material vector....
	virtual void SetGeometry(Geometry* geo) = 0;
	virtual void SetMaterial(Material* mat) = 0;	
	virtual bool IsVisible() = 0;
	virtual void SetVisible(bool flag) = 0;
	virtual void Draw(GLenum mode = GL_TRIANGLES) = 0;

    virtual Geometry* GetGeometry() = 0;
	virtual Material* GetMaterial() = 0;
	virtual Transform* GetTransform() = 0;
	virtual const AABB& GetLocalAABB() = 0;
};

#endif
