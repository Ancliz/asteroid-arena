
#include "globals.h"
#include "Keyboard.h"
#include "Math.h"
#include "Ship.h"

Key_state keys;

void onSpecialUp(int key, int x, int y) {
    if(config.useArrowKeys) {
        if     (key == GLUT_KEY_UP)     keys.forwardsDown = false;
        else if(key == GLUT_KEY_LEFT)   keys.leftDown = false;
        else if(key == GLUT_KEY_DOWN)   keys.backDown = false;
        else if(key == GLUT_KEY_RIGHT)  keys.rightDown = false;
    }
 
}

void onKeyUp(unsigned char key, int x, int y) {
    if     (key == 27)                      keys.escDown      = false; 
    else if(key == config.forwardsKey)      keys.forwardsDown = false;
    else if(key == config.turnLeftKey)      keys.leftDown     = false; 
    else if(key == config.backwardsKey)     keys.backDown     = false; 
    else if(key == config.turnRightKey)     keys.rightDown    = false;
}

void onKeyDown(unsigned char key, int x, int y) {
    if     (key == 27)                      keys.escDown      = true; 
    else if(key == config.forwardsKey)      keys.forwardsDown = true;
    else if(key == config.turnLeftKey)      keys.leftDown     = true; 
    else if(key == config.backwardsKey)     keys.backDown     = true; 
    else if(key == config.turnRightKey)     keys.rightDown    = true;
    else if(key == 'q')                     exit(EXIT_SUCCESS);
}

void onSpecialDown(int key, int x, int y) {
    if(config.useArrowKeys) {
        if     (key == GLUT_KEY_UP)     keys.forwardsDown = true;
        else if(key == GLUT_KEY_LEFT)   keys.leftDown = true;
        else if(key == GLUT_KEY_DOWN)   keys.backDown = true;
        else if(key == GLUT_KEY_RIGHT)  keys.rightDown = true;
    }
}