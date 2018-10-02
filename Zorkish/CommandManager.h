#pragma once
// project
#include "Command.h"

//std
#include <map>
class CommandManager
{
public:
	CommandManager();
	~CommandManager();

	void processInput(std::string args);
	void run();
	
	
private:
	std::vector<std::string> split(std::string data);
	std::vector<std::string> data;
	Command* command;
};

