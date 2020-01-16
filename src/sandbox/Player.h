/**
* Include guard, as the class is Inherited from other classes,
* as the header is called within other function.
*/
#pragma once 

#ifndef _Player_
#define _Player_

/**
* Included Libraries.
*/
#include <iostream>
#include <memory>
#include <list>
#include <glm/glm.hpp>

//#include "GameEngine/GameEngine.h"
/**
* Forward declaration Class's used within the Class
*/
class Core;
class Mesh;
class Ray;
class UserInput;
class Camera;

/**
* Componet Class included, for inheritance.
*/
#include "GameEngine/Component.h"

/**
* Initalisation of the class.
*/
class Player : public Component
{
public:
    /**
    * This class is used for the Player, it primiarly is used to display the GUI.
    * it inherits from Componet, the onGUI function will overwrite the Componets onGUI.
    */
	Player();
	virtual ~Player();

    /**
    * This function overwrites the GUI function from Component.
    */
    void onGUI();

private:
	
};

#endif
