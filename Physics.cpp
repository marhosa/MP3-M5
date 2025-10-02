#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

// ! Settings you can modify:

// * Velocity:
float speed = 1.0f;

// * Jump Power
float jumpPower = 0.06f;

// * Gravity:
float gravity = -0.003f;

// * Ground level:
float groundY = -0.5f;




// ! Some Settings not recommended to modify:

// * Positions:
// Player Anchor Point
float player_x = 0.0f;
float player_y = groundY;
float player_vx = 0.0f;
float player_vy = 0.0f;

// Obstacle Anchor Point
float obstacle_x = -1.0f;
float obstacle_y = groundY;
float obstacle_vx = 0.02f;
float obstacle_vy = 0.0f;

// Clouds
float bg_x = 0.0f;
float bg_y = 0.0f;
float bg_vx = 0.003f;
float bg_vy = 0.0f;





// ! Below this line contains all codes to run, not reco to modify



// * Cloud
// Draw a circle
  void drawCircle(float cx, float cy, float r, int num_segments) {
      glBegin(GL_POLYGON);
      glColor3ub(255,255,255);
      for (int i = 0; i < num_segments; i++) {
          float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
          float x = r * cosf(theta);
          float y = r * sinf(theta);
          glVertex2f(cx + x, cy + y);
      }
      glEnd();
  }
// Draw a Cloud made of 3 circles
  void drawCloud(float x, float y, float size) {
    
      drawCircle(x, y, size, 40);
      drawCircle(x + size * 0.8f, y + size * 0.4f, size * 1.2f, 40);
      drawCircle(x + size * 1.6f, y, size, 40);
  }
  void cloudCluster() {
      // 6 non-overlapping small clouds
    drawCloud(-0.9f + bg_x, 0.40f + bg_y, 0.05f);
    drawCloud(-0.6f + bg_x, 0.55f + bg_y, 0.05f);
    drawCloud(-0.3f + bg_x, 0.45f + bg_y, 0.05f);
    drawCloud( 0.0f + bg_x, 0.60f + bg_y, 0.05f);
    drawCloud( 0.4f + bg_x, 0.42f + bg_y, 0.05f);
    drawCloud(0.7f + bg_x, 0.55f + bg_y, 0.05f);

    //other 6 at last part for illusion
    drawCloud(-0.9f + 2 + bg_x, 0.40f + bg_y, 0.05f);
    drawCloud(-0.6f + 2 + bg_x, 0.55f + bg_y, 0.05f);
    drawCloud(-0.3f + 2 + bg_x, 0.45f + bg_y, 0.05f);
    drawCloud( 0.0f + 2 + bg_x, 0.60f + bg_y, 0.05f);
    drawCloud( 0.4f + 2 + bg_x, 0.42f + bg_y, 0.05f);
    drawCloud(0.7f + 2 + bg_x, 0.55f + bg_y, 0.05f);

}



// * Player
void PlayerKun() {
    glPointSize(20.0);

    glBegin(GL_POINTS);
    glColor3ub(0, 0, 255);
    glVertex2f(0.0 + player_x, 0.0 + player_y); // dot 1
    glEnd();
}



// * Obstacle
void Obstacle() {
    glPointSize(40.0);

    glBegin(GL_POINTS);
    glColor3ub(0, 255, 255);
    glVertex2f(0.0 + obstacle_x, 0.0 + obstacle_y); // dot 1
    glEnd();
}




// * Background
void Background() {
    
}


// * Display MAIN
void display() {
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    cloudCluster();
    Obstacle();
    PlayerKun();
    

    glFlush();
}




// * Update movement
void update(int value) {

    // * Player Logic:

    // Apply gravity
    player_vy += gravity;
    player_y += player_vy;

    // Stop at ground
    if (player_y < groundY) {
        player_y = groundY;
        player_vy = 0.0f;
    }



    // * Obstacle Logic:

    obstacle_x -= obstacle_vx * speed;
    if (obstacle_x <= -1) {
        obstacle_x = 1;
    }



    // * Clouds Logic:
    bg_x -= bg_vx * speed;
    if (bg_x <= -2) {
        bg_x = 0;
    }


    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
    
}






// * Keyboard controls
void keyboard(unsigned char key, int x, int y) {
    if (key == 119 || key == 32) { // w key
        if (player_y <= groundY + 0.001f) { 
            // only jump if on ground
            player_vy = jumpPower;
        }
    }
    if (key == 115) { // w key
        if (!(player_y <= groundY + 0.001f)) { 
            // only jump if on ground
            player_vy =  -jumpPower;
        }
    }
    if (key == 27) { // ESC to exit
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Jump Simulation");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}