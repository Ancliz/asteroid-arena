#ifndef ASTEROID_LAUNCHER_H
#define ASTEROUD_LAUNCHER_H

#include <vector>
#include "Asteroid.h"
#include "Ship.h"


class AsteroidManager {

	private:
	std::vector<Asteroid*> asteroids;

	public:
		void launch(Asteroid* asteroid);
		friend void Renderer::drawAsteroid(Asteroid* asteroid);


};

#endif