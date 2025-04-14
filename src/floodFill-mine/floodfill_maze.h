// floodfill_maze.h
#ifndef FLOODFILL_MAZE_H
#define FLOODFILL_MAZE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAZE_SIZE 16
#define MAX_WALLS 4

typedef enum {
    TOP = 1,
    RIGHT,
    BOTTOM,
    LEFT
} Direction;

typedef struct {
    Direction walls[MAX_WALLS];
    int wall_count;
    bool visited;
    int distance;
} Cell;

typedef struct {
    int row;
    int col;
    Direction pro_dir;
} Mice;

typedef struct {
    Cell* table[MAZE_SIZE][MAZE_SIZE];
    int mice_row;
    int mice_col;
} Maze;

#endif
