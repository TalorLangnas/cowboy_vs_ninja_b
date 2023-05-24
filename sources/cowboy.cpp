#include "Cowboy.hpp"
using namespace std;

Cowboy::Cowboy()
{

};
Cowboy::Cowboy(double x, double y): Character(x, y), ammo(6)
{
    (*this).get_health_point() = 110;
    
};
Cowboy::Cowboy(Point point): Character(point), ammo(6)
{
    (*this).get_health_point() = 110;
};
Cowboy::Cowboy(string other, Point point): Character(other, point), ammo(6)
{
    (*this).get_health_point() = 110;
};
void Cowboy::shoot(Character* character)
{   
    if(character == NULL)
    {
        throw std::runtime_error("Null pointer");
    }
    if(this == character)
    {
        throw std::runtime_error("Cowboy can't attack himself");
    }
    // cout << "enter shoot cpp" << endl;
    // cout << "ammo at the beggining = "<< ammo << endl;
    // cout << " --------------------------- " << endl;
    // cout << "enter shoot" << endl;
    if((this->isAlive() == false)) //|| ammo <= 0)
    {
        throw std::runtime_error("cowboy is alredy dead, dead warior can't attack");
    }
    if(character->isAlive() == false)
    {   
        //cout << "if(character->isAlive() == false)" << endl;
        throw std::runtime_error("Enemy is alredy dead");
    }
    if(ammo <= 0)
    {
        //cout << "enter if(ammo <= 0)" << endl;
        reload();
        //cout << "ammo after reload() in shoot cpp = " << ammo << endl;
        return;
    }
    character->hit(10);
    ammo = ammo - 1;

    //cout << "exit shoot cpp " << endl;
};
bool Cowboy::hasboolets()
{
    if(ammo > 0)
    {
        return true;
    }
    else
        return false;    
};
void Cowboy::reload()
{   
    if(this->isAlive() == false)
    {
        throw std::runtime_error("Dead cowboy can't reload");
    }
    int missing_bolet = 6 - ammo;
    ammo = ammo + missing_bolet;
};
int Cowboy::get_ammo()
{
    return ammo;
};
string Cowboy::to_string()
{
    string str = (*this).Character::to_string() + "ammo: " + std::to_string(ammo);
    return str;
};

string Cowboy::print()
{
    return to_string();
};
void Cowboy::attack(Character *other)
{   
    cout << "enter Cowboy::attack" << endl;
    if(ammo > 0)
    {
        cout << " enter if ammo > 0" << endl;
        this->shoot(other);
        cout << "exit if ammo > 0 " << endl;
        return;
    }
    this->reload();
};

bool Cowboy::is_cowboy()
{
    return true;
};
