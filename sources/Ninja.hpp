#ifndef NINJA_HPP
#define NINJA_HPP
#include "Character.hpp"
#include <string>

using namespace std;

namespace ariel{
class Ninja : public Character
{
public:
    int speed;

public:
    // tidy:
    ~Ninja() override = default;
    Ninja(const Ninja &) = default;            // Copy constructor
    Ninja &operator=(const Ninja &) = default; // Copy assignment operator
    Ninja(Ninja &&) = default;                 // Move constructor
    Ninja &operator=(Ninja &&) = default;      // Move assignment operator

    // Constructor:
    Ninja(string name, Point location) : Character(std::move(name), location), speed(0){};

    // Methods:
    void move(Character *other);
    void attack(Character *other) override { slash(other); }
    void slash(Character *other);
    int getAgility() const { return speed; }
    string get_type() override { return "Ninja"; }
    string print() override;
};
};

#endif