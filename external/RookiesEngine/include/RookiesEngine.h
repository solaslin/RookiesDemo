#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <cstring>

#if _WIN32 || _WIN64 || __linux
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#else
#endif

#include "Definition\EnumDef.h"
#include "Definition\RenderStateDef.h"
#include "Utils\Math3D.h"

#include "Interface\Transform.h"
#include "Interface\ViewCamera.h"
#include "Interface\OGLProgram.h"
#include "Interface\OGLTexture.h"
#include "Interface\Material.h"
#include "Interface\RenderTarget.h"
#include "Interface\Geometry.h"
#include "Interface\Model.h"
#include "Interface\SunLight.h"
#include "Interface\LightManager.h"
#include "Interface\PostEffectManager.h"
#include "Interface\Graphics.h"

// independent post effects
#include "PostEffect\BasePostEffectTech.h"
#include "PostEffect\extension\BilateralFilter.h"
#include "PostEffect\extension\BlurEffect.h"
#include "PostEffect\extension\BrightnessEffect.h"
#include "PostEffect\extension\GrayscaleFilter.h"
#include "PostEffect\extension\NonMaximumSuppressionFilter.h"
#include "PostEffect\extension\SobelEdgeDetection.h"
#include "PostEffect\extension\WeakPixelInclusionFilter.h"
// dependent post effects
#include "PostEffect\extension\BloomEffect.h"
#include "PostEffect\extension\CannyEdgeDetection.h"

Graphics* ROOKIES3D_CreateGraphicsHandler();
