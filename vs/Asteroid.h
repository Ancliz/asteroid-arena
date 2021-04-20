#ifndef ASTEROID_H
#define ASTEROID_H

#include "Point.h"
#include "Vec2d.h"


class Asteroid {
	private:
		Vec2d  direction;
		Point* origin;
		int    size;
		int    hp;
		float  speed;
		bool   alive;

	public:
		Asteroid(Point* origin);
		Point* getOrigin();

		int  getSize();
		int  getHP();
		void decrementHP(int hp);
		void reRoll();
		void kill();
		bool isAlive();
		void setAlive();
		void setDirection(Vec2d direction);
		void move(double dt);
};






#endif