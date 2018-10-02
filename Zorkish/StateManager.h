#pragma once

#include "State.h"
#include "Adventure.h"
class StateManager
{
public:
	StateManager();
	~StateManager();

	static StateManager* getInstance();
	static void setAdventure(Adventure* adv);
	static Adventure* getAdventure();
	void changeState(State* newState);
	void run();
	void kill();

private:
	State* stateInstance;
	void processInput();
	static StateManager* instance;
	static Adventure* quest;
	bool running;
};

