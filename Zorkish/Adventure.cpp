#include "Adventure.h"


std::string Adventure::file;
World Adventure::world;

Adventure::Adventure()
{
}

Adventure::Adventure(std::string fileName)
{
	p = new Player();
	file = fileName;
	currentLocation = 0;
}

Adventure::~Adventure()
{

}

std::string Adventure::getAdvName() const
{
	return name;
}


void Adventure::loadAdventure()
{
	world.build(file);
}

bool Adventure::move(std::string movement)
{
	bool valid = false;
	if (world.getLocation(currentLocation)->paths.find(movement) != world.getLocation(currentLocation)->paths.end())
	{
		valid = true;
		currentLocation = world.getLocation(currentLocation)->paths.at(movement)->id;
	}
	return valid;
}

Location * Adventure::getCurrentLocation()
{
	return world.getLocation(currentLocation);
}

Player * Adventure::getPlayer()
{
	return p;
}


std::string Adventure::toString()
{
	std::string result;
	result += "You are at :" + world.getLocation(currentLocation)->name + "\n";
	result += "You can see: \n";
	if (world.getLocation(currentLocation)->containers.size() > 0)
	{
		result += "\t Containers: \n";
		for (int i = 0; i < world.getLocation(currentLocation)->containers.size(); i++)
		{
			result += "\t\t" + world.getLocation(currentLocation)->containers[i]->getName() + "\n";
		}
	}
	result += world.getLocation(currentLocation)->items->toString() + "\n";
	result += "You can move: \n";
	for (std::map<std::string, Location*>::iterator it = world.getLocation(currentLocation)->paths.begin(); it != world.getLocation(currentLocation)->paths.end(); ++it)
	{
		result += "\t" + it->first + "\n";
	}
	return result;
}
