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

#include "../vs/globals.h"
#include "../vs/Keyboard.h"
#include "../vs/Engine.h"

extern void onKeyDown(unsigned char key, int x, int y);
extern void onSpecialDown(int key, int x, int y);
extern void onKeyUp(unsigned char key, int x, int y);
extern void onSpecialUp(int key, int x, int y);

Configuration config =
{
	{1, 0.75, 0},
	{0, 1, 0},
	3,
	2, 2,
	'w', 'a', 's', 'd',
	false,
	{WIDTH, HEIGHT},
	{1,1,1},
	false,
	5,
	1,
	1,
	5,
	20,
	{0.5, 0.7, 0.1}
};

Engine engine = Engine();


void onIdle() {

	double t, dt;
	static double last_t = 0.0;

	t = glutGet(GLUT_ELAPSED_TIME) / 100.0;
	dt = t - last_t;
	last_t = t;


	engine.updateGameState(dt);

	glutPostRedisplay();
}

void onReshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	int w = WIDTH;
	int h = HEIGHT;

	//glOrtho(-10, 10, -10, 10, -1.0, 1.0);
	if(config.useFullWindowForArena) {
		w = width;
		h = height;
	} else {
		w = config.arenaDimensions[0];
		h = config.arenaDimensions[1];
	}

	if(width >= height)
		glOrtho(-w/2 * width/height,w/2 * width/height, -h/2, h/2, -1.0, 1.0);
	else
		glOrtho(-w/2, w/2, -h/2 * height/width, h/2 * height/width, -1.0, 1.0);

	glutPostRedisplay();

}


void onDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	engine.render();

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

