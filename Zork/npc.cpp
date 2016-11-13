#include "stdafx.h"
#include "npc.h"
#include "item.h"
#include <iostream>

using namespace std;


Npc::Npc(const string name, const string description, Room *location, const string dialog, const NPC_TYPE npc_type) : Creature(name, description, location) {
	type = ENTITY_TYPE::NPC;
	this->dialog = dialog;
	this->npc_type = npc_type;
}


Npc::~Npc() {
}

void Npc::Speak() const {
	cout << name << " says: \"" << dialog << "\"" << endl;
	if (npc_type == NPC_TYPE::TRADER) {
		cout << "Name\t\tDescription\t\tPrice" << endl;
		for each (auto entity in contains) {
			if (entity->type == ENTITY_TYPE::ITEM) {
				Item *item = (Item *)entity;
				cout << item->name << "\t\t"<< item->description << "\t\t" << item->price << endl;
			}
		}
	}
}

