/************************************************************************
*  Program Name: Engine main.h                                              
*  Name: GSP420 Rendering Core - Mike Murrell, Anthony Garza, Jesse Goldan, Christopher Carlos                                                                                         *
*  Date: January 28th - February 1st
*  Description: Mainly for the rendering of the engine
*  Update: February 8, 2013
//=============================================================================
// Modified from Frank Luna (C) 2005 All Rights Reserved.
//=============================================================================   
************************************************************************/
#ifndef	ENGINEMAIN_H_
#define ENGINEMAIN_H_

#include "d3dApp.h"
#include "DirectInput.h"
#include <crtdbg.h>
#include "GfxStats.h"
#include <list>
#include "Vertex.h"
#include "Lighting.h"
#include "Camera.h"
#include "Shaders.h"
#include "Model.h"
#include "AnimatedModel.h"

class EngineMain : public D3DApp
{
public:
	EngineMain(HINSTANCE hInstance, std::string winCaption, D3DDEVTYPE devType, DWORD requestedVP);
	~EngineMain();

	bool checkDeviceCaps();
	void onLostDevice();
	void onResetDevice();
	void updateScene(float dt);
	void drawScene();

	// Helper methods
	void buildFX();
	void buildViewMtx();
	void buildProjMtx();
	void drawMeshes();

private:
	GfxStats* m_GfxStats;

	// // // Models // // //
	Model*			skull;
	Model*			dwarf;
	AnimatedModel*	tiny;
	// // // // // // // // 

	DirectionalLight m_DirLight;

	Camera camera;

	D3DXMATRIX m_World;

};

#endif