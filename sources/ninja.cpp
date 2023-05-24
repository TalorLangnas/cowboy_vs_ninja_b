# include "Ninja.hpp"

// Constructors:
Ninja::Ninja()
{

};
Ninja::Ninja(double x, double y): Character(x, y)
{

};
Ninja::Ninja(Point point): Character(point)
{

};
Ninja::Ninja(string name, Point point): Character(name, point)
{

};
// Copy:
Ninja::Ninja(const Ninja& other)
{
    Ninja ninja = other;
    speed = other.speed;
    this->getLocation() = ninja.getLocation();
    this->getName() = ninja.getName();
    this->get_health_point() = ninja.get_health_point();
};


//Class Methods:
void Ninja::move(Character *character)
{
    set_location(Point::moveTowards(this->getLocation(), character->getLocation(), speed));
};
void Ninja::slash(Character *character)
{
    if(character == NULL)
    {
        throw std::runtime_error("Null pointer");
    }
    if(this == character)
    {
        throw std::runtime_error("Cowboy can't attack himself");
    }
    if(character->isAlive() == false)
    {
        throw std::runtime_error("Enemy is alredy dead");
    }
    if(isAlive() == false)
    {
        throw std::runtime_error("ninja is alredy dead");
    }
    
    double dist = this->getLocation().distance(character->getLocation());
    if (dist > 1)
    {
        return;
    }
    character->hit(40);    
};
int& Ninja::get_speed()
{
    return speed;
};

string Ninja::to_string()
{
    string str = (*this).Character::to_string() + "speed: " + std::to_string(speed);
    return str;
}

void Ninja::attack(Character* other)
{   
    if(this->distance(other) < 1)
    {
        this->slash(other);
        return;
    }
    this->move(other);
};

bool Ninja::is_cowboy()
{
    return false;
};

// Operators:
