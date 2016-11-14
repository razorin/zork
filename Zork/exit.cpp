#include "stdafx.h"
#include "exit.h"
#include <iostream>

using namespace std;

Exit::Exit(const string name, const string description, Room *source, Room *destination, const GAME_DIRECTION direction) : Entity(name, description) {
	type = ENTITY_TYPE::EXIT;
	(this)->direction = direction;
	this->source = source;
	this->destination = destination;

	this->source->contains.push_back(this);
	this->destination->contains.push_back(this);
}


Exit::~Exit() {

}

void Exit::Update() {
	//cout << "Exit!! " << endl;
}
