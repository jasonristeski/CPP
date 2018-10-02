#pragma once
#include "State.h"
#include "CommandManager.h"
class GameplayState :
	public State
{
public:
	GameplayState() : State("Gameplay State") {};
	~GameplayState();

	void init();
	void processInput(std::string input);

	void run();
	void render();
private:
	static CommandManager* cm;
};

