#ifndef NINJA_HPP
#define NINJA_HPP
#include "Character.hpp"
using namespace std;

class Ninja: public Character
{
    private:
    int speed;

    public:

// Constructors:
    Ninja();
    Ninja(double, double);
    Ninja(Point);
    Ninja(string, Point);
    // Copy:
    Ninja(const Ninja&);
    ~Ninja() override = default;
    // move constructor
    Ninja(Ninja &&) noexcept = default;
    Ninja& operator=(Ninja &&) noexcept = default;

// Class Methods:    
    void slash(Character*);
    virtual void move(Character*);
    virtual int& get_speed();
    string to_string() override;
    void attack(Character* other) override;
    bool is_cowboy() override;

// Operators:
    Ninja& operator=(Ninja);

    friend std::ostream& operator<< (std::ostream& output, Ninja& ninja)
    {
        output << ninja.Ninja::to_string();
        return output;
    };
};

#endif