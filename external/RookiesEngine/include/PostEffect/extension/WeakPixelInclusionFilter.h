#ifndef __WEAK_PIXEL_INCLUSION__
#define __WEAK_PIXEL_INCLUSION__

class WeakPixelInclusionFilter : public BasePostEffect
{
public:
	WeakPixelInclusionFilter();
	virtual ~WeakPixelInclusionFilter()override;

	virtual void Init() override;
	virtual void Render(RenderTarget* inputRtt, RenderTarget* outputRtt) override;
	void SetFilterSize(float filterSize);

private:
	float _filterSize = 1.0f;
	Vector2 _texel;
};

#endif