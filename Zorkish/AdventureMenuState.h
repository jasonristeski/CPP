#pragma once
#include "State.h"
#include "Adventure.h"
#include <map>
class AdventureMenuState :
	public State
{
public:
	AdventureMenuState() : State("Adventure Menu State") {}; 
	~AdventureMenuState();

	void processInput(std::string input);

	void run();
	void render();
private:


	void readFiles();
	std::vector<std::string> options;
	std::vector<std::string> files;
	std::string selection;
};

