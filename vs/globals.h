#ifndef GLOBALS_H
#define GLOBALS_H

#define WIDTH	200
#define HEIGHT	200
#define AA_RGB	3

#define SPAWN_CIRCLE_NODES	200

extern bool gameOver;

struct Configuration {

	// Ship
	float shipColour[AA_RGB];
	float shipOutlineColour[AA_RGB];
	float wallWarnDistance;
	float shipSpeed, shipTurnSpeed;
	bool  useArrowKeys;
	char  forwardsKey, turnLeftKey, backwardsKey, turnRightKey;

	// Arena
	int   arenaDim[2];
	float arenaRGB[AA_RGB];

	// Asteroids
	int   maxAliveAsteroids;
	bool  varyAsteroidSize;
	int   asteroidMaxHP;
	int   asteroidMinHP;
	int   asteroidMaxSize;
	int   asteroidMinSize;
	float asteroidMinSpeed;
	float asteroidMaxSpeed;
	float timeBetweenWaves;
	float asteroidColour[AA_RGB];
};

extern struct Configuration config;
#endif