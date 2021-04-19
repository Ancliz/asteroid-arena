#include "globals.h"
#include "Engine.h"

Engine::Engine() {
	arena = { WIDTH, HEIGHT, {1,1,1} };
	renderer = Renderer(&arena);
}

void Engine::updateGameState(float dt) {
	if(!keys.escDown) {
		if(keys.forwardsDown)	ship.moveForwards(dt);
		if(keys.backDown)		ship.moveBackwards(dt);
		if(keys.leftDown)		ship.turnLeft(dt, keys.backDown);
		if(keys.rightDown)		ship.turnRight(dt, keys.backDown);
	}
}

void Engine::render() {
	renderer.drawArena();
	renderer.drawShip(ship);
	renderer.drawQuads();
	renderer.drawAsteroids();
}