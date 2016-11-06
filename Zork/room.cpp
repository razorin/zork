#include "stdafx.h"
#include "room.h"

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
