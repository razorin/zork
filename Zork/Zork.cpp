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
	GAME_STATE game_state = GAME_STATE::CONTINUE;

	cout << "Welcome to Zorkian!!!" << endl;
	cout << "---------------------" << endl;
	cout << "You play as a rookie monster hunter who has received a petition to help the inhabitants of Zorkian with a monster that threatens the tranquility of the island" << endl << endl;

	World *world = new World();

	while (key != KEYBOARD_KEY_ESCAPE && game_state == GAME_STATE::CONTINUE) {
		vector<string> arguments;
		key = _getch();
			if (key == KEYBOARD_KEY_ESCAPE)
				game_state = GAME_STATE::QUIT;
			else if (key == KEYBOARD_KEY_ENTER) {
				CommandParser::ParseCommand(command, arguments);
				game_state =  world->Update(arguments);

				command = "";
				continue;
			} else if (key == KEYBOARD_KEY_BACKSPACE) {
				cout << "You can't erase anything!" << endl;
			} else if (key >= 32 && key <= 126) {
				command += key;
				cout << command << endl;
			} else {
			cout << "Input character not allowed!. Are you sure that you want to write that?" << endl;
		}

	}
	if (game_state != GAME_STATE::QUIT) {
		if (game_state == GAME_STATE::GAME_OVER)
			cout << "GAME OVER" << endl;
		else if (game_state == GAME_STATE::END)
			cout << "Congratulations!!! You have completed your quest!!" << endl;

		_getch();
	}
	delete world;
	world = NULL;

	return 0;
}

