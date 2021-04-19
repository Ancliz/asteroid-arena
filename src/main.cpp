#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef _INCL_GLUT
#define _INCL_GLUT
#if _WIN32
# include <windows.h>
#endif
#if __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#else
# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>
#endif
#endif

#include "../vs/Ship.h"
#include "../vs/Renderer.h"
#include "../vs/Keyboard.h"


extern void onKeyDown(unsigned char key, int x, int y);
extern void onSpecialDown(int key, int x, int y);
extern void onKeyUp(unsigned char key, int x, int y);
extern void onSpecialUp(int key, int x, int y);

Renderer renderer = Renderer();

void onIdle() {

	double t, dt;
	static double last_t = 0.0;

	t = glutGet(GLUT_ELAPSED_TIME) / 1000;
	dt = t - last_t;
	last_t = t;

	if(!keys.escDown) {
		if(keys.forwardsDown)	ship.moveForwards(dt);
		if(keys.backDown)		ship.moveBackwards(dt);
		if(keys.leftDown)		ship.turnLeft(dt, keys.backDown);
		if(keys.rightDown)		ship.turnRight(dt, keys.backDown);
	}
	glutPostRedisplay();
}

void onReshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-0.5 * width, width / 2, -0.5 * height, height / 2, -1.0, 1.0);

	glutPostRedisplay();

}


void onDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	renderer.drawShip(ship);
	renderer.drawQuads();
	//renderer.drawAsteroids();

	int err;
	while ((err = glGetError()) != GL_NO_ERROR)
		printf("display: %s\n", gluErrorString(err));

	glutSwapBuffers();
}


void init(int* argc, char** argv) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Asteroid Arena");
	//glutFullScreen();
	glEnable(GL_DEPTH_TEST);

	glutReshapeFunc(onReshape);

	glutIdleFunc(onIdle);
	glutDisplayFunc(onDisplay);

	glutKeyboardFunc(onKeyDown);
	glutSpecialFunc(onSpecialDown);
	glutKeyboardUpFunc(onKeyUp);
	glutSpecialUpFunc(onSpecialUp);
}

int main(int argc, char** argv) {
	init(&argc, argv);
	glutMainLoop();
	return(EXIT_SUCCESS);
}

