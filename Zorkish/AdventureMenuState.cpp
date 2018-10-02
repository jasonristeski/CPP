#include "AdventureMenuState.h"
#include "GameplayState.h"
#include "StateManager.h"
#include "Adventure.h"


// std
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdlib>

AdventureMenuState::~AdventureMenuState()
{
}

void AdventureMenuState::processInput(std::string input)
{
	StateManager* instance = StateManager::getInstance();
	bool valid = false;
	for(int i = 0; i < options.size();i++)
	{
		if (std::stoi(input) == i)
		{
			Adventure* adv = new Adventure(files[i]);
			instance->setAdventure(adv);
			instance->changeState(new GameplayState());
			valid = true;
			delete this;
		}
	}
	if(!valid)
		invalidInput();
}

void AdventureMenuState::run()
{
	readFiles();
}

void AdventureMenuState::render()
{
	renderHeader();
	std::cout << "Choose your destiny:" << std::endl;
	for (int i = 0; i < options.size(); i++)
	{
		std::cout << "\t" << i << " - " << options[i].substr(2) << std::endl;
	}
}

void AdventureMenuState::readFiles()
{
	std::ifstream file;
	file.open("input.txt", std::ifstream::in);
	std::string input;
	while (getline(file, input))
	{
		files.push_back(input);
	}
	file.close();
	for (int i = 0; i < files.size(); i++)
	{
		std::ifstream file2;
		std::string temp;
		file2.open(files[i].c_str(), std::ifstream::in);
		while(getline(file2, temp))
		{
			if (temp.at(0) == 'A' && !input.empty()) 
			{
				options.push_back(temp);
				break;
			}
		}
		file2.close();
	}
}




