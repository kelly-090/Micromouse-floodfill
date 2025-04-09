// coordinate.h
#ifndef COORDINATE_H
#define COORDINATE_H

typedef struct {
    int x;
    int y;
} Coordinate;

Coordinate create_coordinate(int x, int y);
void print_coordinate(Coordinate c);
Coordinate add_coordinates(Coordinate a, Coordinate b);

// Getters
int get_x(Coordinate c);
int get_y(Coordinate c);

#endif