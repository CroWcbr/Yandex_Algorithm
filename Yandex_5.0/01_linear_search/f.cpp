#include <iostream>
#include <vector>

int find_max_right(const std::vector<int>& data, int i1, int i2)
{
    int max = 0;

    for (; i1 != i2 + 1; ++i1)
    {
        if (i1 == data.size())
            i1 = 0;
        if (data[i1] > max)
            max = data[i1];
    }
    return max;
}

int main()
{
	int n;
	std::cin >> n;
    
    std::vector<int> data(n);
    for (int i = 0; i < n; ++i)
        std::cin >> data[i];

    int a, b, k;
    std::cin >> a >> b >> k;

    int min_right, min_left, max_right, max_left;
    min_right = (a / k - (a >= k && a % k == 0));
    max_right = (b / k - (b >= k && b % k == 0));

    // std::cout << min_right << "\t" << max_right << std::endl;
    if (max_right - min_right >= n - 1 || max_left - min_left >= n - 1)
        std:: cout << find_max_right(data, 0, n - 1) << std::endl;
    else
    {
        min_right %= n;
        max_right %= n;
 
        min_left = ((n - max_right) >= data.size() ? 0 : (n - max_right));
        max_left = ((n - min_right) >= data.size() ? 0 : (n - min_right));
        // std::cout << min_right << "\t" << max_right << std::endl;
        // std::cout << min_left << "\t" << max_left << std::endl;
        std:: cout << std::max(find_max_right(data, min_right, max_right), find_max_right(data, min_left, max_left)) << std::endl;
    }

    return 0;
}


