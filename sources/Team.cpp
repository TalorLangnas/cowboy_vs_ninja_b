#include "Team.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <limits>

namespace ariel{
Team::Team(Character *leader)
{
    if (leader->has_team)
    {
        throw runtime_error("Character is already in a team");
    }
    leader->has_team = true;
    this->leader = leader;
    this->team = new Character *[10];
    this->capacity = 10;
    this->size = 1;
    this->team[0] = leader;
}

Team::~Team()
{
    for (int i = 0; i < this->size; i++)
    {

        delete this->team[i];
    }
    delete[] this->team;
}

// // Team Methods:
void Team::add(Character *character)
{
    if (character == nullptr)
    {
        throw std::runtime_error("Null pointer");
    }
    if (size == 10)
    {
        throw std::runtime_error("Team is full");
    }
    if (character->has_team)
    {
        throw std::runtime_error("Character alredy has team");
    }

    this->team[this->size] = character;
    character->has_team = true;
    size++;
};

void Team::print()
{
    string printer = "";
    if (this->size > 0)
    {
        for (int i = 0; i < this->size; i++)
        {
            printer += this->team[i]->print() + "\n";
        }
    }
    printf("%s\n", printer.c_str());
}

int Team::stillAlive()
{
    int counter = 0;
    for (int i = 0; i < this->size; i++)
    {
        if (this->team[i]->isAlive())
        {
            counter++;
        }
    }
    return counter;
};
/// @brief 
/// @param other 
/// @return 
Character *Team::find_enemy(Team *other)
{
    int min = std::numeric_limits<int>::max();
        Character *enemy;
        
        for(int i = 0; i < other->size; i++)
        {
            if(other->team[i]->isAlive())
            {
                if(other->team[i]->distance(this->leader) < min)
                {
                    min = other->team[i]->distance(this->leader);
                    enemy = other->team[i];
                }
            }
        }
        
        return enemy;
}

void Team::attack(Team *other)
{
    // check if there are alive members in the team
    if (this->stillAlive() == 0)
    {
        throw runtime_error("Team is dead");
    }
    // if leader is dead, find new leader by distance from the old leader
    if (!this->leader->isAlive())
    {
        int min = std::numeric_limits<int>::max();
        Character *new_leader;
        // find new leader
        for (int i = 0; i < this->size; i++)
        {
            if (this->team[i]->isAlive())
            {
                if (this->team[i]->distance(this->leader) < min)
                {
                    min = this->team[i]->distance(this->leader);
                    new_leader = this->team[i];
                }
            }
        }
        this->leader = new_leader;
    }

    if (other == nullptr)
    {
        throw invalid_argument("nullptr");
    }

    if (other->stillAlive() == 0)
    {
        throw runtime_error("all the team is dead");
    }
    Character *enemy = this->find_enemy(other);

    // attack

    for (int i = 0; i < this->size; i++)
    {
        if (this->team[i]->isAlive())
        {
            if (!enemy->isAlive())
            {
                if (other->stillAlive() == 0)
                {
                    return;
                }
                else
                {
                    enemy = this->find_enemy(other);
                }
            }
            if (this->team[i]->get_type() == "Ninja" && this->team[i]->distance(enemy) > 1)
            {
                ((Ninja *)this->team[i])->move(enemy);
            }
            else
            {
                this->team[i]->attack(enemy);
            }
        }
    }
}

void Team::organize_team()
{
    for (int i = 0; i < this->size; i++)
    {
        for (int j = i + 1; j < this->size; j++)
        {
            if (this->team[i]->compare_to(this->team[j]) == 1)
            {
                Character *temp = this->team[i];
                this->team[i] = this->team[j];
                this->team[j] = temp;
            }
        }
    }
}
}