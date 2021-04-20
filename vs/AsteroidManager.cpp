#define _USE_MATH_DEFINES
#include "AsteroidManager.h"
#include "Math.h"
#include "Engine.h"


//Point* spawnCircle[asteroids.size()];

AsteroidManager::AsteroidManager() {}

AsteroidManager::AsteroidManager(Renderer& renderer) {
	aliveCount = 0;
	createAsteroidSpawnCircle(142, SPAWN_CIRCLE_NODES);
	populateAsteroidPool(config.maxAliveAsteroids);
	renderer.setSpawnCircle(spawnCircle);
}

void AsteroidManager::populateAsteroidPool(int wantedAlive) {
	for(int i = 0; i < wantedAlive; ++i) {
		asteroids.push_back(new Asteroid(spawnCircle[i]));
		printf("i: %d, %s\n", i, asteroids.at(i)->getOrigin()->toString().c_str());
		fflush(stdout);
		if(aliveCount < wantedAlive && rand() % 100 <= 10) {
			asteroids.at(i)->setAlive();
			++aliveCount;
		}
	}
}

bool AsteroidManager::testShipCollision(Point position, float radius) {

	for(Asteroid* asteroid : asteroids) {
		Vec2d dispVec = Vec2d(*asteroid->getOrigin() - position);

		if(dispVec.getMag() <= asteroid->getSize() + radius)
			return true;
	}
	return false;
}





void AsteroidManager::update(float dt) {
	updatePositions(dt);
	if(aliveCount < config.maxAliveAsteroids) {
		int i = Math::randRange(0, asteroids.size()-1);
		launch(asteroids.at(i));
	}
		
		
}

void AsteroidManager::createAsteroidSpawnCircle(int radius, int nodes) {
	double x, y, theta;

	for(int i = 0; i < nodes; ++i) {
		theta = i/(double)nodes * 2 * M_PI;
		x = radius * cos(theta);
		y = radius * sin(theta);
		spawnCircle[i] = new Point(x, y, 0);
	}
}

void AsteroidManager::killAsteroid(Asteroid* asteroid) {
	--aliveCount;
	asteroid->kill();

	bool colliding = false;

	do {
		int i = Math::randRange(0, SPAWN_CIRCLE_NODES-1);

		for(Asteroid* a : asteroids) {
			asteroid->getOrigin()->translateTo(*spawnCircle[i]);

			Vec2d dispVec = Vec2d(*asteroid->getOrigin() - *a->getOrigin());

			if(dispVec.getMag() <= asteroid->getSize() + a->getSize()) {
				colliding = true;
				break;
			} else colliding = false;
		}
	} while(colliding);
	

}

 // set starting alive
void AsteroidManager::spawnAsteroids() {
	while(aliveCount < config.maxAliveAsteroids) {
		int i = Math::randRange(0, asteroids.size()-1);
		asteroids.at(i)->setAlive();
		++aliveCount;
	}
}

void AsteroidManager::launch(Asteroid* asteroid) {
	Vec2d direction = Vec2d(ship.getOrigin() - *asteroid->getOrigin());
	asteroid->setAlive();
	asteroid->setDirection(direction.getUnitVec());
	++aliveCount;
}

void AsteroidManager::updatePositions(float dt) {
	for(Asteroid* a : asteroids) {
		if(a->isAlive())
			a->move(dt);
		//if out of bounds, kill...
	}
}


Asteroid* AsteroidManager::getAsteroidAt(int i) {
	if(i < asteroids.size())
		return asteroids.at(i);
	return nullptr;
}