#include <iostream>
#include "Organism.h"
//#include "World.h"

Organism::Organism(World* world,Point position, int power, int initiative, std::string name) {
	this->power = power;
	this->initiative = initiative;
	this->world = world;
	this->position.x = position.x;
	this->position.y = position.y;
	this->name = name;
}
Organism::Organism() {
	power = 0;
	initiative = 0;
	world = nullptr;
}
Organism::~Organism() {

}
Point Organism::action() {
	return position;
}
std::string Organism::collision(std::shared_ptr<Organism> guest) {
	return "Organism collided";
}
void Organism::draw() {
	std::cout << "organism cannot be drawn";
}
std::shared_ptr<Organism> Organism::create_any_offspring(World* world, Point childs_position, std::string name) {
	return world->create_any_offspring(world, childs_position, name);
}
int Organism::get_initiative() {
	return initiative;
}
int Organism::get_power() {
	return power;
}
Point Organism::get_position() {
	return position;
}
std::string Organism::get_name() {
	return name;
}
void Organism::set_position(Point p) {
	//world->place_on_map(position, nullptr);
	//world->place_on_map(p, this);
	position.x = p.x;
	position.y = p.y;
}
void Organism::set_power(int p) {
	power = p;
}
void Organism::set_world(World* world) {
	this->world = world;
}
void Organism::add_age() {
	age++;
}
int Organism::get_age() {
	return age;
}