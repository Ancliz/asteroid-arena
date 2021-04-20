#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include "Asteroid.h"
#include "Ship.h"
#include "Keyboard.h"
#include "Math.h"
#include "Renderer.h"
#include "Arena.h"
#include "AsteroidManager.h"


class Engine {

	private:
		//std::vector<Asteroid*> asteroids;
		Point* asteroidCircle[NUM_ASTEROID_NODES];
		AsteroidManager asteroidManager;
		Renderer renderer;
		Arena arena;


		void changeWallColour(float* colourArr, float r, float g, float b);
		bool isCloseToWall(float x, float y, float x1, float x2, float y1, float y2);
	public:
		Engine();
		void updateGameState(float dt);
		void render();
		bool testShipAsteroidCollision();
		bool testShipWallCollision();

};

#endif