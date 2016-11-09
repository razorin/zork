#include "stdafx.h"
#include "exit.h"
#include <iostream>

using namespace std;

Exit::Exit(const string name, const string description, const GAME_DIRECTIONS direction) : Entity(name, description) {
	type = ENTITY_TYPE::EXIT;
	(this)->direction = direction;
}


Exit::~Exit() {
	delete source;
	source = NULL;
	delete destination;
	destination = NULL;
}

void Exit::Update() {
	//cout << "Exit!! " << endl;
}
