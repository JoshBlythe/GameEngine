#include <list>

#include "Object.h"

class Player
{
public:
	Player();
	~Player();

	void CameraMovement();
	void Controls();

private:
	
	//resoures
	int wood, stone, food;

	//list of units
	std::list<std::shared_ptr<Object>> UnitList;
	//list of buildings
	std::list<std::shared_ptr<Object>> BuildingsList;

};
