#pragma once
#ifndef UTILS_H
#define UTILS_H

#include "globals.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CommandParser {
public:
	CommandParser();
	virtual ~CommandParser();

	static const void ParseCommand(const string command, vector<string> & arguments);
	static const bool IsToken(const string word);
	static const bool IsIgnoredWord(const string word);
	static const bool IsEquals(string a, string b);

	static const string Trim(const string &s);
};

class Utils {
public:
	Utils();
	virtual ~Utils();

	static const GAME_DIRECTION DirectionInverse(const GAME_DIRECTION direction);
	static const GAME_DIRECTION GetDirection(const string name_direction, bool inverse = false);
	static const string GetDirectionName(const GAME_DIRECTION direction, bool inverse = false);
	
};

#endif // !UTILS_H

