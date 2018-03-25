#ifndef __BILATERAL_FILTER__
#define __BILATERAL_FILTER__

class BilateralFilter : public BasePostEffect
{
public:
	BilateralFilter();
	virtual ~BilateralFilter() override;

	virtual void Init() override;
	virtual void Render(RenderTarget* inputRtt, RenderTarget* outputRtt) override;

	void SetDistanceNormalizationFactor(float factor);
	void SetFilterSize(float filterSize);
	void SetBlurIteration(int iter);

private:
	int _iteration = 1;
	float _filterSize = 4.0f;
	float _distanceNormalizationFactor = 4.0f;

	Vector2 _offsetX = Vector2(1.0f, 0.0f);
	Vector2 _offsetY = Vector2(0.0f, 1.0f);
	RenderTarget *_tmpRtt = nullptr;
};

#endif