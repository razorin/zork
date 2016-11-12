#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

#define KEYBOARD_KEY_ESCAPE 27
#define KEYBOARD_KEY_ENTER 13

/*
	PLAYER ACTIONS TOKENS
*/
#define PLAYER_ACTION_LOOK "look" 
#define PLAYER_ACTION_TAKE "take"
#define PLAYER_ACTION_DROP "drop"
#define PLAYER_ACTION_HELP "help"
#define PLAYER_ACTION_GO "go"
#define PLAYER_ACTION_INVENTORY "inventory"

/*
	IGNORE WORDS
*/
#define IGNORE_WORD_THE "the"
#define IGNORE_WORD_TO "to"
#define IGNORE_WORD_A "a"
#define IGNORE_WORD_AND "and"
#define IGNORE_WORD_FROM "from"

/*
	GAME DIRECTIONS STRINGS
*/
#define GAME_DIRECTION_NORTH "north"
#define GAME_DIRECTION_SOUTH "south"
#define GAME_DIRECTION_EAST "east"
#define GAME_DIRECTION_WEST "west"

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
	CREATURE,
	PLAYER
};


#endif // !GLOBALS_H
