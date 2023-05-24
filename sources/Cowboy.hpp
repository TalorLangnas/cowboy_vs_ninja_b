#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "Character.hpp"
using namespace std;


class Cowboy: public Character
{   
    private:
    
    int ammo;

    public:

// Constructors:
    Cowboy();
    Cowboy(double, double);
    Cowboy(Point);
    Cowboy(string, Point);

// Class Methods:    
    void shoot(Character*);
    bool hasboolets();
    void reload();
    int get_ammo();
    string to_string() override;
    void attack(Character* character) override;
    bool is_cowboy() override;
    string print();
    

// Operators:
    friend std::ostream& operator<< (std::ostream& output, Cowboy& cowboy)
    {
        output << cowboy.Cowboy::to_string();
        return output;
    };

};


#endif