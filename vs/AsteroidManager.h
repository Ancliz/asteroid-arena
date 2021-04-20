#ifndef ASTEROID_LAUNCHER_H
#define ASTEROID_LAUNCHER_H

#include <vector>
#include "Asteroid.h"
#include "Ship.h"
#include "Renderer.h"
#include "globals.h"

class AsteroidManager {

	private:
	std::vector<Asteroid*> asteroids;
	Point* spawnCircle[SPAWN_CIRCLE_NODES];
	int aliveCount;

	public:
		AsteroidManager();
		AsteroidManager(Renderer& r);
		void launch(Asteroid* asteroid);
		void createAsteroidSpawnCircle(int radius, int nodes);

		void killAsteroid(Asteroid* a);
		void spawnAsteroids();

		void update(float dt);
		void updatePositions(float dt);

		void populateAsteroidPool(int wantedAlive);
		Asteroid* getAsteroidAt(int i);

		bool testShipCollision(Point origin, float radius);


};

#endif