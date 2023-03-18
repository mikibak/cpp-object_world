#pragma once
#include "Plant.h"

class Guarana : public Plant
{
	int strength_added;
	void draw() override;
	std::string collision(std::shared_ptr<Organism> guest) override;
public:
	Guarana(World* world, Point position);
};

