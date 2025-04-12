#include "API.h"

void findWallFrontOrientation(){
    switch{
          case wallLeft():
              mazeWalls[currX][currY] = 1;
              break;
          case wallFront():
              mazeWalls[currX][currY] = 2;
              break;
          case wallRight():
              mazeWalls[currX][currY] = 3;
              break;
          case wallRight() && wallFront():
              mazeWalls[currX][currY] = 7;
              break;
          case wallLeft() && wallFront():
              mazeWalls[currX][currY] = 8;
              break;
          case wallLeft() && wallRight():
              mazeWalls[currX][currY] = 9;
              break;
          case wallRight() && wallFront() && wallLeft():
              mazeWalls[currX][currY] = 13;
              break;
          default:
              maze[x][y] = 15;
              break;
      }
  }
  
  void findWallRightOrientation(){
    switch {
          case wallLeft():
              mazeWalls[currX][currY] = 2;
              break;
          case wallFront():
              mazeWalls[currX][currY] = 3;
              break;
          case wallRight():
              mazeWalls[currX][currY] = 4;
              break;
          case wallRight() && wallFront():
              mazeWalls[currX][currY] = 6;
              break;
          case wallLeft() && wallFront():
              mazeWalls[currX][currY] = 7;
              break;
          case wallLeft() && wallRight():
              mazeWalls[currX][currY] = 10;
              break;
          case wallRight() && wallFront() && wallLeft():
              mazeWalls[currX][currY] = 12;
              break;
          default:
              maze[x][y] = 15;
              break;
      }
  }
  void findWallLeftOrientation(){
    switch {
          case wallLeft():
              mazeWalls[currX][currY] = 4;
              break;
          case wallFront():
              mazeWalls[currX][currY] = 1;
              break;
          case wallRight():
              mazeWalls[currX][currY] = 2;
              break;
          case wallRight() && wallFront():
              mazeWalls[currX][currY] = 8;
              break;
          case wallLeft() && wallFront():
              mazeWalls[currX][currY] = 5;
              break;
          case wallLeft() && wallRight():
              mazeWalls[currX][currY] = 10;
              break;
          case wallRight() && wallFront() && wallLeft():
              mazeWalls[currX][currY] = 14;
              break;
          default:
              maze[x][y] = 15;
              break;
    }
  }
  void findWallBackOrientation(){
    switch {
          case wallLeft():
              mazeWalls[currX][currY] = 3;
              break;
          case wallFront():
              mazeWalls[currX][currY] = 4;
              break;
          case wallRight():
              mazeWalls[currX][currY] = 1;
              break;
          case wallRight() && wallFront():
              mazeWalls[currX][currY] = 5;
              break;
          case wallLeft() && wallFront():
              mazeWalls[currX][currY] = 6;
              break;
          case wallLeft() && wallRight():
              mazeWalls[currX][currY] = 9;
              break;
          case wallRight() && wallFront() && wallLeft():
              mazeWalls[currX][currY] = 11;
              break;
          default:
              maze[x][y] = 15;
              break;
      }
  }