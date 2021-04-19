#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include "Keyboard.h"
#include "Ship.h"
#include "Asteroid.h"


class Renderer {

	private:
		std::vector<Ship*> ships;
		std::vector<Asteroid*> asteroids;

	public:
		Renderer();

		void drawShip(Ship& ship);
		void drawAsteroid(Asteroid* asteroid);
		void drawAsteroids();

		// Debug
		void drawAxis();
		void drawQuads();
};

#endif