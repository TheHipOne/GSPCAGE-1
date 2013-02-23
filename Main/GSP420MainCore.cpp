// GSP420MainCore.cpp : Defines the entry point for the console application
//

#include "stdafx.h"
#include "MainInterface.h"
#include <iostream> // Only being used because of reporting errors to console. Delete this line when fixed up better.

#include "..\Render\EngineMain.h"

using namespace std;

//Stub method for testing purposes
void Test()
{
}

int _tmain(HINSTANCE hInstance, HINSTANCE prevInstance,
				   PSTR cmdLine, int showCmd) //Entry point of application //int argc, _TCHAR* argv[]
{
	//Test(hInstance, prevInstance, cmdLine, showCmd);
	MainInterface mainCore = MainInterface(hInstance);
	mainCore.Run();

	return 0;
}

