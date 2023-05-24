#include "YoungNinja.hpp"

YoungNinja::YoungNinja()
{
    this->getName() = "Young Ninja";
    this->get_speed() = 14;
    this->get_health_point() = 100;
};
YoungNinja::YoungNinja(string name, Point point): Ninja(name, point)
{
    this->get_speed() = 14;
    this->get_health_point() = 100;
};

