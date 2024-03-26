#include <iostream>
#include <vector>
#include <fstream>

#define DEBUG 0

bool check_square(std::vector<std::vector<int>>& data, int r, int c, int s)
{
    if (data[r][c] >= s)
        return true;
    return false;
}

bool check(int mid, int n, int m, std::vector<std::vector<int>>& data)
{
    for (int r = 2 * mid; r <= n - mid; ++r)
        for (int c = 2 * mid; c <= m - mid; ++c)
        {
            if (check_square(data, r, c, mid) &&
                    check_square(data, r - mid, c, mid) &&
                    check_square(data, r + mid, c, mid) &&
                    check_square(data, r, c - mid, mid) &&
                    check_square(data, r, c + mid, mid))
                return true;
        }
    return false;
}

size_t binary_search(int n, int m, std::vector<std::vector<int>>& data) 
{
    size_t L = 1;
    size_t R = std::min(n, m) / 3;

    while (L < R)
    {
        size_t mid = (L + R + 1) / 2;
if (DEBUG) std::cout << mid << " " << L << " " << R << std::endl;

        if (check(mid, n, m, data))
            L = mid;
        else
            R = mid - 1;
if (DEBUG) std::cout << "\t" << mid << " " << L << " " << R << std::endl; 
    }
    return L;
}

int main()
{
    std::ifstream input("input.txt");
    int n, m;
    input >> n >> m;

    std::vector<std::vector<int>> data(n + 2, std::vector<int>(m + 2, 0)); // add false border
    {
        char tmp;
        for (int r = 1; r <= n; ++r)
            for (int c = 1; c <= m; ++c)
            {
                input >> tmp;
                if (tmp == '#')
                    data[r][c] = std::min(std::min(data[r - 1][c], data[r][c - 1]), data[r - 1][c - 1]) + 1;
            }
    }
    input.close();

    // for (int r = 1; r <= n; ++r)
    // {
    //     for (int c = 1; c <= m; ++c)
    //         std::cout << data[r][c] << " ";
    //     std::cout << std::endl;
    // }

    std::cout << binary_search(n, m, data) << std::endl;
    return 0;
}