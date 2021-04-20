#include "Point.h"

Point::Point() : x(0), y(0), z(0) {}

Point::Point(const Point& other) : x(other.x), y(other.y), z(other.z) {}

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

Point::Point(Point& const point, double xOff, double yOff) {
	x = xOff + point.getX();
	y = yOff + point.getY();
	z = 0;
}

void Point::translate(float x, float y, float z) {
	this->x += x;
	this->y += y;
	this->z += z;
}

void Point::translate(Point& other) {
	translate(other.x, other.y, other.z);
}

void Point::translateTo(Point& dest) {
	x = dest.x;
	y = dest.y;
	z = dest.z;

}

void Point::translateTo(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

double Point::getX() const { return x; }
double Point::getY() const { return y; }
double Point::getZ() const { return z; }

void Point::setX(double x) { this->x = x; }
void Point::setY(double y) { this->y = y; }
void Point::setZ(double z) { this->z = z; }


Point& Point::operator-=(Point& p2) {
	translate(-p2.x, -p2.y, -p2.z);
	return *this;
}

Point& Point::operator+=(Point& p2) {
	translate(p2.x, p2.y, p2.z);
	return *this;
}

Point operator-(Point p1, Point& p2) {
	p1 -= p2;
	return p1;
}

Point operator+(Point p1, Point& p2) {
	p1 += p2;
	return p1;
}

bool operator==(const Point& p1, const Point& p2) {
	return p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ();
}

std::string Point::toString() {
	return "(" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + ")";
}


