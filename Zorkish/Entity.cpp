#include "Entity.h"
#include <iostream>
#include <algorithm>
#include "MessageController.h"
Entity::Entity(int eid, std::string aName,std::string aDesc)
{
	name = aName;
	desc = aDesc;
	toLower(name);
	toLower(desc);
}


Entity::~Entity()
{
}

std::string Entity::getName() const

{
	return name;
}
std::string Entity::getDescription() const
{
	return desc;
}

bool Entity::is(std::string label)
{
	toLower(label);
	if (name == label)
		return true;
	else
	{
		for (int i = 0; i < alias.size(); i++)
		{
			if (label == alias[i])
				return true;
		}
	}
	return false;
}

bool Entity::addAlias(std::string label)
{
	toLower(label);
	std::vector<std::string>::iterator iter = std::find(alias.begin(), alias.end(), label);
	if (iter == alias.end())
	{
		alias.push_back(label);
		return true;
	}
	return false;
}


bool Entity::removeAlias(std::string label)
{
	std::vector<std::string>::iterator iter = std::find(alias.begin(), alias.end(), label);
	if (iter != alias.end())
	{
		alias.erase(iter);
		return true;
	}
	return false;
}

void Entity::registerSubscription(std::string subscription)
{
	MessageController::getInstance()->addEntity(subscription, this);
}

void Entity::recieveMessage(std::string sender,std::string value)
{
	std::cerr << "Message recieved from: " << sender << "\n" << "value :" << value << std::endl;
	messageValue = value;
}

void Entity::sendMessage(std::string recipieint, std::string value, std::string sub)
{
	MessageController::getInstance()->directMessage(name, recipieint, value, sub);
}

void Entity::writeBlackboard(std::string recipient, std::string value, std::string subscription)
{
	MessageController::getInstance()->postAnnouncement(this->getName(), value, subscription);
}

std::string Entity::toString() const
{
	std::string result;
	result = name + " : " + desc +  "\n";
	if (alias.size() > 0)
	{
		result += "Also known as : \n";
		for (int i = 0; i < alias.size(); i++)
		{
			result += "\t" + alias[i] + "\n";
		}
	}
	return result;
}


// internal
void Entity::toLower(std::string data)
{
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
}
