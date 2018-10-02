#pragma once

#include "Message.h"
#include "Entity.h"

#include <map>
#include <vector>

class MessageController
{
public:
	MessageController();
	~MessageController();
	void addEntity(std::string subscription, Entity* e);
	void directMessage(std::string sender, std::string recipient, std::string value, std::string sub); // direct
	void postAnnouncement(std::string sender,std::string value,std::string sub); 
	void publishAnnouncements();
	static MessageController* getInstance();

private:
	static std::map<std::string, std::vector<Entity*>> ks;
	static std::vector<Message> messages;
	static MessageController* instance;
};

