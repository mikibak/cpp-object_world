#include <iostream>
#include "Guarana.h"

void Guarana::draw() {
	std::cout << '"';
}

Guarana::Guarana(World* world, Point position) {
	this->power = 0;
	this->initiative = 0;
	this->world = world;
	this->position.x = position.x;
	this->position.y = position.y;
	this->name = "guarana";
	this->strength_added = 3;
}

std::string Guarana::collision(std::shared_ptr<Organism> guest) {
	guest->set_position(this->position);
	std::string strength = std::to_string(this->strength_added);
	guest->set_power(guest->get_power() + strength_added);
	std::string temp_name = name;
	world->remove_organism(shared_from_this());
	return guest->get_name() + " ate a " + temp_name + " and gained " + strength + " additional strength on x = " + std::to_string(guest->get_position().x) + ", y = " + std::to_string(guest->get_position().y) + "; ";
}