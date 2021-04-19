#ifndef ASTEROID_H
#define ASTEROID_H

#include "Point.h"
#include "Vec2d.h"


class Asteroid {
	private:
		Point* origin;
		bool   alive;
		float  radius;
		float  hp;

	public:

		Point* getOrigin();

		void setHP(float hp);
		float getHP();
		bool isAlive();


};






#endif