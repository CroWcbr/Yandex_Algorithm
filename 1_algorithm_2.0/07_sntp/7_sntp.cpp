#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

int	string_to_sec(std::string &t)
{
	return stoi(t.substr(0, 2)) * 3600 + stoi(t.substr(3, 2)) * 60 + stoi(t.substr(6, 2));
}

void	print_time(int result)
{
	int hours = result / 3600;
	int minutes = (result % 3600) / 60;
	int seconds = result % 60;
	std::cout << std::setfill('0') << std::setw(2) << hours << \
				":" << std::setw(2) << minutes << ":" << \
				std::setw(2) << seconds << std::endl;
}

int main()
{
	std::string A, B, C;
	std::cin >> A >> B >> C;

	int a = string_to_sec(A);
	int b = string_to_sec(B);
	int c = string_to_sec(C);
	if (c - a < 0)
		c += 24 * 3600;

	int ab = b - a;
	int bc = c - b;
	int avg_diff = std::round(1. * (ab + bc) / 2);
	int result = b + avg_diff;

	print_time(result);

	return 0;
}
