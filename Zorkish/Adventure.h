#pragma once

// project
#include "World.h"
#include "Parser.h"
#include "Player.h"

//std
#include <string>

class Adventure
{
public:

	Adventure();
	Adventure(std::string name);

	~Adventure();

	std::string getAdvName() const;

	static void loadAdventure();
	bool move(std::string movement);
	Location* getCurrentLocation();
	Player* getPlayer();

	std::string toString();

	

private:
	std::string name;
	Player* p;
	int currentLocation;
	static World world;
	static std::string file;
};
