#ifndef MATH_H
#define MATH_H


#include <math.h>
#include "Vec2d.h"

static class Math {
	public:
		static void performRotation(Point* point, double angle);
		static void performTranslation(Point* points, double transX, double transY);
		static double scalarProjection(Vec2d& from, const Vec2d& onto);
		static int randRange(int lower, int upper);
		static float randRange(float lower, float upper);

		// Exclusive of bounds
		static bool inRange(float x, float min, float max);
};

#endif