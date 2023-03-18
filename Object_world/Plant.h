#pragma once
#include "Organism.h"

class Plant : public Organism {
	using Organism::Organism; //constructors of parent
protected:
	const int maturity_age = 5;
	const int old_age = 7;
public:
	Point action() override;
	std::string collision(std::shared_ptr<Organism> guest) override;
	virtual void draw() override;
};