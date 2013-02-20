// GSP420MainCore.cpp : Defines the entry point for the console application
//

#include "stdafx.h"
#include "MainInterface.h"
#include <iostream> // Only being used because of reporting errors to console. Delete this line when fixed up better.

#include "..\..\RenderingCore\C++\EngineMain.h"

using namespace std;

void Test(HINSTANCE hInstance, HINSTANCE prevInstance,
				   PSTR cmdLine, int showCmd)
{
	// Enable run-time memory check for debug builds.
	#if defined(DEBUG) | defined(_DEBUG)
		_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	#endif

	EngineMain app(hInstance, "GSP420 Engine", D3DDEVTYPE_HAL, D3DCREATE_HARDWARE_VERTEXPROCESSING);
	g_d3dApp = &app;

	//DirectInput di(DISCL_NONEXCLUSIVE|DISCL_FOREGROUND, DISCL_NONEXCLUSIVE|DISCL_FOREGROUND);
	//gDInput = &di;

    g_d3dApp->run();
}

int _tmain(HINSTANCE hInstance, HINSTANCE prevInstance,
				   PSTR cmdLine, int showCmd) //Entry point of application //int argc, _TCHAR* argv[]
{
	Test(hInstance, prevInstance, cmdLine, showCmd);
	//MainInterface mainCore;
	//mainCore.Run();

	return 0;
}

