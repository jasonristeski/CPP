#include "Player.h"
Player::Player() : Entity(10,"me", "game player")
{
	inv = new Inventory("Player Inventory", 100);
}

Player::Player(std::string name) : Entity(10,name,"Game Player")
{
	inv = new Inventory("Player Inventory", 100);
}
Player::~Player()
{
	delete inv;
}

Inventory* Player::getInventory() 
{
	return inv;
}


