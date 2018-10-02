#pragma once
#include <vector>
#include <string>

class Command
{
public:
	Command();
	~Command();
	virtual void execute(std::vector<std::string> args) = 0;
};

