#pragma once
#include "State.h"
class HelpState: public State
{
public:
	HelpState() : State("Help State") {}; 
	~HelpState();

	void init();
	void processInput(std::string input);

	void run();
	void render();
};

