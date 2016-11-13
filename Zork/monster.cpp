#include "stdafx.h"
#include "monster.h"
#include "player.h"
#include <iostream>

using namespace std;


Monster::Monster(const string name, const string description, Room *location, int hit_points, int attack_points) : Creature(name, description, location, hit_points, attack_points) {
	type = ENTITY_TYPE::MONSTER;
	attack_ready = false;
}


Monster::~Monster() {
}

void Monster::Update() {
	if (IsLive()) {
		if (attack_ready) {
			Player *player = (Player *)location->Find(ENTITY_TYPE::PLAYER, "player");
			if (player == NULL) {
				attack_ready = false;
			} else {
				cout << name << " attacks you with " << attack_points << " points of damage" << endl;
				player->ReceiveDamage(attack_points);
			}
		} else {
			Player *player = (Player *)location->Find(ENTITY_TYPE::PLAYER, "player");
			if (player != NULL)
				attack_ready = true;
		}
	}
}
