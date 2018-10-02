#include "StateManager.h"


//std 
#include<iostream>
#include <stdio.h>

StateManager* StateManager::instance;
Adventure* StateManager::quest;

StateManager::StateManager()
{
	running = true;
}


StateManager::~StateManager()
{
}

StateManager* StateManager::getInstance()
{
	if (instance == NULL)
		instance = new StateManager();
	return instance;
}

void StateManager::setAdventure(Adventure * adv)
{
	quest = adv;
	Adventure::loadAdventure();
}

Adventure* StateManager::getAdventure()
{
	return quest;
}

void StateManager::changeState(State * newState)
{
	if (newState != stateInstance)
	{
		stateInstance = newState;
	}
}

void StateManager::processInput()
{
	char input;
	std::string result;
	input = std::getchar();
	if (input == 13 || input == 27)
	{
		result = "";
	}
	else
	{
		while (input != '\n')
		{
			result += input;
			input = getchar();
		}
	}
	stateInstance->processInput(result);
	stateInstance->clear();

}

void StateManager::run()
{
	stateInstance->render();
	while (running)
	{
		
		
		processInput();
		if (!running) // bandaid ;)
			break;
		stateInstance->run();
		stateInstance->render();
		
	}
}

void StateManager::kill()
{
	running = false;
}

