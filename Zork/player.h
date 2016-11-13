#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"
#include <vector>
#include "item.h"

class Player : public Creature {
public:
	Player(Room *location, int hit_points, int attack_points);
	virtual ~Player();
	void Update();
	void Do(const vector<string> *arguments);
	Item *weapon;
private:
	void Look() const;
	void Look(const string name) const;
	void Equip() const;
	void Equip(const string name);
	void UnEquip();
	void Inventory() const;
	void Take(const string name);
	void Take(const string name, const string parent_name);
	void Drop(const string name);
	void Drop(const string name, const string parent_name);
	void Go(const string name_direction);
	void Attack(const string creature);
};

#endif // !PLAYER_H

