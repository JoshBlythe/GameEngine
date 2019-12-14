#include <iostream>
#include <memory>
#include <list>

//#include "GameEngine/GameEngine.h"

class Mesh;

class Player
{
public:
	Player();
	~Player();
	 
	void InitPlayer(std::shared_ptr<Mesh> _obj);
	void Update();
	void IsSelected();
private:

	bool m_isSelected;
	std::list<std::shared_ptr<Mesh>> m_playerUnits;
	
};
