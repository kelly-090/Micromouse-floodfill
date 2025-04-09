#include <queue>

int mazeWalls[16][16];
int mazeValues[16][16];
int orient, currX, currY;


void init(){
  log("Running...");
  orient = 0;
  currX = 0;
  currY = 0;
  mazeValues[7][7] = 0;
  mazeValues[7][8] = 0;
  mazeValues[8][7] = 0;
  mazeValues[8][8] = 0;
  floodMaze();
}


void assignWall(int type, Coordinate wallCoor){
  mazeWalls[c.x][y];
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
