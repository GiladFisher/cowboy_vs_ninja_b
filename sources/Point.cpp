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
        if(dist >= src.distance(dst)){
            return dst;
        }
        double curr_dist = src.distance(dst);
        double ratio = dist/curr_dist;
        double x_n = src.getX() + ratio*(dst.getX() - src.getX());
        double y_n = src.getY() + ratio*(dst.getY() - src.getY());
        return Point(x_n, y_n);
    }
    

}