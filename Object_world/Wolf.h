#pragma once
#include"Animal.h"

class Wolf : public Animal
{
	void draw() override;
public:
	Wolf(World* world, Point position);
};

