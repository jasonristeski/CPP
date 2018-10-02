#include "HelpState.h"
#include "MainMenuState.h"
#include"StateManager.h"

HelpState::~HelpState()
{
}

void HelpState::processInput(std::string input)
{
	
	StateManager* instance = StateManager::getInstance();
	if (input == "")
	{
		instance->changeState(new MainMenuState());
		delete this;
	}
	else
		invalidInput();
}

void HelpState::render()
{
	std::cout << "The following options are supported" << std::endl;
	std::cout << "\t" << "quit" << std::endl;
	std::cout << "\t" << "hiscore" << std::endl;
	std::cout << "Press any key to return to main menu" << std::endl;
}

void HelpState::run()
{
	
}
