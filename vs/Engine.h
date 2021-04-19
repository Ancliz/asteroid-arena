#ifndef ENGINE_H
#define ENGINE_H

#include "Asteroid.h"
#include "Ship.h"
#include "Keyboard.h"
#include "Configuration.h"
#include "Math.h"
#include "Renderer.h"
#include "Arena.h"

class Engine {

	private:
			Renderer renderer;
			Arena arena;
			
	public:
		Engine();
		void updateGameState(float dt);
		void render();
};

#endif