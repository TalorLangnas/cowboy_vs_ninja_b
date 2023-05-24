#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <climits>
#include<string>
#include "Point.hpp"
using namespace std;
using namespace ariel;



class Character
{
    private:
    Point location;
    string name;
    // protected:
    int health_point;
    bool assigned;
    //int team_number;
    double distance_from_leader;
    
    

    public:

// Constructors:
    Character();
    Character(double, double);
    Character(Point);
    Character(string , Point);
    // copy constructor
    Character(const Character&)= default;
    
    // move constructor
    Character(Character &&) noexcept = default;
   
    // Destructor:
    virtual ~Character() = default;

// Class Methods:
    
    // getters:
    string& getName();
    Point getLocation();
    int& get_health_point();
    //int& get_team_number();

    bool isAlive();
    double distance(Character*);
    void hit(int);
    virtual void attack(Character*);
    virtual bool is_cowboy();
    bool& has_team();
    void set_location(Point);
    // double set_distance_from_leader(Point);
    // double get_distance_from_leader();
    void print();
    // Defind get_health_point() as refernce for the option to initialize this value from subclasses. 
    
    virtual string to_string();
// Operators:
    friend std::ostream& operator<< (std::ostream& output, Character& character)
    {
        output << character.Character::to_string();
        return output;
    };
    virtual bool operator==(const Character&) const;
    //bool operator==(const Character&);
    // copy assignment operator
    Character& operator=(const Character &);
    // move assignment operator
    Character& operator=(Character &&) noexcept = default;
};







#endif