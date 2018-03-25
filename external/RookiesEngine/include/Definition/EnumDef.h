/**
*
* @file     EnumDef.h
* @author   Ethan Lin
* @version  1.0
*
* @section  LICENSE
*/

#ifndef __ENUM_DEF__
#define __ENUM_DEF__

#ifndef __SET_DEBUG__
#define CHECK_GL_ERROR()
#else
#define CHECK_GL_ERROR() \
{ \
GLenum err = glGetError(); \
if (err != GL_NO_ERROR) \
{	\
printf("GLError: %x, at %s, line %d\n",err,__FILE__, __LINE__-1);   \
abort(); \
} \
}
#endif //__SET_DEBUG__

#define VertexType int

namespace ROOKIES3D
{
	const VertexType VertexType_POS = 1;
	const VertexType VertexType_POS_UV = 2;
	const VertexType VertexType_POS_UV_NORMAL = 3;
	const VertexType VertexType_POS_UV_NORMAL_TANGENT = 4;
	const VertexType VertexType_CUSTOM_TYPE_START = 5;
}

typedef enum
{
	CT_RGB = 0,
	CT_BGR = 1,
	CT_RGBA = 2,
	CT_BGRA = 3,
	CT_ARGB = 4
} EColorType;

typedef enum
{
	MESH_UNKNOWN = 0,
	MESH_RAWDATA = 1,
	MESH_OBJ = 2,
	MESH_FBX = 3
} EMeshType;

typedef enum 
{
	AT_DEGREE = 0,
	AT_RADIAN = 1
} EAngleType;

//

class VertAttrBinding
{
public:
	VertAttrBinding(){};
	VertAttrBinding(const std::string& name, int loc) : attributeName(name), location(loc) {};
	std::string attributeName;	// variable name in shader
	int  location;		// desired binding register
};

class VertexElement
{
public:
	VertexElement(){};
	VertexElement(const VertAttrBinding& b, GLuint num, GLuint format, GLboolean isNormalized,
		GLuint elemSize, GLuint vertSize, GLuint numElem)
		: numComp(num)
		, compDataFormat(format)
		, normalized(isNormalized)
		, elementSize(elemSize)
		, vertTotalSize(vertSize)
		, numElements(numElem)
	{
		binding.attributeName = b.attributeName;
		binding.location = b.location;
	};

	VertAttrBinding	binding;	// variable name in shader
	GLuint			numComp;
	GLuint			compDataFormat;
	GLboolean		normalized;
	GLuint			elementSize;	// should be sizeof(DataFormat) * numComp
	GLuint			vertTotalSize;	// summation of total element
	GLuint			numElements;
};

// Build in Binding
static VertAttrBinding PosRegBinding("inPos", 0);
static VertAttrBinding UVRegBinding("inUV", 1);
static VertAttrBinding NormalRegBinding("inNormal", 2);
static VertAttrBinding TangentRegBinding("inTangent", 3);

//
//typedef struct
//{
//	const std::string	attributeName;	// variable name in shader
//	const int  location;		// desired binding register
//}VertAttrBinding;
//
//typedef struct
//{
//	VertAttrBinding	binding;	// variable name in shader
//	GLuint			numComp;
//	GLuint			compDataFormat;
//	GLboolean		normalized;
//	GLuint			elementSize;	// should be sizeof(DataFormat) * numComp
//	GLuint			vertTotalSize;	// summation of total element
//	GLuint			numElements;
//} VertexElement;
//
//// Build in Binding
//static VertAttrBinding PosRegBinding = { "inPos", 0 };
//static VertAttrBinding UVRegBinding = { "inUV", 1 };
//static VertAttrBinding NormalRegBinding = { "inNormal", 2 };
//static VertAttrBinding TangentRegBinding = { "inTangent", 3 };
//


#endif	// endif __ENUM_DEF__
