#include <iostream>
#include <string>
#include "Map.h"
using namespace std;

void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);
void PathToHome(Map &map);

int main()
{
	Map map = Map("Home");

	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		cout << "1) Display Current Location" << endl;
		cout << "2) Go North" << endl;
		cout << "3) Go East" << endl;
		cout << "4) Go South" << endl;
		cout << "5) Go west" << endl;
		cout << "6) Path To Home" << endl;
		cout << "0) Exit" << endl;		
		cin >> choice;

		switch (choice) 
		{
		case 1: cout << map.CurrentLocation->getName() << endl; break;
		case 2: GoNorth(map); break;
		case 3: GoEast(map); break;
		case 4: GoSouth(map); break;
		case 5: GoWest(map); break;
		case 6: PathToHome(map); break;
		default: break;
		}

		system("pause");
	}


	system("pause");
	return 0;
}


void GoNorth(Map &map)
{
	system("cls");
	if (map.CurrentLocation->North == nullptr) 
	{

		cout << "You haven't been here before.  Enter a Name: ";
		string newName;
		cin >> newName;

		map.CurrentLocation->North = new Location(newName);
		map.CurrentLocation->North->South = map.CurrentLocation;
	}

	map.CurrentLocation = map.CurrentLocation->North;
	cout << "You are now at " + map.CurrentLocation->getName() << endl;
	map.Path.push(map.CurrentLocation);
}
void GoSouth(Map &map)
{
	system("cls");
	if (map.CurrentLocation->South == nullptr)
	{

		cout << "You haven't been here before.  Enter a Name: ";
		string newName;
		cin >> newName;

		map.CurrentLocation->South = new Location(newName);
		map.CurrentLocation->South->North = map.CurrentLocation;
	}

	map.CurrentLocation = map.CurrentLocation->South;
	cout << "You are now at " + map.CurrentLocation->getName() << endl;
	map.Path.push(map.CurrentLocation);
}
void GoEast(Map &map)
{
	//TODO Implement this
}
void GoWest(Map &map)
{
	//TODO Implement this
}
void PathToHome(Map &map)
{

}