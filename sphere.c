/** 
 * 
 */
#include <stdio.h>

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
