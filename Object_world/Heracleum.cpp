#include <iostream>
#include "Heracleum.h"

void Heracleum::draw() {
	std::cout << '&';
}


Heracleum::Heracleum(World* world, Point position) {
	this->power = 10;
	this->initiative = 0;
	this->world = world;
	this->position.x = position.x;
	this->position.y = position.y;
	this->name = "heracleum";
}

Point Heracleum::action() {
	int n_of_organisms = world->get_number_of_organisms();
	std::vector<std::shared_ptr<Organism>> temp = world->get_all_organisms();
	for (int i = 0; i < n_of_organisms; i++) {
		std::shared_ptr<Organism> other = temp[i];
		if (abs(other->get_position().x - position.x) <= 1 && abs(other->get_position().y - position.y) <= 1 && other->get_name() != name) {
			if (true) {
				//there is an animal too close, it dies
				world->remove_organism(other);
			}
		}
	}
	return position;
}