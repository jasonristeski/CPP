#include "CommandMove.h"
#include "Adventure.h"
#include "StateManager.h"

void CommandMove::execute(std::vector<std::string> args)
{
	Adventure* adv = StateManager::getAdventure();
	adv->move(args[args.size() - 1]);
		
}
