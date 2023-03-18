#include "Point.h"
#include "World.h"
#include "Organism.h"

Point Point::find_random_point_nearby(World* world) {
	Point new_position;
	while (true) {
		//set x
		if (rand() % 3 == 0) {
			new_position.x = x - 1;
		}
		else if (rand() % 3 == 1) {
			new_position.x = x + 1;
		}
		else {
			new_position.x = x;
		}

		//set y
		if (rand() % 3 == 0) {
			new_position.y = y - 1;
		}
		else if (rand() % 3 == 1) {
			new_position.y = y + 1;
		}
		else {
			new_position.y = y;
		}

		if (world->is_in_bounds(new_position) && !(new_position.x==x && new_position.y==y)) {
			break;
		}
	}
	return new_position;
}

Point Point::find_empty_point_nearby(World* world) {
	int n_of_organisms = world->get_number_of_organisms();
	for (int j = 0; j < 100; j++) {
		//try 100 times, if it fails return itself
		Point new_position = find_random_point_nearby(world);
		if (world->is_empty(new_position)) {
			return new_position;
		}
	}
	return Point(x, y);
}

Point Point::find_random_empty_point(World* world) {
	Point new_position;
	while (true) {
		new_position.x = rand() % world->get_map_size_x();
		new_position.y = rand() % world->get_map_size_y();
		if (world->is_empty(new_position) && world->is_in_bounds(new_position)) {
			break;
		}
	}
	return new_position;
}


Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

Point::Point() {
	x = 1;
	y = 1;
}

Point::Point(const Point& other) {
	x = other.x;
	y = other.y;
}

Point::~Point() {
	this->x = 0;
	this->y = 0;
}