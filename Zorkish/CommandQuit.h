#pragma once
#include "Command.h"
class CommandQuit : public Command
{
public:
	void execute(std::vector<std::string> args);
};

