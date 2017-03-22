#pragma once
#include "Location.h"
#include <unordered_map>
#include <stack>
class Map
{
private:	
	std::stack<Location *> Path;
	std::unordered_map <std::string, Location *> coordinates;
public:
	Map(std::string startingLocationName);
	~Map();	

	Location * CurrentLocation = nullptr; 
	void Move(Location *newLocation);
	Location * LookupLocationOnMap(int x, int y);
	

	

};

