#pragma once

#include "Command.h"
class CommandLook : public Command
{
public:
	void execute(std::vector<std::string> args);
};

