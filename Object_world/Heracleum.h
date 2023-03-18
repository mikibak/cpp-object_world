#pragma once
#include "Plant.h"

class Heracleum : public Plant
{
	void draw() override;
	Point action() override;
public:
	Heracleum(World* world, Point position);
};