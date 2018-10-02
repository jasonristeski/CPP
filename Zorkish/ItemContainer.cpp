#include "ItemContainer.h"

ItemContainer::~ItemContainer()
{
	for (std::map<std::string, std::vector<Entity*>>::iterator it = entity.begin(); it != entity.end();)
	{
		for (std::vector<Entity*>::iterator iter = it->second.begin(); iter != it->second.end(); ++iter)
		{
			delete *iter;
		}
		it->second.clear();
		it = entity.erase(it);
	}
}

bool ItemContainer::isOpen() const
{
	return state;
}

void ItemContainer::open()
{
	state = true;
}

void ItemContainer::close()
{
	state = false;
}

 void ItemContainer::toggleState()
{
	state = !state;
}

 bool ItemContainer::has(std::string name)
 {
	 return entity.find(name) != entity.end();
 }


void ItemContainer::addEntity(Entity* e)
{
	std::map<std::string, std::vector<Entity*>>::iterator it = entity.find(e->getName());
	if (it != entity.end())
		it->second.push_back(e);
	
	else
	{
		std::vector<Entity*> data;
		data.push_back(e);
		entity.insert({ e->getName(),data });
	}
}

Entity* ItemContainer::removeEntity(std::string item)
{
	Entity* result = NULL;
	std::map<std::string, std::vector<Entity*>>::iterator it = entity.find(item);
	if (it != entity.end()) 
	{
		result = it->second.back();
		it->second.pop_back();
		if (it->second.size() == 0)
		{
			it->second.clear();
			entity.erase(it);
		}
	}
	return result;
}

std::string ItemContainer::toString()
{
	std::string result;
	result = Entity::toString();
	result += "State: ";
	if (state)
		result += "Open \n";
	else
		result += "Closed \n";
	result += "Entities: \n";
	if (entity.size() > 0)
	{
		for (std::map<std::string, std::vector<Entity*>>::iterator iter = entity.begin(); iter != entity.end(); ++iter)
		{
			result += "\t " + std::to_string(iter->second.size()) + " " + iter->first + "'s \n";
		}
	}
	else
		result += "\t { is Empty!}";
	return result;
}
