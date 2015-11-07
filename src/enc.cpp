#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <time.h>

#include "aes.h"

// srand((unsigned int)time(NULL)) effect is global. But I use it in every function scope
// to make it more random

void generate_iv(uint8_t output_buf[])
{
	int i;

	srand((unsigned int)time(NULL));

	for (i = 0; i < 16; i++) // IV_SIZE = 16
	{
		// rand between 0x00 and 0xff
		output_buf[i] = (uint8_t)(rand() % 0xff);	
	}
}

// test purposes
void generate_key(uint8_t output_buf[])
{
	int i;

	srand((unsigned int)time(NULL));

	for (i = 0; i < 16; i++) // KEY_SIZE = 16
	{
		// rand between 0x00 and 0xff
		output_buf[i] = (uint8_t)(rand() % 0xff);	
	}
}

// test purposes
void generate_string(uint8_t output_buf[], int key_size)
{
	int i;	

	srand((unsigned int)time(NULL));

	for (i = 0; i < key_size; i++)
	{
		// rand between 0x00 and 0xff
		output_buf[i] = (uint8_t)(rand() % 0xff);	
	}
}

// print encrypted key
void print_encrypted_key(uint8_t buffer[], int buff_size)
{
	int i;

	for (i = 0; i < buff_size; i++) 
	{
		printf("%.2x", buffer[i]);
	}	

	putchar('\n');
}

void print_decrypted_key(uint8_t buffer[], int buff_size)
{
	int i;

	for (i = 0; i < buff_size; i++) 
	{
		printf("%c", buffer[i]);
	}	

	putchar('\n');
}
