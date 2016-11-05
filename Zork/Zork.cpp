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
			auto arguments = Utils::ParseCommand(command);
			world->Update(arguments);
			for (auto it = arguments->begin(); it != arguments->end(); ++it) {
				cout << *it << endl;
			}

			command = "";
			continue;
		}

		command += key;
		cout << "Command: " << command << endl;
	}

	return 0;
}

