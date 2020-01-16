/**
* Include guard, as the class is Inherited from other classes,
* therefore the header is called within other function.
*/
#pragma once

#ifndef _Component_
#define _Component_

/**
* Included Libraries.
*/
#include <iostream>
#include <memory>

/**
* Forward declaration Class's used within the Class
*/
//#include "Mesh.h"
//#include "Material.h"
class Core;
class Entity;
class Resources;

/**
* Initalisation of the class.
*/
class Component
{
public:

	/**
	* The Component class has the ability to move up the hierachy to the Entity class.
	* It purpose is to be able to implement different components types to a Entity, to do this
	* the class has different classes inherit from it and overwrite it's virtual functions.
	*/
	Component();
	~Component();

	/**
	* Function to return a shared pointer to Entity, used to go back up the hierachy
	*/
	std::shared_ptr<Entity> getEntity();
	/**
	* Function to return a shared pointer to Core, used to go back up the hierachy
	*/
	std::shared_ptr<Core> getCore();
	/**
	* Function to return a shared pointer to Resource
	*/
	std::shared_ptr<Resources> getResources();


	/**
	* Virtual function declaration, this is overwritten by inherited classes functions
	* of the same name.
	*/
	virtual void onDraw();
	/**
	* Virtual function declaration, this is overwritten by inherited classes functions
	* of the same name.
	*/
	virtual void onInitalise();

	/**
	* Virtual function declaration, this is overwritten by inherited classes functions
	* of the same name.
	*/
	virtual void onTick();

	virtual void onGUI();

protected: 
	
	friend class Entity; /*!< Friend Class, allows access to the private variables of Entity. */

	std::weak_ptr<Entity> entity; /*!< Weak pointer to Entity. */

	bool m_compIsAlive; /*!< Variable used to Flag the Component for deletion, if is false the Component will get deleted. */

};

#endif // !_Component_
