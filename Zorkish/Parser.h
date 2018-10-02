#pragma once

//std
#include <string>
#include <fstream>
#include <vector>

class Parser
{
public:
	Parser(std::string name);
	~Parser();

	void parse();
	std::vector<std::string> split(const std::string& data, char delim);
	std::vector<std::string> getLocations();
	std::vector<std::string> getPaths();
	std::vector<std::string> getAdventureMenu();
	std::vector<std::string> getContainers();
	std::vector<std::string> getItems();


private:
	std::string fileName;
	std::ifstream file;

	std::vector<std::string> locations;
	std::vector<std::string> paths;
	std::vector<std::string> menu;
	std::vector<std::string> containers;
	std::vector<std::string> items;
};

