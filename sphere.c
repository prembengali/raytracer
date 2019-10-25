/** 
 * This is a file for making Sphere entities 
 */
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "vector.c"
#include "color.c"


/* The sphere */
typedef struct{
        vector center;
        float  radius;
        color col;
}sphere;


/**
 * This method makes spheres
 *
 * @param center
 */
sphere makeSphere(vector center, double radius, color x) {
    sphere s = { .center = center, .radius = radius, .col = x };
    return s;
}

vector getSphereCenter(sphere s) {
	return s.center;
}

color getSphereColor(sphere s) {
	return s.col;
}

float getSphereRadius(sphere s) {
	return s.radius;
}

sphere initSphere() {
	sphere s
	s.center = makeVector(0,0,0);
	s.col = makeColor(0.5,0.5,1);
	s.radius = 1.0;
	return s;
}
