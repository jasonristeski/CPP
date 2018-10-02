#include "State.h"

// std 
#include <iostream>
#include <windows.h>






State::~State()
{
}

std::string State::getName() const
{
	return name;
}

void State::renderHeader()
{
	std::cout << "Zork ::" << name << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;

}

void State::clear()
{
	std::system("cls");
}

void State::invalidInput()
{
	clear();
	std::cout << "Invalid input" << std::endl;
	Sleep(500);
	run();
}
