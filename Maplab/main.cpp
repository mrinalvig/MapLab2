    #include <iostream>
#include <string>
#include "Map.h"
using namespace std;

void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);
//void PathToHome(Map &map);

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
		//cout << "6) Path To Home" << endl;
		cout << "0) Exit" << endl;		
		cin >> choice;

		switch (choice) 
		{
		case 1: cout << map.CurrentLocation->getName() << endl; break;
		case 2: GoNorth(map); break;
		case 3: GoEast(map); break;
		case 4: GoSouth(map); break;
		case 5: GoWest(map); break;
		//case 6: PathToHome(map); break;
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

	auto newLocation = map.CurrentLocation->North;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();

	if (map.CurrentLocation->North == nullptr)
	{
		int newX = currentX;
		int newY = currentY + 1;
		auto existing = map.LookupLocationOnMap(newX, newY);

		if (existing == nullptr)
		{

			cout << "You haven't been here before.  Enter a Name: ";
			string newName;
			cin >> newName;

			map.CurrentLocation->North = new Location(newName, newX, newY);
			map.CurrentLocation->North->South = map.CurrentLocation;
			
		}
		else
		{
			cout << "You've been here bofore. " << existing->DisplayLocationInfo();
		}
	}
	map.CurrentLocation = map.CurrentLocation->North;
	map.Move(newLocation);
	map.coordinates.emplace("(" + std::to_string(currentX) + "," + std::to_string(currentY + 1) + ")", newLocation);
	cout << map.CurrentLocation->getName() << endl;
}
void GoSouth(Map &map)
{
	system("cls");

	auto newLocation = map.CurrentLocation->South;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();

	if (map.CurrentLocation->South == nullptr)
	{
		int newX = currentX;
		int newY = currentY - 1;
		auto existing = map.LookupLocationOnMap(newX, newY);

		if (existing == nullptr)
		{
			cout << "You haven't been here before.  Enter a Name: ";
			string newName;
			cin >> newName;

			map.CurrentLocation->South = new Location(newName, newX, newY);
			map.CurrentLocation->South->North = map.CurrentLocation;
		}
		else
		{
			cout << "You've been here bofore. " << existing->DisplayLocationInfo();
		}
	}

	map.CurrentLocation = map.CurrentLocation->South;
	map.Move(newLocation);
	cout <<  map.CurrentLocation->getName() << endl;
}
void GoEast(Map &map)
{
	system("cls");

	auto newLocation = map.CurrentLocation->East;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();

	if (map.CurrentLocation->East == nullptr)
	{
		int newX = currentX + 1;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);

		if (existing == nullptr)
		{
			cout << "You haven't been here before.  Enter a Name: ";
			string newName;
			cin >> newName;

			map.CurrentLocation->East = new Location(newName, newX, newY);
			map.CurrentLocation->East->West = map.CurrentLocation;
		}
		else
		{
			cout << "You've been here bofore. " << existing->DisplayLocationInfo();
		}
	}

	map.CurrentLocation = map.CurrentLocation->East;
	map.Move(newLocation);
	cout << "You are now at " + map.CurrentLocation->getName() << endl;
}
void GoWest(Map &map)
{
	system("cls");

	auto newLocation = map.CurrentLocation->West;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();

	if (map.CurrentLocation->West == nullptr)
	{
		int newX = currentX - 1;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);

		if (existing == nullptr)
		{
			cout << "You haven't been here before.  Enter a Name: ";
			string newName;
			cin >> newName;

			map.CurrentLocation->West = new Location(newName, newX, newY);
			map.CurrentLocation->West->East = map.CurrentLocation;
		}
		else
		{
			cout << "You've been here bofore. " << existing->DisplayLocationInfo();
		}
	}

	map.CurrentLocation = map.CurrentLocation->West;
	map.Move(newLocation);
	cout << "You are now at " + map.CurrentLocation->getName() << endl;
}

/*void PathToHome(Map &map)
{
	for (int i = 0; i <= map.Move.Path.size(); i++)
	{
			cout << map.Move.Path.top()->getName() << endl;
			map.Move.Path.pop();
	}
} */