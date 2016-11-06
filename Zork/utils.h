#pragma once
#ifndef UTILS_H
#define UTILS_H

#include "globals.h"
#include <string>
#include <vector>

using namespace std;

class Utils
{
public:
	Utils();
	~Utils();

	static const vector<string> * ParseCommand(const string command);
	static const bool IsToken(const string word);
	static const bool IsIgnoredWord(const string word);
	static const bool IsEquals(string a, string b);
};

#endif // !UTILS_H

