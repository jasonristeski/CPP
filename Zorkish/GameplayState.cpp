#include "GameplayState.h"
#include "StateManager.h"

#include"MainMenuState.h"
#include "AddHighScoreState.h"
#include "Adventure.h"
#include "CommandLook.h"

CommandManager* GameplayState::cm = new CommandManager();
Adventure* adv;
GameplayState::~GameplayState()
{

}

void GameplayState::processInput(std::string input)
{
	cm->processInput(input);
	
}


void GameplayState::run()
{
	cm->run();
	StateManager* instance = StateManager::getInstance();
	MessageController::getInstance()->publishAnnouncements();
	adv = instance->getAdventure();
	
}

void GameplayState::render()
{
	renderHeader();
	

}
