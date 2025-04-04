#include "manhattan.h"

int manhattan_distance(point a, point b)
{
    return ABS(a.x - b.x) + ABS(a.y - b.y);
}