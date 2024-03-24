#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

struct Point
{
    int x;
    int y;
    int x_v;
    int y_v;
};

void read_input(std::ifstream& input,
                int n,
				std::vector<Point>& line)
{
    int x1, y1, x2, y2;
    for (int i = 0; i < n; ++i)
    {
        input >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2 || (x2 == x1 && y1 > y2))
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        x1 += 10000;
        y1 += 10000;
        x2 += 10000;
        y2 += 10000;
        line[i] = {x1, y1, x2 - x1, y2 - y1};
    }
}

size_t my_key(int x, int y)
{
    return x * 20000 + y;
}

int main()
{
	std::ifstream input("input.txt");
	int n;
	input >> n;
    std::vector<Point> first_line(n);
    std::vector<Point> second_line(n);
	read_input(input, n, first_line);
    read_input(input, n, second_line);
	input.close();

    std::unordered_map<int, int> ans;
    for (auto& f : first_line)
        for (auto& v : second_line)
            if (f.x_v == v.x_v && f.y_v == v.y_v)
                ans[my_key(v.x - f.x, v.y - f.y)] += 1;

    int answer = 0;
    for (const auto& pair : ans)
        if (pair.second > answer)
            answer = pair.second;
    std::cout << n - answer << std::endl;

    return 0;
}
