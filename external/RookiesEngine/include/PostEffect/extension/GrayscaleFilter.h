#ifndef __GRAYSCALE_FILTER__
#define __GRAYSCALE_FILTER__

class GrayscaleFilter : public BasePostEffect
{
public:
	GrayscaleFilter();
	virtual ~GrayscaleFilter() override;

	virtual void Init() override;
	virtual void Render(RenderTarget* inputRtt, RenderTarget* outputRtt) override;
};

#endif