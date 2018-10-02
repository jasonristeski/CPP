#pragma once
#include "Command.h"
class CommandInvalid : public Command
{
public:
	void execute(std::vector<std::string> args);
};

