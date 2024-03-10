#include <iostream>

int main()
{
	int K;
	std::cin >> K;
    
    int x, y;
    std::cin >> x >> y;
    int x_min, x_max, y_min, y_max;
    x_min = x_max = x;
    y_min = y_max = y;
    for (int i = 1; i < K; ++i)
    {
        std::cin >> x >> y;
        if (x < x_min)
            x_min = x;
        if (x > x_max)
            x_max = x;
        if (y < y_min)
            y_min = y;
        if (y > y_max)
            y_max = y; 
    }
    std:: cout << x_min << " " << y_min << " " << x_max << " " << y_max << std::endl;
    return 0;
}