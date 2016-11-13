#pragma once
#ifndef ITEM_H
#define ITEM_H
#include "entity.h"

class Item : public Entity
{
public:
	Item();
	Item(const string name, const string description, ITEM_TYPE type, int attack = 0);
	virtual ~Item();
	void Update();

	ITEM_TYPE item_type;
	int attack;
};

#endif // !ITEM_H

