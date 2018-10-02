#include "CommandPut.h"
#include "Adventure.h"
#include "StateManager.h"


void CommandPut::execute(std::vector<std::string> args)
{
	Adventure* adv = StateManager::getAdventure();
	if (args.size() == 4 && args[2] == "in") // put x in y 
	{
		if (adv->getPlayer()->getInventory()->has(args[1]))
		{
			Item* temp = adv->getPlayer()->getInventory()->removeItem(args[1]);

			bool found = false;
			for (int i = 0; i < adv->getCurrentLocation()->containers.size(); i++)
			{
				if (adv->getCurrentLocation()->containers[i]->getName() == args[3])
				{
					adv->getCurrentLocation()->containers[i]->addEntity(temp);
					found = true;
				}
			}
		}
	}
}
