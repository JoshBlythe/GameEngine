#include <iostream>
#include <fstream>


class Map
{
public:
	Map();
	~Map();

	void LoadMap(std::ifstream FileName);
	void DisplayMap();

private:

	int StoredMap[30][35];

};
