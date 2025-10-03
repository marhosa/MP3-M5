#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    //Land
    glColor3f(0.0f, 0.5f, 1.0f);

    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -0.4f);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();


    //Gorilla

    //Back Leg
    glColor3f(0.2f, 0.2f, 0.2f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.746f, -0.16f);
    glVertex2f(-0.7f, -0.16f);
    glVertex2f(-0.7f, -0.4f);
    glVertex2f(-0.746f, -0.4f);
    glEnd();


    //Torso
    glColor3f(0.3f, 0.3f, 0.3f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.83f, -0.128f);
    glVertex2f(-0.65f, -0.128f);
    glVertex2f(-0.65f, -0.295f);
    glVertex2f(-0.83f, -0.295f);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-0.787f, -0.108f);
    glVertex2f(-0.65f, -0.108f);
    glVertex2f(-0.65f, -0.295f);
    glVertex2f(-0.787f, -0.295f);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-0.72f, -0.092f);
    glVertex2f(-0.55f, -0.092f);
    glVertex2f(-0.55f, -0.26f);
    glVertex2f(-0.72f, -0.26f);
    glEnd();


    //Front Leg
    glColor3f(0.2f, 0.2f, 0.2f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.85f, -0.16f);
    glVertex2f(-0.76f, -0.16f);
    glVertex2f(-0.76f, -0.4f);
    glVertex2f(-0.85f, -0.4f);
    glEnd();

    //Front Leg Shadow
    glColor3f(0.145f, 0.145f, 0.145f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.85f, -0.16f);
    glVertex2f(-0.8f, -0.16f);
    glVertex2f(-0.8f, -0.4f);
    glVertex2f(-0.85f, -0.4f);
    glEnd();


    //Arms
    glColor3f(0.25f, 0.25f, 0.25f);

    //Front Arm

    glBegin(GL_POLYGON);
    glVertex2f(-0.7f, -0.14f);
    glVertex2f(-0.61f, -0.14f);
    glVertex2f(-0.61f, -0.4f);
    glVertex2f(-0.7f, -0.4f);
    glEnd();

    //Back Arm

    glBegin(GL_POLYGON);
    glVertex2f(-0.576f, -0.14f);
    glVertex2f(-0.496f, -0.14f);
    glVertex2f(-0.496f, -0.4f);
    glVertex2f(-0.576f, -0.4f);
    glEnd();


    //Arm Shadow
    glColor3f(0.145f, 0.145f, 0.145f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.72f, -0.14f);
    glVertex2f(-0.672f, -0.14f);
    glVertex2f(-0.672f, -0.4f);
    glVertex2f(-0.72f, -0.4f);
    glEnd();

    //Head
    glColor3f(0.2f, 0.2f, 0.2f);

    //Main
    glBegin(GL_POLYGON);
    glVertex2f(-0.66f, -0.032f);
    glVertex2f(-0.505f, -0.032f);
    glVertex2f(-0.505f, -0.23f);
    glVertex2f(-0.66f, -0.23f);
    glEnd();

    //Top
    glBegin(GL_POLYGON);
    glVertex2f(-0.62f, -0.012f);
    glVertex2f(-0.526f, -0.012f);
    glVertex2f(-0.526f, -0.23f);
    glVertex2f(-0.62f, -0.23f);
    glEnd();

    //Head Shadow
    glColor3f(0.145f, 0.145f, 0.145f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.66f, -0.032f);
    glVertex2f(-0.62f, -0.032f);
    glVertex2f(-0.62f, -0.23f);
    glVertex2f(-0.66f, -0.23f);
    glEnd();


    //Face 
    glColor3f(0.6f, 0.6f, 0.6f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.598f, -0.08f);
    glVertex2f(-0.525f, -0.08f);
    glVertex2f(-0.525f, -0.14f);
    glVertex2f(-0.598f, -0.14f);
    glEnd();

    //Mouth
    glColor3f(0.494f, 0.486f, 0.486f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.577f, -0.14f);
    glVertex2f(-0.513f, -0.14f);
    glVertex2f(-0.513f, -0.2);
    glVertex2f(-0.577f, -0.2);
    glEnd();


    //Eyes
    glColor3f(0.0f, 0.0f, 0.0f);

    //Left Eye
    glBegin(GL_POLYGON);
    glVertex2f(-0.5674f, -0.09f);
    glVertex2f(-0.585f, -0.09f);
    glVertex2f(-0.585f, -0.117f);
    glVertex2f(-0.5674f, -0.117f);
    glEnd();

    //Right Eye
    glBegin(GL_POLYGON);
    glVertex2f(-0.553f, -0.09f);
    glVertex2f(-0.5354f, -0.09f);
    glVertex2f(-0.5354f, -0.117f);
    glVertex2f(-0.553f, -0.117f);
    glEnd();


    //Feet
    glColor3f(0.6f, 0.6f, 0.6f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.85f, -0.358f);
    glVertex2f(-0.746f, -0.358f);
    glVertex2f(-0.746f, -0.4f);
    glVertex2f(-0.85f, -0.4f);
    glEnd();

    //Feet Shadow
    glColor3f(0.494f, 0.486f, 0.486f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.85f, -0.358f);
    glVertex2f(-0.78f, -0.358f);
    glVertex2f(-0.78f, -0.4f);
    glVertex2f(-0.85f, -0.4f);
    glEnd();


    //Hand 1
    glColor3f(0.6f, 0.6f, 0.6f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.672f, -0.338f);
    glVertex2f(-0.61f, -0.338f);
    glVertex2f(-0.61f, -0.4f);
    glVertex2f(-0.672f, -0.4f);
    glEnd();


    //Hand 1 Shadow
    glColor3f(0.494f, 0.486f, 0.486f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.735f, -0.338f);
    glVertex2f(-0.672f, -0.338f);
    glVertex2f(-0.672f, -0.4f);
    glVertex2f(-0.735f, -0.4f);
    glEnd();


    //Hand 2
    glColor3f(0.6f, 0.6f, 0.6f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.592f, -0.334f);
    glVertex2f(-0.496f, -0.334f);
    glVertex2f(-0.496f, -0.4f);
    glVertex2f(-0.592f, -0.4f);
    glEnd();

    //Hand 2 Shadow
    glColor3f(0.494f, 0.486f, 0.486f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.598f, -0.334f);
    glVertex2f(-0.55f, -0.334f);
    glVertex2f(-0.55f, -0.4f);
    glVertex2f(-0.598f, -0.4f);
    glEnd();


    //Building

    //Main Outline
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(0.269f, -0.01f);
    glVertex2f(0.508f, -0.01f);
    glVertex2f(0.508f, -0.4f);
    glVertex2f(0.269f, -0.4f);
    glEnd();

    //Main Building
    glColor3f(0.675f, 0.655f, 0.643f);

    glBegin(GL_POLYGON);
    glVertex2f(0.29f, -0.032f);
    glVertex2f(0.49f, -0.032f);
    glVertex2f(0.49f, -0.4f);
    glVertex2f(0.29f, -0.4f);
    glEnd();

    //Main Shadow
    glColor3f(0.490f, 0.478f, 0.443f);
    glBegin(GL_POLYGON);
    glVertex2f(0.42f, -0.032f);
    glVertex2f(0.49f, -0.032f);
    glVertex2f(0.49f, -0.4f);
    glVertex2f(0.42f, -0.4f);
    glEnd();

    //Windows
    glColor3f(0.749f, 0.831f, 0.937f);

    //Window1
    glBegin(GL_POLYGON);
    glVertex2f(0.31f, -0.07f);
    glVertex2f(0.344f, -0.07f);
    glVertex2f(0.344f, -0.12f);
    glVertex2f(0.31f, -0.12f);
    glEnd();

    //Window2
    glBegin(GL_POLYGON);
    glVertex2f(0.363f, -0.07f);
    glVertex2f(0.398f, -0.07f);
    glVertex2f(0.398f, -0.12f);
    glVertex2f(0.363f, -0.12f);
    glEnd();

    //Window3
    glBegin(GL_POLYGON);
    glVertex2f(0.31f, -0.15f);
    glVertex2f(0.344f, -0.15f);
    glVertex2f(0.344f, -0.2f);
    glVertex2f(0.31f, -0.2f);
    glEnd();

    //Window 4
    glBegin(GL_POLYGON);
    glVertex2f(0.363f, -0.15f);
    glVertex2f(0.398f, -0.15f);
    glVertex2f(0.398f, -0.2f);
    glVertex2f(0.363f, -0.2f);
    glEnd();

    //Window 5
    glBegin(GL_POLYGON);
    glVertex2f(0.31f, -0.23f);
    glVertex2f(0.344f, -0.23f);
    glVertex2f(0.344f, -0.28f);
    glVertex2f(0.31f, -0.28f);
    glEnd();

    //Window 6
    glBegin(GL_POLYGON);
    glVertex2f(0.363f, -0.23f);
    glVertex2f(0.398f, -0.23f);
    glVertex2f(0.398f, -0.28f);
    glVertex2f(0.363f, -0.28f);
    glEnd();

    //Window Shadow
    glColor3f(0.553f, 0.627f, 0.816f);

    //Window 1
    glBegin(GL_POLYGON);
    glVertex2f(0.439f, -0.07f);
    glVertex2f(0.474f, -0.07f);
    glVertex2f(0.474f, -0.12f);
    glVertex2f(0.439f, -0.12f);
    glEnd();

    //Window 2
    glBegin(GL_POLYGON);
    glVertex2f(0.439f, -0.15f);
    glVertex2f(0.474f, -0.15f);
    glVertex2f(0.474f, -0.2f);
    glVertex2f(0.439f, -0.2f);
    glEnd();

    //Window 3
    glBegin(GL_POLYGON);
    glVertex2f(0.439f, -0.23f);
    glVertex2f(0.474f, -0.23f);
    glVertex2f(0.474f, -0.28f);
    glVertex2f(0.439f, -0.28f);
    glEnd();

    //Window 4
    glBegin(GL_POLYGON);
    glVertex2f(0.439f, -0.309f);
    glVertex2f(0.474f, -0.309f);
    glVertex2f(0.474f, -0.359f);
    glVertex2f(0.439f, -0.359f);
    glEnd();

    //Door
    glColor3f(0.749f, 0.831f, 0.937f);

    glBegin(GL_POLYGON);
    glVertex2f(0.329f, -0.309f);
    glVertex2f(0.379f, -0.309f);
    glVertex2f(0.379f, -0.4f);
    glVertex2f(0.329f, -0.4f);
    glEnd();


    glFlush();


}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Gorilla Game");

    glClearColor(1.0, 1.0, 1.0, 1.0); // white background

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

