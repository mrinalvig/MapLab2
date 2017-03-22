#pragma once
#include "Location.h"
#include <unordered_map>
#include <stack>
class Map
{
private:	
	std::stack<Location *> Path;
public:
	Map(std::string startingLocationName);
	~Map();	

	std::unordered_map <std::string, Location *> coordinates;
	Location * CurrentLocation = nullptr; 
	void Move(Location *newLocation);
	Location * LookupLocationOnMap(int x, int y);
	

	

};

