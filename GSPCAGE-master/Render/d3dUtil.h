//=============================================================================
// d3dUtil.h by Frank Luna (C) 2005 All Rights Reserved.
//
// Contains various utility code for DirectX applications, such as, clean up
// and debugging code.
//=============================================================================

#ifndef D3DUTIL_H
#define D3DUTIL_H

// Enable extra D3D debugging in debug builds if using the debug DirectX runtime.  
// This makes D3D objects work well in the debugger watch window, but slows down 
// performance slightly.
#if defined(DEBUG) | defined(_DEBUG)
#ifndef D3D_DEBUG_INFO
#define D3D_DEBUG_INFO
#endif
#endif

#include <d3d9.h>
#include <d3dx9.h>
#include <dxerr.h>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "../Audio/ResourceManager.h"

//===============================================================
// Globals for convenient access.
class D3DApp;
extern D3DApp* g_d3dApp;
extern IDirect3DDevice9* g_d3dDevice;

//===============================================================
// Clean up

#define ReleaseCOM(x) { if(x){ x->Release();x = 0; } }

//===============================================================
// Geometry generation.

void GenTriGrid(int numVertRows, int numVertCols, 
	float dx, float dz, const D3DXVECTOR3& center, 
	std::vector<D3DXVECTOR3>& verts, std::vector<DWORD>& indices);

//===============================================================
// Colors and Materials

const D3DXCOLOR WHITE(1.0f, 1.0f, 1.0f, 1.0f);
const D3DXCOLOR BLACK(0.0f, 0.0f, 0.0f, 1.0f);
const D3DXCOLOR RED(1.0f, 0.0f, 0.0f, 1.0f);
const D3DXCOLOR GREEN(0.0f, 1.0f, 0.0f, 1.0f);
const D3DXCOLOR BLUE(0.0f, 0.0f, 1.0f, 1.0f);

struct Mtrl
{
	Mtrl()
		:ambient(WHITE), diffuse(WHITE), spec(WHITE), specPower(8.0f){}
	Mtrl(const D3DXCOLOR& a, const D3DXCOLOR& d, 
		 const D3DXCOLOR& s, float power)
		:ambient(a), diffuse(d), spec(s), specPower(power){}

	D3DXCOLOR ambient;
	D3DXCOLOR diffuse;
	D3DXCOLOR spec;
	float specPower;
};

struct DirLight
{
	D3DXCOLOR ambient;
	D3DXCOLOR diffuse;
	D3DXCOLOR spec;
	D3DXVECTOR3 dirW;
};

//===============================================================
// .X Files

void LoadXFile(
	const std::wstring& filename, 
	ID3DXMesh** meshOut, 
	std::vector<Mtrl>& mtrls, 
	std::vector<IDirect3DTexture9*>& texs);

//===============================================================
// Math Constants

const float INFINITY = FLT_MAX;
const float EPSILON  = 0.001f;

//===============================================================
// Bounding Volumes

struct AABB 
{
	// Initialize to an infinitely small bounding box.
	AABB()
		: minPt(INFINITY, INFINITY, INFINITY),
		  maxPt(-INFINITY, -INFINITY, -INFINITY){}

    D3DXVECTOR3 center()
	{
		return 0.5f*(minPt+maxPt);
	}

	D3DXVECTOR3 minPt;
	D3DXVECTOR3 maxPt;
};

struct BoundingSphere 
{
	BoundingSphere()
		: pos(0.0f, 0.0f, 0.0f), radius(0.0f){}

	D3DXVECTOR3 pos;
	float radius;
};

class cRenderManager
{

public:
	cResource* load3DFromXML(TiXmlElement *Element);
	cRenderManager(){};
	~cRenderManager(){};


};

//-------------------------------------------------------------------------------
//===============================================================================
//---------------------------RenderResource Interface class----------------------------
//===============================================================================
class cRenderResource : public cResource 
{
private:
	ID3DXMesh* mMesh;
	std::vector<Mtrl> mMtrl;
	std::vector<IDirect3DTexture9*> mTex;
protected:
public:

	//To be overloaded by derived classes
	
	void load();
	void unload();
	LPCWSTR StringToLPCWSTR(std::string s_Variable);	
	
	inline cRenderResource()
	{
		m_ResourceID = m_Scope = 0;
		m_Type = RESOURCE_GRAPHIC;
	}
};


//===============================================================
// Debug

#if defined(DEBUG) | defined(_DEBUG)
	#ifndef HR
	#define HR(x)                                             \
	{                                                         \
		HRESULT hr = x;                                       \
		if(FAILED(hr))                                        \
		{                                                     \
			DXTrace(__FILE__, __LINE__, hr, L#x, TRUE); \
		}                                                     \
	}
	#endif

#else
	#ifndef HR
	#define HR(x) x;
	#endif
#endif 

#endif // D3DUTIL_H