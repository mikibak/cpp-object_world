#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>
#include <memory>


class Point;
class Organism;
typedef std::map<std::string, std::shared_ptr<Organism> (*)()> map_type;

class World {
	std::vector<std::shared_ptr<Organism>> organism_array;
	int map_size_x;
	int map_size_y;
	std::string logs;
	int turn;
	void play_turn();
	void operate_on_file(std::ifstream& file);
public:
	map_type map_of_types;
	World(int map_size_x,int map_size_y);
	//game
	void simulate();
	void save_game();
	void load_save();
	void draw_world();
	//map
	int get_map_size_x();
	int get_map_size_y();
	bool is_in_bounds(Point point);
	bool is_empty(Point point);
	//operations on vector
	std::shared_ptr<Organism> get_one_organism(int index);
	std::vector<std::shared_ptr<Organism>> get_all_organisms();
	void add_organism(std::shared_ptr<Organism> organism);
	void add_multiple(int number_of_each_species);
	void remove_organism(std::shared_ptr<Organism> organism);
	int get_number_of_organisms();
	//void add_to_types_map();

	std::shared_ptr<Organism> create_any_offspring(World* world, Point childs_position, std::string name);
};