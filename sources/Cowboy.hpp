#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "Character.hpp"
#include "Point.hpp"
#include <string>


using namespace std;


namespace ariel{
class Cowboy : public Character
{

private:
    int ammo;

public:
    // Constructors:
    Cowboy(string name, Point location);
    ~Cowboy() override = default;

    // for tidy:

    Cowboy(const Cowboy &) = default;            // Copy constructor
    Cowboy &operator=(const Cowboy &) = default; // Copy assignment operator
    Cowboy(Cowboy &&) = default;                 // Move constructor
    Cowboy &operator=(Cowboy &&) = default;      // Move assignment operator

    string get_type() override {return "Cowboy";}
    bool hasboolets();
    void reload();
    void attack(Character *other) override { shoot(other); }
    void shoot(Character *other);
   

    string print() override;
};


}
#endif