# include "Character.hpp"
using namespace std;
using namespace ariel;


    // Constructors:
    Character::Character():location(0,0)
    {

    };
    Character::Character(double x, double y): location(x, y), assigned(false)
    {

    };
    Character::Character(Point point): location(point), assigned(false)
    {
        
    };
    Character::Character(string other, Point point): location(point), assigned(false)
    {
        name = other;
        // team_number = 100;
    
    };
    // copy constructor
    // Character::Character(const Character& other):location(other.location), assigned(false)
    // {
    //     if(this == &other)
    //     {
    //         return; 
    //     }
    //     location = other.location;
    //     name = other.name;
    //     health_point = other.health_point;
    //     assigned = other.assigned;
    // };
    // copy assignment operator
    // Character& Character::operator=(const Character& other)
    // {
    //     if(this == &other)
    //     {
    //         return *this;
    //     }
    //     // location = other.location;
    //     // name = other.name;
    //     // health_point = other.health_point;
    //     *this = Character(other);

    //     return *this;
    // };
    // move constructor
    // Character::Character(Character&& other) noexcept: location(other.location), assigned(false)
    // {

    // };
    // move assignment operator
    // Character& Character::operator=(Character&& other) noexcept
    // {
    //     return *this;
    // };    

    // Destructor:
    // Character::~Character()
    // {

    // };
    bool Character::isAlive()
    {   
        if(health_point > 0)
        {
            return true;
        }
        else
            return false;
    };
    double Character::distance(Character *character)
    {   
        cout << "enter Character::distance" << endl;
        Point point = character->getLocation();
        cout << "Point point = character->getLocation()" << endl;
        double dist = location.distance(point);
        cout << "double dist = location.distance(point)" << endl;
        cout << "exit Character::distance" << endl;
        return dist;
    };

    void Character::set_location(Point point)
    {
        location = point;
    };


    void Character::hit(int num)
    {
        if(num < 0)
        {
            throw invalid_argument("input most be positive");
        }

        health_point = health_point - num;
        
    };
    string& Character::getName()
    {
        return name;
    };
    Point Character::getLocation()
    {
        return location;
    };
    string Character::to_string()
    {   
        string output = "Name: " + name + ", " + "hp: " + std::to_string(health_point) +
                          "location: " + string(location) + ".";
        return output;
    };
    void Character::print()
    {
        cout << (*this).Character::to_string() << endl;
    };
    bool& Character::has_team()
    {
        return assigned;
    };
    int& Character::get_health_point()
    { 
        return health_point;
    };
    // int& Character::get_team_number()
    // {
    //     return team_number;
    // };
    void Character::attack(Character*)
    {
        cout << "enter to Character::attack" << endl;
    };
    bool Character::is_cowboy()
    {
        return false;
    };
    // double set_distance_from_leader(Point);
    // double get_distance_from_leader();
    bool Character::operator==(const Character& other) const
    { 
        if(
            (location == other.location) &&
            (name == other.name) &&
            (health_point == other.health_point))
        {
            return true;
        }
        else
        return false;
    };

    //  Point location;
    // string name;
    // // protected:
    // int health_point;
    // int team_number;