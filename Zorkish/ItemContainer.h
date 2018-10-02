#pragma once

//project
#include"Item.h"
#include "Entity.h"
#include "Inventory.h"
// std
#include <string>
#include <map>


// Entity Wraper for inventory
class ItemContainer : public Entity
{
public:
	ItemContainer(int id, std::string label, std::string description,int cap) : Entity(id, label, description) 
	{
		max = cap;
		state = false;
	}
	~ItemContainer();
	

	bool isOpen() const;
	void open();
	void close();
	void toggleState();
	bool has(std::string name);
	void addEntity(Entity* newE);
	Entity* removeEntity(std::string name);
	std::string toString();

private:
	int size;
	int max;
	bool state;
	std::map<std::string, std::vector<Entity*>> entity;
	
};

