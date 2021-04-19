#include <math.h>
#include "Vec2d.h"

Vec2d::Vec2d() {
	coords = Point(0, 0, 0);
	mag = calcMagnitude();
}

Vec2d::Vec2d(Point* point) : coords(*point) {
	mag = calcMagnitude();
}

Vec2d::Vec2d(Point point) : coords(point) {
	mag = calcMagnitude();
}

Vec2d::Vec2d(const Vec2d& other) : coords(other.coords), mag(other.mag) {}

void Vec2d::setMag(float mag) {
	this->mag = mag;
}

void Vec2d::setCoords(Point point) {
	coords.setX(point.getX());
	coords.setY(point.getY());
}

float Vec2d::getMag() {
	return mag;
}

 Point* Vec2d::getCoords() {
	return &coords;
}

 Vec2d Vec2d::getUnitVec() const {
	 float ux = coords.getX() / mag;
	 float uy = coords.getY() / mag;
	 return Vec2d(Point(ux, uy, 0));

 }

 float Vec2d::calcMagnitude() {
	 double x = coords.getX();
	 double y = coords.getY();

	 return sqrt((x*x + y*y));
 }


 double operator*(Vec2d v1, Vec2d v2) {
	 double x = v1.getCoords()->getX() * v2.getCoords()->getX();
	 double y = v2.getCoords()->getY() * v2.getCoords()->getY();
	 return x + y;
 }

 Vec2d& Vec2d::operator-=(const Vec2d v) {
	 float x = coords.getX();
	 float y = coords.getY();
	 this->coords.setX(x - v.coords.getX());
	 this->coords.setY(y - v.coords.getY());
	 return *this;
 }
  
 Vec2d operator*(double scalar, Vec2d v) {
	 Vec2d r = Vec2d(v);
	 Point* p = r.getCoords();
	 r.setCoords(Point(scalar * p->getX(), scalar * p->getY(), scalar * p->getZ()));
	 return r;
 }

 Vec2d operator*(Vec2d v, double scalar) {
	 return scalar * v;
 }

  Vec2d operator-(Vec2d v1, const Vec2d& v2) {
	 v1 -= v2;
	 return v1;
 }


