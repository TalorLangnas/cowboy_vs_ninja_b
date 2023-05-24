#ifndef POINT_HPP
#define POINT_HPP
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

namespace ariel
{
class Point
{
    private:
    
    double x;
    double y;

    public:
// Constructors:
    Point(double, double);
    // Copy Constructor:
    Point(const Point&);
    ~Point() = default;
    // move constructor
    Point(Point &&) noexcept = default;

// Methods:
    double distance(Point);
    string print();
    static Point moveTowards(Point, Point, double);
// Operators:
    bool operator==(const Point& other) const;
    Point& operator=(const Point& other);
    operator string() const;
    // move assignment operator
    Point& operator=(Point &&) noexcept = default;

};
};
# endif