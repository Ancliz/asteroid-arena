#ifndef SHIP_H
#define SHIP_H

#include "Vec2d.h"
#include "globals.h"

#define REF_POINTS		2
#define SHIP_POINTS		5

class Ship {
private:
	Point *origin;
	Vec2d  dir;
	Point points[SHIP_POINTS];
	float outlineColour[AA_RGB];
	float fillColour[AA_RGB];
	int boundingRadius;
	float speed;
	float rotSpeed;
	float angleFromX;

public:
	Ship(Point* startingPos);

	void updateDir();
	void setOutline(float r, float g, float b);
	void setFill(float r, float g, float b);

	Point* getPoints();
	Point* getOrigin();
	Point* getFront();
	Vec2d  getDir();
	float* getFill();
	float* getOutline();
	float  getSpeed();
	float  getAngleFromX();

	void moveForwards(double dt);
	void moveBackwards(double dt);
	void turnLeft(double dt, bool backwards);
	void turnRight(double dt, bool backwards);
};

extern Ship ship;
#endif