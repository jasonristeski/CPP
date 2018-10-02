#include "CommandManager.h"

#include "CommandInvalid.h"
#include "CommandLook.h"
#include "CommandMove.h"
#include "CommandPut.h"
#include "CommandTake.h"
#include "CommandQuit.h"
#include "CommandOpen.h"
#include <sstream>
#include <istream>

CommandManager::CommandManager()
{
}


CommandManager::~CommandManager()
{
}

void CommandManager::processInput(std::string args)
{
	data = split(args);
	if (data[0] == "quit")
	{
		command = new CommandQuit();
	}
	else if (data[0] == "go")
	{
		command = new CommandMove();
	}
	else if (data[0] == "look")
	{
		command = new CommandLook();
	}
	else if (data[0] == "take")
	{
		command = new CommandTake();
	}
	else if (data[0] == "put")
	{
		command = new CommandPut();
	}
	else if (data[0] == "open")
	{
		command = new CommandOpen();
	}
	else
	{
		command = new CommandInvalid();
	}
}

void CommandManager::run()
{
	if(command != NULL)
		command->execute(data);
	
}

std::vector<std::string> CommandManager::split(std::string data)
{
	std::vector<std::string> result;
	std::string buffer;
	std::stringstream ss(data);
	while (ss >> buffer)
		result.push_back(buffer);
	return result;
}

