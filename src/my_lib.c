#include <stdint.h>
#include <stdlib.h>

#include "my_lib.h"

#define NOINLINE __attribute__((noinline))

char caesarLookup[][26] = {
    "abcdefghijklmnopqrstuvwxyz",
    "bcdefghijklmnopqrstuvwxyza",
    "cdefghijklmnopqrstuvwxyzab",
    "defghijklmnopqrstuvwxyzabc",
    "efghijklmnopqrstuvwxyzabcd",
    "fghijklmnopqrstuvwxyzabcde",
    "ghijklmnopqrstuvwxyzabcdef",
    "hijklmnopqrstuvwxyzabcdefg",
    "ijklmnopqrstuvwxyzabcdefgh",
    "jklmnopqrstuvwxyzabcdefghi",
    "klmnopqrstuvwxyzabcdefghij",
    "lmnopqrstuvwxyzabcdefghijk",
    "mnopqrstuvwxyzabcdefghijkl",
    "nopqrstuvwxyzabcdefghijklm",
    "opqrstuvwxyzabcdefghijklmn",
    "pqrstuvwxyzabcdefghijklmno",
    "qrstuvwxyzabcdefghijklmnop",
    "rstuvwxyzabcdefghijklmnopq",
    "stuvwxyzabcdefghijklmnopqr",
    "tuvwxyzabcdefghijklmnopqrs",
    "uvwxyzabcdefghijklmnopqrst",
    "vwxyzabcdefghijklmnopqrstu",
    "wxyzabcdefghijklmnopqrstuv",
    "xyzabcdefghijklmnopqrstuvw",
    "yzabcdefghijklmnopqrstuvwx",
    "zabcdefghijklmnopqrstuvwxy"
};

uint8_t lookup[256];

void init(void)
{
	srand(0);
	
	for(int i = 0; i < sizeof(lookup) / sizeof(lookup[0]); ++i)
		lookup[i] = (uint8_t)rand();
}

void caesarEncrypt(char input[], int length, char output[], int shift)
{
    for(int i = 0; i < length; ++i)
    {
        if(input[i] < 'a' || input[i] > 'z')
        {
            output[i] = input[i];
            continue;
        }
        
        output[i] = caesarLookup[shift][input[i] - 'a'];
    }
}

void lookup_leakage(uint8_t *input, int inputLength, uint8_t *output)
{
	// Convert input to alpha string
	char *alpha = (char *)malloc(inputLength + 1);
	for(int i = 0; i < inputLength; ++i)
		alpha[i] = 'a' + (input[i] % 26);
	alpha[inputLength] = '\0';

	caesarEncrypt(alpha, inputLength, (char *)output, input[0] % 26);
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