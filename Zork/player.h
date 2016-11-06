#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"
#include <vector>

class Player : public Creature {
public:
	Player();
	virtual ~Player();
	void Update();
	void Do(const vector<string> *arguments);
private:
	void Look() const;
	void Inventory() const;
};

#endif // !PLAYER_H

