#include "AddHighScoreState.h"

#include "StateManager.h"
#include"LeaderboardState.h"


AddHighScoreState::~AddHighScoreState()
{
}

void AddHighScoreState::init()
{

}

void AddHighScoreState::processInput(std::string input)
{
	StateManager* instance = StateManager::getInstance();
	if (input == "")
	{
		instance->changeState(new LeaderboardState());
		delete this;
	}
	else
		invalidInput();
}

void AddHighScoreState::render()
{
	std::cout << "Congrats!" << std::endl;
	std::cout << "Your actually good at the game, But the game doesn't work" << std::endl;
	std::cout << "\t" << "Adventure: World1" << std::endl;
	std::cout << "\t" << "Score: 3" << std::endl;
	std::cout << "\t" << "Moves: Right" << std::endl;
	std::cout << "Press any key to view dummy leaderboard"; 

}

void AddHighScoreState::run()
{
	
}
