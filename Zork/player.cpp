#include "stdafx.h"
#include "player.h"

#include <iostream>
#include "globals.h"
#include "item.h"
#include "utils.h"
#include "exit.h"
#include "monster.h"

using namespace std;

Player::Player(Room *location, int hit_points, int attack_points) : Creature("", "", location, hit_points, attack_points){
	type = ENTITY_TYPE::PLAYER;
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
		} else {
			cout << "I don't understand you" << endl;
		}
		break;
	case 3:
		if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_TAKE)) {
			Take(arguments->at(1), arguments->at(2));
		} else if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_DROP)) {
			Drop(arguments->at(1), arguments->at(2));
		}

		break;
	default:
		cout << "I don't understand you" << endl;
		break;
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
	GAME_DIRECTIONS direction = GAME_DIRECTIONS::NONE;
	if (CommandParser::IsEquals(name_direction, GAME_DIRECTION_NORTH)) {
		direction = GAME_DIRECTIONS::NORTH;
	} else if (CommandParser::IsEquals(name_direction, GAME_DIRECTION_EAST)) {
		direction = GAME_DIRECTIONS::EAST;
	} else if (CommandParser::IsEquals(name_direction, GAME_DIRECTION_WEST)) {
		direction = GAME_DIRECTIONS::WEST;
	} else if (CommandParser::IsEquals(name_direction, GAME_DIRECTION_SOUTH)) {
		direction = GAME_DIRECTIONS::SOUTH;
	}

	if (direction == GAME_DIRECTIONS::NONE)
		cout << "Invalid direction to go" << endl;
	else {
		Exit *exit = location->GetExit(direction);
		if (exit != NULL) {
			if(exit->direction == direction)
				location = exit->destination;
			else
				location = exit->source;
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
	cout << "Location name: " << location->name << endl;
}

void Player::Inventory() const {
	cout << "Name \t\t\t Description" << endl;
	for each (auto item in contains) {
		item->Show();
	}
}

void Player::Attack(const string monster_name) {
	Monster *monster = (Monster*)location->Find(ENTITY_TYPE::MONSTER, monster_name);
	if (monster != NULL) {
		if (monster->IsLive()) {
			int total_attack = attack_points + (weapon == NULL ? 0 : weapon->attack);
			cout << "Attack " << monster_name << " with a total damage of " << total_attack << endl;
			monster->ReceiveDamage(total_attack);
		} else {
			cout << "Are you sure that attack a corpse is really a good idea?" << endl;
		}
	}	else {
		cout << "There is not such enemy!" << endl;
	}
}

