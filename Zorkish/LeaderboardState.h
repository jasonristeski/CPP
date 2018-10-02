#pragma once
#include"State.h"
class LeaderboardState : public State
{
public:
	LeaderboardState();
	~LeaderboardState();

	void init();
	void run();
	void render();
	void processInput(std::string input);
	

};

