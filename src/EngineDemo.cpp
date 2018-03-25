// ROOKIES3DDemo.cpp : Defines the entry point for the console application.
//

#include "RookiesEngine.h"

//
// Global variables
//
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

GLFWwindow*	_window;

// custom
int RTT_WIDTH;
int RTT_HEIGHT;
RenderTarget* rtt;

ViewCamera* mainCamera;
ViewCamera* rttCamera;
Model* customMask;
Model* monkey;
Model* quad;
Model* vertColorQuad;
Material* maskMat;
Material* monkeyMat;
Material* defTexMat;
Material* vertColorMat;

OGLTexture* woodTex;
OGLTexture* monkeyTex;

float rotateDegree = 0.0f;
Vector3 tintColor(0.3f, 0.5f, 0.2f);

VertAttrBinding ColorRegBinding = { "inColor", 1 };
VertexType POS_COLOR = ROOKIES3D::VertexType_CUSTOM_TYPE_START + 0;
VertexElement VERT_POS_COLOR[2] =
{
	{ PosRegBinding, 3, GL_FLOAT, GL_FALSE, 12, 28, 2 },
	{ ColorRegBinding, 4, GL_FLOAT, GL_FALSE, 16, 28, 2 },
};

OGLProgram* blurShader;
OGLProgram* brigtnessShader;
OGLProgram* bloomShader;
RenderTarget* rtt1, *rtt2;

bool enablePostEffect = false;

bool _ClosingWindow()
{
	bool closing = glfwWindowShouldClose(_window) != 0;
	return closing;
}

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_F1 && action == GLFW_PRESS)
	{
		enablePostEffect = !enablePostEffect;
	}
}

int main(int argc, char** argv)
{
	Graphics* graphics = ROOKIES3D_CreateGraphicsHandler();
	_window = graphics->CreateContext(WINDOW_WIDTH, WINDOW_HEIGHT);
	glfwSetKeyCallback(_window, KeyCallback);

	// pre-setting: (optional) only needed if you have your own vertex layout
	// add your own vertex type design:
	graphics->AddAttributeBinding(&ColorRegBinding);
	graphics->AddVertexLayoutType(POS_COLOR, VERT_POS_COLOR);
	//

	// main camera
	mainCamera = graphics->CreateCamera();
	mainCamera->SetProjType(EProjType::PT_ORTHO);
	mainCamera->SetFar(500.0f);
	mainCamera->SetNear(-500.0f);
	mainCamera->SetViewPort(WINDOW_WIDTH, WINDOW_HEIGHT);
	graphics->SetMainCamera(mainCamera);


	// ----------------------
	// Create Used Resources
	// ----------------------
	// create an off screen render target
	// and camera
	RTT_WIDTH = WINDOW_WIDTH >> 1;
	RTT_HEIGHT = WINDOW_HEIGHT >> 1;
	rttCamera = graphics->CreateCamera();
	rttCamera->CopyFrom(mainCamera);
	rtt = graphics->CreateRenderTexture(RTT_WIDTH, RTT_HEIGHT);
	rtt->SetCamera(rttCamera);

	// not used in the shader
	monkeyTex = graphics->CreateTexture("../../assets/textures/11.png");	

	// create model and texture and shader of mask
	OGLProgram* maskShader = graphics->CreateShaderProgramFromFile("../../assets/shaders/default_tex.vs", "../../assets/shaders/uvColor.fs");	
	maskMat = graphics->CreateMaterial();
	woodTex = graphics->CreateTexture("../../assets/textures/wood.tga");
	maskMat->BindTexture("colorMap", monkeyTex);
	maskMat->BindProgram(maskShader);

	customMask = graphics->CreateModelFromObjFile("../../assets/models/sampleModel.obj", ROOKIES3D::VertexType_POS_UV);
	customMask->SetMaterial(maskMat);

	// create model and shader of monkey head
	OGLProgram* monkeyShader = graphics->CreateShaderProgramFromFile("../../assets/shaders/tintWorldNormal.vs", "../../assets/shaders/tintWorldNormal.fs");
	monkeyMat = graphics->CreateMaterial();
	monkeyMat->BindShaderVector("tintColor", tintColor);
	monkeyMat->BindProgram(monkeyShader);

	monkey = graphics->CreateModelFromObjFile("../../assets/models/monkey-long.obj", ROOKIES3D::VertexType_POS_UV_NORMAL);
	monkey->SetMaterial(monkeyMat);

	// manually create mesh
	float vert[4 * 5] = {
		-1, -1, 0, 0, 0,
		1, -1, 0, 1, 0,
		1, 1, 0, 1, 1,
		-1, 1, 0, 0, 1
	};
	unsigned short index[6] = { 0, 1, 2, 0, 2, 3 };
	Geometry* quadGeo = graphics->CreateGeomtry(ROOKIES3D::VertexType_POS_UV, false, false);
	quadGeo->UploadVertexBuffer(vert, 4, sizeof(float) * 5);
	quadGeo->UploadIndexBuffer(index, 6, sizeof(unsigned short));
	
	OGLProgram* defProg = graphics->CreateShaderProgramFromFile("../../assets/shaders/default_tex.vs", "../../assets/shaders/default_tex.fs");
	defTexMat = graphics->CreateMaterial();	
	defTexMat->BindProgram(defProg);
	defTexMat->BindTexture("colorMap", rtt->GetColorTexture());
	defTexMat->SetRenderState(RenderStateDef::RS_COLOR_WRT_ENABLE | RenderStateDef::RS_DEPTH_WRT_ENABLE | RenderStateDef::RS_DEPTH_TEST_ENABLE | RenderStateDef::RS_DEPTHCMP_LESS_EQUAL
		| RenderStateDef::RS_BLENDSRC_ONE | RenderStateDef::RS_BLENDDST_ZERO | RenderStateDef::RS_CULL_NONE);

	quad = graphics->CreateEmptyModel();
	quad->SetGeometry(quadGeo);
	quad->SetMaterial(defTexMat);
	quad->GetTransform()->SetLocalScale(Vector3(70, 70, 1));

	// create a mesh with your own custom vertex type : pos + color
	float vertWithColor[4 * 7] = {
		-1, -1, 0, 1, 0, 0, 1,
		1, -1, 0, 0, 1, 0, 1,
		1, 1, 0, 0, 0, 1, 1,
		-1, 1, 0, 1, 1, 1, 1
	};
	Geometry* colorQuadGeo = graphics->CreateGeomtry(POS_COLOR, false, false);
	colorQuadGeo->UploadVertexBuffer(vertWithColor, 4, sizeof(float) * 7);
	colorQuadGeo->UploadIndexBuffer(index, 6, sizeof(unsigned short));

	OGLProgram* colorProg = graphics->CreateShaderProgramFromFile("../../assets/shaders/vertColor.vs", "../../assets/shaders/vertColor.fs");
	vertColorMat = graphics->CreateMaterial();
	vertColorMat->BindProgram(colorProg);

	vertColorQuad = graphics->CreateEmptyModel();
	vertColorQuad->SetMaterial(vertColorMat);
	vertColorQuad->SetGeometry(colorQuadGeo);
	vertColorQuad->GetTransform()->SetLocalScale(Vector3(70, 70, 1));
	vertColorQuad->GetTransform()->SetLocalPosition(Vector3(-100, 100, 0));
	


	// Post Effect Setting
	// main
	PostEffectManager* mainPEMgr = graphics->CreatePostEffectManager();
	mainPEMgr->SetRenderTargetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	BloomEffect* bloom = new BloomEffect();
	mainPEMgr->AddPostEffect(ROOKIES3D::PostEffType_Bloom, bloom);
	bloom->SetBlurIteration(30);
	bloom->SetEnable(true);
	mainCamera->SetPostEffectManager(mainPEMgr);

	// rtt
	PostEffectManager* rttPEMgr = graphics->CreatePostEffectManager();
	rttPEMgr->SetRenderTargetSize(RTT_WIDTH, RTT_HEIGHT);
	rttPEMgr->SetEnable(true);
	GrayscaleFilter* gray = new GrayscaleFilter();
	rttPEMgr->AddPostEffect(ROOKIES3D::PostEffType_Grayscale, gray);
	gray->SetEnable(true);
	rttCamera->SetPostEffectManager(rttPEMgr);
	
	
	//PostEffectType types[] = { BEAUTIFY };
	//g->GetPostEffectManager()->SetPostEffectOrder(types, 1);
	////g->GetPostEffectManager()->SetPostEffectTypeEnable(BLOOM, true);
	////g->GetPostEffectManager()->SetBloomEffectBlurFilterSize(2.0f);
	////g->GetPostEffectManager()->SetBloomEffectBlurAmount(30);
	////g->GetPostEffectManager()->SetPostEffectTypeEnable(BRIGHTNESS, true);
	////g->GetPostEffectManager()->SetPostEffectTypeEnable(BLUR, true);
	////g->GetPostEffectManager()->SetBlurEffectAmount(30);
	//g->GetPostEffectManager()->SetPostEffectTypeEnable(BEAUTIFY, true);
	graphics->SetClearColor(0.3f, 0.4f, 0.6f, 1.0f);
	// ----------------------
	// Rendering frame
	// ----------------------
	while (!_ClosingWindow())
	{
		mainPEMgr->SetEnable(enablePostEffect);
		quad->GetTransform()->LocalRotateDeltaAroundY(10.0f);

		// rendering: must need!!
		graphics->BeginFrame();

		// ---------- render to texture
		graphics->SetRenderToTarget(rtt);
		customMask->Draw();
		// ----------- end of render to texture	

		// switch back to default buffer	
		graphics->SetRenderToTarget(nullptr);		
		// draw monkey head
		monkey->Draw();
		customMask->Draw();

		// draw the quad and paste the render texture		
		quad->Draw();

		// draw the color quad		
		vertColorQuad->Draw();

		// must call !!
		graphics->EndFrame();
	}

	delete graphics;
	return 0;
}

