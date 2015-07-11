#ifndef ENC_H_
#define ENC_H_

#include <stdint.h>

void generate_iv(uint8_t output_buf[]);
void generate_key(uint8_t output_buf[]);
void generate_string(uint8_t output_buf[], int key_size);
void print_encripted_key(uint8_t buffer[], int b_size);

#endif
