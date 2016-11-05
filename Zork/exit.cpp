#include "stdafx.h"
#include "exit.h"
#include <iostream>

using namespace std;

Exit::Exit() {

}


Exit::~Exit() {
	delete source;
	source = NULL;
	delete destination;
	destination = NULL;
}

void Exit::Update() {
	cout << "Exit!! " << endl;
}
