#include <iostream>
#include "Sonchus.h"

void Sonchus::draw() {
	std::cout << '*';
}

Point Sonchus::action() {
	if (age > maturity_age && age < old_age) {
		for (int i = 0; i < 3; i++) {
			Point childs_position(position.find_empty_point_nearby(world));
			if (!(childs_position.x == position.x && childs_position.y == position.y)) {
				create_any_offspring(world, position.find_empty_point_nearby(world),this->name);
				//create_offspring(world, childs_position);
			}
		}
	}
	return position;
}


Sonchus::Sonchus(World* world, Point position) {
	this->power = 0;
	this->initiative = 0;
	this->world = world;
	this->position.x = position.x;
	this->position.y = position.y;
	this->name = "sonchus";
}