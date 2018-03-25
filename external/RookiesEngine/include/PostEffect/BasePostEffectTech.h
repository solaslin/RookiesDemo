#ifndef __BASE_POSTEFFECTTECH__
#define __BASE_POSTEFFECTTECH__

class BasePostEffect
{
public:	
	virtual ~BasePostEffect();
	virtual void Init() = 0;
	virtual void Render(RenderTarget* inputRtt, RenderTarget* outputRtt) = 0;
	virtual void CheckInit() final;	
	virtual bool IsEnable() final;
	virtual void SetEnable(bool enable) final;
	virtual void SetGraphics(Graphics* g) final;
	virtual PostEffectType GetPostEffctType() final;

protected:
	PostEffectType			_type;
	bool					_enable = false;
	bool					_inited = false;
	Graphics*				_graphic = nullptr;
	Material*				_material = nullptr;
	OGLProgram*				_effectShader = nullptr;
	Geometry*				_renderQuad = nullptr;

	const char* _vsCode;
	const char* _fsCode;
};

#endif
