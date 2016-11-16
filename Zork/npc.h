#pragma once


#ifndef NPC_H
#define NPC_H

#include "creature.h"
#include "quest.h"
#include <vector>
#include "player.h"

using namespace std;

class Npc :
	public Creature {
public:
	Npc(const string name, const string description, Room *location, const string dialog, const NPC_TYPE npc_type);
	virtual ~Npc();
	void Speak() const;
	void Sell(const string item_name, Player *player);

	string dialog;
	NPC_TYPE npc_type;
	vector<Quest*> quests;
};
#endif // !NPC_H

