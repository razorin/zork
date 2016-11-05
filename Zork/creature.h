#pragma once
#ifndef CREATURE_H
#define CREATURE_H

#include "entity.h"
#include "room.h"

class Creature : public Entity {
public:
	Creature();
	virtual ~Creature();
	virtual void Update();

	Room *location;
};

#endif // !CREATURE_H

