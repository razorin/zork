#pragma once
#ifndef WORLD_H
#define WORLD_H

#include "entity.h"
#include <vector>
#include "player.h"
#include "monster.h"

class World
{
public:
	World();
	virtual ~World();

	GAME_STATE Update(const vector<string> arguments);


	vector<Entity*> entities;
	Player *player;
	Monster *final_boss;


};

#endif // !WORLD_H

