#pragma once
#include "Command.h"
class CommandPut : public Command
{
public:
	void execute(std::vector<std::string> args);
};

