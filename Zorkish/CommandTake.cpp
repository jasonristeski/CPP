#include "CommandTake.h"
#include "Adventure.h"
#include "StateManager.h"




void CommandTake::execute(std::vector<std::string> args)
{
	Adventure* adv = StateManager::getAdventure();
	if (args.size() == 2) // take x (from location)
	{
		if (adv->getCurrentLocation()->items->has(args[1]))
		{
			Item* temp = adv->getCurrentLocation()->items->removeItem(args[1]);
			adv->getPlayer()->getInventory()->addItem(temp);
		}
	}
	else if (args.size() == 4 && args[2] == "from")
	{
		for (int i = 0; i < adv->getCurrentLocation()->containers.size(); i++)
		{
			if (adv->getCurrentLocation()->containers[i]->getName() == args[3])
			{
				if (adv->getCurrentLocation()->containers[i]->isOpen())
				{
					if (adv->getCurrentLocation()->containers[i]->has(args[1]))
					{
						Item* temp = dynamic_cast<Item*>(adv->getCurrentLocation()->containers[i]->removeEntity(args[1]));
						if (temp != NULL)
							adv->getPlayer()->getInventory()->addItem(temp);
					}
				}
				else
					std::cout << "Open " + args[3] + " before using" << std::endl;
			}
		}
	}
}
