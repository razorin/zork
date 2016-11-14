#include "stdafx.h"
#include "npc.h"
#include "item.h"
#include <iostream>
#include "player.h"

using namespace std;


Npc::Npc(const string name, const string description, Room *location, const string dialog, const NPC_TYPE npc_type) : Creature(name, description, location) {
	type = ENTITY_TYPE::NPC;
	this->dialog = dialog;
	this->npc_type = npc_type;
}


Npc::~Npc() {
	for each (auto quest in quests) {
		delete quest;
		quest = NULL;
	}

	quests.clear();
}

void Npc::Speak() const {
		cout << name << " says: \"" << dialog << "\"" << endl;
		for each (auto quest in quests) {
			if (!quest->rewarded) {
				if (quest->monster->IsLive()) {
					cout << quest->message << endl;
				} else {
					cout << "Thank you for kill the " << quest->monster->name << endl;
					cout << "Take this for your help: " << quest->gold << " gold pieces" << endl;
					Player *player = (Player *)location->Find(ENTITY_TYPE::PLAYER, "player");
					player->gold += quest->gold;
					quest->rewarded = true;
				}
			}
		}
		if (npc_type == NPC_TYPE::TRADER) {
			if (contains.size() > 0) {
				cout << "Name\t\tDescription\t\tPrice" << endl;
				for each (auto entity in contains) {
					if (entity->type == ENTITY_TYPE::ITEM) {
						Item *item = (Item *)entity;
						cout << item->name << "\t\t" << item->description << "\t\t" << item->price << endl;
					}
				}
			}
			else {
				cout << "Sorry but I have anything to sell right now." << endl;
			}
		}
}

