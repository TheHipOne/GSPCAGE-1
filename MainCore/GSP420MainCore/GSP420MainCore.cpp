// GSP420MainCore.cpp : Defines the entry point for the console application
//

#include "stdafx.h"
#include "MainInterface.h"
#include <iostream> // Only being used because of reporting errors to console. Delete this line when fixed up better.

using namespace std;


int _tmain(int argc, _TCHAR* argv[]) //Entry point of application
{
	MainInterface mainCore;
	mainCore.Run();

	return 0;
}

