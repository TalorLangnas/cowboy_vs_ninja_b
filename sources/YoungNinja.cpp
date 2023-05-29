#include "YoungNinja.hpp"

namespace ariel{
YoungNinja::YoungNinja(string name, Point point): Ninja(name, point)
{
    this->speed = 14;
    this->health_point = 100;
};

}