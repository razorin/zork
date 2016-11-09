#include "stdafx.h"
#include "item.h"
#include <iostream>

using namespace std;

Item::Item(){
}

Item::Item(const string name, const string description) : Entity(name, description) {
	type = ENTITY_TYPE::ITEM;
}


Item::~Item() {
}

void Item::Update() {
	//cout << "Item updated!!!" << endl;
}
