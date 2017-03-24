#pragma once
#include "Location.h"
#include <unordered_map>
#include <stack>
#include <queue>
class Map
{
private:	
	
public:
	Map(std::string startingLocationName);
	~Map();	

	std::unordered_map <std::string, Location *> coordinates;
	std::stack<Location *> Path;
	std::queue<Location *> Order;
	Location * CurrentLocation = nullptr; 
	Location * LookupLocationOnMap(int x, int y);
	

	

};

