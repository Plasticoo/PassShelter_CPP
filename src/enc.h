#ifndef ENC_H_
#define ENC_H_

#include <stdint.h>

#define IV_SIZE 16

void generate_iv(uint8_t output_buf[IV_SIZE]);
void print_encripted_key(uint8_t buffer[], int b_size);
void aes_encrypt_cbc();

#endif
