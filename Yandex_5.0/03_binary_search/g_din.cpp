// dynamic program
#include <iostream>
#include <fstream>
#include <vector>

#define DEBUG 1

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

    int answer = 1;
    for (int r = 1; r <= n; ++r)
        for (int c = 1; c <= m; ++c)
        {
            if (data[r][c] > answer)
            {
                for (int i = 1; ; ++i)
                {
                    int tmp_answer = std::min(std::min(data[r - i][c], data[r][c - i]), std::min(data[r + i][c], data[r][c + i]));
                    if (i > tmp_answer)
                        break;
                    if (answer < i)
                        answer = i;
                }   
            }

        }

    std::cout << answer << std::endl;
    return 0;
}