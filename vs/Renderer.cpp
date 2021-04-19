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

#define _USE_MATH_DEFINES

#include "Renderer.h"
#include "Keyboard.h"

Renderer::Renderer() {
	Asteroid* a = new Asteroid();
	asteroids.push_back(a);

}

void Renderer::drawShip(Ship& ship) {
	Point points[SHIP_POINTS];
	float rgb_fill[SHIP_RGB];
	float rgb_out[SHIP_RGB];

	for (int i = 0; i < SHIP_POINTS; ++i)
		points[i] = ship.getPoints()[i];

	for (int i = 0; i < SHIP_RGB; ++i)
		rgb_fill[i] = ship.getFill()[i];

	for (int i = 0; i < SHIP_RGB; ++i)
		rgb_out[i] = ship.getOutline()[i];


	// Draw body
	glPushMatrix();

	glTranslatef(ship.getOrigin()->getX(), ship.getOrigin()->getY(), 0);
	glRotated(ship.getAngleFromX()*1.0, 0, 0, 1);

	glScaled(20, 20, 0.0);

	drawAxis();
	glColor3f(rgb_fill[0], rgb_fill[1], rgb_fill[2]);
	glBegin(GL_TRIANGLES);
	{
		glVertex3f(points[1].getX(), points[1].getY(), 0.0);
		glVertex3f(points[2].getX(), points[2].getY(), 0.0);
		glVertex3f(points[3].getX(), points[3].getY(), 0.0);

		glVertex3f(points[1].getX(), points[1].getY(), 0.0);
		glVertex3f(points[3].getX(), points[3].getY(), 0.0);
		glVertex3f(points[4].getX(), points[4].getY(), 0.0);
	}
	glEnd();

	// Draw Outline
	glColor3f(rgb_out[0], rgb_out[1], rgb_out[2]);
	//glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	{
		glVertex3f(points[1].getX(), points[1].getY(), 0.0);
		glVertex3f(points[2].getX(), points[2].getY(), 0.0);
		glVertex3f(points[3].getX(), points[3].getY(), 0.0);
		glVertex3f(points[4].getX(), points[4].getY(), 0.0);
	}
	glEnd();
	glPopMatrix();
}

void Renderer::drawAsteroids() {
	for(Asteroid* a : asteroids)
		drawAsteroid(a);
}


void Renderer::drawAsteroid(Asteroid* asteroid) {
	glPushMatrix();
	glScalef(20,20,0);

	glColor3f(0.545, 0.271, 0.0745);
	glBegin(GL_POLYGON);
	
	float x, y, theta;
	for(int i = 0; i < 20; ++i) {
		theta = i/(float)20 * 2 * M_PI;
		x = 4 * cos(theta);
		y = 4 * sin(theta);
		glVertex3f(x,y,0);
	}
	glEnd();
	glPopMatrix();

}

void Renderer::drawQuads() {
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	{
		glVertex3f(-width / 2, 0, 0);
		glVertex3f(width / 2, 0, 0.0);
		glVertex3f(0, -height / 2, 0.0);
		glVertex3f(0, height / 2, 0.0);
	}
	glEnd();
	glPopMatrix();
}

void Renderer::drawAxis() {
	glPushMatrix();
	glScalef(3, 3, 0);
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);
	glEnd();
	glPopMatrix();
}