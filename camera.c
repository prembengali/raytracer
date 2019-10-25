
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "vector.c"

/* Camera or Eye */
typedef struct {
    vector camPosition, camDirection, camRight, camDown;
}camera;

camera makeCamera(vector pos, vector dir, vector right, vector down) {
    camera c;
    c.camPosition = pos, c.camDirection = dir, c.camRight = right, c.camDown = down;
    return c;
}

camera initCam() {
	camera c;
	c.camPosition = makeVector(0,0,0);
	c.camDirection = makeVector(0,0,1);
	c.camRight = makeVector(0,0,0);
	c.camDown = makeVector(0,0,0);
	return c;
}

vector getCameraPosition(camera c) {
	return c.camPosition;
}

vector getCameraDirection(camera c) {
	return c.camDirection;
}
