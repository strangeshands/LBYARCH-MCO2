#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
#include <time.h>    

/**
 *  float kernel: address of the function
 *	float *a:	contains values for vector a
 *	float *b:	contains valus for vector b
 *	int size:	size of the vector;
 * 
 *	return float:	the dot product
 *
 *  reference: https://learn.microsoft.com/en-us/windows/win32/api/profileapi/nf-profileapi-queryperformancefrequency
 */
double time_kernel(void (*kernel)(float*, float*, int, float*), float* a, float* b, int size, float* sdot, int runs) {
    LARGE_INTEGER start, end, freq;
    QueryPerformanceFrequency(&freq);

    double total_time = 0.0;
    for (int i = 0; i < runs; i++) {
        QueryPerformanceCounter(&start);
        kernel(a, b, size, sdot);
        QueryPerformanceCounter(&end);

        double run_time = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
        total_time += run_time;
        printf("Flag %d\t|\tCurrent Runtime: %.6f\t|\tCummulative Time: %.6f\n", i+1, run_time, total_time);
    }

    return total_time / runs; 
}