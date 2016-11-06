#include "stdafx.h"
#include "player.h"

#include <iostream>
#include "globals.h"
#include "item.h"
#include "utils.h"

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
		if (Utils::IsEquals(arguments->at(0), PLAYER_ACTION_LOOK)) {
			Look();
		} else if(Utils::IsEquals(arguments->at(0), PLAYER_ACTION_INVENTORY)){
			Inventory();
		} else{
			cout << "I don't understand you" << endl;
		}
		break;
	case 2:
		if (Utils::IsEquals(arguments->at(0), PLAYER_ACTION_LOOK)) {
			Look(arguments->at(1));
		} else if(Utils::IsEquals(arguments->at(0), PLAYER_ACTION_TAKE)){
			Take(arguments->at(1));
		} else if (Utils::IsEquals(arguments->at(0), PLAYER_ACTION_DROP)) {
			Drop(arguments->at(1));
		}
		break;
	default:
		cout << "I don't understand you" << endl;
		break;
	}
}

void Player::Take(const string name) {
	Item *item = (Item *) location->Find(name);
	if (item != NULL) {
		location->contains.remove(item);
		contains.push_back(item);
		cout << "Taken" << endl;
	} else{
		cout << "There is not such thing!" << endl;
	}
}

void Player::Drop(const string name) {
	Item *item = (Item *)Find(name);
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
	item->Look();
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

