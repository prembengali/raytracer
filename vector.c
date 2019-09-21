/**
 * This creates vectors for the ray tracer
 *
 */
#include <stdio.h>
#include <math.h>

/* The vector structure */                                                      
typedef struct{                                                                 
      float x,y,z;                                                              
}vector;                 

/*                                                                              
 * This method creates 3D vector                
 *                                                                              
 * @param x                                                 
 * @param y 
 * @param z                                               
 */  
vector makeVector(float x, float y, float z) {
    vector v;
    v.x = x, v.y = y, v.z = z;
    return v;
}


/*
 * This method is a dotproduct of two vectors to create a scalar
 *
 * @param v1 is the first vector
 * @param v2 is the second vector
 */
float dotVector(vector a, vector b) {
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

/**
 * This method subtracts two vectors to get the resulting vector
 *
 * @param v1 is the first vector
 * @param v2 is the second vector
 */                
vector vectorSub(vector a, vector b){
    return makeVector(a.x - b.x, a.y - b.y, a.z - b.z);
}

/**                                                                             
 * This method adds two vectors to get the resulting vector                
 *                                                                              
 * @param a is the first vector                                                
 * @param b is the second vector                                               
 */  
vector vectorAdd(vector a, vector b) {
    return makeVector(a.x + b.x, a.y + b.y, a.z + b.z);
}

/**
 * This returns the magnitude of the vector
 *
 * @param v is the vector
 */
float vec_length(vector v) {
    return sqrt(SQUARE(v.x) + SQUARE(v.y) + SQUARE(v.z));
}

