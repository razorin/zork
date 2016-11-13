#include "stdafx.h"
#include "monster.h"


Monster::Monster(const string name, const string description, Room *location, int hit_points, int attack_points) : Creature(name, description, location, hit_points, attack_points) {
	type = ENTITY_TYPE::MONSTER;
}


Monster::~Monster() {
}


