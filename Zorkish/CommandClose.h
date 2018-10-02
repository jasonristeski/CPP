#pragma once
#include "Command.h"
class CommandClose :public Command
{
public:
	void execute(std::vector<std::string> args);
};

