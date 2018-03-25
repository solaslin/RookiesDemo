#ifndef __NON_MAX_SUPPRESSION__
#define __NON_MAX_SUPPRESSION__

class NonMaximumSuppressionFilter : public BasePostEffect
{
public:
	NonMaximumSuppressionFilter();
	virtual ~NonMaximumSuppressionFilter() override;

	virtual void Init() override;
	virtual void Render(RenderTarget* inputRtt, RenderTarget* outputRtt) override;

	void SetUpperThreshold(float upperThreshold);
	void SetLowerThreshold(float lowerThreshold);

private:
	float _upperThreshold = 0.4f;
	float _lowerThreshold = 0.1f;
	Vector2 _texel;
};

#endif