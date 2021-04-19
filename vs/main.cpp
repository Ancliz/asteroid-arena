Skip to content

Search…
All gists
Back to GitHub
@Ancliz
@KarlRombauts
KarlRombauts / gist:404ac87abaeb484c24293e28d5aa8129 Secret
Created 22 hours ago • Report abuse
0
0
Code
Revisions 1
< script src = "https://gist.github.com/KarlRombauts/404ac87abaeb484c24293e28d5aa8129.js" > < / script>
Spinning Squares
gistfile1.txt
#include <stdlib.h>
#include <stdio.h>

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

/* Display callback */

static float rotDeg = 0.0f;
static float lastTime = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);

    // Red quad

    glPushMatrix();
    glRotatef(rotDeg, 0, 0, 1);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    {
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(-0.5, 0.5, -0.5);
    }
    glEnd();
    glPopMatrix();

    // Green quad
    glPushMatrix();
    glRotatef(-rotDeg, 0, 0, 1);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    {
        glVertex3f(-0.25, -0.25, -0.75);
        glVertex3f(0.75, -0.25, -0.75);
        glVertex3f(0.75, 0.75, -0.75);
        glVertex3f(-0.25, 0.75, -0.75);
    }
    glEnd();
    glPopMatrix();
    int err;


    while ((err = glGetError()) != GL_NO_ERROR)
        printf("display: %s\n", gluErrorString(err));

    glutSwapBuffers();
}

/* Keyboard callback */
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
    case 'q':
        exit(EXIT_SUCCESS);
        break;
    default:
        break;
    }
}

static void idle_func(void)
{
    int thisTime;

    thisTime = glutGet(GLUT_ELAPSED_TIME);
    rotDeg += (float)(thisTime - lastTime) * 0.1f;
    lastTime = thisTime;

    glutPostRedisplay();
}

void init() {
    /* In this simple program these OpenGL calls only need to be done once, */
    glMatrixMode(GL_PROJECTION);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("I3DG&A - Tutorial 1");
    init();
    /* Display and keyboard callbacks */
    glutIdleFunc(idle_func);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    /* Let glut take over */
    glutMainLoop();
}
@Ancliz

Leave a comment
No file chosen
Attach files by dragging& dropping, selecting or pasting them.
© 2021 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
