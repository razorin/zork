#include "stdafx.h"
#include "world.h"
#include "item.h"
#include "room.h"
#include "exit.h"
#include "creature.h"
#include "player.h"
#include "globals.h"
#include "monster.h"
#include "npc.h"

World::World() {
	entities = vector<Entity*>();
	
	Item *item = new Item("Sword", "Increment your attack (+3)", ITEM_TYPE::WEAPON, 3);
	Item *chest = new Item("Chest", "A chest that maybe contains something", ITEM_TYPE::CONTAINER);
	chest->contains.push_back(item);

	Item *spear = new Item("Rusty Spear", "A rusty spear. Increase your attack (+1)", ITEM_TYPE::WEAPON, 1, 20);
	Item *dagger = new Item("Silver Dagger", "A silver dagger. Increase your attack (+3)", ITEM_TYPE::WEAPON, 3, 15);
	Item *knife = new Item("Sharp Knife", "A sharp knife. Increase your attack (+2)", ITEM_TYPE::WEAPON, 2, 10);

	Item *red_potion = new Item("Red potion", "A vial with reddish substance. Recovers 5 HP", ITEM_TYPE::CONSUMABLE, 5, 10);
	Item *yellow_potion = new Item("Yellow potion", "A vial with yellowish substance. Recovers 10 HP", ITEM_TYPE::CONSUMABLE, 10, 10);
	//entities.push_back(item);

	Room *beach = new Room("Beach", "A nice beach");
	Room *forest = new Room("Forest", "A dark forest");
	Room *dock = new Room("Dock", "A small dock full of small boats and fishy smell.");
	Room *village = new Room("Village", "A small a peaceful village");
	Room *chaman_hut = new Room("Chaman's hut", "A poor hut");

	Exit *beach_forest_exit = new Exit("North Exit", "A pathfind", beach, forest, GAME_DIRECTION::NORTH);
	Exit *dock_village = new Exit("Road", "A small road that connects the port and the village", dock, village, GAME_DIRECTION::EAST);
	Exit *village_beach = new Exit("Path", "A small path that connects the village and the beach", village, beach, GAME_DIRECTION::SOUTH);
	Exit *beach_chaman = new Exit("Path", "", beach, chaman_hut, GAME_DIRECTION::EAST);
	

	Monster *giant_crab = new Monster("Giant crab", "A huge crab", beach, 5, 2);
	Monster *troll = new Monster("Troll", "A huge troll", beach, 5, 2);
	
	Npc *fisher = new Npc("Old fisher", "An old man that seems to have been fishing all his life", dock, "Hey kid! Are you the hunter we were hoping for? You should talk to the mayor. He is in the village going east.", NPC_TYPE::SPEAKER);
	Npc *blacksmith = new Npc("Blacksmith", "A big strong man", village, "Do you need some weapons? I have the best prices in the village", NPC_TYPE::TRADER);
	Npc *chaman = new Npc("Chaman", "An old and strange man", chaman_hut, "I have some potions that maybe help to you in your journey. Do you want to buy something?", NPC_TYPE::TRADER);

	blacksmith->contains.push_back(spear);
	blacksmith->contains.push_back(dagger);
	blacksmith->contains.push_back(knife);

	chaman->contains.push_back(red_potion);
	chaman->contains.push_back(yellow_potion);
	
	//Exit *forest_exit = new Exit("North Exit", "A pathfind", GAME_DIRECTIONS::SOUTH);

	
	//beach_forest_exit->destination = forest;
	//beach_forest_exit->source = beach;

	//forest_exit->destination = beach;
	//forest_exit->source = forest;


	//beach_exit->direction = GAME_DIRECTIONS::NORTH;
	//beach->contains.push_back(beach_forest_exit);
	beach->contains.push_back(giant_crab);
	beach->contains.push_back(troll);
	beach->contains.push_back(village_beach);
	beach->contains.push_back(beach_chaman);
	//beach->contains.push_back(chest);

	dock->contains.push_back(fisher);
	dock->contains.push_back(dock_village);

	village->contains.push_back(dock_village);
	village->contains.push_back(blacksmith);
	village->contains.push_back(village_beach);

	chaman_hut->contains.push_back(chaman);
	chaman_hut->contains.push_back(beach_chaman);

	forest->contains.push_back(beach_forest_exit);

	entities.push_back(beach);
	//entities.push_back(exit);

	//Creature *creature = new Creature();
	//entities.push_back(creature);

	player = new Player(dock, 10, 1);
	final_boss = troll;
	dock->contains.push_back(player);

	player->Look();
	//player->location = beach;
	//player->contains.push_back(item);
	//entities.push_back(player);
}


World::~World() {
	for each (auto element in entities) {
		delete element;
		element = NULL;
	}
}

GAME_STATE World::Update(const vector<string> *arguments) {
	player->Do(arguments);
	for each (auto entity in entities) {
		entity->Update();
	}
	if (!player->IsLive())
		return GAME_STATE::GAME_OVER;
	if (!final_boss->IsLive())
		return GAME_STATE::END;

	return GAME_STATE::CONTINUE;
}