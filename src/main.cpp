#include <iostream>
#include <sstream>

#include <vector>

#include <sqlite3.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "main.h"
#include "sqlite.h"

#include "aes.h"

// print encrypted key
void print_encripted_key()
{

}

// example function
void aes_encrypt_cbc()
{
	// 16 byte key
	uint8_t key[] = {0x2b, 0x21, 0x32, 0x10, 0x3d, 0x3e, 0xf4, 0x32, 0x32, 0x33, 0xff, 0x54, 0x32, 0xf3, 0xff, 0xfd};

	// 16 byte IV
	uint8_t iv[] = {0x21, 0x21, 0x31, 0x11, 0x31, 0x31, 0xf1, 0x31, 0x31, 0x31, 0xf1, 0x51, 0x31, 0xf1, 0xf2, 0xf2};

	// 64 byte word
	uint8_t word[] = {0x3b, 0x41, 0x52, 0x70, 0x8d, 0xae, 0xe4, 0xd2, 0x39, 0x31, 0x2f, 0x34, 0x72, 0x03, 0xdf, 0xdd,
		0x3b, 0x41, 0x52, 0x70, 0x8d, 0xae, 0xe4, 0xd2, 0x39, 0x31, 0x2f, 0x34, 0x72, 0x03, 0xdf, 0xdd,
		0x3b, 0x41, 0x52, 0x70, 0x8d, 0xae, 0xe4, 0xd2, 0x39, 0x31, 0x2f, 0x34, 0x72, 0x03, 0xdf, 0xdd,
		0x3b, 0x41, 0x52, 0x70, 0x8d, 0xae, 0xe4, 0xd2, 0x39, 0x31, 0x2f, 0x34, 0x72, 0x03, 0xdf, 0xdd};

	uint8_t buffer[64];

	AES128_CBC_encrypt_buffer(buffer, word, 64, key, iv);

	int i;

	for(i=0;i<63;i++)
	{
		printf("%2x ", buffer[i]);
	}
}

// verify if file exists
bool file_exists(const std::string& file_name)
{
	struct stat buffer;
	return(stat(file_name.c_str(), &buffer) == 0); 
}

// some info about the program itself and stuff used by the program
void print_stats(void)
{
	std::cout << "PassShelter - " << PSVERSION << "\n";
	std::cout << "SQLite3 - " << sqlite3_libversion() << ":" << sqlite3_libversion_number() << "\n";
}

// splits the string from the command prompt
	std::vector<std::string>
split_string(std::string user_string)
{
	std::vector<std::string> splitted_string;
	std::istringstream cmd_buffer(user_string);

	while(cmd_buffer)
	{
		std::string temp;
		cmd_buffer >> temp;
		splitted_string.push_back(temp);
	}

	return splitted_string;
}

// main function
int main(int argc, char* argv[])
{
	std::string db_file = "pshelter.db";
	sqlite3* sqlite_db = NULL;
	SQLite sql_class(sqlite_db);

	std::string user_cmd;
	std::vector<std::string> cmd_words;

	print_stats();
	aes_encrypt_cbc();

	if(!file_exists(db_file))
	{
		std::cout << "File 'pshelter.db' does not exist. Creating...\n";
		std::cout << "File successfully created.\n";
	}
	else
	{
		std::cout << "File 'pshelter.db' found.\n";
	}

	std::cout << "Insert command: \n";
	std::getline(std::cin, user_cmd);

	cmd_words = split_string(user_cmd);

	if(cmd_words.size() != 0)
	{
		if (cmd_words[0] == "ins")
		{
			if(cmd_words.size() == 4)
			{
				sql_class.sql_insert(cmd_words[1], cmd_words[2], cmd_words[3]);	
			}
			else
			{
				std::cout << "Wrong number of arguments.\n";
			}
		}
		else if(cmd_words[0] == "rm")
		{
			if(cmd_words.size() == 4)
			{
				sql_class.sql_delete(cmd_words[1], cmd_words[2], cmd_words[3]);	
			}
			else
			{
				std::cout << "Wrong number of arguments.\n";
			}
		}
		else if(cmd_words[0] == "exit" || cmd_words[0] == "quit")
		{
			exit(EXIT_SUCCESS);	
		}
		else
		{
			std::cout << "Invalid command.\n";
		}
	}

	return 0;
}
