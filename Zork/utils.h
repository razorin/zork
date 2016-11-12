#pragma once
#ifndef UTILS_H
#define UTILS_H

#include "globals.h"
#include <string>
#include <vector>

using namespace std;

class CommandParser {
public:
	CommandParser();
	virtual ~CommandParser();

	static const vector<string> * ParseCommand(const string command);
	static const bool IsToken(const string word);
	static const bool IsIgnoredWord(const string word);
	static const bool IsEquals(string a, string b);

};

class Utils {
public:
	Utils();
	virtual ~Utils();

	static const GAME_DIRECTIONS DirectionInverse(const GAME_DIRECTIONS direction) { 
		if (direction == GAME_DIRECTIONS::NORTH) {
			return GAME_DIRECTIONS::SOUTH;
		}
		else if (direction == GAME_DIRECTIONS::SOUTH) {
			return GAME_DIRECTIONS::NORTH;
		}
		else if (direction == GAME_DIRECTIONS::EAST) {
			return GAME_DIRECTIONS::WEST;
		}
		else if (direction == GAME_DIRECTIONS::WEST) {
			return GAME_DIRECTIONS::EAST;
		}

		return GAME_DIRECTIONS::NONE;
	}
};

#endif // !UTILS_H

