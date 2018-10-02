#include "CommandInvalid.h"
#include "Adventure.h"
#include "StateManager.h"

void CommandInvalid::execute(std::vector<std::string> args)
{
	std::cout << "Invalid Command: \n" << std::endl;
	std::string comData;
	for (int i = 0; i < args.size(); i++)
		comData += args[i];
	std::cout << comData << std::endl;
}
