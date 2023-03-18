#include <iostream>
#include "Sheep.h"

void Sheep::draw() {
	std::cout << '@';
}

Sheep::Sheep(World* world, Point position) :
	Animal::Animal(world, position, 4, 4, "sheep") {
}