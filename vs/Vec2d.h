#ifndef VEC2D_H
#define VEC2D_H

#include "Point.h"

class Vec2d {
private:
	Point coords;
	float mag;

	void calcUnitVec();
	float calcMagnitude();
public:
	Vec2d();
	Vec2d(Point* coords);
	Vec2d(Point coords);
	Vec2d(const Vec2d& other);

	void setCoords(Point point);
	void setMag(float mag);
	
	Point* getCoords();
	float getMag();
	Vec2d getUnitVec() const;

	Vec2d& operator-=(const Vec2d v);
	
};

const Vec2d UVEC_I = Vec2d(Point(1, 0, 0));
const Vec2d UVEC_J = Vec2d(Point(0, 1, 0));

// Calculate dot product
double operator*(Vec2d v1, Vec2d v2);

// Multiply vector by scalar
Vec2d operator*(double scalar, const Vec2d v);
Vec2d operator*(const Vec2d v, double scalar);

// Vector subtraction
Vec2d operator-(Vec2d v1, const Vec2d& v2);

#endif