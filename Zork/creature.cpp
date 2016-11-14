#include "stdafx.h"
#include "creature.h"
#include <iostream>

using namespace std;

Creature::Creature(const string name, const string description, Room *location, int hit_points, int attack_points) : Entity(name, description){
	this->location = location;
	this->attack_points = attack_points;
	this->hit_points = hit_points;
	this->max_hit_points= hit_points;

	this->location->contains.push_back(this);
}


Creature::~Creature() {
}

void Creature::Update() {
	//cout << " Creature!!! " << endl;
}

bool Creature::IsLive() {
	return hit_points > 0;
}

void Creature::ReceiveDamage(int damage) {
	if (IsLive()) {
		hit_points -= damage;
		if (type == ENTITY_TYPE::PLAYER)
			cout << "You have " << hit_points << "/" << max_hit_points << " HP" << endl;
		if (!IsLive()) {
			if (type == ENTITY_TYPE::PLAYER)
				cout << "You are dead." << endl;
			else
				cout << name << " is dead." << endl;
		}
	}
}

