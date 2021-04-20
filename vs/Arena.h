#ifndef ARENA_H
#define ARENA_H

#include "globals.h"

struct Arena {
	int width, height;
	float topWallColour[AA_RGB];
	float leftWallColour[AA_RGB];
	float bottomWallColour[AA_RGB];
	float rightWallColour[AA_RGB];
	Point shadowBox[4];
};

#endif