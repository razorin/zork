#include "stdafx.h"
#include "quest.h"


Quest::Quest(Monster *monster, int gold, const string message) {
	this->monster = monster;
	this->gold = gold;
	this->rewarded = false;
	this->message = message;
}


Quest::~Quest() {
}
