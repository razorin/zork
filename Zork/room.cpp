#include "stdafx.h"
#include "room.h"
#include "exit.h"
#include <iostream>

using namespace std;

Room::Room() {
}

Room::Room(const string name, const string description) : Entity(name, description) {
	
}


Room::~Room() {
}

void Room::Look() const {
	cout << "\t\t" << name << endl;
	cout << "--------------------------------------" << endl;
	cout << description << endl;


	for each (auto element in contains) {
		if (element->type == ENTITY_TYPE::EXIT) {
			Exit *exit = (Exit *)element;
			GAME_DIRECTION direction = exit->direction;

			cout << "There is a " << element->name << " to the " << Utils::GetDirectionName(exit->direction, exit->destination == this) <<endl;
		}
	}

	for each (auto element in contains) {
		if (element->type == ENTITY_TYPE::ITEM) {
			cout << "There is a " << element->name << endl;
		}
	}

	for each (auto element in contains) {
		if (element->type == ENTITY_TYPE::NPC) {
			cout << "There is a " << element->name << endl;
		}
	}

	for each (auto element in contains) {
		if (element->type == ENTITY_TYPE::MONSTER) {
			cout << "There is a " << element->name << endl;
		}
	}
}

void Room::Update() {
	//cout << "It's a room" << endl;
	//Entity::Update();
}

Exit* Room::GetExit(const GAME_DIRECTION direction) {
	for (auto it = contains.begin(); it != contains.end(); ++it) {
		if ((*it)->type == ENTITY_TYPE::EXIT) {
			Exit* ex = (Exit*)*it;
			GAME_DIRECTION inverse = Utils::DirectionInverse(ex->direction);
			if ((*ex->source) == (*this) && ex->direction == direction) {
				return ex;
			} else if ((*ex->destination) == (*this) &&  direction == inverse) {
				return ex;
			}
		}
	}

	return NULL;
}


