#include <iostream>
#include "Wolfberry.h"

void Wolfberry::draw() {
	std::cout << ':';
}

Wolfberry::Wolfberry(World* world, Point position) {
	this->power = 99;
	this->initiative = 0;
	this->world = world;
	this->position.x = position.x;
	this->position.y = position.y;
	this->name = "wolfberry";
}