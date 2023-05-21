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
        cout << "(" << this->x_ax << "," << this->y_ax << ")" << endl;
        
    }
    double Point::distance(Point other) const{
        return sqrt(pow(this->x_ax - other.x_ax, 2) +
                     pow(this->y_ax - other.y_ax, 2));
    }
    double Point::getX() const{
        return this->x_ax;
    }
    double Point::getY() const{
        return this->y_ax;
    }
    Point Point::moveTowards(Point src, Point dst, double distance){
        Point distance(src.getX() - dst.getX(), src.getY() - dst.getY());
        double norm = sqrt(pow(distance.getX(), 2) + pow(distance.getY(), 2));
        Point direction(distance.getX() / norm, distance.getY() / norm);
        return Point(src.getX() + direction.getX() * distance,
                     src.getY() + direction.getY() * distance);
    }
    

}