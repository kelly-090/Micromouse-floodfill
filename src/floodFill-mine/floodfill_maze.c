// floodfill_maze.c
#include "floodfill_maze.h"

// Cell functions
Cell* create_cell() {
    Cell* cell = malloc(sizeof(Cell));
    cell->wall_count = 0;
    cell->visited = false;
    cell->distance = 0;
    return cell;
}

bool has_wall(Cell* cell, Direction d) {
    for (int i = 0; i < cell->wall_count; i++) {
        if (cell->walls[i] == d) {
            return true;
        }
    }
    return false;
}

void assign_wall(Cell* cell, Direction d) {
    if (cell->wall_count < MAX_WALLS && !has_wall(cell, d)) {
        cell->walls[cell->wall_count++] = d;
    }
}

void set_distance(Cell* cell, int dist) {
    cell->distance = dist;
}

void init_maze(Maze* maze) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze->table[i][j] = create_cell();
        }
    }
    maze->mice_row = 15;
    maze->mice_col = 0;
}

Cell* get_cell(Maze* maze, int row, int col) {
    if (row < 0 || row >= MAZE_SIZE || col < 0 || col >= MAZE_SIZE) {
        return NULL;
    }
    return maze->table[row][col];
}

int get_cell_distance(Maze* maze, int row, int col) {
    Cell* cell = get_cell(maze, row, col);
    return (cell) ? cell->distance : 9999;
}

Cell* get_current_cell(Maze* maze) {
    return maze->table[maze->mice_row][maze->mice_col];
}


void make_move(Maze* maze, Mice* mice, int r_inc, int c_inc) {
    mice->row += r_inc;
    mice->col += c_inc;
    maze->mice_row = mice->row;
    maze->mice_col = mice->col;
}
Direction lowest_surrounding_direction(Maze* maze) {
    int cur_r = maze->mice_row;
    int cur_c = maze->mice_col;
    Cell* cur_cell = get_current_cell(maze);

    int best_dist = 9999;
    Direction best_dir = -1;

    int directions[4][3] = {
        {0, 1, RIGHT},
        {1, 0, BOTTOM},
        {0, -1, LEFT},
        {-1, 0, TOP}
    };

    for (int i = 0; i < 4; i++) {
        int dr = directions[i][0];
        int dc = directions[i][1];
        Direction dir = directions[i][2];

        if (has_wall(cur_cell, dir)) continue;

        int new_r = cur_r + dr;
        int new_c = cur_c + dc;
        int dist = get_cell_distance(maze, new_r, new_c);

        if (dist < best_dist) {
            best_dist = dist;
            best_dir = dir;
        }
    }

    return best_dir;
}

void flood_fill(Maze* maze, Mice* mice) {
    while (true) {
        Cell* cell = get_current_cell(maze);
        if (cell->distance == 0) {
            printf("Mice reached the goal!\n");
            break;
        }

        Direction dir = lowest_surrounding_direction(maze);

        if (dir == RIGHT) make_move(maze, mice, 0, 1);
        else if (dir == BOTTOM) make_move(maze, mice, 1, 0);
        else if (dir == LEFT) make_move(maze, mice, 0, -1);
        else if (dir == TOP) make_move(maze, mice, -1, 0);

        mice->pro_dir = dir;

        printf("Mice at: (%d, %d)\n", mice->row, mice->col);
    }
}

int main() {
    Maze maze;
    init_maze(&maze);

    // For testing you can add walls manually
    assign_wall(get_cell(&maze, 15, 0), RIGHT);
    assign_wall(get_cell(&maze, 15, 0), BOTTOM);

    // Set simple goal
    get_cell(&maze, 0, 0)->distance = 0;
    get_cell(&maze, 15, 0)->distance = 10;

    Mice mice = {15, 0, TOP};
    flood_fill(&maze, &mice);

    return 0;
}
