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
	void Look(const string name) const;
	void Inventory() const;
	void Take(const string name);
	void Take(const string name, const string parent_name);
	void Drop(const string name);
	void Go(const string name_direction);
};

#endif // !PLAYER_H

