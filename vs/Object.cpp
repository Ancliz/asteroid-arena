#include "Object.h"



Object::Object(Point* o, Vec2d dir) : origin(o), direction(dir) {}



Point* Object::getOrigin() {
	return origin;
}

Vec2d Object::getDirection() {
	return direction;
}

float Object::getSpeed() {
	return speed;
}

float Object::getSize() {
	return hp;
}

int Object::getHP() {
	return hp;
}