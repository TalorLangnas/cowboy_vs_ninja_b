#ifndef TRAINED_NINJA_HPP
#define TRAINED_NINJA_HPP
#include "Ninja.hpp"
using namespace std;
using namespace ariel;

class TrainedNinja: public Ninja
{
    public:
    TrainedNinja();
    TrainedNinja(string, Point);
}; 

#endif