#ifndef POINT_HPP
#define POINT_HPP
#include <string>


using namespace std;

namespace ariel{

    class Point
    {
    private:
        double x;
        double y;

    public:
        Point(double x_point, double y_point) : x(x_point), y(y_point) {};
        double distance(Point pnt);
        void print();
        string toString();
        double get_x() const { return x; }
        double get_y() const { return y; }
        void set_x(double x_point) { x = x_point; }
        void set_y(double y_point) { y = y_point; }
        static Point moveTowards(Point& pnt1, Point& pnt2, double distance);
    };

}

#endif