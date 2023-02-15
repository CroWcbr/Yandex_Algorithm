#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() 
{
	std::map<char, int>	dict;
	size_t				max = 0;
	std::ifstream		file("input.txt");
	std::string			line;

	while (std::getline(file, line))
	{
		for (char &c : line)
			if (c != ' ' && c != '\n')
				dict[c]++;
	}
	if (!dict.empty())
	{
		for (auto &c : dict)
			if (max < c.second)
				max = c.second;

		for (size_t i = max; i > 0; i--) 
		{
			for (const auto& c : dict) 
			{
				if (c.second >= i)
					std::cout << "#";
				else
					std::cout << " ";
			}
			std::cout << std::endl;
		}

		for (auto &c : dict)
			std::cout << c.first;
		std::cout << std::endl;
	}
	return 0;
}
