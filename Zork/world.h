#pragma once
#ifndef WORLD_H
#define WORLD_H

#include "entity.h"
#include <vector>

class World
{
public:
	World();
	virtual ~World();

	void Update(const vector<string> *arguments);


	vector<Entity*> entities;


};

#endif // !WORLD_H

