#ifndef SHIP_H
#define SHIP_H

//#include "globals.h"
#include "Vec2d.h"

#define REF_POINTS		2
#define SHIP_POINTS		5
#define SHIP_RGB		3

class Ship {
private:
	Point *origin;
	Vec2d  dir;
	Point points[SHIP_POINTS];
	float outlineColour[SHIP_RGB];
	float fillColour[SHIP_RGB];
	//float boundingRadius;
	float velocity;
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
	float  getVel();
	float  getAngleFromX();

	void moveForwards(double dt);
	void moveBackwards(double dt);
	void turnLeft(double dt, bool backwards);
	void turnRight(double dt, bool backwards);
};

extern Ship ship;
#endif