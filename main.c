/* Ray tracer */

#include <stdio.h>
#include <stdbool.h> 
#include <math.h>

/* The sphere */
typedef struct{
        vector pos;
        float  radius;
    int material;
}sphere;

/* The ray */
typedef struct{
        vector start;
        vector dir;
}ray;

/* Color */
typedef struct{
    float red, green, blue;
}color;

/* Material Definition */
typedef struct{
	color color;
	float reflection;
}material;

/* Camera or Eye */
typedef struct {
    vector position;
    vector distance;
    float width;
    float heigt;
}camera;

//-----------------------------------------------------------------------------

int main(int argc, char *argv) {



}

