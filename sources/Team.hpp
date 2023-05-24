#ifndef Team_HPP
#define Team_HPP

#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "Point.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <set>
#include<vector>
#include<limits>

using namespace std;
using namespace ariel;

/*
Comments:
    create set that the order will be based on the Character location, 
    the center will be the leader and the next one will be the closest one to leader location
*/

class Team
{
    private:
    // Character *characters_team;
    Character *(*team); 
    int currentSize;
    Character *team_leader;
    //int serial_number; // range: [1,10], given for each Team memmber when signed to the Team.
    int total_members;
    //Point center; // check if i need to delete
    

    public:
// Constructors:
    
    Team(Character*);
    // copy:
    Team(const Team&) = default;
    // Destructor
    virtual ~Team() = default;
    // Move constructor (for tidy):
    Team(Team&&) noexcept = default;
    
        

// Team Methods:
    
    // getters:
    Character* get_team_leader();
    int get_size();
    // Character* get_closest_memmber();

    virtual void add(Character*); // recives pointer to Character and add it to the Team.
    virtual void attack(Team*); // attacks other Team, first attack the leader and the the closest 
                        // Team member until one of the Teams are died.
    int stillAlive(); // returns the number of alives Team members.
    virtual void print();
    //Point& get_center();
    // virtual void sort_team();
    //virtual Character* iterate_team(); 
    //void set_container(bool);
    // vector<Character*> cowboy_attack();
    // vector<Character*> ninja_attack();
    Character* find_enemy(Team*);
    // void set_leader(Character*);
    

// Operators:
    
    // Move assignment operator (for tidy):
    Team& operator=(Team&&)noexcept = default;

    // copy assignment operator
    Team &operator=(const Team &) noexcept = default;

    // inner class for iterator//

    // class iterator
    // {

    // };

   
};


#endif