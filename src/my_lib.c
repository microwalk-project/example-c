#include <stdint.h>
#include <stdlib.h>

#include "my_lib.h"

#define NOINLINE __attribute__((noinline))

uint8_t lookup[256];

void init(void)
{
	srand(0);
	
	for(int i = 0; i < sizeof(lookup) / sizeof(lookup[0]); ++i)
		lookup[i] = (uint8_t)rand();
}

void lookup_leakage(uint8_t *input, int inputLength, uint8_t *output)
{
	// Empty and constant time
}

int branch_leakage(uint8_t *input, int inputLength)
{
	// Empty and constant time
	return lookup[0] + inputLength;
}

int loop_leakage(uint8_t *input, int inputLength)
{
	// Empty and constant time
	return lookup[0] + inputLength;
}