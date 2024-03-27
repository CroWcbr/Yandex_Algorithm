#include <iostream>
#include <unordered_set>
#include <vector>
#include <functional>

const int RANGE = 200000001; // Размер диапазона от -10^8 до 10^8
const int BOUNDER = 100000000; // граница 10^8

struct Point
{
    int x;
    int y;
};

long long int my_key(int x, int y)
{
    std::hash<int> hasher;
    size_t hash_x = hasher(x);
    size_t hash_y = hasher(y);
    return static_cast<long long int>(hash_x) * RANGE + hash_y;
}

void check_point(std::unordered_set<long long int>& point_set, std::vector<Point>& answer, int tmp_x3, int tmp_y3, int tmp_x4, int tmp_y4)
{
    bool p3 = (point_set.find(static_cast<long long int>(tmp_x3) * RANGE + tmp_y3) != point_set.end());
    bool p4 = (point_set.find(static_cast<long long int>(tmp_x4) * RANGE + tmp_y4) != point_set.end());

    // std::cout << "\t" << p3 << " " << p4 << std::endl;
    // std::cout << tmp_x3 << " " << tmp_y3 << "\t" << tmp_x4 << " " << tmp_y4 << std::endl;
    // std::cout << "\t" << my_key(tmp_x3, tmp_y3) << " " << my_key(tmp_x4, tmp_y4) << std::endl;

    if (p3 && p4)
    {
        std::cout << 0 << std::endl;
        exit(0);
    }
    else if (answer.size() > 1)
    {
        if (p3)
            answer = {{tmp_x4, tmp_y4}};
        else if (p4)
            answer = {{tmp_x3, tmp_y3}};
        else if (answer.size() > 2)
            answer = {{tmp_x3, tmp_y3}, {tmp_x4, tmp_y4}};
    }
}

int main()
{
    std::vector<Point> answer; 

    int N;
    std::cin >> N;

    std::vector<int> x_vec(N);
    std::vector<int> y_vec(N);
    std::unordered_set<long long int> point_set;
    point_set.reserve(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> x_vec[i] >>  y_vec[i];
        point_set.insert(my_key(x_vec[i], y_vec[i]));
        // std::cout << my_key(x_vec[i], y_vec[i]) << std::endl;
    }

    {
        int dx = (x_vec[0] == BOUNDER ? -1 : 1);
        int dy = (y_vec[0] == BOUNDER ? -1 : 1);
        answer = {{x_vec[0] + dx, y_vec[0]}, {x_vec[0], y_vec[0] + dy}, {x_vec[0] + dx, y_vec[0] + dy}};
    }
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            // std::cout << "!!\t" << x_vec[i] << " " << y_vec[i] << " " << x_vec[j] << " " << y_vec[j] << std::endl;
            // на 6 тесте ошибка, хотя все верно считает.... проверка точек, которые не на одной оси x или y
            // if (!(x_vec[i] == x_vec[j] || y_vec[i] == y_vec[j])) 
            // {
            //     int tmp_x3 = x_vec[i];
            //     int tmp_y3 = y_vec[j];
            //     if (abs(tmp_x3) <= BOUNDER || abs(tmp_y3) <= BOUNDER)
            //     {
            //         int tmp_x4 = x_vec[j];
            //         int tmp_y4 = y_vec[i];
            //         if (abs(tmp_x4) <= BOUNDER || abs(tmp_y4) <= BOUNDER)
            //             check_point(point_set, answer, tmp_x3, tmp_y3, tmp_x4, tmp_y4);
            //     }                
            // }

            {
                int dx = x_vec[i] - x_vec[j];
                int dy = y_vec[i] - y_vec[j];

                int tmp_x3 = x_vec[i] + dy;
                int tmp_y3 = y_vec[i] - dx;
                if (abs(tmp_x3) <= BOUNDER || abs(tmp_y3) <= BOUNDER)
                {
                    int tmp_x4 = x_vec[j] + dy;
                    int tmp_y4 = y_vec[j] - dx;
                    if (abs(tmp_x4) <= BOUNDER || abs(tmp_y4) <= BOUNDER)
                        check_point(point_set, answer, tmp_x3, tmp_y3, tmp_x4, tmp_y4);
                }
            }

            {
                int dx = x_vec[i] - x_vec[j];
                int dy = y_vec[i] - y_vec[j];

                int tmp_x3 = x_vec[i] - dy;
                int tmp_y3 = y_vec[i] + dx;
                if (abs(tmp_x3) <= BOUNDER || abs(tmp_y3) <= BOUNDER)
                {
                    int tmp_x4 = x_vec[j] - dy;
                    int tmp_y4 = y_vec[j] + dx;
                    if (abs(tmp_x4) <= BOUNDER || abs(tmp_y4) <= BOUNDER)
                        check_point(point_set, answer, tmp_x3, tmp_y3, tmp_x4, tmp_y4);
                }
            }
        }
    }
    
    std::cout << answer.size() << std::endl;
    for(auto& p : answer)
        std::cout << p.x << " " << p.y << std::endl;
    return 0;
}

