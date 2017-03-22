#include "Map.h"


Map::Map(std::string startingLocationName)
{
	CurrentLocation = new Location(startingLocationName, 0, 0);
	Path.push(CurrentLocation);
	std::string hash = "(0,0)";
	coordinates[hash] = CurrentLocation;

}


Map::~Map()
{
}

void Map::Move(Location * newLocation)
{
	Path.push(newLocation);
	CurrentLocation = newLocation;
}

Location * Map::LookupLocationOnMap(int x, int y)
{
	std::string hash = "(" + std::to_string(x) + "," + std::to_string(y) + ")";
	return coordinates[hash];
}
