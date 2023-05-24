#include "Team.hpp"

// Constructors:
Team::Team(Character *character) //: team_leader(*character)//, center(character->getLocation())
{
    this->team = new Character*[10];
    if (character->has_team() == true)
    {
        throw std::runtime_error("character assigned to other team already");
    }
    character->has_team() = true;
    team[0] = character;
    currentSize = 1;

    // serial_number = 0;
    // character->get_team_number() = serial_number;
    // serial_number++;
};
// Copy:
// Team::Team(const Team& other)//: team_leader(other.team_leader)//, center(team.center)
// {
//     Team other_team = other;
//     int other_size = other_team.get_size();
//     if(other_team.get_size() == 0)
//     {
//         return;
//     }
//     Character *tmp = new Character(*(other.team_leader));
//     for (Character *memmber: team)
//     {
//         if(memmber != other.team_leader)
//         {
//             Character *tmp = new Character(*memmber);
//             this->team.insert(tmp);
//         }
//     }

// };
// Team::~Team()
// {

// };
// Move constructor (for tidy):
// Team::Team(Team&& other)noexcept:team_leader(other.team_leader)//, center(other.center)
// {

// };
// Destructor:
// Team::~Team()
// {
//     for (Character* memmber: team)
//     {
//         delete memmber;
//     }
//     delete[] team;
// };

// Operators:
// Team &Team::operator=(const Team &other) noexcept
// {
//     *this = other;
//     return *this;
// };

// // Move assignment operator (for tidy):
// Team &Team::operator=(Team &&other) noexcept
// {

//     return *this;
// };

// Team Methods:
void Team::add(Character *character) // recives pointer to Character and add it to the Team.
{
    if (character == nullptr)
    {
        throw std::runtime_error("Null pointer");
    }
    if (currentSize == 10)
    {
        throw std::runtime_error("Team is full");
    }
    if (character->has_team() == true)
    {
        throw std::runtime_error("Character alredy has team");
    }
    character->has_team() = true;
    team[currentSize] = character;
    currentSize++;
    // character->get_team_number() = serial_number;
    // serial_number++;
};
// attack v1
// void Team::attack(Team *other)  // attacks other Team, first attack the leader and the the closest
//                     // Team member until one of the Teams are died.
// {
//     cout << " ------------- enter to Team attack ----------- " << endl;
//     // Find team leader:
//     if(other == NULL)
//     {
//         cout << "enter to if(other == NULL) " << endl;
//         throw std::invalid_argument("input pointer is NULL");
//     }
//     if(this->stillAlive() == 0)
//     {
//         cout << "if(this->stillAlive() == 0) " << endl;
//         return;
//     }
//     // if team leader is dead set new team leader
//     while(team_leader->isAlive() == false)
//     {   //other->get_team_leader().isAlive() == false
//         cout << "enter  while(team_leader->isAlive() == false)" << endl;
//         //*team_leader = get_team_leader();
//         cout << "exit  while(team_leader->isAlive() == false)" << endl;
//     }
//     int other_size = other->get_size();
//     cout << "other_team size = " << other_size << endl;
//     for(int i = 0; i < other_size; i++)
//     {
//         cout << " iter = " << i << endl;
//         Character *tmp = get_closest_memmber();
//         int iter = 0; // for debug
//         while (tmp->isAlive() == true)
//         {
//             cout << "enter while (tmp->isAlive() == true) = " << iter << endl;
//             int iter2 = 0;
//             for(Character *memmber: team)
//             {
//                 cout << "enter for each cowboy, iter - " << iter2 <<endl;
//                 if(memmber->is_cowboy() == true)
//                 {
//                     cout << "enter to cowboy " << endl;
//                     // each attack check if the enemy still alive
//                 if(tmp->isAlive() == false)
//                 {
//                     cout << "enter to if(tmp->isAlive() == false)"<<endl;
//                     break;
//                 }
//                 cout << "line 137" << endl;
//                 memmber->attack(tmp);
//                 }
//                 iter2++;
//                 cout << "exit for each cowboy" << endl;
//             }
//             int iter3 = 0;
//             for(Character *memmber: team)
//             {
//                 cout << " enter for each ninja, iter - " << iter3;
//                 if(memmber->is_cowboy() == false)
//                 {
//                     cout << "enter to if its not cowboy" <<endl;
//                 // each attack check if the enemy still alive
//                 if(tmp->isAlive() == false)
//                 {
//                     cout << "enter isAlive == false" <<endl;
//                     break;
//                 }
//                 cout << " line 156 " << endl;
//                 memmber->attack(tmp);
//                 }
//                 iter3++;
//             }
//             iter++;

//         }
//     }
//     cout << " ------------- exit from the end Team attack ----------- " << endl;
// };
// attack v2
void Team::attack(Team *other)
{
    // cout << "enter to attack cpp" << endl;
    // if (other == nullptr)
    // {
    //     cout << "enter to if(other == NULL)" << endl;
    //     cout << "enter if(other team == NULL)" << endl;
    //     throw std::invalid_argument("input pointer is NULL");
    // }
    // // if all the team is dead
    // if (stillAlive() == 0)
    // {
    //     cout << "enter to if(stillAlive() == 0)" << endl;
    //     throw std::runtime_error(" team is dead");
    // }
    // if (other->stillAlive() == 0)
    // {
    //     cout << " enter to if(other->stillAlive() == 0)" << endl;
    //     throw std::runtime_error("enemy team is dead");
    // }
    // if (team_leader->isAlive() == false)
    // {
    //     cout << "team leader before = " << team_leader->getName();
    //     team_leader = get_closest_memmber();
    //     cout << "team leader after = " << team_leader->getName();
    // }
    // cout << "before vector lists" << endl;
    // // vector<Character*> cowboy_list = cowboy_attack();
    // // vector<Character*> ninja_list = ninja_attack();
    // Character *enemy = find_enemy(other);
    // cout << "pass *enemy_leader = other->get_team_leader()" << endl;
    // for (Character *cowboy : team)
    // {
    //     // cout << "enter to for each cowboys" << endl;
    //     // if((cowboy->is_cowboy() == true) && cowboy->isAlive() == true)
    //     // {
    //     // if((enemy->isAlive() == false))
    //     // {
    //     //     if(other->stillAlive() == 0)
    //     //     {
    //     //         return;
    //     //     }
    //     //     cout << "enter to enemy_leader->isAlive() == false" << endl;
    //     //     enemy = find_enemy(other);
    //     // }
    //     // cowboy->attack(enemy);
    // }

    // for (Character *ninja : team)
    // {
    //     // {
    //     // cout << "enter to for each ninja" << endl;
    //     // if((ninja->is_cowboy() == false) && ninja->isAlive() == true)
    //     // {ma
    //     // if((enemy->isAlive() == false))
    //     // {
    //     //     if(other->stillAlive() == 0)
    //     //     {
    //     //         return;
    //     //     }
    //     //     cout << "enter to enemy_leader->isAlive() == false" << endl;
    //     //     enemy = find_enemy(other);
    //     // }
    //     // ninja->attack(enemy);
    // }
    // cout << "exit atack cpp" << endl;
    // if (other == nullptr)
    // {
    //     throw std::invalid_argument("zona");
    // }
    // if (this->stillAlive() == 0)
    // {
    //     throw std::runtime_error("zona");
    // }
    // if (other->stillAlive() == 0)
    // {
    //     throw std::runtime_error("zona");
    // }
    if (!team_leader->isAlive())
    {
        // Character *_tmp_leader;
        // double _distance = std::numeric_limits<double>::max();
        // for (int i = 0 ; i < currentSize ; i++)
        // {
        //     if (team[i]->isAlive())
        //     {
        //         double tmp = (team[i]->getLocation()).distance(team_leader->getLocation());
        //         if (tmp < _distance)
        //         {
        //             _distance = tmp;
        //             _tmp_leader = team[i];
        //         }
        //     }
        // }
        
    }

    
}


// vector<Character*> Team::ninja_attack()
// {
//     cout << "enter to ninja_attack()" << endl;
//     vector<Character*> list;
//     for(Character* memmber: team)
//     {
//         if((memmber->is_cowboy() == false) && memmber->isAlive() == true)
//         {
//             list.push_back(memmber);
//         }
//     }
//     cout << "exit to ninja_attack()" << endl;
//     return list;
// };
// vector<Character*> Team::cowboy_attack()
// {
//     cout << "enter cowboy_attack()" << endl;
//     vector<Character*> list;
//     for(Character* memmber: team)
//     {
//         if((memmber->is_cowboy() == true) && memmber->isAlive() == true)
//         {
//             list.push_back(memmber);
//         }
//     }
//     cout << "exit cowboy_attack()" << endl;
//     return list;
//     // auto comp = [] (Character* mem_1, Character* mem_2)
//     // {
//     //    Point leader_point = team_leader->getLocation();
//     //    double dist_1 = mem_1->getLocation().distance(leader_point);
//     //    return a>b;
//     // };

// };

// void Team::set_container(bool order)
// {
//     team = set<Character*, order>;
// };


int Team::stillAlive() // returns the number of alives Team members.
{
    int counter = 0;
    for (int i = 0; i < currentSize ; i++)
    {
        if (team[i]->isAlive())
        {
            counter++;
        }
    }
    return counter;
};
void Team::print()
{
    for (int i = 0 ; i < currentSize ; i++)
    {
        if (team[i]->is_cowboy())
        {
            string str = team[i]->to_string();
            cout << str << endl;
        }
    }
    for (int i = 0 ; i < currentSize ; i++)
    {
        if (team[i]->is_cowboy() == false)
        {
            string str = team[i]->to_string();
            cout << str << endl;
        }
    }
};

Character *Team::get_team_leader()
{
    cout << "----------- enter get_team_leader() ----- " << endl;
    if (this->stillAlive() == 0)
    {
        return team_leader;
        cout << "----------- exit get_team_leader() ----- " << endl;
    }
    // pass over all the death team memmber. exit from while loop its mean that the closest one is alive
    // team_leader = get_closest_memmber();

    return team_leader;
};
Character *Team::find_enemy(Team *other)
{
    Point leader_location = team_leader->getLocation();
    Character *enemy;
    double distance = std::numeric_limits<double>::max();
    for (int i = 0 ; i < other->currentSize ; i++)
    {
        if (other->team[i]->isAlive())
        {
            double tmp = (other->team[i]->getLocation()).distance(leader_location);
            if (tmp < distance)
            {
                distance = tmp;
                enemy = other->team[i];
            }
        }
    }
    return enemy;
};

int Team::get_size()
{
    return currentSize;
};
// Point& Team::get_center()
// {
//     Point point = team_leader.getLocation();
//     return point;
// };
// Character* Team::get_closest_memmber()
// {
//     cout << "enter to get_closest_memmber()" << endl;
//     // creating tmp Character:
//     Point point = Point(MAXFLOAT, MAXFLOAT);
//     cout << "Point point = Point(MAXFLOAT, MAXFLOAT)" << endl;
//     Character *tmp = new Character("tmp", point);
//     cout << "Character *tmp = new Character(, point)" << endl;
//     for (Character* memmber: team)
//     {
//         cout << "enter for (Character* memmber: team)" << endl;
//         if(team_leader != memmber) // check this line
//         {
//             cout << "enter if(team_leader != memmber)" << endl;
//             if(memmber->isAlive() == true)
//             {
//                 cout << "enter if(memmber->isAlive() == true)" << endl;
//                 double dist_memmber = team_leader->distance(memmber);
//                 double dist_tmp = team_leader->distance(tmp);
//                 if(dist_memmber < dist_tmp)
//                 {
//                     cout << "enter if(team_leader->distance(memmber) < team_leader->distance(tmp))" << endl;
//                     tmp = (memmber);
//                 }
//             }
//         }
//     }
//     cout << "exit from get_closest_memmber()" << endl;
//     return tmp;
// };
// Character *Team::get_closest_memmber()
// {
    // Point point_leader = team_leader->getLocation();
    // Character *new_leader;
    // double distance = 10; // std::numeric_limits<double>::max();
    // for (Character *memmber : team)
    // {
    //     if (memmber->isAlive())
    //     {
    //         double tmp = memmber->getLocation().distance(point_leader);
    //         if (tmp < distance)
    //         {
    //             distance = tmp;
    //             new_leader = memmber;
    //         }
    //     }
    // }
    // return new_leader;
// };

// void Team::sort_team()
// {

// };
