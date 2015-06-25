#include <iostream>
#include <sstream>

#include <vector>

int main(int argc, char* argv[])
{
	std::string user_cmd;

	std::cout << "Insert command: \n";
	std::getline(std::cin, user_cmd);

	std::istringstream cmd_buffer(user_cmd);

	while(cmd_buffer)
	{
		std::string temp;
		cmd_buffer >> temp;
		std::cout << temp << "\n";
	}

	return 0;
}
