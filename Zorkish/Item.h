#pragma once

#include "Entity.h"

// std
#include <string>
#include <vector>
class Item : public Entity
{
public:
	Item(int id, std::string name, std::string desc,int mass) :Entity(id, name, desc) 
	{
		size = mass;
	};
	int getSize() const;
	std::string toString() const;
	~Item();
private:
	int size;

};

