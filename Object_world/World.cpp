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


template<typename T> 
std::shared_ptr<Organism> createInstance() { 
	World* world = nullptr;
	Point p;
	return std::make_shared<T>(world, p);
}

World::World(int map_size_x, int map_size_y) {
	this->map_size_x = map_size_x;
	this->map_size_y = map_size_y;
	logs = "";
	turn = 0;
	Point middle_of_map(map_size_x / 2, map_size_y / 2);
	std::shared_ptr<Human> main_character = std::make_shared<Human>(this, middle_of_map);
	this->add_organism(main_character);
	srand((unsigned int)time(0));

	map_of_types["antelope"] = &createInstance<Antelope>;
	map_of_types["fox"] = &createInstance<Fox>;
	map_of_types["grass"] = &createInstance<Grass>;
	map_of_types["guarana"] = &createInstance<Guarana>;
	map_of_types["heracleum"] = &createInstance<Heracleum>;
	map_of_types["human"] = &createInstance<Human>;
	map_of_types["sheep"] = &createInstance<Sheep>;
	map_of_types["sonchus"] = &createInstance<Sonchus>;
	map_of_types["turtle"] = &createInstance<Turtle>;
	map_of_types["wolf"] = &createInstance<Wolf>;
	map_of_types["wolfberry"] = &createInstance<Wolfberry>;
}

void World::simulate() {
	while (true) {
		play_turn();
		//draw_world();
	}
}

void World::save_game() {
	std::ofstream file;
	file.open("save.txt");
	file << organism_array.size() << "\n";
	file << map_size_x << "\n";
	file << map_size_y << "\n";
	file << turn << "\n";
	for (std::shared_ptr<Organism> o : organism_array) {
		file << o->get_position().x << "\n";
		file << o->get_position().y << "\n";
		file << o->get_name() << "\n";
		file << o->get_power() << "\n";
		file << o->get_age() << "\n";
	}
	file.close();
}

void World::load_save() {
	std::ifstream file("save.txt");
	if (file.is_open())
	{
		operate_on_file(file);
		file.close();
	}
	else std::cout << "Unable to open file";
}

void World::operate_on_file(std::ifstream& file) {
	std::string line;
	organism_array.clear();

	getline(file, line);
	int n_of_organisms = stoi(line);

	getline(file, line);
	map_size_x = stoi(line);

	getline(file, line);
	map_size_y = stoi(line);

	getline(file, line);
	turn = stoi(line);

	for (int i = 0; i < n_of_organisms; i++) {
		Point p;
		getline(file, line);
		p.x = stoi(line);

		getline(file, line);
		p.y = stoi(line);

		getline(file, line);
		auto organism = map_of_types[line]();
	
		getline(file, line);
		organism->set_power(stoi(line));

		getline(file, line);
		for (int i = 0; i < stoi(line); i++) {
			organism->add_age();
		}
		organism->set_position(p);
		organism->set_world(this);
		add_organism(organism);
	}
}

int World::get_map_size_x() {
	return map_size_x;
}

int World::get_map_size_y() {
	return map_size_y;
}

bool World::is_in_bounds(Point point) {
	if (point.x >= 0 && point.y >= 0 && point.x < map_size_x-1 && point.y < map_size_y-1) {
		return true;
	}
	else {
		return false;
	}
}

bool World::is_empty(Point point) {
	bool occupied = false;
	for (std::shared_ptr<Organism> o : organism_array) {
		if (o->get_position().x == point.x && o->get_position().y == point.y) {
			occupied = true;
		}
	}
	if (occupied == false) {
		//iterated through all organisms, this position is empty
		return true;
	}
	else {
		return false;
	}
}

void World::play_turn() {
	int i = 0;
	while(i < organism_array.size()) {
		std::shared_ptr<Organism> current = organism_array[i];
		current->add_age();
		Point new_position = current->action();
		bool collided = false;
		for (std::shared_ptr<Organism> host : organism_array) {
			//check whether a collision occured
			if (host->get_position().x == new_position.x && host->get_position().y == new_position.y && host != current) {
				logs = logs + host->collision(current);
				collided = true;
				break;
			}
		}
		if (collided == false) {
			current->set_position(new_position);
		}
		i++;
	}
	turn++;
}

void World::draw_world() {
	std::system("cls");
	std::cout << "Autor: Mikolaj Bak 188968;  Tura " << turn << "    Poruszanie sie - strzalki;  Tarcza Alzura - a;  Zapis - s;  Wczytanie - l;" << std::endl;
	std::cout << "Legenda:  h - czlowiek;  w - wilk;  @ - owca;  , - trawka;  f - lis;  : - wilcze jagody;  & - barszcz sosnowskiego;  ; - guarana;  Y - antylopa;  G - zolw;  * - mlecz;" << std::endl;
	std::cout << "  ";
	for (int i = 0; i < map_size_x;i++) {
		std::cout << i/10 % 10;
	}
	std::cout << std::endl << "  ";
	for (int i = 0; i < map_size_x; i++) {
		std::cout << i % 10;
	}
	std::cout << std::endl;
	for (int i = 0; i < map_size_y; i++) {
		std::cout << i / 10 % 10 << i % 10;
		for (int j = 0; j < map_size_x; j++) {
			bool occupied = false;
			for (std::shared_ptr<Organism> o : organism_array) {
				if (o->get_position().x == j && o->get_position().y == i) {
					o->draw();
					occupied = true;
				}
			}
			if (occupied == false) {
				if (i == map_size_y - 1 || j == map_size_x - 1) {
					std::cout << 'x';
				}
				else {
					std::cout << ' ';
				}
			}
		}
		std::cout << std::endl;
	}
	std::cout << logs << std::endl;
	logs = "";
}

void World::add_organism(std::shared_ptr<Organism> organism) {
	int iterator = 0;
	bool added = false;
	for (std::shared_ptr<Organism> o : organism_array) {
		if (organism->get_initiative() > o->get_initiative()) {
			organism_array.insert(organism_array.begin() + iterator, organism);
			added = true;
			break;
		}
		iterator++;
	}
	if (added == false) {
		organism_array.push_back(organism);
	}
}

void World::add_multiple(int number_of_each_species) {
	for (int i = 0; i < number_of_each_species;i++) {
		for (auto const& x : map_of_types) {
			if (x.first != "human") {
				//there can only be one human
				create_any_offspring(this, Point().find_random_empty_point(this), x.first);
			}
		}
		
		/*add_organism(new Sheep(this, Point().find_random_empty_point(this)));
		add_organism(new Grass(this, Point().find_random_empty_point(this)));
		add_organism(new Fox(this, Point().find_random_empty_point(this)));
		add_organism(new Turtle(this, Point().find_random_empty_point(this)));
		add_organism(new Antelope(this, Point().find_random_empty_point(this)));
		add_organism(new Guarana(this, Point().find_random_empty_point(this)));
		add_organism(new Wolfberry(this, Point().find_random_empty_point(this)));
		add_organism(new Heracleum(this, Point().find_random_empty_point(this)));
		add_organism(new Sonchus(this, Point().find_random_empty_point(this)));*/
	}
}

void World::remove_organism(std::shared_ptr<Organism> organism) {
	int iterator = 0;
	for (std::shared_ptr<Organism> o : organism_array) {
		if (o == organism) {
			organism_array.erase(organism_array.begin() + iterator);
			break;
		}
		iterator++;
	}
}

int World::get_number_of_organisms() {
	return organism_array.size();
}

std::shared_ptr<Organism> World::get_one_organism(int index) {
	return organism_array[index];
}

std::vector<std::shared_ptr<Organism>> World::get_all_organisms() {
	return organism_array;
}

std::shared_ptr<Organism> World::create_any_offspring(World* world, Point childs_position, std::string name) {
	auto organism = map_of_types[name]();
	organism->set_position(childs_position);
	organism->set_world(this);
	add_organism(organism);
	return organism;
}
