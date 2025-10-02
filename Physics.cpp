#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <string>
#include <GL/freeglut.h>
using namespace std;

// ! Settings you can modify:

// * Velocity:
float speed = 1.0f;

// * Jump Power
float jumpPower = 0.06f;

// * Gravity:
float gravity = -0.003f;

// * Ground level:
float groundY = -0.4f;




// ! Some Settings not recommended to modify:

// * Positions:

// Ground Main:
float ground_x = 0.0f;
float ground_vx = 0.02f;

// Ground Grass:
float grassTop_y = groundY;
float grassBottom_y = grassTop_y - 0.15f;
float grassLeft_x = -1.0f;
float grassRight_x = 3.0f;

// Ground Dirt
float dirtTop_y = grassBottom_y;
float dirtBottom_y = -1.0f;
float dirtLeft_x = grassLeft_x;
float dirtRight_x = grassRight_x;


// Player 
float player_x = 0.0f;
float player_y = groundY;
float player_vx = 0.0f;
float player_vy = 0.0f;

// Obstacle 
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

// * Ground
void Ground() {
    //grassPart
    glBegin(GL_QUADS);
    glColor3ub(61, 163, 38);
    glVertex2f(grassLeft_x + ground_x, grassTop_y);
    glVertex2f(grassRight_x + ground_x, grassTop_y);
    glVertex2f(grassRight_x + ground_x, grassBottom_y);
    glVertex2f(grassLeft_x + ground_x, grassBottom_y);
    glEnd();

    //dirtPart
    glBegin(GL_QUADS);
    glColor3ub(153, 116, 81);
    glVertex2f(dirtLeft_x + ground_x, dirtTop_y);
    glColor3ub(138, 92, 47);
    glVertex2f(dirtRight_x + ground_x, dirtTop_y);
    glColor3ub(148, 119, 90);
    glVertex2f(dirtRight_x + ground_x, dirtBottom_y);
    glColor3ub(112, 70, 36);
    glVertex2f(dirtLeft_x + ground_x, dirtBottom_y);
    glEnd();
}



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










// * Draw Text 
void drawText(float x, float y, const std::string& text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text.c_str()));
}




// * Display MAIN
void display() {
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    



    cloudCluster();
    Ground();
    Obstacle();
    PlayerKun();
    


    // Text OVerlay:
    glColor3f(1.0f, 0.0f, 0.0f);
    drawText(-0.95f, -0.9f, "FPS: 240  |  RTX: ON  |  PacketLoss: 0.0% | Ping: 12ms  | Graphics: Ultra");
    glColor3f(0.0f, 0.0f, 0.0f);
    drawText(-0.95f, 0.9f, "JUMP: w / space");
    drawText(-0.95f, 0.75f, "DASHDOWN: s");
    drawText(-0.95f, 0.60f, "QUIT: ESC");


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

    // * Ground Logic:
    ground_x -= ground_vx * speed;
    if (true) { //ground_x <= -2
        ground_x = 0;
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
    glutCreateWindow("Ultra High Graphic Game Dino Game Pro Max");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}