#ifndef __BLUR_EFFECT__
#define __BLUR_EFFECT__

class BlurEffect : public BasePostEffect
{
public:
	BlurEffect();
	virtual ~BlurEffect() override;

	virtual void Init() override;
	virtual void Render(RenderTarget* inputRtt, RenderTarget* outputRtt) override;

	void SetFilterSize(float filterSize);
	void SetBlurIteration(int iter);

private:
	static float _weight[5];

	int _iteration = 1;
	float _filterSize = 1.0f;
	
	Vector4 _weights14;
	Vector2 _offsetX = Vector2(1.0f, 0.0f);
	Vector2 _offsetY = Vector2(0.0f, 1.0f);
	RenderTarget *_tmpRtt = nullptr;
};

#endif