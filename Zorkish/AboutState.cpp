#include "AboutState.h"
#include "StateManager.h"


AboutState::~AboutState()
{
}

void AboutState::init()
{

}

void AboutState::run()
{
	
}

void AboutState::render()
{
	renderHeader();
	std::cout << "Written by Jason Risteski" << std::endl;
	std::cout << "Press anykey to return to main menu" << std::endl;
} 

void AboutState::processInput(std::string input)
{
	StateManager* instance = StateManager::getInstance();
	if (input == "")
	{
		instance->changeState(new  MainMenuState());
		delete this;
	}
	else
		invalidInput();

}