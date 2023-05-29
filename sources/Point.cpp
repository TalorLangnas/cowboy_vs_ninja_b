#include "Point.hpp"
#include <math.h>
#include <string>
#include <iostream>
#include <limits>



using namespace std;

namespace ariel{


    double Point::distance(Point pnt)
    {   
        return sqrt(pow(x - pnt.x, 2) + pow(y - pnt.y, 2));
    }

    void Point::print()
    {
        cout << "(" << x << "," << y << ")";
    }
    
    string Point::toString()
    {
        return "(" + to_string(x) + "," + to_string(y) + ")";
    }

    Point Point::moveTowards( Point& pnt1, Point& pnt2, double distance)
    {   
        // if distance is negative throw error
        if(distance < 0)
        {
            throw invalid_argument("Distance cannot be negative");
        }
        else if(distance > pnt1.distance(pnt2))
        {
            return Point(pnt2.get_x(), pnt2.get_y());
        }

        double x1 = pnt1.get_x();
        double y1 = pnt1.get_y();
        double x2 = pnt2.get_x();
        double y2 = pnt2.get_y();
        double x3 = x1 + (distance * (x2 - x1) / pnt1.distance(pnt2));
        double y3 = y1 + (distance * (y2 - y1) / pnt1.distance(pnt2));
        return Point(x3, y3);
    }

}