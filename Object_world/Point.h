#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class World;

class Point {
public:
	int x;
	int y;
	Point();
	Point(int x, int y);
	Point(const Point& other);
	Point find_random_point_nearby(World* world);
	Point find_empty_point_nearby(World* world);
	Point find_random_empty_point(World* world);
	~Point();
};