#ifndef GLOBALS_H
#define GLOBALS_H

#define WIDTH	200
#define HEIGHT	200
#define AA_RGB	3

struct Configuration {

	// Ship
	float shipColour[AA_RGB];
	float shipOutlineColour[AA_RGB];
	float wallWarnDistance;
	float shipSpeed, shipTurnSpeed;
	char  fowardsKey, turnLeftKey, backwardsKey, turnRightKey;

	// Arena
	bool  useFullWindowForArena;
	float arenaDimensions[2];
	float arenaRGB[AA_RGB];

	// Asteroids
	bool  varyAsteroidSize;
	float asteroidMaxSize;
	float asteroidMinSize;
	float asteroidMinSpeed;
	float asteroidMaxSpeed;
	float timeBetweenWaves;
	float asteroidColour[AA_RGB];
};

extern struct Configuration config;
#endif