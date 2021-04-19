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
#include "AsteroidManager.h"

Renderer::Renderer(Arena* arena) : arena(arena) {}
Renderer::Renderer() {}

void Renderer::drawArena() {

	glPushMatrix();
	glColor3f(arena->colour[0], arena->colour[1], arena->colour[2]);
	//glScalef(100,100,0);
	glBegin(GL_LINE_LOOP);
	{
		glVertex3f(-arena->width/2, -arena->height/2, 0);
		glVertex3f(arena->width/2, -arena->height/2, 0);
		glVertex3f(arena->width/2, arena->height/2, 0);
		glVertex3f(-arena->width/2, arena->height/2, 0);
	}
	glEnd();
	glPopMatrix();
}
void Renderer::drawShip(Ship& ship) {
	Point points[SHIP_POINTS];
	float rgb_fill[AA_RGB];
	float rgb_out[AA_RGB];

	for (int i = 0; i < SHIP_POINTS; ++i)
		points[i] = ship.getPoints()[i];

	for (int i = 0; i < AA_RGB; ++i)
		rgb_fill[i] = ship.getFill()[i];

	for (int i = 0; i < AA_RGB; ++i)
		rgb_out[i] = ship.getOutline()[i];


	// Draw body
	glPushMatrix();

	glTranslatef(ship.getOrigin()->getX(), ship.getOrigin()->getY(), 0);
	glRotated(ship.getAngleFromX() * 180.0/M_PI, 0, 0, 1);

	glScaled(2.5, 2.5, 0.0);

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
//	drawAsteroid()
}

void Renderer::drawCircle(int radius, int nodes) {
	glBegin(GL_POLYGON);
	float x, y, theta;

	for(int i = 0; i < nodes; ++i) {
		theta = i/(float)nodes * 2 * M_PI;
		x = radius * cos(theta);
		y = radius * sin(theta);
		glVertex3f(x, y, 0);
	}
	glEnd();
}

void Renderer::drawAsteroid(Asteroid* asteroid) {
	glPushMatrix();
	glColor3f(0.545, 0.271, 0.0745);
	glTranslatef(-5,0,0);
	glScalef(5,5,0);
	drawCircle(2, 10);
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