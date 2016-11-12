#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <list>
#include "globals.h"

using namespace std;


class Entity
{
public:
	Entity();
	Entity(const string name, const string description);
	virtual ~Entity();
	virtual void Update();
	virtual void Look() const;
	virtual void Show() const;
	virtual Entity * Find(const string name) const;
	virtual Entity* Find(const ENTITY_TYPE type, const string name) const;

	virtual bool operator==(const Entity &other) const;
	virtual bool operator!=(const Entity &other) const;

	string name;
	string description;
	list<Entity*> contains;
	ENTITY_TYPE type;

};

#endif // !ENTITY_H
