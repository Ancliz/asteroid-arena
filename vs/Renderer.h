#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "Keyboard.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Arena.h"

#define NUM_ASTEROID_NODES	200


class Renderer {

	private:
		Arena* arena;
		Point* spawnCircle[NUM_ASTEROID_NODES];
		std::vector<Ship*> ships;

	public:
		Renderer();
		Renderer(Arena* arena);

		void drawArena();
		void drawShip(Ship& ship);
		void drawAsteroid(Asteroid* asteroid);
		void drawAsteroids();
		void drawCircle(int radius, int nodes, bool fill);
		void drawSpawnCircle();


		// Debug
		void drawAxis();
		void drawQuads();
		void setSpawnCircle(Point** spawnCircle);
};

#endif