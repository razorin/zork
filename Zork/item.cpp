#include "stdafx.h"
#include "item.h"
#include <iostream>

using namespace std;

Item::Item(){
}

Item::Item(const string name, const string description) : Entity(name, description) {

}


Item::~Item() {
}

void Item::Update() {
	//cout << "Item updated!!!" << endl;
}
