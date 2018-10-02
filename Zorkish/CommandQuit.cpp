#include "CommandQuit.h"
#include "Adventure.h"
#include "StateManager.h"
#include "MainMenuState.h"



void CommandQuit::execute(std::vector<std::string> args)
{
	StateManager* sm = StateManager::getInstance();
	sm->changeState(new MainMenuState());
	delete this;

}
