#include "World.h"
#include "Point.h"
#include "Organism.h"
#include "Human.h"
#include "Sheep.h"
#include "Wolf.h"
#include "Grass.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Guarana.h"
#include "Wolfberry.h"
#include "Heracleum.h"
#include "Sonchus.h"

int main()
{
    World world(50,20);
    world.add_multiple(10);
	/*
	for (int i = 0; i < 10; i++) {
		//world.add_organism(std::make_shared<Sheep>(&world, Point().find_random_empty_point(&world)));
		//world.add_organism(std::make_shared<Grass>(&world, Point().find_random_empty_point(&world)));
		//world.add_organism(std::make_shared<Fox>(&world, Point().find_random_empty_point(&world)));
		//world.add_organism(std::make_shared<Turtle>(&world, Point().find_random_empty_point(&world)));
		//world.add_organism(std::make_shared<Antelope>(&world, Point().find_random_empty_point(&world)));
		//world.add_organism(std::make_shared<Guarana>(&world, Point().find_random_empty_point(&world)));
		//world.add_organism(std::make_shared<Wolfberry>(&world, Point().find_random_empty_point(&world)));
		//world.add_organism(std::make_shared<Heracleum>(&world, Point().find_random_empty_point(&world)));
		//world.add_organism(std::make_shared<Sonchus>(&world, Point().find_random_empty_point(&world)));
		world.add_organism(std::make_shared<Wolf>(&world, Point().find_random_empty_point(&world)));
	}
	//*/
    world.simulate();
}
