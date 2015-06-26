#include <iostream>
#include <sstream>

#include <vector>

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

int main(int argc, char* argv[])
{
	std::string user_cmd;
	std::vector<std::string> cmd_words;

	std::cout << "Insert command: \n";
	std::getline(std::cin, user_cmd);

	cmd_words = split_string(user_cmd);
	for(int i = 0; i < (int)cmd_words.size() - 1; i++)
	{
		std::cout << cmd_words[i] << "\n";	
	}	

	return 0;
}
