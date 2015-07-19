#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>

#include <vector>

#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "sqlite.h"

#include "aes.h"
#include "enc.h"

void print_help(const std::string& command)
{
	if(command == "ins")
	{
		std::cout << "Command to insert data.\n"
			<< "Usage: ins [table] [username] [password]\n\n";
	}
	else if(command == "rm")
	{
		std::cout << "Command to delete data.\n"
			<< "Usage: ins [table] [username] [password]\n\n";
	}
	else if(command == "")
	{
		std::cout << "List of commands:\n"
			<< "\tins\n"
			<< "\trm\n\n";
	}
	else
	{
		std::cout << "Command doesn't exist.\n";
	}
}

// verify if file exists
bool file_exists(const std::string& file_name)
{
	std::ifstream f(file_name.c_str());

	if(f.good())
	{
		f.close();
		return true;
	}
	else
	{
		return false;
	}	
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
int main(int argc, char** argv)
{

	std::string user_cmd;
	std::string db_file_name = "pshelter.sqlite3";

	std::vector<std::string> cmd_words;

	bool loop = true;

	if(!file_exists(db_file_name))
	{
		std::cout << "File 'pshelter.sqlite3' does not exist. Creating...\n";
		std::cout << "File successfully created.\n";
	}
	else
	{
		std::cout << "File 'pshelter.sqlite3' found.\n";
	}

	sqlite3* sqlite_db = NULL;
	SQLite sql_class(sqlite_db, db_file_name);

	print_stats();

	while(loop)
	{
		std::cout << "Insert command: \n";
		std::getline(std::cin, user_cmd);

		cmd_words = split_string(user_cmd);

		if(cmd_words.size() != 0)
		{
			if (cmd_words[0] == "ins")
			{
				if(cmd_words.size() == 5)
				{
					sql_class.insert(cmd_words[1], cmd_words[2], cmd_words[3]);	
				}
				else
				{
					std::cout << "Wrong number of arguments.\n";
				}
			}
			else if(cmd_words[0] == "rm")
			{
				if(cmd_words.size() == 3)
				{
					sql_class.delete_table(cmd_words[1]);	
				}
				else if(cmd_words.size() == 4)
				{
					sql_class.delete_data(cmd_words[1], cmd_words[2]);	
				}
				else
				{
					std::cout << "Wrong number of arguments.\n";
				}
			}	
			else if(cmd_words[0] == "testenc")
			{
				if(cmd_words.size() == 3)
				{
					int ws = cmd_words[1].length(); 
					uint8_t buff[ws], iv[16], key[16], out[ws];

					generate_iv(iv);
					generate_key(key);
					AES128_CBC_encrypt_buffer(buff, (uint8_t*)cmd_words[1].c_str(), ws, key, iv);

					std::cout << "\nEncrypted: ";
					print_encrypted_key(buff, ws);

					AES128_CBC_decrypt_buffer(out, buff, ws, key, iv);

					std::cout << "Decrypted: ";
					print_decrypted_key(out, ws);

					putchar('\n');
				}
				else
				{
					std::cout << "Wrong number of arguments.\n";
				}
			}
			else if(cmd_words[0] == "exit" || cmd_words[0] == "quit")
			{
				// loop = false;
				exit(EXIT_SUCCESS);	
			}
			else if(cmd_words[0] == "help")
			{
				print_help(cmd_words[1]);
			}
			else
			{
				std::cout << "Invalid command.\n";
			}
		}
	}
	return 0;
}
