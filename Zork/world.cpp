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
	Item *dagger = new Item("Silver Dagger", "A silver dagger. Increase your attack (+3)", ITEM_TYPE::WEAPON, 1, 15);
	Item *knife = new Item("Sharp Knife", "A sharp knife. Increase your attack (+2)", ITEM_TYPE::WEAPON, 1, 10);
	//entities.push_back(item);

	Room *beach = new Room("Beach", "A nice beach");
	Room *forest = new Room("Forest", "A dark forest");
	Room *dock = new Room("Dock", "A small dock full of small boats and fishy smell.");
	Room *village = new Room("Village", "A small a peaceful village");

	Exit *beach_forest_exit = new Exit("North Exit", "A pathfind", beach, forest, GAME_DIRECTIONS::NORTH);
	Exit *dock_village = new Exit("Road", "A small road that connects the port and the village", dock, village, GAME_DIRECTIONS::EAST);
	Exit *village_beach = new Exit("Path", "A small paththat connects the village and the beach", village, beach, GAME_DIRECTIONS::SOUTH);

	

	Monster *giant_crab = new Monster("Giant crab", "A huge crab", beach, 5, 2);
	
	Npc *fisher = new Npc("Old fisher", "An old man that seems to have been fishing all his life", dock, "Hey kid! Are you the hunter we were hoping for? You should talk to the mayor. He is in the village going east.", NPC_TYPE::SPEAKER);
	Npc *blacksmith = new Npc("Blacksmith", "A big strong man", village, "Do you need some weapons? I have the best prices in the village", NPC_TYPE::TRADER);

	blacksmith->contains.push_back(spear);
	blacksmith->contains.push_back(dagger);
	blacksmith->contains.push_back(knife);
	//Exit *forest_exit = new Exit("North Exit", "A pathfind", GAME_DIRECTIONS::SOUTH);

	
	//beach_forest_exit->destination = forest;
	//beach_forest_exit->source = beach;

	//forest_exit->destination = beach;
	//forest_exit->source = forest;


	//beach_exit->direction = GAME_DIRECTIONS::NORTH;
	//beach->contains.push_back(beach_forest_exit);
	beach->contains.push_back(giant_crab);
	beach->contains.push_back(village_beach);
	//beach->contains.push_back(chest);

	dock->contains.push_back(fisher);
	dock->contains.push_back(dock_village);

	village->contains.push_back(dock_village);
	village->contains.push_back(blacksmith);
	village->contains.push_back(village_beach);

	forest->contains.push_back(beach_forest_exit);

	entities.push_back(beach);
	//entities.push_back(exit);

	//Creature *creature = new Creature();
	//entities.push_back(creature);

	player = new Player(dock, 10, 1);
	dock->contains.push_back(player);
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

void World::Update(const vector<string> *arguments) {
	player->Do(arguments);
	for each (auto entity in entities) {
		entity->Update();
	}
}