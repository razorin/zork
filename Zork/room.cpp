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

void Room::Update() {
	//cout << "It's a room" << endl;
	Entity::Update();
}

Exit* Room::GetExit(const GAME_DIRECTIONS direction) {
	for (auto it = contains.begin(); it != contains.end(); ++it) {
		if ((*it)->type == ENTITY_TYPE::EXIT) {
			Exit* ex = (Exit*)*it;
			GAME_DIRECTIONS inverse = Utils::DirectionInverse(ex->direction);
			if ((*ex->source) == (*this) && ex->direction == direction) {
				return ex;
			} else if ((*ex->destination) == (*this) &&  direction == inverse) {
				return ex;
			}
		}
	}

	return NULL;
}


