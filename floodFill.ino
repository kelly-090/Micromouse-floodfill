#include <queue>
#include "Coordinate.h"

int mazeWalls[16][16];
int maze[16][16];
int orient, currX, currY;


void init(){
  log("Running...");
  orient = 0;
  currX = 0;
  currY = 0;
  maze[7][7] = 0;
  maze[7][8] = 0;
  maze[8][7] = 0;
  maze[8][8] = 0;
  floodMaze();
}
void setWall(int left, int right, int forward){
  switch (value) {
        case wallLeft():
            maze[currX][currY] = 1;
            break;
        case wallFront():
            maze[currX][currY] = 2;
            break;
        case wallRight():
            maze[currX][currY] = 3;
            break;
        case 4:
            maze[currX][currY] = 1;
            break;
        case 5:
            maze[currX][currY] = 1;
            break;
        case 6:
            maze[currX][currY] = 1;
            break;
        case wallRight() && wallFront():
            maze[currX][currY] = 7;
            break;
        case wallLeft() && wallFront():
            maze[currX][currY] = 8;
            break;
        case wallLeft() && wallRight():
            maze[currX][currY] = 9;
            break;
        case 9:
            maze[x][y] = 1;
            break;
        case 10:
            maze[x][y] = 1;
            break;
        case 11:
            maze[x][y] = 1;
            break;
        case 12:
            maze[x][y] = 1;
            break;
        case 13:
            maze[x][y] = 1;
            break;
        case 14:
            maze[x][y] = 1;
            break;
        case 15:
            maze[x][y] = 1;
            break;
        default:
            maze[x][y] = 1;
            break;
    }
}

void assignWall(int type, Coordinate wallCoor){
  mazeWalls[wallCoor.get_x()][wallCoor.get_y()];
}

void floodMaze(){
  queue<int> queue;

}

void test(){

}
void setup() {
  Serial.begin(19200);
}

void loop() {
  while (true) {
    int arr[4];
        if (wallLeft()) {
            turnLeft();
        }
        while (wallFront()) {
            turnRight();
        }
        moveForward();
    }
}
