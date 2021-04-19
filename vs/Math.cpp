#include "Vec2d.h"
#include "Math.h"

void Math::performRotation(Point* point, double theta) {
	double x = point->getX();
	double y = point->getY();
	point->setX((x * cos(theta)) - (y * sin(theta)));
	point->setY((x * sin(theta)) + (y * cos(theta)));
}

void Math::performTranslation(Point* point, double transX, double transY) {
	double x = point->getX();
	double y = point->getY();
	point->setX((x += transX));
	point->setY((y += transY));
}


double Math::scalarProjection(Vec2d& v1, const Vec2d& v2) {
	return v1 * v2.getUnitVec();
}

