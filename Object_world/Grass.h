#pragma once
#include "Plant.h"

class Grass : public Plant
{
	void draw() override;
public:
	Grass(World* world, Point position);
};