#include <stdint.h>
#include <stdio.h>

#include <my_lib.h>

extern void RunTarget(FILE* input)
{
    uint8_t plain[16];
    if(fread(plain, 1, 16, input) != 16)
        return;
	
	branch_leakage(plain, 16);
}

extern void InitTarget(FILE* input)
{
	init();
	RunTarget(input);
}