#include "OldNinja.hpp"

namespace ariel{
OldNinja::OldNinja(string name, Point point): Ninja(name, point)
{
    this->speed = 8;
    this->health_point = 150;
};
};