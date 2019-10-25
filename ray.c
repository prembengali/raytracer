#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.c"

/* The ray */                                                                   
typedef struct{                                                                 
        vector origin;
        vector dir;                                                             
}ray;                                                                           
     

ray makeRay(vector start, vector direction) {
    ray r;
    r.origin = start, r.dir = direction;
    return r;
}

vector getOrigin(ray r) {
	return r.origin;
}

vector getDirection(ray r) {
	return r.dir;
}

ray initRay(){
	ray r;
	r.origin = makeVector(0,0,0);
	r.dir = makeVector(1,0,0);
	return r;
}



