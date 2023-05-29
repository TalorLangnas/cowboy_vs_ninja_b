#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>
#include <stdbool.h>
#include <stdexcept>

using namespace std;



namespace ariel{
class Character
{
    public:
    Point location;
    string name;
    int health_point;
            
    

    public:
    bool has_team = false;
    virtual ~Character() = default;
// Constructors:
    Character(string name, Point location) : name(std::move(name)), location(location), health_point(0){};
    
// for tidy:
Character& operator=(const Character&) = default;  // Copy assignment operator
Character(const Character&) = default;  // Copy constructor
Character& operator=(Character&&) = default;  // Move assignment operator        
Character(Character&&) = default;  // Move constructor
            

// methods:
    int compare_to(Character *other);
    virtual string print() = 0;
    virtual void attack(Character *other) = 0;
    void hit(int num);
    bool isAlive();
    double distance(Character* other);
    string get_name() const {return name;}
    Point getLocation() const {return location;}
    void set_location(Point location) {this->location = location;}
    int get_health_point() const {return health_point;}
    virtual string get_type() = 0;
    string getName() { return name; }
    
};
}   
#endif