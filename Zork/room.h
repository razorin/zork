#pragma once
#ifndef ROOM_H
#define ROOM_H

#include "entity.h"
#include "globals.h"

class Exit;


class Room : public Entity{
public:
	Room();
	Room(const string name, const string description);
	virtual ~Room();
	void Update();
	Exit* GetExit(const GAME_DIRECTION);
	void Look() const;
};

#endif // !ROOM_H

