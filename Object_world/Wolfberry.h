#pragma once
#include "Plant.h"

class Wolfberry : public Plant
{
	const int maturity_age = 10;
	const int old_age = 12;

	void draw() override;
public:
	Wolfberry(World* world, Point position);
};