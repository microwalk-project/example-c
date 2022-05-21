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
	for(int i = 0; i < inputLength; ++i)
		output[i] = lookup[input[i]];
}

static int NOINLINE branch_leakage_util(uint8_t data)
{
	// Use primes and random calculation to keep the compiler from optimizing this function too much
	
	if(data < 79)
		return 7;
	
	if(data < 119)
		return data;
		
	return 19 * data + 23;
}

int branch_leakage(uint8_t *input, int inputLength)
{
	int result = 0;
	
	for(int i = 0; i < inputLength; ++i)
		result += branch_leakage_util(input[i]);
	
	return result;
}

int loop_leakage(uint8_t *input, int inputLength)
{
	for(int i = 0; i < input[0]; ++i)
	{
		if(lookup[i] < 5)
			return 1;
	}
	
	return 2;
}