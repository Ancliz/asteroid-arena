#ifndef POINT_H
#define POINT_H

#include <string>
class Point {
	private:
		double x, y, z;

	public:
		Point();
		Point(double x, double y, double z);
		Point(Point& other, double xOff, double yOff);
		Point(const Point& other);

		double getX() const;
		double getY() const;
		double getZ() const;

		void setX(double x);
		void setY(double y);
		void setZ(double z);

		void translate(float x, float y, float z);
		void translate(Point& addition);
		void translateTo(Point& dest);
		void translateTo(float x, float y, float z);

		Point& operator-=(Point& p2);
		Point& operator+=(Point& p2);

		// Debug
		std::string toString();
};


bool operator==(const Point& p1, const Point& p2);


Point operator-(Point p1, Point& p2);
Point operator+(Point p1, Point& p2);
#endif