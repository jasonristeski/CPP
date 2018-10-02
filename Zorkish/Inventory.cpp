#include "Inventory.h"



Inventory::Inventory()
{
}


Inventory::Inventory(std::string label, int max)
{
	name = label;
	size = 0;
	capacity = max;
}

Inventory::~Inventory()
{
	for (std::map<std::string, std::vector<Item*>>::iterator it = items.begin(); it != items.end(); )
	{
		for (std::vector<Item*>::iterator iter = it->second.begin(); iter != it->second.end(); ++iter)
		{
			delete *iter;
		}
		it->second.clear();
		it = items.erase(it);
	}
}

int Inventory::getSize() const
{
	return size;
}

int Inventory::getFreeSpace() const
{
	return capacity - size;
}

std::string Inventory::getName() const
{
	return name;
}

bool Inventory::addItem(Item* newItem)
{
	if (size + newItem->getSize() <= capacity)
	{
		std::map<std::string, std::vector<Item*>>::iterator it = items.find(newItem->getName());
		if (it != items.end())
			it->second.push_back(newItem);
		else
		{
			std::vector<Item*> data;
			data.push_back(newItem);
			items.insert({ newItem->getName(), data });
		}
		size += newItem->getSize();
		return true;
	}
	return false;
}

Item* Inventory::removeItem(std::string item)
{
	Item* result = NULL;
	std::map<std::string, std::vector<Item*>>::iterator it = items.find(item);
	if (it != items.end())
	{
		size -= it->second.back()->getSize();
		result = it->second.back();
		it->second.pop_back();
		if (it->second.size() == 0)
		{
			it->second.clear();
			items.erase(it);
		}
	}
	return result;
}



bool Inventory::has(std::string name)
{
	return items.find(name) != items.end();
}




std::string Inventory::toString() 
{
	std::string result;
	result += "Items: \n";
	if (items.size() > 0)
	{
		for (std::map<std::string, std::vector<Item*>>::iterator iter = items.begin(); iter != items.end(); ++iter)
		{
			result += "\t Name: " + iter->first + " Quantity: " + std::to_string(iter->second.size()) + "\n";
		}
	}
	else
		result += "\t {empty}";
	return result;
}