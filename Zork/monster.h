#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include "creature.h"
class Monster :
	public Creature {
public:
	Monster(const string name, const string description, Room *location, int hit_points, int attack_points);
	virtual ~Monster();
	void Update();
private:
	bool attack_ready;
	
};

#endif // !MONSTER_H

