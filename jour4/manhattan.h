#ifndef MANHATTAN_H
#define MANHATTAN_H

typedef struct {
    int x;
    int y;
} point;

#define ABS(x) ((x) < 0 ? -(x) : (x))

int manhattan_distance(point a, point b);

#endif