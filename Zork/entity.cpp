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
	contains.clear();
}

void Entity::Update() {
	for each (auto element in contains) {
		element->Update();
	}
}

void Entity::Look() const {
	cout << "\t" << name << endl;
	cout << "__________________________" << endl;
	cout << description << endl;

	if(contains.size() > 0)
		cout << "Also there are: " << endl;

	for each (auto element in contains) {
		element->Look();
	}
	
}

void Entity::Show() const {
	cout << name << " \t\t\t " << description << endl;
}

Entity* Entity::Find(const string name) const {
	Entity* result = NULL;

	for each (auto element in contains) {
		if (CommandParser::IsEquals(element->name, name)) {
			result = element;
			break;
		}
	}

	return result;
}

Entity* Entity::Find(const ENTITY_TYPE type, const string name) const {
	Entity* result = NULL;

	for each (auto element in contains) {
		if (CommandParser::IsEquals(element->name, name) && element->type == type) {
			result = element;
			break;
		}
	}

	return result;
}

bool Entity::operator==(const Entity &other) const {
	return (this->name == other.name && this->description == other.description);
}

bool Entity::operator!=(const Entity &other) const {
	return !(*this == other);
}
