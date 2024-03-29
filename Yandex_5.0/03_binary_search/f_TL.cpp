// bad algoritm for big H W (less 2000 is OK)
#include <iostream>
#include <vector>
#include <fstream>

bool check(size_t mid, 
            std::vector<std::vector<int>>& data,
            std::vector<int>& data_y,
            size_t h, size_t w, size_t n)
{
    // for (int i = 0; i < data_y.size(); ++i)
    //     std::cout << "!\t" << i << " : " << data_y[i] << std::endl;
    
    int max = 0;
    int sum_y = 0;
    for (int y = 0; y <= h - mid; ++y)
    {
        std::vector<int> data_x(w, 0);
        int sum_x = 0;

        if (y == 0)
        {
            for (int y = 0; y < mid; ++y)
            {
                sum_y += data_y[y];
                // std::cout << "\ty : " << y << " " << sum_y << "(" << data_y[y] << ")" << std::endl;
            }
        }
        else
        {
            sum_y -= data_y[y - 1];
            sum_y += data_y[y + mid - 1];
            // std::cout << "\ty : " << y << " " << sum_y << "(" << data_y[y - 1] << "/" << data_y[y + mid - 1] << ")" << std::endl;
        }
        for (int x = 0; x <= w - mid; ++x)
        {
            if (x == 0)
            {
                for (int x = 0; x < mid; ++x)
                {
                    for (int dy = 0; dy < y; ++dy)
                    {
                        data_x[x] += data[dy][x];
                    }
                    for (int dy = y + mid; dy < h; ++dy)
                    {
                        data_x[x] += data[dy][x];
                    }
                    sum_x += data_x[x];
                }

                // for (int i = 0; i < data_x.size(); ++i)
                //     std::cout << "x0!\t" << i << " : " << data_x[i] << std::endl;                
            }
            else
            {
                sum_x -= data_x[x - 1]; 
                for (int dy = 0; dy < y; ++dy)
                {
                    data_x[x + mid - 1] += data[dy][x + mid - 1];
                }
                for (int dy = y + mid; dy < h; ++dy)
                {
                    data_x[x + mid - 1] += data[dy][x + mid - 1];
                }
                sum_x += data_x[x + mid - 1];
                // for (int i = 0; i < data_x.size(); ++i)
                //     std::cout << "x!\t" << i << " : " << data_x[i] << std::endl;    
            }
            max = std::max(max, sum_x + sum_y);
            // std::cout << "y/x : " << y << "/" << x << " " << sum_y << "/" << sum_x << std::endl;
            if (max == n)
                return true;
        }
    }
    return false;
}

size_t binary_search(std::vector<std::vector<int>>& data,
                    std::vector<int>& data_y,
                    size_t h, size_t w, size_t n)
{
    size_t left = 1;
    size_t right = std::min(w, h);

    while (left < right)
    {
        size_t mid = (left + right) / 2;
        // std::cout << "before : " << mid << " " << left << " " << right << std::endl;
        if (check(mid, data, data_y, h, w, n))
            right = mid;
        else
            left = mid + 1;
        // std::cout << "after : " << left << " " << right << std::endl;
    }

    return left;
}

int main()
{
    std::ifstream input("input.txt");
    size_t w, h, n;
    input >> w >> h >> n;

    std::vector<std::vector<int>> data(h, std::vector<int>(w, 0));
    std::vector<int> data_y(h, 0);
    for (int i = 0; i < n; ++i)
    {
        size_t x, y;
        input >> x >> y;
        data[y - 1][x - 1] = 1;
        data_y[y - 1] += 1;
    }
    input.close();

    std::cout << binary_search(data, data_y, h, w, n) << std::endl;

    // std::cout << "  ";
    // for (int x = 0; x < w; ++x)
    //     std::cout << x; 
    // std::cout << std::endl;  
    // for (int y = 0; y < h; ++y)
    // {
    //     std::cout << y << " ";
    //     for (int x = 0; x < w; ++x)
    //     {
    //         std::cout << (data[y][x] ? '#' : '.'); 
    //     }
    //     std::cout << std::endl;
    // }        
    return 0;
}