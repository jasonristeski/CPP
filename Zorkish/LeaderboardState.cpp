#include "LeaderboardState.h"

#include"StateManager.h"
#include "MainMenuState.h"

LeaderboardState::LeaderboardState()
{
}


LeaderboardState::~LeaderboardState()
{
}

void LeaderboardState::run()
{
	
}

void LeaderboardState::render()
{
	std::cout << "Top 3 champs" << std::endl;
	std::cout << "\t" << "1. Me, World 1,321" << std::endl;
	std::cout << "\t" << "2. Fred,World 1,312" << std::endl;
	std::cout << "\t" << "3. Bill,World 1,2" << std::endl;
	std::cout << "Press anyley to return" << std::endl;
}

void LeaderboardState::processInput(std::string input)
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
