// coordinate.c
#include <stdio.h>
#include "coordinate.h"

Coordinate create_coordinate(int x, int y) {
    Coordinate c;
    c.x = x;
    c.y = y;
    return c;
}

void print_coordinate(Coordinate c) {
    printf("Coordinate: (%d, %d)\n", c.x, c.y);
}

Coordinate add_coordinates(Coordinate a, Coordinate b) {
    return create_coordinate(a.x + b.x, a.y + b.y);
}

int get_x(Coordinate c) {
    return c.x;
}

int get_y(Coordinate c) {
    return c.y;
}