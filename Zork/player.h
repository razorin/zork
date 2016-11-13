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
	int gold;
	void Look() const;
private:
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
	void Use(const string name);
	void Attack(const string creature);
	void Talk(const string npc_name);
	void Buy(const string item, const string trader);
};

#endif // !PLAYER_H

