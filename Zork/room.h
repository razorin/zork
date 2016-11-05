#pragma once
#ifndef ROOM_H
#define ROOM_H

#include "entity.h"
class Room : public Entity{
public:
	Room();
	virtual ~Room();
	void Update();
};

#endif // !ROOM_H

