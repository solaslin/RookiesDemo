/**
*
* @file     RenderStateDef.h
* @version  1.0
*
* @section  LICENSE
*/

#ifndef __RENDERSTATE_DEF__
#define __RENDERSTATE_DEF__

class RenderStateDef
{
public:
	//static const int RS_ATEST_GE0						= 0x00000001;		// 0001
	//static const int RS_ATEST_GE128						= 0x00000002;		// 0010
	//static const int RS_ATEST_LT128						= 0x00000003;		// 0011
	//static const int RS_ATEST_BITS						= 0x0000000f;		// 1111

	static const int RS_BLENDSRC_SRC_ALPHA				= 0x00000010;		// 0001
	static const int RS_BLENDSRC_SRC_COLOR				= 0x00000020;		// 0010
	static const int RS_BLENDSRC_ONE					= 0x00000030;		// 0011
	static const int RS_BLENDSRC_ZERO					= 0x00000040;		// 0100
	static const int RS_BLENDSRC_ONE_MINUS_DST_ALPHA	= 0x00000050;		// 0101
	static const int RS_BLENDSRC_ONE_MINUS_DST_COLOR	= 0x00000060;		// 0110
	static const int RS_BLENDSRC_ONE_MINUS_SRC_ALPHA	= 0x00000070;		// 0111
	static const int RS_BLENDSRC_ONE_MINUS_SRC_COLOR	= 0x00000080;		// 1000
	static const int RS_BLENDSRC_DST_COLOR				= 0x00000090;		// 1001
	static const int RS_BLENDSRC_DST_ALPHA				= 0x000000a0;		// 1010
	static const int RS_BLENDSRC_BITS					= 0x000000f0;		// 1111

	static const int RS_BLENDDST_SRC_ALPHA				= 0x00000100;
	static const int RS_BLENDDST_SRC_COLOR				= 0x00000200;
	static const int RS_BLENDDST_ONE					= 0x00000300;
	static const int RS_BLENDDST_ZERO					= 0x00000400;
	static const int RS_BLENDDST_ONE_MINUS_DST_ALPHA	= 0x00000500;
	static const int RS_BLENDDST_ONE_MINUS_DST_COLOR	= 0x00000600;
	static const int RS_BLENDDST_ONE_MINUS_SRC_ALPHA	= 0x00000700;
	static const int RS_BLENDDST_ONE_MINUS_SRC_COLOR	= 0x00000800;
	static const int RS_BLENDDST_DST_COLOR				= 0x00000900;
	static const int RS_BLENDDST_DST_ALPHA				= 0x00000a00;
	static const int RS_BLENDDST_BITS					= 0x00000f00;

	static const int RS_CULL_BACK						= 0x00010000;
	static const int RS_CULL_FRONT						= 0x00020000;
	static const int RS_CULL_TWO_SIDED					= 0x00030000;		// draw nothing..
	static const int RS_CULL_NONE						= 0x00040000;		// no culling
	static const int RS_CULL_BITS						= 0x000f0000;

	static const int RS_COLOR_WRT_ENABLE				= 0x00100000;	// 0001
	static const int RS_DEPTH_WRT_ENABLE				= 0x00200000;	// 0010
	static const int RS_DEPTH_TEST_ENABLE				= 0x00400000;	// 0100

	static const int RS_DEPTHCMP_ALWAYS					= 0x01000000;
	static const int RS_DEPTHCMP_EQUAL					= 0x02000000;
	static const int RS_DEPTHCMP_GREATER				= 0x03000000;
	static const int RS_DEPTHCMP_GREATER_EQUAL			= 0x04000000;
	static const int RS_DEPTHCMP_LESS					= 0x05000000;
	static const int RS_DEPTHCMP_LESS_EQUAL				= 0x06000000;
	static const int RS_DEPTHCMP_NEVER					= 0x07000000;
	static const int RS_DEPTHCMP_NOT_EQUAL				= 0x08000000;
	static const int RS_DEPTHCMP_BITS					= 0x0f000000;

	static const int defaultState = (RS_COLOR_WRT_ENABLE | RS_DEPTH_WRT_ENABLE | RS_DEPTH_TEST_ENABLE | RS_DEPTHCMP_LESS_EQUAL
		| RS_BLENDSRC_ONE | RS_BLENDDST_ZERO /*| RS_ATEST_GE0*/ | RS_CULL_BACK);

	static const int defaultBlendState = (RS_COLOR_WRT_ENABLE | RS_DEPTH_TEST_ENABLE | RS_DEPTHCMP_LESS_EQUAL
		| RS_BLENDSRC_SRC_ALPHA | RS_BLENDDST_ONE_MINUS_SRC_ALPHA /*| RS_ATEST_GE0*/ | RS_CULL_BACK);

	static int ClearAlphaBlendingSrcBit(int curBits)	{ return (curBits & ~RS_BLENDSRC_BITS); }
	static int ClearAlphaBlendingDstBit(int curBits)	{ return (curBits & ~RS_BLENDDST_BITS); }
	static int ClearCullingBit(int curBits)				{ return (curBits & ~RS_CULL_BITS); }
	static int ClearDepthCmpBit(int curBits)			{ return (curBits & ~RS_DEPTHCMP_BITS); }
	static int ClearDepthTestBit(int curBits)			{ return (curBits & ~RS_DEPTH_TEST_ENABLE); }
	static int ClearDepthWriteBit(int curBits)			{ return (curBits & ~RS_DEPTH_WRT_ENABLE); }
	static int ClearColorWriteBit(int curBits)			{ return (curBits & ~RS_COLOR_WRT_ENABLE); }
	//static int RemainAlphaBlendingDstBit(int bits)	{ return (bits & 0x00000f00); }

	static int SetAlphaBlendingSrcBit(int curBits, int setBit)	{ return ClearAlphaBlendingSrcBit(curBits) | setBit; };
	static int SetAlphaBlendingDstBit(int curBits, int setBit)	{ return ClearAlphaBlendingDstBit(curBits) | setBit; };
	static int SetCullingBit(int curBits, int setBit)			{ return ClearCullingBit(curBits) | setBit; };
	static int SetDepthCmpBit(int curBits, int setBit)			{ return ClearDepthCmpBit(curBits) | setBit; };
	static int SetDepthTestBit(int curBits)						{ return ClearDepthTestBit(curBits) | RS_DEPTH_TEST_ENABLE; };
	static int SetDepthWriteBit(int curBits)					{ return ClearDepthWriteBit(curBits) | RS_DEPTH_WRT_ENABLE; };
	static int SetColorWriteBit(int curBits)					{ return ClearColorWriteBit(curBits) | RS_COLOR_WRT_ENABLE; };
};

#endif // End of __RENDERSTATE_DEF__
