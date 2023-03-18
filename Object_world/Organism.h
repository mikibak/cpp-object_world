#pragma once
#include "World.h"
#include "Point.h"
#include <string>

class Organism : public std::enable_shared_from_this<Organism>{
protected:
	std::string name;
	int power;
	int initiative;
	int age = 0;
	Point position;
	World* world;
	const int maturity_age = 5;
	const int old_age = 15;
public:
	Organism();
	Organism(World* world, Point position, int power, int initiative, std::string name);
	virtual Point action();
	virtual std::string collision(std::shared_ptr<Organism> guest);
	virtual void draw();
	std::shared_ptr<Organism> create_any_offspring(World* world, Point childs_position, std::string name);

	int get_initiative();
	int get_power();
	Point get_position();
	std::string get_name();
	int get_age();

	void set_position(Point p);
	void set_world(World* world);
	void set_power(int p);
	void add_age();
	~Organism();
};