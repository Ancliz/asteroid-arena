#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "Keyboard.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Arena.h"


class Renderer {

	private:
		Arena* arena;
		std::vector<Ship*> ships;

	public:
		Renderer();
		Renderer(Arena* arena);

		void drawArena();
		void drawShip(Ship& ship);
		void drawAsteroid(Asteroid* asteroid);
		void drawAsteroids();
		void drawCircle(int radius, int nodes);

		// Debug
		void drawAxis();
		void drawQuads();
};

#endif