#pragma once
#ifndef CREATURE_H
#define CREATURE_H

#include "entity.h"
#include "room.h"

class Creature : public Entity {
public:
	Creature(const string name, const string description, Room *location, int hit_points = 1, int attack_points = 1);
	virtual ~Creature();
	virtual void Update();

	virtual bool IsLive();
	virtual void ReceiveDamage(int damage);

	Room *location;
	int hit_points;
	int max_hit_points;
	int attack_points;
};

#endif // !CREATURE_H

