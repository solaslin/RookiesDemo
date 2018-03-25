#ifndef __SOBEL_EDGE__
#define __SOBEL_EDGE__

class SobelEdgeDetection : public BasePostEffect
{
public:
	SobelEdgeDetection();
	virtual ~SobelEdgeDetection() override;

	virtual void Init() override;
	virtual void Render(RenderTarget* inputRtt, RenderTarget* outputRtt) override;
	void SetFilterSize(float filterSize);

private:
	float _filterSize = 1.0f;
	Vector2 _texel;
};
#endif