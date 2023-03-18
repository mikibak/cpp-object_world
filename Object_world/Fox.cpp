#include <iostream>
#include "Fox.h"

void Fox::draw() {
	std::cout << 'f';
}

Point Fox::action() {
	int n_of_organisms = world->get_number_of_organisms();
	for (int j = 0; j < 15; j++) {
		//try 15 times, if it fails there is probably nowhere to go, so the fox
		//has to attack a random stronger creature
		Point new_position = position.find_random_point_nearby(world);
		bool occupied = false;
		for (int i = 0; i < n_of_organisms;i++) {
			std::shared_ptr<Organism> other = world->get_one_organism(i);
			if (other->get_position().x == new_position.x && other->get_position().y == new_position.y) {
				if (other->get_power() <= this->power) {
					//the other organism is not stronger, attack him
					return other->get_position();
				}
				else {
					//the other organism is stronger, try again
					occupied = true;
					break;
				}
			}
		}
		if (occupied == false) {
			//iterated through all organisms, none occupies the spot so the fox moves there
			return new_position;
		}
	}
	return position.find_random_point_nearby(world);
}

Fox::Fox(World* world, Point position) :
	Animal::Animal(world, position, 3, 7, "fox") {
}