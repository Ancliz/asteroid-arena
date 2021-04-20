#ifndef OBJECT_H

#include "globals.h"
#include "Point.h"
#include "Vec2d.h"

class Object {
	protected:
		Point *origin;
		Vec2d direction;
		float fillColour[AA_RGB];
		float speed;
		float size;
		int   hp;

	public:
		Object(Point* origin, Vec2d direction);

		Point *getOrigin();
		Vec2d getDirection();
		float getSpeed();
		float getSize();
		int   getHP();

		void move();
};

#endif

