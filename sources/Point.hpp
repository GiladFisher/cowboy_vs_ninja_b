#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;
namespace ariel{
    class Point{
        private:
            double x_ax;
            double y_ax;
        public:
            Point(double x_ax, double y_ax);
            void print() const;
            double distance(Point other) const;
            double getX() const;
            double getY() const;
            static Point moveTowards(Point src, Point dst, double distance);
    };
}