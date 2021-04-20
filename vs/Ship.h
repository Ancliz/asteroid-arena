#ifndef SHIP_H
#define SHIP_H

#include "Vec2d.h"
#include "globals.h"
#include "Object.h"

#define REF_POINTS		2
#define SHIP_POINTS		5

class Ship : public Object {
private:
	Vec2d  dir;
	Point points[SHIP_POINTS];
	float outlineColour[AA_RGB];
	float fillColour[AA_RGB];
	float size;
	float speed;
	float rotSpeed;
	float angleFromX;

public:
	Ship(Point* startingPos);

	Point* getPoints();
	//Point* getOrigin();
	Vec2d  getDirection();
	float* getFill();
	float* getOutline();
	float  getSpeed();
	float  getAngleFromX();
//	float  getSize();

	void moveForwards(double dt);
	void moveBackwards(double dt);
	void turnLeft(double dt, bool backwards);
	void turnRight(double dt, bool backwards);

};

extern Ship ship;
#endif