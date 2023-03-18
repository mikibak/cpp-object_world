#include <iostream>
#include "Antelope.h"

void Antelope::draw() {
	std::cout << 'Y';
}

Point Antelope::action() {
	return position.find_random_point_nearby(world).find_random_point_nearby(world);;
}

std::string Antelope::collision(std::shared_ptr<Organism> guest) {
	if (rand() % 2 == 0 && guest->get_name() != this->get_name()) {
		Point temp = position.find_empty_point_nearby(world);
		if (temp.x != position.x && temp.y != position.y) {
			guest->set_position(this->position);
			position = temp;
			return name + " managed to escape from a " + guest->get_name() + " on x=" + std::to_string(position.x) + ", y=" + std::to_string(position.y) + "; ";
		}
		else {
			return Animal::collision(guest);
		}
	}
	else {
		return Animal::collision(guest);
	}
}

Antelope::Antelope(World* world, Point position) :
	Animal::Animal(world, position, 4, 4, "antelope") {
}
