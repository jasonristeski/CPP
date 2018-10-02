#pragma once
#include "State.h"
#include "MainMenuState.h"
class AboutState :
	public State
{
public:
	AboutState() : State("About") {};
	~AboutState();

	void init();
	void processInput(std::string input);

	void run();
	void render();

};

