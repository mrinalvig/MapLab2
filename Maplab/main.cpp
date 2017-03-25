#include <iostream>
#include <string>
#include "Map.h"
using namespace std;

void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);
void PathToHome(Map &map);
void GettingHere(Map &map);

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
		cout << "7) How Did I Get Here?" << endl;
		cout << "0) Exit" << endl;		
		cin >> choice;

		switch (choice) 
		{
		case 1: cout << "Current Location is " << map.CurrentLocation->getName() << endl; break;
		case 2: GoNorth(map); break;
		case 3: GoEast(map); break;
		case 4: GoSouth(map); break;
		case 5: GoWest(map); break;
		case 6: PathToHome(map); break;
		case 7: GettingHere(map); break;
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
			map.Path.push(map.CurrentLocation);
			map.Order.push(map.CurrentLocation);
			
			map.CurrentLocation = map.CurrentLocation->North;
			cout << "Location is: " << map.CurrentLocation->getName() << endl;
		}
		else
		{
			map.CurrentLocation->South = map.CurrentLocation;
			map.CurrentLocation->South->North = map.CurrentLocation;
			map.Path.push(map.CurrentLocation);
			map.Order.push(map.CurrentLocation);
			cout << "You've been here before. " << existing->DisplayLocationInfo();
		}
	}
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
			map.Path.push(map.CurrentLocation);
			map.Order.push(map.CurrentLocation);

			map.CurrentLocation = map.CurrentLocation->South;
			cout << "Location is: " << map.CurrentLocation->getName() << endl;
		}
		else
		{
			map.CurrentLocation->South = map.CurrentLocation;
			map.CurrentLocation->South->North = map.CurrentLocation;
			map.Path.push(map.CurrentLocation);
			map.Order.push(map.CurrentLocation);
			cout << "You've been here before. " << existing->DisplayLocationInfo();
		}
	}
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
			map.Path.push(map.CurrentLocation);
			map.Order.push(map.CurrentLocation);

			map.CurrentLocation = map.CurrentLocation->East;
			cout << "Location is: " << map.CurrentLocation->getName() << endl;
		}
		else
		{
			map.CurrentLocation->East = map.CurrentLocation;
			map.CurrentLocation->East->West = map.CurrentLocation;
			map.Path.push(map.CurrentLocation);
			map.Order.push(map.CurrentLocation);
			cout << "You've been here before. " << existing->DisplayLocationInfo();
		}
	}
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
			map.Path.push(map.CurrentLocation);
			map.Order.push(map.CurrentLocation);

			map.CurrentLocation = map.CurrentLocation->West;
			cout << "Location is: " << map.CurrentLocation->getName() << endl;

		}
		else
		{
			map.CurrentLocation->West = map.CurrentLocation;
			map.CurrentLocation->West->East = map.CurrentLocation;
			map.Path.push(map.CurrentLocation);
			map.Order.push(map.CurrentLocation);
			cout << "You've been here before. " << existing->DisplayLocationInfo() << endl;
		}
	}
	
}

void PathToHome(Map &map)
{
	cout << "Your directions to get back home are: \n" << endl;

	for (int i = 0; i <= map.Path.size(); i++)
	{
		cout << "Step " << i + 1 << ": Go to location " << map.Path.top()->getName() << endl;
		map.Path.pop();
	}
}

void GettingHere(Map &map)
{
	cout << "You got here with these steps:" << endl;

	for (int i = 0; i <= map.Order.size(); i++)
	{
		cout << "Step " << i + 1 << ": " << map.Order.front()->getName() << endl;
		map.Order.pop();
	}

}