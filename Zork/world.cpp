#include "stdafx.h"
#include "world.h"
#include "item.h"
#include "room.h"
#include "exit.h"
#include "creature.h"
#include "player.h"

World::World() {
	entities = vector<Entity*>();
	
	Item *item = new Item("Sword", "Increment your attack (+3)");
	//entities.push_back(item);

	Room *beach = new Room("Beach", "A nice beach");
	Room *forest = new Room("Forest", "A dark forest");
	Exit *beach_forest_exit = new Exit("North Exit", "A pathfind", GAME_DIRECTIONS::NORTH);
	//Exit *forest_exit = new Exit("North Exit", "A pathfind", GAME_DIRECTIONS::SOUTH);
	
	beach_forest_exit->destination = forest;
	beach_forest_exit->source = beach;

	//forest_exit->destination = beach;
	//forest_exit->source = forest;


	//beach_exit->direction = GAME_DIRECTIONS::NORTH;
	beach->contains.push_back(beach_forest_exit);
	beach->contains.push_back(item);

	forest->contains.push_back(beach_forest_exit);

	entities.push_back(beach);
	//entities.push_back(exit);

	Creature *creature = new Creature();
	entities.push_back(creature);

	player = new Player();
	player->location = beach;
	player->contains.push_back(item);
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