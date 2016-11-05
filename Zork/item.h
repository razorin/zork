#pragma once
#ifndef ITEM_H
#define ITEM_H
#include "entity.h"

class Item : public Entity
{
public:
	Item();
	virtual ~Item();
	void Update();
};

#endif // !ITEM_H

