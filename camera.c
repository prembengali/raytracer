
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "vector.c"

/* Camera or Eye */
typedef struct {
    vector position;
    vector distance;
    float width;
    float heigt;
}camera;
