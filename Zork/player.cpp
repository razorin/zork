#include "stdafx.h"
#include "player.h"

#include <iostream>
#include "globals.h"
#include "item.h"
#include "utils.h"
#include "exit.h"

using namespace std;

Player::Player() {
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
		}
		break;
	case 3:
		if (CommandParser::IsEquals(arguments->at(0), PLAYER_ACTION_TAKE)) {
			Take(arguments->at(1), arguments->at(2));
		}

		break;
	default:
		cout << "I don't understand you" << endl;
		break;
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
	if (parent_item != NULL) {
		Item *item = (Item *)parent_item->Find(ENTITY_TYPE::ITEM, name);
		if (item != NULL) {
			location->contains.remove(item);
			contains.push_back(item);
			cout << "Taken" << endl;
		}
		else {
			cout << "There is not " << name << " in " << parent_name << endl;
		}
	}
	else {
		cout << "There is not such thing!" << endl;
	}
}

void Player::Drop(const string name) {
	Item *item = (Item *)Find(ENTITY_TYPE::ITEM, name);
	if (item != NULL) {
		location->contains.push_back(item);
		contains.remove(item);
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
	cout << "Name /t Description" << endl;
	for each (auto item in contains) {
		item->Show();
	}
}

