#pragma once
#include"Animal.h"

class Fox : public Animal
{
	void draw() override;
	Point action() override;
public:
	Fox(World* world, Point position);
};
