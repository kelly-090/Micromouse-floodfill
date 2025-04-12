#include "jkwsolver.h"
#include "API.h"

Action solver() {
    return leftWallFollower();
}

// This is an example of a simple left wall following algorithm.
Action leftWallFollower() {
    if(API_wallFront()) {
        if(API_wallLeft()){
            return RIGHT;
        }
        return LEFT;
    }
    return FORWARD;
}


// Put your implementation of floodfill here!
Action floodFill() {
    int width = API_mazeWidth();
    int height = API_mazeHeight();

    bool wall_front = API_wallFront();
    bool wall_left = API_wallLeft();
    bool wall_right = API_wallRight();


    if (!wall_left) {
        API_turnLeft();
        dir = (dir + 3) % 4; 
        return LEFT;
    } else if (!wall_front) {
        API_moveForward();
        // Update position based on direction
        if (dir == NORTH) y++;
        else if (dir == EAST) x++;
        else if (dir == SOUTH) y--;
        else if (dir == WEST) x--;
        return FORWARD;
    } else if (!wall_right) {
        API_turnRight();
        dir = (dir + 1) % 4; // Update direction (turn right)
        return RIGHT;
    } else {
        API_turnRight();
        API_turnRight();
        dir = (dir + 2) % 4; // Update direction (turn around)
        return IDLE;
    }
}

}


