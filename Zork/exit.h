#pragma once
#ifndef EXIT_H
#define EXIT_H

#include "entity.h"
#include "room.h"
#include "utils.h"

class Room;

class Exit :
	public Entity {
public:
	Exit(const string name, const string description, Room *source, Room *destination, const GAME_DIRECTION direction);
	virtual ~Exit();
	void Update();

	Room *source;
	Room *destination;
	GAME_DIRECTION direction;
	bool opened;
};

#endif // !EXIT_H

