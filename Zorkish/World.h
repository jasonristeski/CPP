#pragma once

//project
#include "ItemContainer.h"
#include "Item.h"
#include "Inventory.h"
#include "MessageController.h"	
// std
#include <map>
#include <vector>

struct Location
{

	// Thought about using  Location ID based map instead, but I chose 
	// Not too as it would have been creating double data
	// Would that have been a better solution?
	
	Location(int id,std::string name, std::string localeDesc) : id(id),name(name), description(localeDesc) {};
	std::string name;
	int id;
	std::string description;
	std::vector<ItemContainer*> containers;
	Inventory* items;
	std::map<std::string,Location*> paths;
};


class World
{
public:
	World();
	~World();

	void build(std::string fileName);
	std::map<std::string, Location*> getAvaliablePaths(int id);
	Location* getLocation(int id);

private:
	std::map<int, Location*> map;
	MessageController* mc;
	
};

