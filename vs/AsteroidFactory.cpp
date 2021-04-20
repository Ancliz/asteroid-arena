//#define _USE_MATH_DEFINES
//#include "AsteroidFactory.h"
//#include "Math.h"
//
//
//
//void AsteroidFactory::populateAsteroidPool(int wantedAlive) {
//	int aliveCount = 0;
//
//	for(int i = 0; i < config.maxAliveAsteroids; ++i) {
//		asteroids.push_back(new Asteroid(spawnPoints[i]));
//
//		if(aliveCount < wantedAlive && rand() % 100 <= 10) {
//			asteroids.at(i)->setAlive();
//			++aliveCount;
//		}
//	}
//}
//
//std::vector<Asteroid*>* AsteroidFactory::getAsteroids() {
//	return &asteroids;
//}
//
//
//Point** AsteroidFactory::createAsteroidSpawnPoints(int radius, int nodes) {
//	double x, y, theta;
//
//	for(int i = 0; i < nodes; ++i) {
//		theta = i/(double)nodes * 2 * M_PI;
//		x = radius * cos(theta);
//		y = radius * sin(theta);
//		spawnPoints[i] = new Point(x, y, 0);
//	}
//	return spawnPoints;
//}
