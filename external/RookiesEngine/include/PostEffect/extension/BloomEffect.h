#ifndef __BLOOM_EFFECT__
#define __BLOOM_EFFECT__

class BloomEffect : public BasePostEffect
{
public:
	BloomEffect();
	virtual ~BloomEffect() override;

	virtual void Init() override;
	virtual void Render(RenderTarget* inputRtt, RenderTarget* outputRtt) override;

	void SetExposure(float exposure);
	void SetBrightnessOffset(float intensityOffset);
	void SetBrightnessScale(float intensityScale);
	void SetBlurFilterSize(float filterSize);
	void SetBlurIteration(int iter);

private:
	BrightnessEffect	*_brightnessFilter = nullptr;
	BlurEffect			*_blurFilter = nullptr;
	RenderTarget		*_tmpRtt = nullptr;
	float				_exposure = 3.0f;

	float				_brightOffset = -0.3f;
	float				_brightScale = 1.5f;
	float				_blurFilterSize = 1.0f;
	int					_blurFilterIter = 1;
};


#endif