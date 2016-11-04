// Zork.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <string>
#include <iostream>
#include "globals.h"


using namespace std;

int main()
{
	string arguments = "";
	char key = 0;
	while (1) {
		key = _getch();
		if (key == KEYBOARD_KEY_ESCAPE)
			break;
		arguments += key;
	}
	


	return 0;
}

