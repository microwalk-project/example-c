#include <stdint.h>

void init(void);

void lookup_leakage(uint8_t *input, int inputLength, uint8_t *output);

int branch_leakage(uint8_t *input, int inputLength);

int loop_leakage(uint8_t *input, int inputLength);