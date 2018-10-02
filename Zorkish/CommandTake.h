#pragma once
#include "Command.h"
class CommandTake : public Command
{
public:

	void execute(std::vector<std::string> args);
};

