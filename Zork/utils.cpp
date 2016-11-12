#include "stdafx.h"
#include "utils.h"


CommandParser::CommandParser() {
}


CommandParser::~CommandParser() {
}

const vector<string> * CommandParser::ParseCommand(const string command) {
	vector<string> *result = new vector<string>();
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
					result->push_back(multiple_words);
				result->push_back(word);
				multiple_words = "";
			}
			else if (CommandParser::IsIgnoredWord(word) == false) {
				if (is_last_element) {
					multiple_words += word;
					result->push_back(multiple_words);
				}
				else {
					multiple_words += word + " ";;
				}
			}
			else if (CommandParser::IsIgnoredWord(word) == true) {
				if (multiple_words != "") {
					result->push_back(multiple_words);
					multiple_words = "";
				}
			}

			word = "";
		}
	}

	return result;
}

const bool CommandParser::IsToken(const string word) {
	return (IsEquals(word, PLAYER_ACTION_GO) || IsEquals(word, PLAYER_ACTION_LOOK) || IsEquals(word, PLAYER_ACTION_TAKE) || IsEquals(word, PLAYER_ACTION_DROP));
}

const bool CommandParser::IsIgnoredWord(const string word) {
	return (IsEquals(word, IGNORE_WORD_INTO) ||  IsEquals(word, IGNORE_WORD_FROM) || IsEquals(word, IGNORE_WORD_A) || IsEquals(word, IGNORE_WORD_THE) || IsEquals(word, IGNORE_WORD_TO));
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

const GAME_DIRECTIONS Utils::DirectionInverse(const GAME_DIRECTIONS direction) {
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

