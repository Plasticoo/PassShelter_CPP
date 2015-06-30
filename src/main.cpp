#include <iostream>
#include <sstream>

#include <vector>

#include <sqlite3.h>
#include <stdlib.h>

// some info about the program itself and stuff used by the program
void print_stats(void)
{
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
	sqlite3* sqlite_db;

	std::string user_cmd;
	std::vector<std::string> cmd_words;

	print_stats();

	std::cout << "Insert command: \n";
	std::getline(std::cin, user_cmd);

	cmd_words = split_string(user_cmd);

	if (cmd_words[0] == "ins")
	{
		//do something	
	}
	else if(cmd_words[0] == "rm")
	{
		//do something
	}
	else if(cmd_words[0] == "exit" || cmd_words[0] == "quit")
	{
		exit(EXIT_SUCCESS);	
	}
	else
	{
		std::cout << "Invalid command.\n";
	}

	return 0;
}
