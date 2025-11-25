#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>    

// x86-64 Kernel
extern void asmsdot(float *a, float *b, int size, float* sdot);

// C Kernel
void c_sdot(float* a, float* b, int size, float* sdot);

// Timer
double time_kernel(void (*kernel)(float*, float*, int, float*), float* a, float* b, int size, float* sdot, int runs);

// For generating vector based on size
float* init_vector(size_t n) {
    float* v = (float*)malloc(n * sizeof(float));
    for (size_t i = 0; i < n; i++) {
        v[i] = (float)rand() / RAND_MAX;
    }
    return v;
}

int main() {
	srand((unsigned int)time(NULL));

	int runs = 25; // Adjust runs here
	size_t size = 16777216; // Adjust size here

	printf("\n>> Vector size: %zu\n", size);
	printf(">> Generating vector A and B...\n\n");

	printf("===================================================\n\n");

	float* a = init_vector(size);
	float* b = init_vector(size);

	float sdot_val = 0.0f;
	float* sdot = &sdot_val;

	// Time
	printf(">> ASM Kernel...\n\n");
	double time_asm = time_kernel(asmsdot, a, b, size, sdot, runs);
	asmsdot(a, b, size, sdot);
	printf("\n>> Dot product result (ASM): %.2f\n", *(sdot));
	printf(">> Average Time of ASM Kernel: %.6f\n\n", time_asm);

	printf("===================================================\n\n");

	printf(">> C Kernel...\n\n");
	double time_c = time_kernel(c_sdot, a, b, size, sdot, runs);
	printf("\n>> Dot product result (C): %.2f\n", *(sdot));
	printf(">> Average Time of C Kernel: %.6f\n\n", time_c);

	printf("===================================================\n");

	// Free memory
	free(a);
	free(b);

	return 0;
}