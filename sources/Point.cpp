#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <cmath>
// #include <bits/stdc++.h>
#include "Point.hpp"
using namespace std;
namespace ariel{
    Point::Point(double x_ax, double y_ax) : x_ax(x_ax), y_ax(y_ax){
    }
    void Point::print() const{
        cout << "(" << this->x_ax << "," << this->y_ax << ")" << endl;
    }
    double Point::distance(Point other) const{
        return std::sqrt(std::pow(this->x_ax - other.getX(), 2) +
                     std::pow(this->y_ax - other.getY(), 2));
    }
    double Point::getX() const{
        return this->x_ax;
    }
    double Point::getY() const{
        return this->y_ax;
    }
    Point Point::moveTowards(Point src, Point dst, double dist){
        if(dist < 0){
            throw invalid_argument("distance cannot be negative");
        }
        Point distance(src.getX() - dst.getX(), src.getY() - dst.getY());
        double norm = sqrt(pow(distance.getX(), 2) + pow(distance.getY(), 2));
        Point direction(distance.getX() / norm, distance.getY() / norm);
        return Point(src.getX() + direction.getX() * dist,
                     src.getY() + direction.getY() * dist);
    }
    

}