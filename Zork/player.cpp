#include "stdafx.h"
#include "player.h"

#include <iostream>
#include "globals.h"
#include "item.h"
#include "utils.h"
#include "exit.h"
#include "monster.h"
#include "npc.h"

using namespace std;

Player::Player(Room *location, int hit_points, int attack_points) : Creature("Player", "Player", location, hit_points, attack_points){
	type = ENTITY_TYPE::PLAYER;
	gold = 30;
}


Player::~Player() {
}

void Player::Update() {
	//cout << "Player!!" << endl;
}

void Player::Do(const vector<string> *arguments) {
	switch (arguments->size()) {
	case 0:
		cout << "I don't understand you" << endl;
		break;
	case 1:
		if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_LOOK)) {
			Look();
		} else if(CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_INVENTORY)){
			Inventory();
		}
		else if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_EQUIP)) {
			Equip();
		}
		else if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_UNEQUIP)) {
			UnEquip();
		} else{
			cout << "I don't understand you" << endl;
		}
		break;
	case 2:
		if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_LOOK)) {
			Look(arguments->at(1));
		} else if(CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_TAKE)){
			Take(arguments->at(1));
		} else if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_DROP)) {
			Drop(arguments->at(1));
		} else if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_GO)) {
			Go(arguments->at(1));
		} else if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_EQUIP)) {
			Equip(arguments->at(1));
		} else if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_ATTACK)) {
			Attack(arguments->at(1));
		} else if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_TALK)) {
			Talk(arguments->at(1));
		} else if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_USE)) {
			Use(arguments->at(1));
		} else {
			cout << "I don't understand you" << endl;
		}
		break;
	case 3:
		if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_TAKE)) {
			Take(arguments->at(1), arguments->at(2));
		} else if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_DROP)) {
			Drop(arguments->at(1), arguments->at(2));
		} else if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_BUY)) {
			Buy(arguments->at(1), arguments->at(2));
		} else {
			cout << "I don't understand you" << endl;
		}

		break;
	default:
		cout << "I don't understand you" << endl;
		break;
	}
}

void Player::Buy(const string item_name, const string trader) {
	Npc *npc = (Npc *)location->Find(ENTITY_TYPE::NPC, trader);
	if (npc == NULL) {
		cout << "He's not here." << endl;
	} else if (npc->npc_type != NPC_TYPE::TRADER) {
		cout << "He hasn't anything to sell!" << endl;
	} else{
		Item *item = (Item *)npc->Find(ENTITY_TYPE::ITEM, item_name);
		if (item == NULL) {
			cout << npc->name << " hasn't such item" << endl;
		} else {
			if(item->price > gold) {
				cout << "You haven't enough gold pieces!" << endl;
			} else {
				cout << "You have bought a " << item->name << endl;
				npc->contains.remove(item);
				contains.push_back(item);
				gold -= item->price;
			}			
		}
	}
}

void Player::Talk(const string npc_name) {
	Npc *npc = (Npc *) location->Find(ENTITY_TYPE::NPC, npc_name);

	if (npc == NULL) {
		cout << "He's not here." << endl;
	}
	else {
		npc->Speak();
	}
}

void Player::Equip() const {
	if (weapon == NULL)
		cout << "You haven't any weapon equipped right now" << endl;
	else {
		weapon->Look();
	}
}

void Player::Equip(const string name) {
	Item *item = (Item *)Find(ENTITY_TYPE::ITEM, name);
	if (item == NULL)
		cout << "You haven't such item" << endl;
	else {
		if (item->item_type == ITEM_TYPE::WEAPON) {
			weapon = item;
			cout << "Equipped" << endl;
		} else {
			cout << "You can't equip this!" << endl;
		}
	}
}

void Player::UnEquip() {
	if (weapon == NULL)
		cout << "You haven't any weapon equipped right now" << endl;
	else {
		weapon = NULL;
		cout << "Unequipped" << endl;
	}
}

void Player::Drop(const string name, const string container_name) {
	Item *item = (Item *) Find(ENTITY_TYPE::ITEM, name);
	if (item == NULL) {
		cout << "You haven't any " << name << endl;
	} else {
		Item *container = (Item *)Find(ENTITY_TYPE::ITEM, container_name);
		if (container == NULL) {
			container = (Item *)location->Find(ENTITY_TYPE::ITEM, container_name);
		}

		if (container == NULL) {
			cout << "There isn't any" << container_name << endl;
		} else{
			if (container->item_type == ITEM_TYPE::CONTAINER) {
				container->contains.push_back(item);
				contains.remove(item);
				if (item == weapon) {
					weapon = NULL;
				}
				cout << "Dropped" << endl;
			} else {
				cout << "You can't drop " << name << " in " << container_name << endl;
			}
 		}
	}
}

void Player::Go(const string name_direction) {
	GAME_DIRECTION direction = Utils::GetDirection(name_direction);

	if (direction == GAME_DIRECTION::NONE)
		cout << "Invalid direction to go" << endl;
	else {
		Exit *exit = location->GetExit(direction);
		if (exit != NULL) {
			location->contains.remove(this);
			if (exit->direction == direction) 
				location = exit->destination;
			
			else 
				location = exit->source;
			
			location->contains.push_back(this);
			Look();
		}
		else {
			cout << "I can't go in that direction!!!" << endl;
		}
		
	}
}

void Player::Take(const string name) {
	Item *item = (Item *) location->Find(ENTITY_TYPE::ITEM, name);
	if (item != NULL) {
		location->contains.remove(item);
		contains.push_back(item);
		cout << "Taken" << endl;
	} else{
		cout << "There is not such thing!" << endl;
	}
}

void Player::Take(const string name, const string parent_name) {
	Item *parent_item = (Item *)location->Find(ENTITY_TYPE::ITEM, parent_name);

	if(parent_item == NULL)
		parent_item = (Item *)Find(ENTITY_TYPE::ITEM, parent_name);
	
	if (parent_item == NULL) {
		cout << "There isn't any" << parent_name << endl;
	} else {
		Item *item = (Item *)parent_item->Find(ENTITY_TYPE::ITEM, name);
		if (item != NULL) {
			parent_item->contains.remove(item);
			contains.push_back(item);
			cout << "Taken" << endl;
		} else {
			cout << "There isn't any" << name << endl;
		}
	}
}

void Player::Drop(const string name) {
	Item *item = (Item *)Find(ENTITY_TYPE::ITEM, name);
	if (item != NULL) {
		location->contains.push_back(item);
		contains.remove(item);
		if (item == weapon) {
			weapon = NULL;
		}
		cout << "Dropped" << endl;
	}
	else {
		cout << "You have not such thing!" << endl;
	}
}

void Player::Look(const string name) const {
	Entity *item = Find(name);
	if (item != NULL)
		item->Look();
	else
		item = location->Find(name);
		if(item != NULL)
			item->Look();
		else
			cout << "There is not such item" << endl;
}

void Player::Look() const {
	location->Look();
}

void Player::Use(const string name) {
	Item *item = (Item *)Find(ENTITY_TYPE::ITEM, name);
	if (item == NULL)
		cout << "You haven't such item!" << endl;
	else {
		contains.remove(item);
		int prev_hit_points = hit_points;
		this->hit_points += item->attack;
		if (hit_points > max_hit_points)
			hit_points = max_hit_points;
		cout << "You have recovered " << hit_points - prev_hit_points << " HP" << endl;
		cout << "You have " << hit_points << "/" << max_hit_points << " HP" <<endl;
	}
		
}

void Player::Inventory() const {
	cout << "Name \t\t\t Description" << endl;
	for each (auto item in contains) {
		item->Show();
	}
	cout << gold << " Gold pieces" << endl;
}

void Player::Attack(const string monster_name) {
	Monster *monster = (Monster*)location->Find(ENTITY_TYPE::MONSTER, monster_name);
	if (monster != NULL) {
		if (monster->IsLive()) {
			int total_attack = attack_points + (weapon == NULL ? 0 : weapon->attack);
			cout << "You attack " << monster_name << " with a total damage of " << total_attack << endl;
			monster->ReceiveDamage(total_attack);
		} else {
			cout << "Are you sure that attack a corpse is really a good idea?" << endl;
		}
	}	else {
		cout << "There is not such enemy!" << endl;
	}
}

