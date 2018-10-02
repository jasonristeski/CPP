#pragma once

// project
#include "Entity.h"
#include"Inventory.h"


class Player : public Entity
{
public: 
	Player();
	Player(std::string name);
	~Player();
	Inventory* getInventory();
private:
	Inventory* inv;
};

