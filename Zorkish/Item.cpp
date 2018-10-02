#include "Item.h"

Item::~Item() // make ide happy
{
}

int Item::getSize() const
{
	return size;
}

std::string Item::toString() const
{
	std::string result = Entity::toString();
	result += "Weight: " + std::to_string(size) + "\n";
	return result;
}


