#define _USE_MATH_DEFINES
#include "Ship.h"
#include "Math.h"

#define START_X		-WIDTH/2 + 25
#define START_Y		-HEIGHT/2 + 25


Ship ship = Ship(new Point(START_X,START_Y,0));

Ship::Ship(Point* pos) : Object(origin, Vec2d(Point(0.7071, 0.7071, 0))), size(2.5), angleFromX(0), speed(2), rotSpeed(10) {
	points[0] = Point(*pos, 0.0, 0.0);
	points[1] = Point(1.0, 0.0,0);
	points[2] = Point(-1.0, -1.0,0);
	points[3] = Point(-0.5, 0,0);
	points[4] = Point(-1.0, 1.0,0);

	origin = &points[0];

	fillColour[0] = 1.0;
	fillColour[1] = 0.7;
	fillColour[2] = 0.0;

	outlineColour[0] = 0;
	outlineColour[1] = 1;
	outlineColour[2] = 0;
	printf("origin: %s\tdirection: %s\ttheta: %f\n", origin->toString().c_str(), direction.getCoords()->toString().c_str(), angleFromX);

}

float Ship::getAngleFromX() {
	return atan2(direction.getCoords()->getY(), direction.getCoords()->getX());
}

void Ship::turnLeft(double dt, bool backwards) {
	float theta = (backwards ? -M_PI / 180 : M_PI / 180);
	Math::performRotation(direction.getCoords(), dt*rotSpeed * theta);
}

void Ship::turnRight(double dt, bool backwards) {
	float theta = (backwards ? M_PI / 180 : -M_PI / 180);
	Math::performRotation(direction.getCoords(), dt*rotSpeed * theta);
}

void Ship::moveForwards(double dt) {
	Math::performTranslation(origin,dt*speed * direction.getCoords()->getX(), dt*speed * direction.getCoords()->getY());
}

void Ship::moveBackwards(double dt) {
	Math::performTranslation(origin, dt*speed* -direction.getCoords()->getX(), dt*speed * -direction.getCoords()->getY());
}

//Point* Ship::getOrigin() {
//	return origin;
//}

Vec2d Ship::getDirection() {
	return direction;
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

//float Ship::getSize() {
//	return size;
//}
