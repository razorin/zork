#include "stdafx.h"
#include "utils.h"


Utils::Utils()
{
}


Utils::~Utils()
{
}

const vector<string> * Utils::ParseCommand(const string command) {
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
			if (Utils::IsToken(word)) {
				if (multiple_words != "")
					result->push_back(multiple_words);
				result->push_back(word);
				multiple_words = "";
			}
			else if (Utils::IsIgnoredWord(word) == false) {
				if (is_last_element) {
					multiple_words += word;
					result->push_back(multiple_words);
				}
				else {
					multiple_words += word + " ";;
				}
			}

			word = "";
		}
	}

	return result;
}

const bool Utils::IsToken(const string word) {
	return (word == PLAYER_ACTION_LOOK || word == PLAYER_ACTION_TAKE);
}

const bool Utils::IsIgnoredWord(const string word) {
	return (word == IGNORE_WORD_A || word == IGNORE_WORD_THE || word == IGNORE_WORD_TO);
}
