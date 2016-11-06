#pragma once
#ifndef ITEM_H
#define ITEM_H
#include "entity.h"

class Item : public Entity
{
public:
	Item();
	Item(const string name, const string description);
	virtual ~Item();
	void Update();
};

#endif // !ITEM_H

