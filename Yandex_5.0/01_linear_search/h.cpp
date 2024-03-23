#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG 0

struct Point
{
    int y;
    int x;
};

std::vector<Point> find_max(std::vector<std::vector<int>>& data, int y_del, int x_del)
{
if (DEBUG) std::cout << std::endl;
if (DEBUG) std::cout << y_del << "\t" << x_del << std::endl;
    std::vector<Point> tmp;
    int max = 0;
    for (int y = 0; y < data.size(); ++y)
    {
        if (y == y_del)
            continue;
        for (int x = 0; x < data[y].size(); ++x)
        {
            if (x == x_del)
                continue;
if (DEBUG) std::cout << data[y][x] << " ";
            if (max < data[y][x])
            {
                tmp.clear();
                tmp.push_back({y, x});
                max = data[y][x];
            }
        }
if (DEBUG) std::cout << std::endl;
    }
if (DEBUG) std::cout << max << std::endl;
if (DEBUG) std::cout << std::endl;
    return tmp;
}
int main()
{
    
	int n, m;
	std::cin >> n >> m;
    
    std::vector<std::vector<int>> data(n, std::vector<int>(m));
    
    for (int y = 0; y < n; ++y)
        for (int x = 0; x < m; ++x)
            std::cin >> data[y][x];

    std::vector<Point> max_elem = find_max(data, -1, -1);

    Point answer;
    int max = data[max_elem[0].y][max_elem[0].x];
    for (auto& p : max_elem)
    {
        std::vector<Point> max_elem_del_y = find_max(data, p.y, -1);
        for(auto& p_del_y : max_elem_del_y)
        {
            std::vector<Point> max_elem_del_y_x = find_max(data, p.y, p_del_y.x);
            if (max > data[max_elem_del_y_x[0].y][max_elem_del_y_x[0].x])
            {
                max = data[max_elem_del_y_x[0].y][max_elem_del_y_x[0].x];
                answer = {p.y, p_del_y.x};
            }
        }
        std::vector<Point> max_elem_del_x = find_max(data, -1, p.x);
        for(auto& p_del_x : max_elem_del_x)
        {
            std::vector<Point> max_elem_del_x_y = find_max(data, p_del_x.y, p.x);
            if (max > data[max_elem_del_x_y[0].y][max_elem_del_x_y[0].x])
            {
                max = data[max_elem_del_x_y[0].y][max_elem_del_x_y[0].x];
                answer = {p_del_x.y, p.x};
            }
        }
    }
    std::cout << answer.y + 1 << " " << answer.x + 1 << std::endl;
    return 0;
}