#include "stdafx.h"
#include "utils.h"


CommandParser::CommandParser() {
}


CommandParser::~CommandParser() {
}

const void CommandParser::ParseCommand(const string command, vector<string> & arguments) {
	string word = "";
	string multiple_words = "";
	for (auto it = command.begin(); it != command.end(); ++it) {
		bool is_last_element = (prev(command.end()) == it);
		if (*it != ' ' && is_last_element == false) {
			word += *it;
		}
		else {
			if (is_last_element == true) {
				word += *it;
			}
			if (CommandParser::IsToken(word)) {
				if (multiple_words != "")
					arguments.push_back(multiple_words);
				arguments.push_back(word);
				multiple_words = "";
			}
			else if (CommandParser::IsIgnoredWord(word) == false) {
				if (is_last_element) {
					multiple_words += word;
					arguments.push_back(multiple_words);
				}
				else {
					multiple_words += word + " ";;
				}
			}
			else if (CommandParser::IsIgnoredWord(word) == true) {
				if (multiple_words != "") {
					arguments.push_back(multiple_words);
					multiple_words = "";
				}
			}

			word = "";
		}
	}

}

const bool CommandParser::IsToken(const string word) {
	return (IsEquals(word, PLAYER_ACTION_USE) || IsEquals(word, PLAYER_ACTION_SELL) || IsEquals(word, PLAYER_ACTION_BUY) || IsEquals(word, PLAYER_ACTION_TALK) || IsEquals(word, PLAYER_ACTION_ATTACK) || IsEquals(word, PLAYER_ACTION_UNEQUIP) || IsEquals(word, PLAYER_ACTION_EQUIP) || IsEquals(word, PLAYER_ACTION_GO) || IsEquals(word, PLAYER_ACTION_LOOK) || IsEquals(word, PLAYER_ACTION_TAKE) || IsEquals(word, PLAYER_ACTION_DROP));
}

const bool CommandParser::IsIgnoredWord(const string word) {
	return (IsEquals(word, IGNORE_WORD_WITH) || IsEquals(word, IGNORE_WORD_INTO) ||  IsEquals(word, IGNORE_WORD_FROM) || IsEquals(word, IGNORE_WORD_A) || IsEquals(word, IGNORE_WORD_THE) || IsEquals(word, IGNORE_WORD_TO));
}

const bool CommandParser::IsEquals(string a, string b) {
	for (auto & c : a) c = toupper(c);
	for (auto & c : b) c = toupper(c);
	return  Trim(a) == Trim(b);
}

const string CommandParser::Trim(const string &s) {
	auto wsfront = find_if_not(s.begin(), s.end(), [](int c) {return isspace(c);});
	auto wsback = find_if_not(s.rbegin(), s.rend(), [](int c) {return isspace(c);}).base();
	return (wsback <= wsfront ? std::string() : std::string(wsfront, wsback));
}

Utils::Utils() {
}


Utils::~Utils() {
}

const GAME_DIRECTION Utils::DirectionInverse(const GAME_DIRECTION direction) {
	if (direction == GAME_DIRECTION::NORTH) {
		return GAME_DIRECTION::SOUTH;
	} else if (direction == GAME_DIRECTION::SOUTH) {
		return GAME_DIRECTION::NORTH;
	} else if (direction == GAME_DIRECTION::EAST) {
		return GAME_DIRECTION::WEST;
	} else if (direction == GAME_DIRECTION::WEST) {
		return GAME_DIRECTION::EAST;
	}

	return GAME_DIRECTION::NONE;
}

const GAME_DIRECTION Utils::GetDirection(const string name_direction, bool inverse){
	GAME_DIRECTION direction = GAME_DIRECTION::NONE;
	if (CommandParser::IsEquals(name_direction, GAME_DIRECTION_NORTH)) {
		direction = GAME_DIRECTION::NORTH;
	} else if (CommandParser::IsEquals(name_direction, GAME_DIRECTION_EAST)) {
		direction = GAME_DIRECTION::EAST;
	} else if (CommandParser::IsEquals(name_direction, GAME_DIRECTION_WEST)) {
		direction = GAME_DIRECTION::WEST;
	} else if (CommandParser::IsEquals(name_direction, GAME_DIRECTION_SOUTH)) {
		direction = GAME_DIRECTION::SOUTH;
	}

	if (inverse)
		direction = Utils::DirectionInverse(direction);

	return direction;
}


const string Utils::GetDirectionName(const GAME_DIRECTION direction, bool inverse) {
	string direction_name = "";
	GAME_DIRECTION direction_result = direction;
	
	if (inverse)
		direction_result = DirectionInverse(direction_result);

	if (direction_result == GAME_DIRECTION::NORTH) {
		direction_name = GAME_DIRECTION_NORTH;
	} else if (direction_result == GAME_DIRECTION::EAST) {
		direction_name = GAME_DIRECTION_EAST;
	} else if (direction_result == GAME_DIRECTION::WEST) {
		direction_name = GAME_DIRECTION_WEST;
	} else if (direction_result == GAME_DIRECTION::SOUTH) {
		direction_name = GAME_DIRECTION_SOUTH;
	}
		
	return direction_name;
}


