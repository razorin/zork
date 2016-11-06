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

	Room *room = new Room("Beach", "A nice beach");
	Exit *exit = new Exit();
	exit->destination = room;
	exit->source = room;
	exit->direction = GAME_DIRECTIONS::NORTH;
	room->contains.push_back(exit);
	room->contains.push_back(item);

	entities.push_back(room);
	//entities.push_back(exit);

	Creature *creature = new Creature();
	entities.push_back(creature);

	player = new Player();
	player->location = room;
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