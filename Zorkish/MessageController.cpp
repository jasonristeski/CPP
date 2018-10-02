#include "MessageController.h"


MessageController* MessageController::instance;
std::map<std::string, std::vector<Entity*>> MessageController::ks;
std::vector<Message> MessageController::messages;
MessageController::MessageController()
{
}


MessageController::~MessageController()
{
}

MessageController* MessageController::getInstance()
{
	if (instance == NULL)
		return new MessageController();
	else
		return instance;
}

void MessageController::addEntity(std::string subscription, Entity* e)
{
	std::map<std::string, std::vector<Entity*>>::iterator it = ks.find(subscription);
	if (it != ks.end())
	{
		it->second.push_back(e);
	}
	else
	{
		std::vector<Entity*> data;
		data.push_back(e);
		ks.insert({ subscription,data });
	}
}

void MessageController::directMessage(std::string sender, std::string recipient, std::string value, std::string sub)
{
	std::vector<Entity*> delivery;
	std::map<std::string, std::vector<Entity*>>::iterator it = ks.find(sub); // does subscription exist for this msg 
	if (it != ks.end())
	{
		for (int i = 0; i < ks[sub].size(); i++) // iterate over entity to find correct recipient 
		{
			if (ks[sub].at(i)->getName() == recipient)
				delivery.push_back(ks[sub].at(i));
		}
	}
	// else msg is lost 
	for (int i = 0; i < delivery.size(); i++) // for all matching recipients in vector 
	{
		delivery.at(i)->recieveMessage(sender, value);
	}
}

void MessageController::postAnnouncement(std::string sender,std::string value,std::string subscription)
{
	std::vector<Entity*> delivery;
	std::map<std::string, std::vector<Entity*>>::iterator it = ks.find(subscription);
	if (it != ks.end())
	{
		for (int i = 0; i < ks[subscription].size(); i++)
		{
			Message m;
			m.sender = sender;
			m.recipient = ks[subscription].at(i)->getName();
			m.value = value;
			m.subscription = subscription;
			messages.push_back(m);
		}
	}
	
}

void MessageController::publishAnnouncements()
{
	for (int i = 0; i < messages.size(); i++)
	{
		directMessage(messages[i].sender, messages[i].recipient, messages[i].value,messages[i].subscription);
	}
	messages.clear();
}

