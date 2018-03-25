#ifndef __CANNY_EDGE__
#define __CANNY_EDGE__

class CannyEdgeDetection : public BasePostEffect
{
public:
	CannyEdgeDetection();
	virtual ~CannyEdgeDetection() override;

	virtual void Init() override;
	virtual void Render(RenderTarget* inputRtt, RenderTarget* outputRtt) override;

	void SetUpperThreshold(float upperThreshold);
	void SetLowerThreshold(float lowerThreshold);
	void SetBlurFilterSize(float filterSize);
	void SetSobelEdgeFilterSize(float filterSize);
	void SetWeakPixelInclusionFilterSize(float filterSize);

private:
	GrayscaleFilter					*_grayscaleFilter = nullptr;
	BlurEffect						*_blurFilter = nullptr;
	SobelEdgeDetection				*_sobelEdgeFilter = nullptr;
	NonMaximumSuppressionFilter		*_nonMaximumSuppressionFilter = nullptr;
	WeakPixelInclusionFilter		*_weakPixelInclusionFilter = nullptr;

	std::vector<BasePostEffect*> _filters;
	RenderTarget		*_tmpRtt = nullptr;

	float _upperThreshold = 0.4f;
	float _lowerThreshold = 0.1f;
	float _blurFilterSize = 1.0f;
	float _sobelEdgeFilterSzie = 1.0f;
	float _weakPixelInclusionFilterSize = 1.0f;
};

#endif