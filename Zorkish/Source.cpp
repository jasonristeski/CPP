
// Spike 4.0
#include "StateManager.h"
#include "MainMenuState.h"


// spike 5.0
#include "Entity.h"
#include "Item.h"
#include "ItemContainer.h"
// spike 6.0
#include "Adventure.h"




int main()
{
	// SPike 4.0
	//StateManager* zork = StateManager::getInstance();
	//zork->changeState(new MainMenuState());
	//zork->run(); 
	
	Item* apple = new Item(2, "Apple", "Edible Fruit", 2);
	Item* orange = new Item(1, "Orange", "Edible Fruit", 1);
	apple->registerSubscription("Fruit");
	orange->registerSubscription("Fruit");
	orange->sendMessage("Apple", "Orange > Apple", "Fruit");
	apple->writeBlackboard("Orange", "Nah ah", "Fruit");
	orange->sendMessage("Apple", "Out of sync comm", "Fruit");
	MessageController::getInstance()->publishAnnouncements(); 
	std::cin.ignore();
	

}
