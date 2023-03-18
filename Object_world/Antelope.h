#pragma once
#include"Animal.h"

class Antelope : public Animal
{
	void draw() override;
	Point action() override;
	std::string collision(std::shared_ptr<Organism> guest) override;

public:
	Antelope(World* world, Point position);
};