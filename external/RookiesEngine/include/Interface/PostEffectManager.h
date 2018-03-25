#ifndef __POSTEFFECT_MGR_H__
#define __POSTEFFECT_MGR_H__

#define PostEffectType int

namespace ROOKIES3D
{
	const PostEffectType PostEffType_Bilateral = 1;
	const PostEffectType PostEffType_Bloom = 2;
	const PostEffectType PostEffType_Blur = 3;
	const PostEffectType PostEffType_Brightness = 4;
	const PostEffectType PostEffType_CannyEdge = 5;
	const PostEffectType PostEffType_Grayscale = 6;
	const PostEffectType PostEffType_NonMaxSup = 7;
	const PostEffectType PostEffType_SobelEdge = 8;
	const PostEffectType PostEffType_WeakPixelIncl = 9;
	const PostEffectType PostEffType_Custom_Start = 32;
}

class BasePostEffect;

class PostEffectManager
{
public:
	virtual ~PostEffectManager() {};
	
	virtual void SetRenderTargetSize(int width, int height) = 0;
	virtual void SetPostEffectOrder(PostEffectType types[], size_t length) = 0;
	virtual void SetPostEffectTypeEnable(PostEffectType effectType, bool enable) = 0;
	virtual void AddPostEffect(PostEffectType effectType, BasePostEffect* effect ) = 0;
	virtual BasePostEffect* GetPostEffect(PostEffectType peType) = 0;
	virtual void SetEnable(bool enable) = 0;
};
#endif