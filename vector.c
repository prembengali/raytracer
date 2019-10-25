/**
 * This creates vectors for the ray tracer
 *
 */
#include <stdio.h>
#include <math.h>

/* The vector structure */
typedef struct {
	float x, y, z;
} vector;

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
vector vectorSub(vector a, vector b) {
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
float magnitude(vector v) {
	return sqrt(SQUARE(v.x) + SQUARE(v.y) + SQUARE(v.z));
}

vector normalize(vector v) {
	float mag = magnitude(v);
	return makeVector(v.x / mag, v.y / mag, v.z / mag);
}

vector negative(vector v) {
	return makeVector(-v.x, -v.y, -v.z);
}

vector crossProduct(vector a, vector b) {
	vector v;
	v.x = (a.y * b.z) - (b.y * a.z);
	v.y = (a.z * b.x) - (b.z * a.x);
	v.z = (a.x * b.y) - (b.x * a.y);
	return v;
}

vector vectorMult(vector v, double scalar) {
	 return makeVector(v.x * scalar, v.y * scalar, v.z * scalar);
}

float getVecX(vector v) {
	return v.x;
}

float getVecY(vector v) {
	return v.y;
}

float getVecZ(vector v) {
	return v.z;
}

