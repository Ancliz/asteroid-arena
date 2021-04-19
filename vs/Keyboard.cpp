#include <stdlib.h>
#include <iostream>
#include "Keyboard.h"
#include "Math.h"
#include "Ship.h"

Key_state keys;

void onSpecialUp(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:	    keys.forwardsDown = false; break;
        case GLUT_KEY_LEFT:	    keys.leftDown    = false; break;
        case GLUT_KEY_DOWN:	    keys.backDown    = false; break;
        case GLUT_KEY_RIGHT:    keys.rightDown   = false; break;
        default: break;
    }
}

void onKeyUp(unsigned char key, int x, int y) {
    switch (key) {
        case 27: keys.escDown = false;  break;
        default:                        break;
    }
}

void onKeyDown(unsigned char key, int x, int y) {
    switch (key) {

        case 27:    keys.escDown = true; break;
        case 'q':   exit(EXIT_SUCCESS);  break;
        default:                         break;
        }
}

void onSpecialDown(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:		    keys.forwardsDown = true; break;
        case GLUT_KEY_LEFT:	        keys.leftDown     = true; break;
        case GLUT_KEY_DOWN:	        keys.backDown     = true; break;
        case GLUT_KEY_RIGHT:	    keys.rightDown    = true; break;
        default: break;
    }
}