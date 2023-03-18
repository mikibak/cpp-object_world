#include <iostream>
#include "Wolf.h"

void Wolf::draw() {
	std::cout << 'w';
}

Wolf::Wolf(World* world, Point position) :
	Animal::Animal(world, position, 9, 5, "wolf") {
}