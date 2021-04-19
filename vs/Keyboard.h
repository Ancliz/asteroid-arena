#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "GL/freeglut_std.h";

struct Key_state {
	bool forwardsDown, leftDown, backDown, rightDown;
	bool escDown;
};

extern Key_state keys;

#endif