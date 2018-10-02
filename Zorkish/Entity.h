#pragma once

// std
#include <string>
#include <vector>

#include "Message.h"

class MessageController;

class Entity
{
public:
	Entity(int eid, std::string aName,std::string aDesc);
	~Entity();

	std::string getName() const;

	std::string getDescription() const;

	bool is(std::string label);

	bool addAlias(std::string label);
	bool removeAlias(std::string label);
	void registerSubscription(std::string subscription);
	void recieveMessage(std::string sender, std::string value);
	void sendMessage(std::string recipieint, std::string value, std::string sub);
	void writeBlackboard(std::string recipient, std::string value, std::string subscription);
	virtual std::string toString() const;

private:
	int id;
	MessageController* mc;
	std::string name, desc, messageValue;
	std::vector<std::string> alias;
	void toLower(std::string data);
	bool has(std::string name);

};

