#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <time.h>

#include "aes.h"

void generate_iv(uint8_t output_buf[])
{
	int i;

	srand(time(NULL));

	for (i = 0; i < 16; i++) // IV_SIZE = 16
	{
		// rand between 0x00 and 0xff
		output_buf[i] = rand() % 0xff;	
	}
}

void generate_key(uint8_t output_buf[])
{
	int i;

	srand(time(NULL));

	for (i = 0; i < 16; i++) // KEY_SIZE = 16
	{
		// rand between 0x00 and 0xff
		output_buf[i] = rand() % 0xff;	
	}
}

void generate_string(uint8_t output_buf[], int key_size)
{
	int i;	

	srand(time(NULL));

	for (i = 0; i < key_size; i++)
	{
		// rand between 0x00 and 0xff
		output_buf[i] = rand() % 0xff;	
	}
}

// print encrypted key
void print_encripted_key(uint8_t buffer[], int buff_size)
{
	int i;

	for (i = 0; i < buff_size; i++) 
	{
		printf("%.2x", buffer[i]);
	}	

	putchar('\n');
}

