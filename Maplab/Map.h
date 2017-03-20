#pragma once
#include "Location.h"
#include <unordered_map>
#include <stack>
class Map
{
private:	
public:
	Map(std::string startingLocationName);
	~Map();	

	Location * CurrentLocation = nullptr;
	std::stack<Location *> Path; 

	std::unordered_map <std::string, std::string> coordinates;

	

};

