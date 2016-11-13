#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

#define KEYBOARD_KEY_ESCAPE 27
#define KEYBOARD_KEY_ENTER 13

/*
	PLAYER ACTIONS TOKENS
*/
#define PLAYER_ACTION_LOOK "look" 
#define PLAYER_ACTION_EQUIP "equip" 
#define PLAYER_ACTION_UNEQUIP "unequip" 
#define PLAYER_ACTION_TAKE "take"
#define PLAYER_ACTION_DROP "drop"
#define PLAYER_ACTION_HELP "help"
#define PLAYER_ACTION_GO "go"
#define PLAYER_ACTION_BUY "buy"
#define PLAYER_ACTION_SELL "sell"
#define PLAYER_ACTION_INVENTORY "inventory"
#define PLAYER_ACTION_ATTACK "attack"
#define PLAYER_ACTION_TALK "talk"

/*
	IGNORE WORDS
*/
#define IGNORE_WORD_THE "the"
#define IGNORE_WORD_TO "to"
#define IGNORE_WORD_A "a"
#define IGNORE_WORD_AND "and"
#define IGNORE_WORD_FROM "from"
#define IGNORE_WORD_INTO "into"
#define IGNORE_WORD_WITH "with"

/*
	GAME DIRECTIONS STRINGS
*/
#define GAME_DIRECTION_NORTH "North"
#define GAME_DIRECTION_SOUTH "South"
#define GAME_DIRECTION_EAST "East"
#define GAME_DIRECTION_WEST "West"

enum GAME_DIRECTIONS {
	NONE, 
	NORTH,
	SOUTH,
	EAST,
	WEST
};

enum ENTITY_TYPE {
	ROOM,
	EXIT,
	ITEM,
	MONSTER,
	NPC,
	PLAYER
};

enum ITEM_TYPE {
	WEAPON,
	CONTAINER,
	CONSUMABLES,
	INGREDIENTS

};

enum NPC_TYPE {
	SPEAKER,
	TRADER,
};


#endif // !GLOBALS_H
