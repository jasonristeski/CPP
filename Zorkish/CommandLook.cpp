#include "CommandLook.h"
#include "Adventure.h"
#include "StateManager.h"

void CommandLook::execute(std::vector<std::string> args)
{
	Adventure* adv = StateManager::getAdventure();

	if (args.size() == 1)
	{
		std::cout << adv->toString() << std::endl;
	}
	else if (args.size() == 2 && (args[1] == "inv" || args[1] == adv->getPlayer()->getName())) // todo expand for alias
	{
		std::cout << "You are carrying: \n ";
		std::cout << adv->getPlayer()->getInventory()->toString() << std::endl;
	}
	else if (args.size() == 3 && (args[1] == "at" || args[1] == "in"))
	{
		bool found = false;
		std::string result = "Couldn't find " + args[2];

		if (args[1] == "in")
		{
			for (int i = 0; i < adv->getCurrentLocation()->containers.size(); i++)
			{
				if (adv->getCurrentLocation()->containers[i]->getName() == args[2])
				{
					if (adv->getCurrentLocation()->containers[i]->isOpen())
					{
						found = true;
						result = adv->getCurrentLocation()->containers[i]->toString();
						break;
					}
					else
						result = "Open " + args[2] + "before peeking";
				}
			}

			if (!found)
			{
				if (adv->getCurrentLocation()->items->has(args[2]))
				{
					found = true;
					Item* temp = adv->getCurrentLocation()->items->removeItem(args[2]);
					result = "You have found :" + args[2] + "\n";
					result += "Learning : " + temp->toString() + "\n";
					result += "...but have destroyed " + args[2] + " in the process \n";
					delete temp;
				}
			}

		}
		else if (args[1] == "at")
		{
			for (int i = 0; i < adv->getCurrentLocation()->containers.size(); i++)
			{
				if (adv->getCurrentLocation()->containers[i]->getName() == args[2])
				{
					found = true;
					result = adv->getCurrentLocation()->containers[i]->getDescription();
					break;
				}
			}
			if (!found)
			{
				if (adv->getCurrentLocation()->items->has(args[2]))
				{
					found = true;
					Item* temp = adv->getCurrentLocation()->items->removeItem(args[2]);
					result = "I've found " + temp->toString() + "\n";
					result += "....I better put it back!";
					adv->getCurrentLocation()->items->addItem(temp);
				}
			}
		}
		std::cout << result << std::endl;
	}
}
