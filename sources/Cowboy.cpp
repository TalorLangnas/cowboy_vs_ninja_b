#include "Cowboy.hpp"
#include <string>

using namespace std;

namespace ariel{

Cowboy::Cowboy(string name, Point location) : Character(name, location)
    {
        this -> health_point = 110;
        this -> ammo = 6;
    }

bool Cowboy::hasboolets()
{
    return this->ammo > 0;
};

void Cowboy::reload()
{
    if(!this->isAlive())
    {
        throw runtime_error("Cowboy is dead");
    }
    this->ammo = 6;
};
string Cowboy::print()
    {
        string printer = "";
        if (this->isAlive())
        {
            printer = "C - " + this->name + ", " + to_string(this->health_point) + " HP, at " + this->location.toString();
        }
        else
        {
            printer = "C - (" + this->name + "), DEAD";
        }
        return printer;
    }
void Cowboy::shoot(Character *character)
{
    if(character == nullptr)
    {
        throw std::runtime_error("Null pointer");
    }
    if(this == character)
    {
        throw std::runtime_error("Cowboy can't attack himself");
    }
    
    if(!(this->isAlive())) 
    {
        throw std::runtime_error("cowboy is alredy dead, dead warior can't attack");
    }
    if(!(character->isAlive()))
    {   
        throw std::runtime_error("Enemy is alredy dead");
    }
    if(ammo <= 0)
    {
        reload();
        return;
    }
    character->hit(10);
    ammo = ammo - 1;
};
};