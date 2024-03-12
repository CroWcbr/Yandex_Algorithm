#include <iostream>
#include <cmath>

int check(int x, int y, int p, int k)
{
    int step = 0;
    while (y > 0 || k > 0)
    {
        // std::cout << "\t" << step << "\t" << x << "\t" << y << "\t" << k << std::endl;
        if (y == 0)
            k -= x;
        else if (y >= x)
            y -= x;
        else
        {
            k -= (x - y);
            y = 0;
        }
        x -= k;
        if (y > 0)
            k += p;
        if (x <= 0)
            return -1;
        step++;
        // std::cout << "\t" << "\t" << x << "\t" << y << "\t" << k << std::endl;
    }
    return step;
}

int main()
{
	int x, y, p;
	std::cin >> x >> y >> p;

    int result = 0;
    int tmp_result = -1;
    int k = 0;

    while (y > 0 || k > 0)
    {
        // std::cout << result << "\t" << x << "\t" << y << "\t" << k << std::endl;
        if (y > 0 && x <= k)
        {
            result = tmp_result;
            break;
        }

        int tmp = check(x, y, p, k);
        // std::cout << tmp << "\t" << std::endl;
        if (tmp > 0)
            if (tmp_result > result + tmp || tmp_result == -1)
                tmp_result = result + tmp;

        y -= (x - k);
        k = 0;

        x -= k;
        if (x <= 0)
        {
            result = tmp_result;
            break;
        }

        if (y > 0)
            k += p;
        
        result++;
        // std::cout << "\t" << x << "\t" << y << "\t" << k << std::endl;
    }

    std::cout << (tmp_result == -1 ? result : std::min(tmp_result, result)) << std::endl;
    return 0;
}