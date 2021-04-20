#include "Asteroid.h"
#include "globals.h"
#include "Math.h"

Asteroid::Asteroid(Point* origin) : origin(origin) {
	reRoll();
}


void Asteroid::decrementHP(int hp) {
		this->hp -= hp;
}

int Asteroid::getHP() {
	return hp;
}

Point* Asteroid::getOrigin() {
	return origin;
}

int Asteroid::getSize() {
	return size;
}

void Asteroid::reRoll() {
	hp = Math::randRange(config.asteroidMinHP, config.asteroidMaxHP);
	size = Math::randRange(config.asteroidMinSize, config.asteroidMaxSize);
	speed = Math::randRange(config.asteroidMinSpeed, config.asteroidMaxSpeed);
}

bool Asteroid::isAlive() {
	return alive;
}

void Asteroid::kill() {
	alive = false;
	reRoll();
}

void Asteroid::setAlive() {
	alive = true;
}

void Asteroid::setDirection(Vec2d direction) {
	this->direction = direction;
}

void Asteroid::move(double dt) {
	Math::performTranslation(origin, dt*speed * direction.getCoords()->getX(), dt*speed * direction.getCoords()->getY());

}