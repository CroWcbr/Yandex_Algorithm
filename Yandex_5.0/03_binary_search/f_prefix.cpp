// bad algoritm for very big H W (becouse we have prefix map W H)
#include <iostream>
#include <vector>
#include <fstream>

#define DEBUG 0

void prefixSum(const std::vector<std::vector<int>>& data,
                std::vector<std::vector<int>>& prefix,
                int h, int w)
{
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            prefix[i][j] = data[i][j];
            if (j > 0)
            {
                prefix[i][j] += prefix[i][j - 1];
            }
        }
    }
    for (int j = 0; j < w; ++j)
    {
        for (int i = 1; i < h; ++i)
        {
            prefix[i][j] += prefix[i - 1][j];
        }
    }
}

int findPit(const std::vector<std::vector<int>>& prefix, int y1, int x1, int y2, int x2)
{
    if (y1 > y2 || x1 > x2)
        return 0;

    int pit = prefix[y2][x2];
    if (y1 > 0)
        pit -= prefix[y1 - 1][x2];

    if (x1 > 0)
        pit -= prefix[y2][x1 - 1];

    if (y1 > 0 && x1 > 0)
        pit += prefix[y1 - 1][x1 - 1];

    return pit;
}

bool check(size_t mid, 
            std::vector<std::vector<int>>& prefix,
            size_t h, size_t w, size_t n)
{
    int max = 0;
    for (int y = 0; y <= h - mid; ++y)
    {
        int sum_y = findPit(prefix, y, 0, y + mid - 1, w - 1);
if (DEBUG) std::cout << "\tmid : " << mid << "\ty : " << y << "\t sum :" << sum_y << std::endl;
        for (int x = 0; x <= w - mid; ++x)
        {
            int sum_x = findPit(prefix, 0, x, y - 1, x + mid - 1);
            sum_x += findPit(prefix, y + mid, x, h - 1, x + mid - 1);
if (DEBUG) std::cout << "\t\tx : " << x << "\t sum :" << sum_x << std::endl;
            max = std::max(max, sum_x + sum_y);
            // std::cout << "y/x : " << y << "/" << x << " " << sum_y << "/" << sum_x << std::endl;
            if (max == n)
                return true;
        }
    }
    return false;
}

void print(std::vector<std::vector<int>>& data, int h, int w)
{
    std::cout << "  ";
    for (int x = 0; x < w; ++x)
        std::cout << x; 
    std::cout << std::endl;  
    for (int y = 0; y < h; ++y)
    {
        std::cout << y << " ";
        for (int x = 0; x < w; ++x)
        {
            std::cout << (data[y][x] ? '#' : '.'); 
        }
        std::cout << std::endl;
    }
}    

void print_pref(std::vector<std::vector<int>>& data, int h, int w)
{
    std::cout << "  ";
    for (int x = 0; x < w; ++x)
        std::cout << x; 
    std::cout << std::endl;  
    for (int y = 0; y < h; ++y)
    {
        std::cout << y << " ";
        for (int x = 0; x < w; ++x)
        {
            std::cout << data[y][x]; 
        }
        std::cout << std::endl;
    }
}

size_t binary_search(std::vector<std::vector<int>>& data,
                    size_t h, size_t w, size_t n)
{
    size_t left = 1;
    size_t right = std::min(w, h);

    std::vector<std::vector<int>> prefix(h, std::vector<int>(w));
    prefixSum(data, prefix, h, w);

    // print(data, h, w);
    // print_pref(prefix, h, w);

    while (left < right)
    {
        size_t mid = (left + right) / 2;
        std::cout << "before : " << mid << " " << left << " " << right << std::endl;
        if (check(mid, prefix, h, w, n))
            right = mid;
        else
            left = mid + 1;
        std::cout << "after : " << left << " " << right << std::endl;
    }

    return left;
}

int main()
{
    std::ifstream input("input.txt");
    size_t w, h, n;
    input >> w >> h >> n;

    std::vector<std::vector<int>> data(h, std::vector<int>(w, 0));
    for (int i = 0; i < n; ++i)
    {
        size_t x, y;
        input >> x >> y;
        data[y - 1][x - 1] = 1;
    }
    input.close();

    std::cout << binary_search(data, h, w, n) << std::endl;
    
    return 0;
}