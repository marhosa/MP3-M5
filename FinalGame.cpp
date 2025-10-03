#include <GL/glut.h> // Requires FreeGlut
#include <GL/freeglut.h> // Requires FreeGlut
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

// ! Settings you can modify:

// * Velocity:
float speed = 1.0f;

// * Jump Power
float jumpPower = 0.06f;

// * Gravity:
float gravity = -0.0018f;

// * Ground level:
float groundY = -0.4f;




// ! Some Settings not recommended to modify:

// * Game Logic:
float startGame = false;
int tickCount = 0;
int allTimeScore = 0;
int currentPlayerScore = 0;

// * For Bugs:
bool playedOnce = false;

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
float obstacleStartingPosition = 1 + 0.508f;
float obstacle_x = obstacleStartingPosition + 2.0f;
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
    // Adjusts gorilla position
    float x_adjuster = player_x;
    float y_adjuster = player_y + 0.32f;

    //Back Leg
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.746f + x_adjuster, -0.16f + y_adjuster);
    glVertex2f(-0.7f + x_adjuster, -0.16f + y_adjuster);
    glVertex2f(-0.7f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(-0.746f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

    //Torso
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.83f + x_adjuster, -0.128f + y_adjuster);
    glVertex2f(-0.65f + x_adjuster, -0.128f + y_adjuster);
    glVertex2f(-0.65f + x_adjuster, -0.295f + y_adjuster);
    glVertex2f(-0.83f + x_adjuster, -0.295f + y_adjuster);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.787f + x_adjuster, -0.108f + y_adjuster);
    glVertex2f(-0.65f + x_adjuster, -0.108f + y_adjuster);
    glVertex2f(-0.65f + x_adjuster, -0.295f + y_adjuster);
    glVertex2f(-0.787f + x_adjuster, -0.295f + y_adjuster);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.72f + x_adjuster, -0.092f + y_adjuster);
    glVertex2f(-0.55f + x_adjuster, -0.092f + y_adjuster);
    glVertex2f(-0.55f + x_adjuster, -0.26f + y_adjuster);
    glVertex2f(-0.72f + x_adjuster, -0.26f + y_adjuster);
    glEnd();

    //Front Leg
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85f + x_adjuster, -0.16f + y_adjuster);
    glVertex2f(-0.76f + x_adjuster, -0.16f + y_adjuster);
    glVertex2f(-0.76f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(-0.85f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

    //Front Leg Shadow
    glColor3f(0.145f, 0.145f, 0.145f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85f + x_adjuster, -0.16f + y_adjuster);
    glVertex2f(-0.8f + x_adjuster, -0.16f + y_adjuster);
    glVertex2f(-0.8f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(-0.85f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

    //Front Arm
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7f + x_adjuster, -0.14f + y_adjuster);
    glVertex2f(-0.61f + x_adjuster, -0.14f + y_adjuster);
    glVertex2f(-0.61f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(-0.7f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

    //Back Arm
    glBegin(GL_POLYGON);
    glVertex2f(-0.576f + x_adjuster, -0.14f + y_adjuster);
    glVertex2f(-0.496f + x_adjuster, -0.14f + y_adjuster);
    glVertex2f(-0.496f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(-0.576f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

    //Arm Shadow
    glColor3f(0.145f, 0.145f, 0.145f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.72f + x_adjuster, -0.14f + y_adjuster);
    glVertex2f(-0.672f + x_adjuster, -0.14f + y_adjuster);
    glVertex2f(-0.672f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(-0.72f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

    //Head Main
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.66f + x_adjuster, -0.032f + y_adjuster);
    glVertex2f(-0.505f + x_adjuster, -0.032f + y_adjuster);
    glVertex2f(-0.505f + x_adjuster, -0.23f + y_adjuster);
    glVertex2f(-0.66f + x_adjuster, -0.23f + y_adjuster);
    glEnd();

    //Head Top
    glBegin(GL_POLYGON);
    glVertex2f(-0.62f + x_adjuster, -0.012f + y_adjuster);
    glVertex2f(-0.526f + x_adjuster, -0.012f + y_adjuster);
    glVertex2f(-0.526f + x_adjuster, -0.23f + y_adjuster);
    glVertex2f(-0.62f + x_adjuster, -0.23f + y_adjuster);
    glEnd();

    //Head Shadow
    glColor3f(0.145f, 0.145f, 0.145f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.66f + x_adjuster, -0.032f + y_adjuster);
    glVertex2f(-0.62f + x_adjuster, -0.032f + y_adjuster);
    glVertex2f(-0.62f + x_adjuster, -0.23f + y_adjuster);
    glVertex2f(-0.66f + x_adjuster, -0.23f + y_adjuster);
    glEnd();

    //Face
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.598f + x_adjuster, -0.08f + y_adjuster);
    glVertex2f(-0.525f + x_adjuster, -0.08f + y_adjuster);
    glVertex2f(-0.525f + x_adjuster, -0.14f + y_adjuster);
    glVertex2f(-0.598f + x_adjuster, -0.14f + y_adjuster);
    glEnd();

    //Mouth
    glColor3f(0.494f, 0.486f, 0.486f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.577f + x_adjuster, -0.14f + y_adjuster);
    glVertex2f(-0.513f + x_adjuster, -0.14f + y_adjuster);
    glVertex2f(-0.513f + x_adjuster, -0.2f + y_adjuster);
    glVertex2f(-0.577f + x_adjuster, -0.2f + y_adjuster);
    glEnd();

    //Eyes
    glColor3f(0.0f, 0.0f, 0.0f);
    //Left Eye
    glBegin(GL_POLYGON);
    glVertex2f(-0.5674f + x_adjuster, -0.09f + y_adjuster);
    glVertex2f(-0.585f + x_adjuster, -0.09f + y_adjuster);
    glVertex2f(-0.585f + x_adjuster, -0.117f + y_adjuster);
    glVertex2f(-0.5674f + x_adjuster, -0.117f + y_adjuster);
    glEnd();
    //Right Eye
    glBegin(GL_POLYGON);
    glVertex2f(-0.553f + x_adjuster, -0.09f + y_adjuster);
    glVertex2f(-0.5354f + x_adjuster, -0.09f + y_adjuster);
    glVertex2f(-0.5354f + x_adjuster, -0.117f + y_adjuster);
    glVertex2f(-0.553f + x_adjuster, -0.117f + y_adjuster);
    glEnd();

    //Feet
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85f + x_adjuster, -0.358f + y_adjuster);
    glVertex2f(-0.746f + x_adjuster, -0.358f + y_adjuster);
    glVertex2f(-0.746f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(-0.85f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

    //Feet Shadow
    glColor3f(0.494f, 0.486f, 0.486f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85f + x_adjuster, -0.358f + y_adjuster);
    glVertex2f(-0.78f + x_adjuster, -0.358f + y_adjuster);
    glVertex2f(-0.78f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(-0.85f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

    //Hand 1
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.672f + x_adjuster, -0.338f + y_adjuster);
    glVertex2f(-0.61f + x_adjuster, -0.338f + y_adjuster);
    glVertex2f(-0.61f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(-0.672f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

    //Hand 1 Shadow
    glColor3f(0.494f, 0.486f, 0.486f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.735f + x_adjuster, -0.338f + y_adjuster);
    glVertex2f(-0.672f + x_adjuster, -0.338f + y_adjuster);
    glVertex2f(-0.672f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(-0.735f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

    //Hand 2
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.592f + x_adjuster, -0.334f + y_adjuster);
    glVertex2f(-0.496f + x_adjuster, -0.334f + y_adjuster);
    glVertex2f(-0.496f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(-0.592f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

    //Hand 2 Shadow
    glColor3f(0.494f, 0.486f, 0.486f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.598f + x_adjuster, -0.334f + y_adjuster);
    glVertex2f(-0.55f + x_adjuster, -0.334f + y_adjuster);
    glVertex2f(-0.55f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(-0.598f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

}



// * Obstacle
void Obstacle() {

    float x_adjuster = -(0.508f) + obstacle_x;
    float y_adjuster = 0.32f + obstacle_y;

    // Building

    // Main Outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.269f + x_adjuster, -0.01f + y_adjuster);
    glVertex2f(0.508f + x_adjuster, -0.01f + y_adjuster);
    glVertex2f(0.508f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(0.269f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

    // Main Building
    glColor3f(0.675f, 0.655f, 0.643f);
    glBegin(GL_POLYGON);
    glVertex2f(0.29f + x_adjuster, -0.032f + y_adjuster);
    glVertex2f(0.49f + x_adjuster, -0.032f + y_adjuster);
    glVertex2f(0.49f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(0.29f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

    // Main Shadow
    glColor3f(0.490f, 0.478f, 0.443f);
    glBegin(GL_POLYGON);
    glVertex2f(0.42f + x_adjuster, -0.032f + y_adjuster);
    glVertex2f(0.49f + x_adjuster, -0.032f + y_adjuster);
    glVertex2f(0.49f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(0.42f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

    // Windows
    glColor3f(0.749f, 0.831f, 0.937f);

    // Window 1
    glBegin(GL_POLYGON);
    glVertex2f(0.31f + x_adjuster, -0.07f + y_adjuster);
    glVertex2f(0.344f + x_adjuster, -0.07f + y_adjuster);
    glVertex2f(0.344f + x_adjuster, -0.12f + y_adjuster);
    glVertex2f(0.31f + x_adjuster, -0.12f + y_adjuster);
    glEnd();

    // Window 2
    glBegin(GL_POLYGON);
    glVertex2f(0.363f + x_adjuster, -0.07f + y_adjuster);
    glVertex2f(0.398f + x_adjuster, -0.07f + y_adjuster);
    glVertex2f(0.398f + x_adjuster, -0.12f + y_adjuster);
    glVertex2f(0.363f + x_adjuster, -0.12f + y_adjuster);
    glEnd();

    // Window 3
    glBegin(GL_POLYGON);
    glVertex2f(0.31f + x_adjuster, -0.15f + y_adjuster);
    glVertex2f(0.344f + x_adjuster, -0.15f + y_adjuster);
    glVertex2f(0.344f + x_adjuster, -0.2f + y_adjuster);
    glVertex2f(0.31f + x_adjuster, -0.2f + y_adjuster);
    glEnd();

    // Window 4
    glBegin(GL_POLYGON);
    glVertex2f(0.363f + x_adjuster, -0.15f + y_adjuster);
    glVertex2f(0.398f + x_adjuster, -0.15f + y_adjuster);
    glVertex2f(0.398f + x_adjuster, -0.2f + y_adjuster);
    glVertex2f(0.363f + x_adjuster, -0.2f + y_adjuster);
    glEnd();

    // Window 5
    glBegin(GL_POLYGON);
    glVertex2f(0.31f + x_adjuster, -0.23f + y_adjuster);
    glVertex2f(0.344f + x_adjuster, -0.23f + y_adjuster);
    glVertex2f(0.344f + x_adjuster, -0.28f + y_adjuster);
    glVertex2f(0.31f + x_adjuster, -0.28f + y_adjuster);
    glEnd();

    // Window 6
    glBegin(GL_POLYGON);
    glVertex2f(0.363f + x_adjuster, -0.23f + y_adjuster);
    glVertex2f(0.398f + x_adjuster, -0.23f + y_adjuster);
    glVertex2f(0.398f + x_adjuster, -0.28f + y_adjuster);
    glVertex2f(0.363f + x_adjuster, -0.28f + y_adjuster);
    glEnd();

    // Window Shadow
    glColor3f(0.553f, 0.627f, 0.816f);

    // Window 1
    glBegin(GL_POLYGON);
    glVertex2f(0.439f + x_adjuster, -0.07f + y_adjuster);
    glVertex2f(0.474f + x_adjuster, -0.07f + y_adjuster);
    glVertex2f(0.474f + x_adjuster, -0.12f + y_adjuster);
    glVertex2f(0.439f + x_adjuster, -0.12f + y_adjuster);
    glEnd();

    // Window 2
    glBegin(GL_POLYGON);
    glVertex2f(0.439f + x_adjuster, -0.15f + y_adjuster);
    glVertex2f(0.474f + x_adjuster, -0.15f + y_adjuster);
    glVertex2f(0.474f + x_adjuster, -0.2f + y_adjuster);
    glVertex2f(0.439f + x_adjuster, -0.2f + y_adjuster);
    glEnd();

    // Window 3
    glBegin(GL_POLYGON);
    glVertex2f(0.439f + x_adjuster, -0.23f + y_adjuster);
    glVertex2f(0.474f + x_adjuster, -0.23f + y_adjuster);
    glVertex2f(0.474f + x_adjuster, -0.28f + y_adjuster);
    glVertex2f(0.439f + x_adjuster, -0.28f + y_adjuster);
    glEnd();

    // Window 4
    glBegin(GL_POLYGON);
    glVertex2f(0.439f + x_adjuster, -0.309f + y_adjuster);
    glVertex2f(0.474f + x_adjuster, -0.309f + y_adjuster);
    glVertex2f(0.474f + x_adjuster, -0.359f + y_adjuster);
    glVertex2f(0.439f + x_adjuster, -0.359f + y_adjuster);
    glEnd();

    // Door
    glColor3f(0.749f, 0.831f, 0.937f);
    glBegin(GL_POLYGON);
    glVertex2f(0.329f + x_adjuster, -0.309f + y_adjuster);
    glVertex2f(0.379f + x_adjuster, -0.309f + y_adjuster);
    glVertex2f(0.379f + x_adjuster, -0.4f + y_adjuster);
    glVertex2f(0.329f + x_adjuster, -0.4f + y_adjuster);
    glEnd();

    glFlush();
}


// * Draw Text 
// doc hadji draw a text function
void drawText(float x, float y, const std::string& text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text.c_str()));
}
// text overlay
void textOverlay() {
    glColor3f(1.0f, 0.0f, 0.0f);

    // game stats
    string message = string("FPS: 240  |  RTX: ON  |  PacketLoss: 0.0% | Ping: 12ms  | Graphics: Ultra | Ticks: " + to_string(tickCount));
    drawText(-0.95f, -0.9f, message);

    // show score
    glColor3ub(110, 107, 96);
    drawText(-0.897f, 0.774f, string("SCORE: " + to_string(currentPlayerScore))); //shadow
    glColor3ub(255, 216, 0);
    drawText(-0.9f, 0.78f, string("SCORE: " + to_string(currentPlayerScore)));
}



//* MENU
void textMessage() {
    // Adjust Description
    float xadj = -0.25f;
    float yadj = 0.6f;

    // Description
    glColor3f(0.0f, 0.0f, 0.0f);
    drawText(0.0f + xadj, 0.08f + yadj,  "   KING KONG SIMULATOR  ");
    drawText(0.0f + xadj, 0.0f + yadj,   "  PRESS SPACE TO START");
    drawText(0.0f + xadj, -0.16f + yadj, "        CONTROLS");
    drawText(0.0f + xadj, -0.24f + yadj, "            JUMP:      'W' or 'A'");
    drawText(0.0f + xadj, -0.32f + yadj, "            DASH DOWN: 'S' or 'D'");

    // Devs
    drawText(0.2f, -0.5f, "                   MADE BY");
    drawText(0.2f, -0.58f, "Game Assets Developer - Luis Anton Gonzales");
    drawText(0.2f, -0.64f, "Game Engine Developer - Matthew Rhomar Santos");

    
    if(playedOnce){ // only show these if game is played at least once
        drawText(-0.9f, 0.7f, string("ALL TIME HIGH SCORE: " + to_string(allTimeScore)));
        drawText(-0.9f, 0.78f, string("YOUR SCORE: " + to_string(currentPlayerScore)));
    }
    

    PlayerKun(); // shows gorilla jumping sa gilid
}




// * Display MAIN
void display() {

    if (startGame) {
        glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        cloudCluster();
        Ground();
        textOverlay(); 
        PlayerKun();
        Obstacle();
        
    }

    else {
        glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        tickCount = 0;
        textMessage();
    }

    glFlush();
}




// * Game Engine / Movement Engine
void update(int value) {

    // * tick count updater
    tickCount += 1;


    // * adapt speed based on time playing
    speed = 1 + float(tickCount/600);

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
        obstacle_x = obstacleStartingPosition;
        // increment score per obstacle passed
        currentPlayerScore++;
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


    // * Hit Box Simulator

    // player hitbox
    float playerWidth = 0.28f;
    float playerHeight = 0.4f;

    // obstacle hitbox
    float obstacleWidth = 0.22f;
    float obstacleHeight = 0.4f;

    // player anchor point adjuster
    float pAdjust_x = -0.55f;
    float pAdjust_y = 0.22f;

    if (player_x + playerWidth/2 + pAdjust_x > obstacle_x - obstacleWidth/2 &&
        player_x - playerWidth/2 + pAdjust_x < obstacle_x + obstacleWidth/2 &&
        player_y + playerHeight/2 + pAdjust_y > obstacle_y &&
        player_y - playerHeight/2 + pAdjust_y < obstacle_y + obstacleHeight) 
    {
        
        startGame = false;
        obstacle_x = obstacleStartingPosition;

        // * Set Player Scores

        // new high score if higher than original
        if (currentPlayerScore > allTimeScore) {
            allTimeScore = currentPlayerScore;
        }

    }



    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
    
}






// * Keyboard controls
void keyboard(unsigned char key, int x, int y) {
    if (key == 119 || key == 97) { // w and akey
        if (player_y <= groundY + 0.001f) { 
            // only jump if on ground
            player_vy = jumpPower;
        }
    }
    if (key == 115 || key == 100) { // s and d key
        if (!(player_y <= groundY + 0.001f)) { 
            // dash down
            player_vy =  -jumpPower * 2;
        }
    }
    if (key == 27) { // ESC to exit
        exit(0);
    }
    if (key == 32) { // Space bar to start game
        startGame = true;
        //reset current Player Score at losing
        currentPlayerScore = 0;
        //game is played once if spacebar is pressed
        playedOnce = true;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1600, 900);
    glutCreateWindow("Ultra High Graphic Game King Kong Game Pro Max");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}