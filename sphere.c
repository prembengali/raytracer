/** 
 * This is a file for making Sphere entities 
 */
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "vector.c"

/* The sphere */
typedef struct{
        vector pos;
        float  radius;
}sphere;


/**
 * This method makes spheres
 *
 * @param center
 */
sphere makeSphere(vector pos, double radius) {
    sphere s = { .pos = pos, .radius = radius };
    return s;
}
