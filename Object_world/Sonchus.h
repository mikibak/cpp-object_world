#pragma once
#include "Plant.h"

class Sonchus : public Plant
{
	const int maturity_age = 15;
	const int old_age = 17;
	Point action() override;
	void draw() override;
public:
	Sonchus(World* world, Point position);
};