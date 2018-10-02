#pragma once



// std 
#include <string>
#include <iostream>
class State
{
public:
	State(){};
	State(std::string stateName) : name(stateName) {};
	~State();
	std::string getName() const;
	
	
	virtual void processInput(std::string input) = 0;
	virtual void run() = 0;
	virtual void render() = 0;
//	virtual void init() = 0;
	
	void renderHeader();
	void clear();

private:
	std::string name;


protected:
	void invalidInput();

};

