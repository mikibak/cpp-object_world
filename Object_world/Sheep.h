#pragma once
#include "Animal.h"

class Sheep : public Animal
{
	void draw() override;
public:
	Sheep(World* world, Point position);
};

