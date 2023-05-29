#include "Ninja.hpp"
#include "Point.hpp"
#include <string>
#include <cmath>

namespace ariel{
// Class Methods:
void Ninja::move(Character *other)
{
    if (!this->isAlive())
    {
        throw "Ninja is dead";
    }
    this->location = Point::moveTowards(this->location, other->location, this->speed);
};

void Ninja::slash(Character *character)
{
    if (character == nullptr)
    {
        throw std::runtime_error("Null pointer");
    }
    if (this == character)
    {
        throw std::runtime_error("Cowboy can't attack himself");
    }
    if (!(character->isAlive()))
    {
        throw std::runtime_error("Enemy is alredy dead");
    }
    if (!(isAlive()))
    {
        throw std::runtime_error("ninja is alredy dead");
    }

    double dist = this->location.distance(character->location);
    if (dist > 1)
    {
        return;
    }
    character->hit(40);
};

string Ninja::print()
{
    string printer = "";
    if (this->isAlive())
    {
        printer = "N - " + this->name + ", " + to_string(this->health_point) + " HP, at " + this->location.toString();
    }
    else
    {
        printer = "N - (" + this->name + "), DEAD";
    }
    return printer;
};
};
