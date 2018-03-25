/***********************************************
*
* @file     Material.h
* @version  0.1
*
* @section  LICENSE
***********************************************/


#ifndef __MATERIAL_H__
#define __MATERIAL_H__


class Material
{
public:
	virtual ~Material(){};

	virtual std::string GetName() = 0;
	virtual int GetRenderState() = 0;
	virtual void SetRenderState(int state) = 0;

	virtual void BindProgram(OGLProgram* prog) = 0;
	virtual void BindTexture(const char* samplerName, OGLTexture* tex) = 0;

	virtual void BindShaderMatrix(const std::string& name, Matrix44 &mat) = 0;
	virtual void BindShaderVector(const std::string& name, Vector2 &vec) = 0;
	virtual void BindShaderVector(const std::string& name, Vector3 &vec) = 0;
	virtual void BindShaderVector(const std::string& name, Vector4 &vec) = 0;
	virtual void BindShaderFloat(const std::string& name, float& value) = 0;

	virtual void BindShaderMatrixValue(const std::string& name, Matrix44 mat) = 0;
	virtual void BindShaderVectorValue(const std::string& name, Vector2 vec) = 0;
	virtual void BindShaderVectorValue(const std::string& name, Vector3 vec) = 0;
	virtual void BindShaderVectorValue(const std::string& name, Vector4 vec) = 0;
	virtual void BindShaderFloatValue(const std::string& name, float value) = 0;

	virtual void SetShaderUniforms() = 0;
};




#endif