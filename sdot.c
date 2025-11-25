#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
*	float *a:	contains values for vector a
*	float *b:	contains valus for vector b
*	int size:	size of the vector;
* 
*	return float:	the dot product
*/
float sdot(float* a, float* b, int size) {
	float sdot_res = 0.0f;

	for (int i = 0; i < size; i++) {
		sdot_res += a[i] * b[i];
	}

	return sdot_res;
}