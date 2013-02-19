#pragma once

#include "WorldObject.h"
#include "StateManager.h"

#include <string>

//Physics variables
const float gravity = -9.81f; //In m/s. See about getting this from physics core
const float friction = -0.1f; //Apparently these have public scope.
const float drag = -0.05f; //Yeah, I'm just making these up for now.

class MainInterface
{
	StateManager stateManager; //Our state manager

public:

	//-----Variables and objects-----
	WorldObject worldObjects[100]; //Array of the different entities in the game world.	

	MainInterface(void);

	void Run(void);

	static void OutputToConsole(std::string s);

	~MainInterface(void);

	//-----AI-----
	//Entity locations. They're in worldObjects, as x y and z floats
	//Object states. Unsure what exactly is meant by this. Easy enough to add new enums or whatever various states you want to put objects in;
	//Vector movement. Physics core has the Vector3D.h class to work with vector movement.

	//-----UI-----
	//Animation. Still figuring out how to work with render core, Studio is freaking out because of Direct X libraries not being set up right for me.

	//-----Scripting-----
    //access to the physics constants: drag, gravity, and friction. Accessible as public constants.
    //a means of binding keys to an action
    //a way to create and position a button, then assign an action to that button. Will figure this out better when I figure out rendering core better
    //a means of opening a window (debug or console) for output. Besides interacting with the console directly, you can call the OutputToConsole method to output to the console.
    //a means of querying active NPCs //Array of worldObjects, including NPCs. May make an NPC class that inherits from WorldObject.
    //a means of locating a specific NPC //That NPC's array number.
    //a means of moving a specific NPC //Changing the x,y,z values for that NPC.
};

