#pragma once
#include "State.h"
class MainMenuState : virtual	public State
{
public:
	MainMenuState() : State("Main Menu") {}; 
	~MainMenuState();

	void init();
	void processInput(std::string input);

	void run();
	void render();


};

