#include <iostream>
#include "Turtle.h"

void Turtle::draw() {
	std::cout << 'G';
}

Point Turtle::action() {
	if (rand() % 4 == 0) {
		return position.find_random_point_nearby(world);
	}
	else {
		return position;
	}
}

std::string Turtle::collision(std::shared_ptr<Organism> guest) {
	if (guest->get_power() < 5) {
		return name + " deflected a " + guest->get_name() + " on x=" + std::to_string(position.x) + ", y=" + std::to_string(position.y) + ";";
	}
	else return Animal::collision(guest);
}


Turtle::Turtle(World* world, Point position) :
	Animal::Animal(world, position, 2, 1, "turtle") {
}
