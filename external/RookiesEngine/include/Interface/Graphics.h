/**
*
* @file     Graphics.h
* @author   Ethan Lin
* @version  1.0
*
* @section  LICENSE
*/


#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

class Model;

class Graphics
{
public:
    virtual ~Graphics() {};
	virtual GLFWwindow* CreateContext(int width, int height, int antiAliasing = 1) = 0;
	virtual void SetClearColor(float r, float g, float b, float a) = 0;
    virtual void SetClearColor(const Vector4& color) = 0;
	virtual const GLubyte* GetFrameBufferToByte( RenderTarget* rt, int* bufferW, int* bufferH, EColorType type = CT_BGRA) = 0;
	virtual GLuint GetDefaultFrameBuffer() = 0;
	virtual GLuint GetDefaultRenderBuffer() = 0;
	virtual RenderTarget* CreateRenderTexture(int width, int height) = 0;
	virtual OGLProgram* CreateShaderProgramFromFile(const char* vsFileName, const char* fsFileName) = 0;
	virtual OGLProgram* CreateShaderProgramFromString(const std::string& vShader, const std::string& fShader, const char* name) = 0;
	virtual OGLTexture* CreateTexture(const char* fileName) = 0;

	virtual Material* CreateMaterial() = 0;
	virtual Material* CreateMaterialFromFile(const char* matFileName) = 0;

	virtual Geometry* CreateGeomtry(VertexType type, bool dynamicVert, bool dynamicIdx) = 0;
	virtual Model* CreateEmptyModel() = 0;	
	virtual Model* CreateModelFromObjFile(const std::string& objName, VertexType type, bool fromRHCoord = true) = 0;
	
	virtual void SetResourceRootPath(const std::string& rootPath) = 0;

	virtual void SetRenderToTarget(RenderTarget* rt) = 0;
	virtual void ForceSwitchRenderTarget(RenderTarget* rt) = 0;
	virtual void SetToFixedFunction() = 0;		// not supported in OGLES
    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;
	virtual Geometry* GetScreenQuad(bool flipY) = 0;
	virtual Geometry* GetMirrorQuad() = 0;	

	virtual void AddAttributeBinding(VertAttrBinding* binding) = 0;
	virtual void AddVertexLayoutType(VertexType type, VertexElement elems[]) = 0;

	virtual void SetDepthBias(bool bEnable, float factor, float unit) = 0;

	virtual PostEffectManager* CreatePostEffectManager() = 0;
	virtual LightManager* GetLightManager() = 0;
	virtual ViewCamera* CreateCamera() = 0;
	virtual void SetMainCamera(ViewCamera* cam) = 0;
	virtual ViewCamera* GetMainCamera() = 0;
};

#endif
