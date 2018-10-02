#pragma once
#include "Command.h"
class CommandMove : public Command
{
public:

	void execute(std::vector<std::string> data);
};

