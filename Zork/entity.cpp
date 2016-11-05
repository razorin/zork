#include "stdafx.h"
#include "entity.h"
#include <iostream>

using namespace std;


Entity::Entity() {
}

Entity::Entity(const string name, const string description) {
	this->name = name;
	this->description = description;
}


Entity::~Entity() {

}

void Entity::Update() {

}

void Entity::Look() const {
	cout << "\t" << name << endl;
	cout << "_____________" << endl;
	cout << description << endl;
}
