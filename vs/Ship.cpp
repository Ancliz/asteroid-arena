#define _USE_MATH_DEFINES
#include "Ship.h"
#include "Math.h"

Ship ship = Ship(new Point(0,0,0));

Ship::Ship(Point* pos) {
	points[0] = Point(*pos, 0, 0);
	points[1] = Point(*pos, 0.0, 1);
	points[2] = Point(*pos, -1, -1);
	points[3] = Point(*pos, 0.0, -0.5);
	points[4] = Point(*pos, 1, -1);

	origin = &points[0];
	dir = UVEC_J;
	angleFromX = 0;

	fillColour[0] = 1.0;
	fillColour[1] = 0.7;
	fillColour[2] = 0.0;

	outlineColour[0] = 0;
	outlineColour[1] = 1;
	outlineColour[2] = 0;
}

float Ship::getAngleFromX() {
	return angleFromX;
}

void Ship::turnLeft(double dt, bool backwards) {
	float theta = (backwards ? -M_PI / 180 : M_PI / 180);
	Math::performRotation(dir.getCoords(), M_PI / 180);
	++angleFromX;

	printf("dir: %s\tangleFromX: %f\n", dir.getCoords()->toString().c_str(), angleFromX);
}

void Ship::turnRight(double dt, bool backwards) {
	float theta = (backwards ? M_PI / 180 : -M_PI / 180);
	Math::performRotation(dir.getCoords(), -M_PI / 180);
	--angleFromX;

	printf("dir: %s\tangleFromX: %f\n", dir.getCoords()->toString().c_str(), angleFromX);
}

void Ship::moveForwards(double dt) {
	Math::performTranslation(origin, dir.getCoords()->getX(), dir.getCoords()->getY());
	printf("dir: %s\torigin: %s\n", origin->toString().c_str(), dir.getCoords()->toString().c_str());
}

void Ship::moveBackwards(double dt) {
	Math::performTranslation(origin, -dir.getCoords()->getX(), -dir.getCoords()->getY());
}

Point* Ship::getOrigin() {
	return origin;
}

Vec2d Ship::getDir() {
	return dir;
}

float* Ship::getFill() {
	return fillColour;
}

float* Ship::getOutline() {
	return outlineColour;
}

Point* Ship::getPoints() {
	return points;
}

