#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "vector.c"
#include "color.c"
#include "object.c"



/* The plane */
typedef struct{
        vector normal;
        float  distance;
        color col;
}plane;


/**
 * This method makes spheres
 *
 * @param normal
 */
plane makePlane(vector normal, double distance, color x) {
    plane p = { .normal = normal, .distance = distance, .col = x };
    return p;
}

vector getPlaneNormal(plane p) {
	return p.normal;
}

vector getPlaneColor(plane p) {
	return p.col;
}

float getPlaneDistance(plane p) {
	return p.distance;
}

plane initPlane() {
	plane p
	p.normal = makeVector(1,0,0);
	p.col = makeColor(0.5,0.5,0.5);
	p.distance = 0;
	return p;
}


vector getNormalAt(plane p, vector point) {
	return p.normal;
}

double findIntersection(plane p, ray r) {
	vector rayDir = getDirection(r);
	float a = dotVector(rayDir, getPlaneNormal(p));

	if(a == 0) {
		return -1; // ray is parallel to plane
	}
	else {
		double b = dotVector(getPlaneNormal(p), vectorAdd(getOrigin(r), negative(vectorMult(getPlaneNormal(p), getPlaneDistance(p)))));
		return -1*b/a;
	}
}
}
