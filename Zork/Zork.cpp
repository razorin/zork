// Zork.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <string>
#include <iostream>
#include "globals.h"
#include "utils.h"
#include "world.h"


using namespace std;

int main() {
	string command = "";
	char key = 0;
	World *world = new World();

	while (key != KEYBOARD_KEY_ESCAPE) {
		key = _getch();

		if (key == KEYBOARD_KEY_ENTER) {
			auto arguments = CommandParser::ParseCommand(command);
			world->Update(arguments);

			command = "";
			continue;
		}

		command += key;
		cout << command << endl;
	}

	return 0;
}

