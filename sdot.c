#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/**
 *	float *a:	contains values for vector a
 *	float *b:	contains valus for vector b
 *	int size:	size of the vector;
 *	float* sdot:	contains the address of the result
 */
void c_sdot(float* a, float* b, int size, float* sdot) {
	float sdot_res = 0.0f;

	for (int i = 0; i < size; i++) {
		sdot_res += a[i] * b[i];
	}

	*(sdot) = sdot_res;
}