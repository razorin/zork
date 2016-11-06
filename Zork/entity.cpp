#include "stdafx.h"
#include "entity.h"
#include <iostream>
#include "utils.h"

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
	for each (auto element in contains) {
		element->Update();
	}
}

void Entity::Look() const {
	cout << "\t" << name << endl;
	cout << "_____________" << endl;
	cout << description << endl;
}

void Entity::Show() const {
	cout << name << "\t" << description << endl;
}

Entity* Entity::Find(const string name) const{
	Entity* result = NULL;

	for each (auto element in contains) {
		if (Utils::IsEquals(element->name, name)) {
			result = element;
			break;
		}
	}

	return result;
}
