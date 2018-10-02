#pragma once
#include "Command.h"
class CommandOpen : public Command
{
public:
	void execute(std::vector<std::string> args);
};

