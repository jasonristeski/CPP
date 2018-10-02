#include "CommandClose.h"
#include "Adventure.h"
#include "StateManager.h"

void CommandClose::execute(std::vector<std::string> args)
{
	Adventure* adv = StateManager::getAdventure();
	if (args.size() == 2)
	{
		for (int i = 0; i < adv->getCurrentLocation()->containers.size(); i++)
		{
			if (adv->getCurrentLocation()->containers[i]->getName() == args[1])
			{
				adv->getCurrentLocation()->containers[i]->close();
			}
		}
	}
}
