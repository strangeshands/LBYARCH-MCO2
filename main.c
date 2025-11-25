#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// x86-64 Kernel
//extern float asmsdot(float *a, float *b, int size);

// C Kernel
float sdot(float* a, float* b, int size);

int main() {
	// Size input
	/*int size = 0;
	printf("Size: ");
	scanf("%d", size);*/

	int size = 5;
	
	// Allocate arrays
	float* a = (float*)malloc(size * sizeof(float));
	float* b = (float*)malloc(size * sizeof(float));

	a[0] = 1.5f;   b[0] = 2.2f;
	a[1] = 3.1f;   b[1] = 4.7f;
	a[2] = 5.5f;   b[2] = 6.6f;
	a[3] = 7.25f;  b[3] = 8.1f;
	a[4] = 9.9f;   b[4] = 10.5f;

	// Call x86-64 Kernel
	//asmsdot();

	// Call C Kernel
	float result = sdot(a, b, size);
	printf("Dot product result: %.2f\n", result);

	// Free memory
	free(a);
	free(b);

	return 0;
}