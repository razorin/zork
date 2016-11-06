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

enum GAME_DIRECTIONS {
	NORTH,
	SOUTH,
	EAST,
	WEST
};


#endif // !GLOBALS_H
