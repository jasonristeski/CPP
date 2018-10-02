#include "Parser.h"

Parser::Parser(std::string name)
{
	fileName = name;
	file.open(fileName, std::ifstream::in);
}


Parser::~Parser()
{
}


std::vector<std::string> Parser::getAdventureMenu()
{
	return menu;
}

std::vector<std::string> Parser::getItems()
{
	return items;
}

std::vector<std::string> Parser::getContainers()
{
	return containers;
}

std::vector<std::string> Parser::getLocations()
{
	return locations;

}

std::vector<std::string> Parser::split(const std::string& data, char delim)
{
	std::vector<std::string> result;
	int i = 0;
	std::size_t idx = data.find(delim);
	while (idx != std::string::npos)
	{
		result.push_back(data.substr(i, idx - i));
		i = ++idx;
		idx = data.find(delim, idx);
		if (idx == std::string::npos)
			result.push_back(data.substr(i, data.length()));
	}
	return result;
}

std::vector<std::string> Parser::getPaths()
{
	return paths;
}

// Approriate strings are sectioned off to theri required areas
void Parser::parse()
{
	std::string input;
	while (getline(file, input))
	{
		if (input != "" || input.at(0) != '/' || !input.empty())
		{
			switch (input.at(0))
			{
			case'A':
				menu.push_back(input);
				break;
			case 'L':
				locations.push_back(input);
				break;
			case 'P':
				paths.push_back(input);
				break;
			case 'C':
				containers.push_back(input);
				break;
			case'I':
				items.push_back(input);
				break;
			default:
				break;
			}
		}
	}
	file.close();
}
