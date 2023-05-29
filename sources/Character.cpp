#include "Character.hpp"
#include <cmath>

using namespace std;



namespace ariel{
void Character::hit(int num)
{
    if ((num != 10) && (num != 40))
    {
        throw invalid_argument("input most be positive");
    }

    this->health_point = this->health_point - num;
    // if health point is negative Character is dead
    if (this->health_point < 0)
    {
        this->health_point = 0;
    }
};

int Character::compare_to(Character *other)
    {
        if(this-> get_type() == "Cowboy" && other->get_type() == "Ninja")
        {
            return -1;
        }
        else if(this-> get_type() == "Ninja" && other->get_type() == "Cowboy")
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
bool Character::isAlive()
{
    if (health_point > 0)
    {
        return true;
    }
    else
        return false;
};

double Character::distance(Character *other)
{

    return this->location.distance(other->location);
};
}