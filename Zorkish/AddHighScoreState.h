#pragma once
#include "State.h"

class AddHighScoreState : public State
{
public:
	AddHighScoreState() : State("Add High Score State") {};
	~AddHighScoreState();

	void init();
	void processInput(std::string input);

	void run();
	void render();
};

