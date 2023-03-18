#include <iostream>
#include <conio.h>
#include "Human.h"
#define KEY_ARROW 224
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define a_KEY 97
#define s_KEY 115
#define l_KEY 108

Human::Human(World* world, Point position) :
    Animal::Animal(world, position, 5, 4, "human") {
    alzurs_shield_duration = 0;
}

void Human::draw() {
	std::cout << 'h';
}

Point Human::action() {
    world->draw_world();
    if (alzurs_shield_duration>0) {
        alzurs_shield_duration--;
    }
    unsigned char key = _getch();
    Point p;
    p.x = position.x;
    p.y = position.y;
    if (key == KEY_ARROW)
    {
        key = _getch();
        switch (key)
        {
        case KEY_UP:
            p.y -= 1;
            if (world->is_in_bounds(p)) {
                return p;
            }
            else {
                p.y += 1;
                return p;
            }
            break;
        case KEY_DOWN:
            p.y += 1;
            if (world->is_in_bounds(p)) {
                return p;
            }
            else {
                p.y -= 1;
                return p;
            }
            break;
        case KEY_LEFT:
            p.x -= 1;
            if (world->is_in_bounds(p)) {
                return p;
            }
            else {
                p.x += 1;
                return p;
            }
            break;
        case KEY_RIGHT:
            p.x += 1;
            if (world->is_in_bounds(p)) {
                return p;
            }
            else {
                p.x -= 1;
                return p;
            }
            break;
        default:
            return p;
            break;
        }
    }
    else {
        switch (key) {
        case a_KEY:
            alzurs_shield_duration = 5;
            break;
        case s_KEY:
            world->save_game();
            break;
        case l_KEY:
            world->load_save();
            break;
        }
    }
    return p;
}

std::string Human::collision(std::shared_ptr<Organism> guest) {
    //deflects an attack of any animal if Alzur's shield abillity is active
    if (alzurs_shield_duration > 0) {
        return name + " deflected a " + guest->get_name() + " using Alzur's shield on x=" + std::to_string(position.x) + ", y=" + std::to_string(position.y) + ";";
    }
    else {
        return Animal::collision(guest);
    }
}

Human::~Human() {
    world->draw_world();
    std::cout << "GAME OVER";
}