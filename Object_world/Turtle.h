#pragma once
#include"Animal.h"

class Turtle : public Animal
{
	const int maturity_age = 15;
	const int old_age = 150;

	void draw() override;
	Point action() override;
	std::string collision(std::shared_ptr<Organism> guest) override;

public:
	Turtle(World* world, Point position);
};