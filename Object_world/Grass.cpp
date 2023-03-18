#include <iostream>
#include "Grass.h"

void Grass::draw() {
	std::cout << ',';
}


Grass::Grass(World* world, Point position) {
	this->power = 0;
	this->initiative = 0;
	this->world = world;
	this->position.x = position.x;
	this->position.y = position.y;
	this->name = "grass";
}