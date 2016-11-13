#pragma once
#include "creature.h"
class Npc :
	public Creature {
public:
	Npc(const string name, const string description, Room *location, const string dialog, const NPC_TYPE npc_type);
	virtual ~Npc();
	void Speak() const;

	string dialog;
	NPC_TYPE npc_type;
};

