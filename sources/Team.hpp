#ifndef Team_HPP
#define Team_HPP

#include <string>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "Point.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <limits>
#include <stdexcept>


using namespace std;

namespace ariel{
class Team
{
public:
    Character *(*team);
    Character *leader;
    int capacity = 10;
    int size;

    // for tidy:

    Team(const Team &) = default;            // Copy constructor
    Team &operator=(const Team &) = default; // Copy assignment operator
    Team(Team &&) = default;                 // Move constructor
    Team &operator=(Team &&) = default;      // Move assignment operator
    
    // Constructor
    Team(Character *leader);
    virtual ~Team();

    // Class methods:
    Character *get_leader() const { return leader; }
    void organize_team();
    void print();
    int stillAlive();
    virtual Character *find_enemy(Team *other);
    virtual void add(Character *member);
    virtual void attack(Team *other);    
    
};
}
#endif