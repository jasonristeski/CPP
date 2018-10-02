#include "MainMenuState.h"
#include "AdventureMenuState.h"
#include "StateManager.h"
#include"LeaderboardState.h"
#include "HelpState.h"
#include "AboutState.h"

MainMenuState::~MainMenuState()
{
}

void MainMenuState::processInput(std::string input)
{
	StateManager* instance = StateManager::getInstance();
	if (input == "1")
	{
		instance->changeState(new AdventureMenuState());
		delete this;
	}
	else if (input == "2")
	{
		instance->changeState(new LeaderboardState());
		delete this;
	}
	else if (input == "3")
	{
		instance->changeState(new HelpState());
		delete this;
	}
	else if (input == "4")
	{
		instance->changeState(new AboutState());
		delete this;
	}
	else if (input == "5")
	{
		instance->kill();
		delete this;
	}
	else
		invalidInput();

}


void MainMenuState::run()
{
}

void MainMenuState::render()
{
	renderHeader();
	std::cout << "Select a option" << std::endl;
	std::cout << "\t" << "1. Play" << std::endl;
	std::cout << "\t" << "2. View Leaderboard" << std::endl;
	std::cout << "\t" << "3. Help" << std::endl;
	std::cout << "\t" << "4. About" << std::endl;
	std::cout << "\t" << "5. Quit" << std::endl;
	std::cout << "Enter 1-5:"; 
}
