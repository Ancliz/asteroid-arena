#define _USE_MATH_DEFINES
#include "Ship.h"
#include "Math.h"

Ship ship = Ship(new Point(0,0,0));

Ship::Ship(Point* pos) : boundingRadius(1), angleFromX(0), speed(5), rotSpeed(10), dir(UVEC_J) {
	points[0] = Point(*pos, 0.0, 0.0);
	points[1] = Point(*pos, 1.0, 0.0);
	points[2] = Point(*pos, -1.0, -1.0);
	points[3] = Point(*pos, -0.5, 0);
	points[4] = Point(*pos, -1.0, 1.0);

	origin = &points[0];

	fillColour[0] = 1.0;
	fillColour[1] = 0.7;
	fillColour[2] = 0.0;

	outlineColour[0] = 0;
	outlineColour[1] = 1;
	outlineColour[2] = 0;

}

float Ship::getAngleFromX() {
	return atan2(dir.getCoords()->getY(), dir.getCoords()->getX());
}

void Ship::turnLeft(double dt, bool backwards) {
	float theta = (backwards ? -M_PI / 180 : M_PI / 180);
	Math::performRotation(dir.getCoords(),dt * rotSpeed * theta);
}

void Ship::turnRight(double dt, bool backwards) {
	float theta = (backwards ? M_PI / 180 : -M_PI / 180);
	Math::performRotation(dir.getCoords(), dt * rotSpeed * theta);
}

void Ship::moveForwards(double dt) {
	Math::performTranslation(origin,dt * speed * dir.getCoords()->getX(),dt * speed * dir.getCoords()->getY());
}

void Ship::moveBackwards(double dt) {
	Math::performTranslation(origin, dt * speed* -dir.getCoords()->getX(), dt * speed * -dir.getCoords()->getY());
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

