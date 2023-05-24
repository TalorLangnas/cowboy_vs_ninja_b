#include "Point.hpp"
using namespace ariel;

// Constructor:
Point::Point(double other_x, double other_y)
{
    x = other_x;
    y = other_y;
};
// Copy Constructor:
Point::Point(const Point& other)
{
    x = other.x;
    y = other.y;
};


double Point::distance(Point other)
{
    cout << " enter Point::distance" << endl;
    double delta_x = x - other.x;
    double delta_y = y - other.y;
    //double dist = sqrt((delta_x*delta_x) + (delta_y*delta_y));
    cout << " exit Point::distance" << endl;
    return sqrt((delta_x*delta_x) + (delta_y*delta_y));
};
string Point::print()
{    
    return string(*this);
};
Point Point::moveTowards(Point srce, Point dst, double alpha)
{   /* ------------------ first version ------------------------
    // input validation:
    // if srce and dst are the same
    if((srce.x == dst.x) && (srce.y == dst.y))
    {
        throw std::invalid_argument("source and destenation Points are the same");
    };
    if(alpha == 0)
    {
        return srce;
    }

    double abs_distance = abs(alpha); 
    double delta_x = srce.x - dst.x;
    double delta_y = srce.y - dst.y;

    // if the Points are parrallel to y axis
    if(delta_x == 0)
    {
        if(srce.y < dst.y)
        {
            Point point = Point(srce.x, srce.y + abs_distance);
            return point;
        }
        else
        {
            Point point = Point(srce.x, srce.y - abs_distance);
            return point;
        }        
    }
    // assume delta_x != 0 
    double slope = delta_y/delta_x;
    double x_alpha = (slope*alpha) + srce.x;
    double y_alpha = (slope*alpha) + srce.y;

    Point point = Point(x_alpha, y_alpha);

    
    Point point = Point(1,1);
    return point;
    
    
    */
// ------------------ end -------------------------
// ------------------ second version ------------------------
    // input validation:
    // if srce and dst are the same
    // input validation
    if(alpha < 0)
    {
        throw invalid_argument("Distance must be positive");
    }
    if((srce.x == dst.x) && (srce.y == dst.y))
    {
        // Point point = srce;
        // return point;
        return srce;
    };

    if(alpha == 0)
    {
        return srce;
    }
    double distance = srce.distance(dst);
    double x_var = srce.x + ((dst.x - srce.x)*alpha)/distance;
    double y_var = srce.y + ((dst.y - srce.y)*alpha)/distance;
    Point point = Point(x_var, y_var);
    return point;

};

// Operators:

bool Point::operator==(const Point& other) const
{
    if((x == other.x) && (y == other.y))
    {
        return true;
    }
    else
    {
        return false;
    }           
};

Point::operator string() const
{
    string x_cordinate = to_string(x);
    string y_cordinate = to_string(y);
    return "("+ x_cordinate + ", " + y_cordinate + ")"; 
};

Point& Point::operator=(const Point& other)
{
    if (this == &other)
    {
        return *this;
    }
    
    x = other.x;
    y = other.y;        
    
    return (*this);   
};

