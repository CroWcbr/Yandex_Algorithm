#include <iostream>
#include <vector>
#include <algorithm>

struct Point
{
    int y;
    int x;
};

bool sort_y(const Point& a, const Point& b)
{
    return a.y < b.y;
}

int main()
{
    
	int N;
	std::cin >> N;
    
    std::vector<Point> data(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> data[i].y >> data[i].x;
        --data[i].y;
        --data[i].x;
    }
    std::sort(data.begin(), data.end(), sort_y);

    int answer_y = 0;
    for (int i = 0; i < data.size(); ++i)
    {
        if (data[i].y != i)
        {
            answer_y += abs(i - data[i].y); 
            data[i].y = i;
        }
    }

    int answer_x = -1;
    for (int i = 0; i < N; ++i)
    {
        int tmp = 0;
        for (int x = 0; x < N; ++x)
            tmp += abs(data[i].x - data[x].x);
        if (answer_x > tmp || answer_x == -1)
            answer_x = tmp;
    }

    std::cout << answer_y + answer_x << std::endl;
    return 0;
}