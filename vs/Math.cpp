#include "Vec2d.h"
#include "Math.h"

void Math::performRotation(Point* point, double theta) {
	double x = point->getX();
	double y = point->getY();
	point->setX((x * cos(theta)) - (y * sin(theta)));
	point->setY((x * sin(theta)) + (y * cos(theta)));
}

void Math::performTranslation(Point* point, double transX, double transY) {
	point->translate(transX, transY, 0);
}

double Math::scalarProjection(Vec2d& v1, const Vec2d& v2) {
	return v1 * v2.getUnitVec();
}

int Math::randRange(int min, int max) {
	return min + rand() % (max - min + 1);
}

float Math::randRange(float min, float max) {
	return min + fmod(rand(), max - min + 1.0);
}

bool Math::inRange(float x, float min, float max) {
	return x > min && x < max;
}

