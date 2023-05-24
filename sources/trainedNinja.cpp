#include "TrainedNinja.hpp"

TrainedNinja::TrainedNinja()
{
    this->getName() = "Trained Ninja";
    this->get_speed() = 12;
    this->get_health_point() = 120;
};
TrainedNinja::TrainedNinja(string name, Point point): Ninja(name, point)
{
    this->get_speed() = 12;
    this->get_health_point() = 120;
};