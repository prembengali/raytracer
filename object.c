/**
 * This is a file for making Sphere entities
 */

#include "vector.c"
#include "color.c"
#include "ray.c"


/* The object */
typedef struct{
        color col;
}object;


/**
 * This method makes spheres
 *
 * @param center
 */
object makeSphere(color x) {
    object s = { .col = x };
    return s;
}


color getSphereColor() {
	object obj;
	return obj.col;
}

float findIntersection() {
	return 0;
}
}


