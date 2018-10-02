#include "World.h"
#include "Parser.h"
#include "ItemContainer.h"

#include <iostream>
#include <fstream>



World::World()
{
	mc = new MessageController();
}


World::~World()
{

}

void World::build(std::string fileName)
{

	Parser p(fileName);
	p.parse();
	std::vector<std::string> locations = p.getLocations();

	// add locaitons 
	for (int i = 0; i < locations.size(); i++)
	{
		std::vector<std::string> data = p.split(locations[i], ':');
		int id = std::stoi(data[1]);
		Location* temp = new Location(id, data[2], data[3]);
		temp->items = new Inventory(temp->name, INT_MAX);
		map[id] = temp;
	}

	// add paths 
	std::vector<std::string> paths = p.getPaths();
	for (int i = 0; i < paths.size(); i++)
	{
		std::vector<std::string> data = p.split(paths[i], ':');
		for (int k = 2; k < data.size() -1; k+= 2)
		{
			int id = std::stoi(data[1]);
			map[id]->paths.insert({ data[k], map[std::stoi(data[k + 1])] });
		}
	}

	// add containers 
	std::vector<std::string> cont = p.getContainers();
	for (int i = 0; i < cont.size(); i++)
	{
		std::vector<std::string> data = p.split(cont[i], ':');
		ItemContainer* temp = new ItemContainer(0,data[2],data[2] + "in location" + data[1] ,std::stoi(data[3]));
		int id = std::stoi(data[1]);
		map[id]->containers.push_back(temp);
	}


	// fill locations w/ items 
	std::vector<std::string> items = p.getItems();
	for (int i = 0; i < items.size(); i++)
	{
		std::vector<std::string> data = p.split(items[i], ':');
		
		int size = data.size();
		Item* temp = new Item(0, data[size - 3], data[size - 2], std::stoi(data[size - 1]));
		int id = std::stoi(data[1]);


		if (data.size() == 6)
		{// add to container
			for (int k = 0; k < map[id]->containers.size(); k++)
			{
				if (map[id]->containers.at(k)->getName() == data[2])
				{
					map[id]->containers.at(k)->addEntity(temp);
				}
			}
		}
		else if (data.size() == 5) // add to location
		{
			map[id]->items->addItem(temp);
		}
	}

	
}

std::map<std::string,Location*> World::getAvaliablePaths(int id)
{
	return map[id]->paths;
}

Location* World::getLocation(int id)
{
	return map[id];
}

