#include <iostream>
#include "Animal.h"

Point Animal::action() {
	return position.find_random_point_nearby(world);
}
Animal::Animal(World* world, Point position, int power, int initiative, std::string name)
	: Organism::Organism(world, position, power, initiative, name) {}

std::string Animal::collision(std::shared_ptr<Organism> guest) {
	if (guest->get_name() == this->get_name()) {
		if (guest->get_age() > maturity_age && age > maturity_age && guest->get_age() < old_age && age < old_age) {
			//breeding occurs only when both parents are of correct age
			return breeding(guest);
		}
	}
	else {
		//stronger one eats the weaker one
		if (guest->get_power() >= this->get_power()) {
			//guest eats the host
			guest->set_position(this->position);
			world->remove_organism(shared_from_this());
			return name + " got eaten by a hungry " + guest->get_name() + " on x=" + std::to_string(position.x) + ", y=" + std::to_string(position.y) + "; ";
		}
		else {
			//host eats the guest
			world->remove_organism(guest);
			return guest->get_name() + " walked into a " + name + " and got eaten on x = " + std::to_string(position.x) + ", y = " + std::to_string(position.y) + "; ";
		}
	}
	return "";
}

std::string Animal::breeding(std::shared_ptr<Organism> guest) {
	Point childs_position = position.find_empty_point_nearby(world);
	if (childs_position.x == guest->get_position().x && childs_position.y == guest->get_position().y || childs_position.x == position.x && childs_position.y == position.y) {
		//there was no space, the child dies
		//return "A newborn " + name + " died;";
		return "";//avoiding too much text messages
	}
	create_any_offspring(world, childs_position, guest->get_name());
	return "A new " + name + " was born on x = " + std::to_string(position.x) + ", y = " + std::to_string(position.y) + "; ";
}

void Animal::draw() {
	std::cout << "animal cannot be drawn";
}
