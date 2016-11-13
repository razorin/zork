#pragma once
#include "monster.h"
#include <string>

class Quest {
public:
	int gold;
	Monster *monster;
	bool rewarded;
	string message;

	Quest(Monster *monster, int gold, const string message);
	virtual ~Quest();
};

