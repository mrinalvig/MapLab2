#pragma once
#include "Location.h"
#include <unordered_map>
#include <stack>
class Map
{
private:	
	std::unordered_map <std::string, Location *> coordinates;
public:
	Map(std::string startingLocationName);
	~Map();	

	Location * CurrentLocation = nullptr;
	std::stack<Location *> Path; 
	Location * LookupLocationOnMap(int x, int y);
	

	

};

