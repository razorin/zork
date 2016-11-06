#include "stdafx.h"
#include "player.h"

#include <iostream>
#include "globals.h"

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
		if (arguments->at(0) == PLAYER_ACTION_LOOK) {
			Look();
		} else if(arguments->at(0) == PLAYER_ACTION_INVENTORY){
			Inventory();
		} else{
			cout << "I don't understand you" << endl;
		}
		break;
	case 2:
		break;
	default:
		cout << "I don't understand you" << endl;
		break;
	}
}

void Player::Look() const {
	location->Look();
	cout << "Location name: " << location->name << endl;
}

void Player::Inventory() const {
	cout << "Name /t Description" << endl;
	for each (auto item in contains) {
		item->Show();
		//cout << item->name << "/t" << item->description << endl;
	}
}

