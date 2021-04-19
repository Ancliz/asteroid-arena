#include "Point.h"

Point::Point() {
	x = 0;
	y = 0;
	z = 0;
}
Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

Point::Point(Point& const point, double xOff, double yOff) {
	x = xOff + point.getX();
	y = yOff + point.getY();
	z = 0;
}

Point& Point::operator-=(Point& p2) {
	x -= p2.getX();
	y -= p2.getY();
	z -= p2.getZ();
	return *this;
}

bool operator==(const Point& p1, const Point& p2) {
	return p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ();
}


Point operator-(Point p1, Point& p2) {
	p1 -= p2;
	return p1;
}


double Point::getX() const { return x; }
double Point::getY() const { return y; }
double Point::getZ() const { return z; }

void Point::setX(double x) { this->x = x; }
void Point::setY(double y) { this->y = y; }
void Point::setZ(double z) { this->z = z; }


std::string Point::toString() {
	return "(" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + ")";
}


