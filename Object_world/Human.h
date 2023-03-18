#pragma once
#include "Animal.h"

class Human : public Animal
{
	using Animal::Animal; //constructors of parent
	int alzurs_shield_duration;
	void draw() override;
	Point action() override;
	std::string collision(std::shared_ptr<Organism> guest) override;
public:
	Human(World* world, Point position);
	~Human();
};

