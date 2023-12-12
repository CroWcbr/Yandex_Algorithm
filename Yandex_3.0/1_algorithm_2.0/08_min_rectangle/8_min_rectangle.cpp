#include <iostream>

int main()
{
	int k;
	std::cin >> k;

	int		x, y;
	std::cin >> x >> y;
	int		x_min = x;
	int		x_max = x;
	int		y_min = y;
	int		y_max = y;

	for (int i = 1; i < k; ++i)
	{
		std::cin >> x >> y;
		if (x < x_min)
			x_min = x;
		else if (x > x_max)
			x_max = x;

		if (y < y_min)
			y_min = y;
		else if (y > y_max)
			y_max = y;
	}
	std::cout << x_min << " " << y_min << " " << x_max << " " << y_max;
	return 0;
}
