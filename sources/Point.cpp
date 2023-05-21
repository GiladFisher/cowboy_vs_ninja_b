#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Point.hpp"
using namespace std;
namespace ariel{
    Point::Point(double x_ax, double y_ax){
        this->x_ax = 0;
        this->y_ax = 0;
    }
    void Point::print() const{
        
    }
    double Point::distance(Point other) const{
        return 0;
    }
    double Point::getX() const{
        return 0;
    }
    double Point::getY() const{
        return 0;
    }
    Point Point::moveTowards(Point src, Point dst, double distance){
        return Point(0,0);
    }
    

}