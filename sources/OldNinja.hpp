#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP
#include "Ninja.hpp"
#include <string>
using namespace std;

namespace ariel{
class OldNinja: public Ninja
{
    public:

    OldNinja(string name, Point location);
}; 
};
#endif