#pragma once
#include "Organism.h"

class Animal : public Organism {
public:
	const int old_age = 150;
	Animal(World* world, Point position, int power, int initiative, std::string name);
	Point action();
	std::string collision(std::shared_ptr<Organism> guest) override;
	std::string breeding(std::shared_ptr<Organism> guest);
	virtual void draw() = 0;
};