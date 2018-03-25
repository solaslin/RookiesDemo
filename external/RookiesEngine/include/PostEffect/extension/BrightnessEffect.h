#ifndef __BIGHTNESS_EFFECT__
#define __BIGHTNESS_EFFECT__

class BrightnessEffect : public BasePostEffect
{
public:
	BrightnessEffect();
	virtual ~BrightnessEffect() override {};

	virtual void Init() override;
	virtual void Render(RenderTarget* inputRtt, RenderTarget* outputRtt) override;

	void SetIntensityOffset(float intensityOffset);
	void SetIntensityScale(float intensityScale);

private:
	float _intensityOffset = 0.5f;
	float _intensityScale = 2.0f;
};
#endif