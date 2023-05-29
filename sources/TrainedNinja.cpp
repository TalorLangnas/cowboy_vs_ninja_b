#include "TrainedNinja.hpp"

namespace ariel{
TrainedNinja::TrainedNinja(string name, Point point): Ninja(name, point)
{
    this->speed = 12;
    this->health_point = 120;
};
};
