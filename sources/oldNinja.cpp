#include "OldNinja.hpp"

OldNinja::OldNinja()
{
    this->getName() = "Old Ninja";
    this->get_speed() = 8;
    this->get_health_point() = 150;
};
OldNinja::OldNinja(string name, Point point): Ninja(name, point)
{
    this->get_speed() = 8;
    this->get_health_point() = 150;
};