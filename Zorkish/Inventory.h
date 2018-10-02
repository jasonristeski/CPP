#pragma once

// project
#include "Item.h"

#include <string>
#include<map>

class Inventory
{
public:
	Inventory();
	Inventory(std::string label, int max);
	~Inventory();

	int getSize() const;
	int getFreeSpace() const;
	std::string getName() const;
	bool addItem(Item* newItem);
	Item* removeItem(std::string name);
	bool has(std::string name);
	virtual std::string toString() ;

private:
	std::string name;
	std::map<std::string, std::vector<Item*>> items;
	int size;
	int capacity;

};

