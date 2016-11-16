#include "stdafx.h"
#include "item.h"
#include <iostream>

using namespace std;

Item::Item(){
}

Item::Item(const string name, const string description, ITEM_TYPE item_type, int attack, int price) : Entity(name, description) {
	type = ENTITY_TYPE::ITEM;
	this->item_type = item_type;
	this->attack = attack;
	this->price = price;
}


Item::~Item() {
}

void Item::Update() {
	//cout << "Item updated!!!" << endl;
}

void Item::Look() const {
	Entity::Look();
	if (contains.size() > 0)
		cout << "Also there are: " << endl;

	for each (auto element in contains) {
		element->Look();
	}
}
