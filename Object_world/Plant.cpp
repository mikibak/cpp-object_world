#include <iostream>
#include "Plant.h"

Point Plant::action() {
	if (age > maturity_age && age < old_age) {
		Point childs_position(position.find_empty_point_nearby(world));
		if (!(childs_position.x == position.x && childs_position.y == position.y)) {
			create_any_offspring(world, position.find_empty_point_nearby(world),this->get_name());
		}
	}
	return position;
}

std::string Plant::collision(std::shared_ptr<Organism> guest) {
	guest->set_position(this->position);
	std::string position_string = "x=" + std::to_string(position.x) + ",y= " + std::to_string(position.y);
	std::string name = get_name();
	std::string guests_name = guest->get_name();
	if (this->get_power() <= guest->get_power()) {
		world->remove_organism(shared_from_this());
		return name + " got eaten by a " + guests_name + " on " + position_string + "; ";
	}
	else {
		world->remove_organism(shared_from_this());
		world->remove_organism(guest);
		return guests_name + " ate a poisonous " + name + " and died on " + position_string +  "; ";
	}
}

void Plant::draw() {
	std::cout << "plant cannot be drawn";
}