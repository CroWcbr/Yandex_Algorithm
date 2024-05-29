// TL - time-limit-exceeded
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Point
{
    int start;
    int end;
    float Intersecting = false;
};

bool comparePoint(const Point& a, const Point& b)
{
    return a.start < b.start;
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<Point> data(N);
    for (int i = 0; i < N; ++i)
        std::cin >> data[i].start >> data[i]. end;

    std::sort(data.begin(), data.end(), comparePoint);

    int answer = data.size();
    for (int i = 0; i < N; ++i)
    {
        if (data[i].Intersecting)
            continue;

        // std::cout << i << "\t" << data[i].start << "\t" << data[i].end << std::endl;
        for (int j = i + 1; j < N; ++j)
        {    
            if (data[i].start == data[j].start || data[i].end >= data[j].end)
            {
                // std::cout << "\t" << data[j].start << "\t" << data[j].end << std::endl;
                if (!data[i].Intersecting)
                {
                    data[i].Intersecting = true;
                    --answer;
                }
                if (!data[j].Intersecting)
                {
                    data[j].Intersecting = true;
                    --answer;
                }
            }
        }
    }

    std::cout << answer << std::endl;
    return 0;
}