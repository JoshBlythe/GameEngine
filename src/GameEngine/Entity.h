#pragma once

#ifndef _Entity_
#define _Entity_

#include <iostream>
#include <list>
#include <memory>
#include <SDL2/SDL.h>

//#include "Component.h"
#include "Exception.h"

class Core;
class Transform;
class Component;
class CollisionDetection;
class ModelCollider;

class Entity
{
public:
	Entity();
	~Entity();

    //friend class core to enable access to private varibales of Entity
    friend class Core;

	//create object template without value
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
	template <typename T, typename V>
	std::shared_ptr<T> addComponent(V v)
	{
		std::shared_ptr<T> t_rtn = std::make_shared<T>();
		
		t_rtn->entity = m_entSelf;

		m_component.push_back(t_rtn);

		t_rtn->onInitalise(v);

		return t_rtn;
	}

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
	void Ticks();
	//update
	void Update();
	//display function to be overide
    virtual void onDisplay();

	//flag to be deleted
    void killEntity();

	//return pointers to classes
    std::shared_ptr<Transform> getTransform();
	std::shared_ptr<CollisionDetection> getCollision();
	std::shared_ptr<ModelCollider> getModelCollision();

	//return pointer to core
    std::shared_ptr<Core> getCore();

private:

	//ptr to core
	std::weak_ptr<Core> m_core;
	//ptr to self
	std::weak_ptr<Entity> m_entSelf;
	bool m_entIsAlive;
	//int m_tick;
	
	//pointer to transform
	std::weak_ptr<Transform> m_trans;
	std::weak_ptr<CollisionDetection> m_checkCol;
	std::weak_ptr<ModelCollider> m_checkModelCol;
	//list of componets
	std::list < std::shared_ptr<Component>> m_component;
};

#endif // !_Entity_
