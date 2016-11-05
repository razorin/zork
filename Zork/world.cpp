#include "stdafx.h"
#include "world.h"
#include "item.h"
#include "room.h"
#include "exit.h"
#include "creature.h"
#include "player.h"

World::World() {
	entities = vector<Entity*>();
	
	Item *item = new Item();
	entities.push_back(item);

	Room *room = new Room();
	entities.push_back(room);

	Exit *exit = new Exit();
	entities.push_back(exit);

	Creature *creature = new Creature();
	entities.push_back(creature);

	Player *player = new Player();
	entities.push_back(player);
}


World::~World() {
	for each (auto element in entities) {
		delete element;
		element = NULL;
	}
}

void World::Update(const vector<string> *arguments) {
	for each (auto entity in entities) {
		entity->Update();
	}
}