#pragma once
#ifndef EXIT_H
#define EXIT_H

#include "entity.h"
#include "room.h"
#include "utils.h"

class Exit :
	public Entity {
public:
	Exit();
	virtual ~Exit();
	void Update();

	Room *source;
	Room *destination;
	GAME_DIRECTIONS direction;
	bool opened;
};

#endif // !EXIT_H

