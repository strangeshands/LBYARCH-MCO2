#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// x86-64 Kernel
extern float asmsdot(float *a, float *b, int size);

// C Kernel
float sdot(float* a, float* b, int size);

int main() {
	/*
	// Size input
	int size = 0;
	printf("Size: ");
	scanf("%d", size);

	// Allocate arrays
	float* a = (float*)malloc(size * sizeof(float));
	float* b = (float*)malloc(size * sizeof(float));

	// Input vector a
	printf("Enter %d elements for vector a (space-separated):\n", size);
	for (int i = 0; i < size; i++) {
		scanf("%f", &a[i]);
	}

	// Input vector b
	printf("Enter %d elements for vector b (space-separated):\n", size);
	for (int i = 0; i < size; i++) {
		scanf("%f", &b[i]);
	}

	// Print vectors to check
	printf("Vector a: ");
	for (int i = 0; i < size; i++) printf("%.2f ", a[i]);
	printf("\n");

	printf("Vector b: ");
	for (int i = 0; i < size; i++) printf("%.2f ", b[i]);
	printf("\n");
	
	*/

	// === TEST VARIABLES
	int size = 5;
	
	// Allocate arrays
	float* a = (float*)malloc(size * sizeof(float));
	float* b = (float*)malloc(size * sizeof(float));

	a[0] = 1.5f;   b[0] = 2.2f;
	a[1] = 3.1f;   b[1] = 4.7f;
	a[2] = 5.5f;   b[2] = 6.6f;
	a[3] = 7.29f;  b[3] = 8.1f;
	a[4] = 9.9f;   b[4] = 10.11f;
	// === TEST VARIABLES

	// Call x86-64 Kernel
	float res_asm = asmsdot(a, b, size);
	printf("Dot product result (ASM): %.2f\n", res_asm);

	// Call C Kernel
	float res_c = sdot(a, b, size);
	printf("Dot product result (C): %.2f\n", res_c);

	// Free memory
	free(a);
	free(b);

	return 0;
}