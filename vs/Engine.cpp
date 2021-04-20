#define _USE_MATH_DEFINES
#include "globals.h"
#include "Engine.h"
#include "AsteroidFactory.h"

bool gameOver = false;


Engine::Engine() {
	arena =
	{
		config.arenaDim[0],
		config.arenaDim[1], 
		{1.0, 1.0, 1.0},
		{1.0, 1.0, 1.0},
		{1.0, 1.0, 1.0},
		{1.0, 1.0, 1.0},
		{
			Point(config.arenaDim[0] /-2.0 + ship.getSize(), config.arenaDim[1] /-2.0 + ship.getSize(), 0.0),
			Point(config.arenaDim[0] / 2.0 - ship.getSize(), config.arenaDim[1] /-2.0 + ship.getSize(), 0.0),
			Point(config.arenaDim[0] / 2.0 - ship.getSize(), config.arenaDim[1] / 2.0 - ship.getSize(), 0.0),
			Point(config.arenaDim[0] /-2.0 + ship.getSize(), config.arenaDim[1] / 2.0 - ship.getSize(), 0.0),
		}
	};
	renderer = Renderer(&arena);
	asteroidManager = AsteroidManager(renderer);

}

// is Max Asteroids
// Am spawning this frame
// select random
// launch

//on death flip status, reroll, translata

void Engine::updateGameState(float dt) {
	gameOver = testShipAsteroidCollision() || testShipWallCollision();

	asteroidManager.update(dt);
	
	if(keys.forwardsDown)	ship.moveForwards(dt);
	if(keys.backDown)		ship.moveBackwards(dt);
	if(keys.leftDown)		ship.turnLeft(dt, keys.backDown);
	if(keys.rightDown)		ship.turnRight(dt, keys.backDown);
}

void Engine::render() {
	renderer.drawSpawnCircle();
	renderer.drawArena();
	renderer.drawShip(ship);
	renderer.drawQuads();

	int i = 0;
	do {
		Asteroid* a = asteroidManager.getAsteroidAt(i);
		if(nullptr == a)
			break;
		if(a->isAlive())
			renderer.drawAsteroid(a);
		++i;
	} while(true);
}

bool Engine::testShipAsteroidCollision() {
	
	return asteroidManager.testShipCollision(*ship.getOrigin(), ship.getSize());
}

bool Engine::isCloseToWall(float x, float y, float x1, float x2, float y1, float y2) {
	return x <= x1 || y <= y1 || x >= x2 || y >= y2;
}

bool Engine::testShipWallCollision() {
	bool collision = false;
	float x = ship.getOrigin()->getX();
	float y = ship.getOrigin()->getY();
	float warn = config.wallWarnDistance;
	float xWarnL	= arena.shadowBox[0].getX() + warn*ship.getSize();
	float yWarnLow	= arena.shadowBox[0].getY() + warn*ship.getSize();
	float xWarnR	= arena.shadowBox[2].getX() - warn*ship.getSize();
	float yWarnHigh = arena.shadowBox[2].getY() - warn*ship.getSize();

	if(isCloseToWall(x, y, xWarnL, xWarnR, yWarnLow, yWarnHigh)) {
		if(x <= xWarnL)		changeWallColour(arena.leftWallColour, 1.0, 0.0, 0.0);
		if(y <= yWarnLow)	changeWallColour(arena.bottomWallColour, 1.0, 0.0, 0.0);
		if(x >= xWarnR)		changeWallColour(arena.rightWallColour, 1.0, 0.0, 0.0);
		if(y >= yWarnHigh)	changeWallColour(arena.topWallColour, 1.0, 0.0, 0.0);

		if(x <= xWarnL - (warn-1.0)*ship.getSize() || y <= yWarnLow - (warn-1.0)*ship.getSize())
			collision = true;

		if(x >= xWarnR + (warn-1.0)*ship.getSize() || y >= yWarnHigh + (warn-1.0)*ship.getSize())
			collision = true;
	}
	else {
		changeWallColour(arena.leftWallColour, 1,1,1);
		changeWallColour(arena.rightWallColour, 1,1,1);
		changeWallColour(arena.topWallColour, 1,1,1);
		changeWallColour(arena.bottomWallColour, 1,1,1);
	}

	if(collision)
		ship.getOrigin()->translateTo(0, 0, 0);

	return collision;
}


void Engine::changeWallColour(float* colourArr, float r, float g, float b) {
	colourArr[0] = r;
	colourArr[1] = g;
	colourArr[2] = b;
}