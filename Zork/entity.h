#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <list>

using namespace std;


class Entity
{
public:
	Entity();
	Entity(const string name, const string description);
	virtual ~Entity();
	virtual void Update();
	virtual void Look() const;

	string name;
	string description;
	list<Entity*> contains;

};

#endif // !ENTITY_H
