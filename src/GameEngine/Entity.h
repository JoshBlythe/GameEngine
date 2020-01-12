/**
* Include guard, as the class is Inherited from other classes,
* therefore the header is called within other function.
*/
#pragma once

#ifndef _Entity_
#define _Entity_

/**
* Included Libraries.
*/
#include <iostream>
#include <list>
#include <memory>
#include <SDL2/SDL.h>

/**
* Forward declaration Class's used within the Class
*/
class Core;
class Transform;
class Component;
class CollisionDetection;
class ModelCollider;

/**
* Entity Class includes.
*/
//#include "Component.h"
#include "Exception.h"

/**
* Initalisation of the class.
*/
class Entity
{
public:
	Entity();
	~Entity();

	//create object template without value
	/**
	* This function creates a component of type passed into function.
	*/
	template<typename T> 
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> t_rtn = std::make_shared<T>();
		
		t_rtn->entity = m_entSelf;
		//t_rtn->m_compIsAlive = true;

		m_component.push_back(t_rtn);

		t_rtn->onInitalise();

		return t_rtn;
	}

	//create object template with value
	/**
	* This function creates a component of type passed into functionm with a value attached.
	*/
	template <typename T, typename V>
	std::shared_ptr<T> addComponent(V v)
	{
		std::shared_ptr<T> t_rtn = std::make_shared<T>();
		
		t_rtn->entity = m_entSelf;

		m_component.push_back(t_rtn);

		t_rtn->onInitalise(v);

		return t_rtn;
	}

	/**
	* This function gets a component of type passed into function.
	*/
	template<typename T>
	std::shared_ptr<T> getComponent()
	{
		std::shared_ptr<T> t_rtn = std::make_shared<T>();

		for (auto it = m_component.begin(); 
			it != m_component.end(); it++)
		{
			t_rtn = std::dynamic_pointer_cast<T>(*it);
			if (t_rtn)
			{
				return t_rtn;
			}
		}
		
		throw Exception("Specified Type was not found");
	}

	/**
	* This function gets a component of type passed into function,
	* returns true if there is a component of that type.
	*/
	template<typename T>
	bool getTheComponent()
	{
		std::shared_ptr<T> t_rtn = std::make_shared<T>();

		for (auto it = m_component.begin();
			it != m_component.end(); it++)
		{
			t_rtn = std::dynamic_pointer_cast<T>(*it);
			if (t_rtn)
			{
				return true;
			}
        }
        return  false;

        //throw Exception("Specified Type was not found");
	}

	//tick through
	/**
	* This function loops though each component and calls there onTick function.
	* Once done it loops though again and check is they flagged to be deleted.
	* If they have been then deletes them from the list, if not continues.
	*/
	void Ticks();
	//update
	//void Update();
	//display function to be overide
	/**
	* This function loops though each component and calls there onDisplay function.
	*/
    virtual void onDisplay();

	//flag to be deleted
	/**
	* This function flags a component to be deleted.
	*/
    void killEntity();

	//return pointers to classes
	/**
	* Function to return a shared pointer to Transform.
	*/
    std::shared_ptr<Transform> getTransform();
	/**
	* Function to return a shared pointer to Collision Detection.
	*/
	std::shared_ptr<CollisionDetection> getCollision();
	/**
	* Function to return a shared pointer to Model Collison.
	*/
	std::shared_ptr<ModelCollider> getModelCollision();

	//return pointer to core
	/**
	* Function to return a shared pointer to Core, this is used to go up the hierachy.
	*/
    std::shared_ptr<Core> getCore();

private:
	//friend class core to enable access to private varibales of Entity
	friend class Core; /*!< Friend Class, allows access to the private variables of Core. */
	//ptr to core
	std::weak_ptr<Core> m_core; /*!< Weak pointer to Core, used to return a smart pointer of Core. */
	//ptr to self
	std::weak_ptr<Entity> m_entSelf; /*!< Weak pointer to Entity (it's self). */
	bool m_entIsAlive; /*!< Variable used to Flag the Entity for deletion, if is false the Entity will get deleted. */
	//int m_tick;
	
	//pointer to transform
	std::weak_ptr<Transform> m_trans; /*!< Weak pointer to Transform, used to return a smart pointer of Transform. */
	std::weak_ptr<CollisionDetection> m_checkCol; /*!< Weak pointer to Collision Detection, used to return a smart pointer of Collision Detection. */
	std::weak_ptr<ModelCollider> m_checkModelCol; /*!< Weak pointer to Model Collider, used to return a smart pointer of Model Collider. */
	//list of componets
	std::list < std::shared_ptr<Component>> m_component; /*!< Vector of all Component, held by the Entity. */
};

#endif // !_Entity_
