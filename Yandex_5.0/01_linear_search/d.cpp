#include <iostream>
#include <vector>

int main()
{
	int N;
    std::cin >> N;

    std::vector<int> tmp(100, 0);
    for (int i = 0; i < N; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        int pos = 10 * y + x;
        tmp[pos] = 4;
        if (tmp[pos - 10])
        {
            tmp[pos - 10]--;
            tmp[pos]--;
        }
        if (tmp[pos + 10])
        {
            tmp[pos + 10]--;
            tmp[pos]--;            
        }
        if (tmp[pos - 1])
        {
            tmp[pos - 1]--;
            tmp[pos]--;                 
        }
        if (tmp[pos + 1])
        {
            tmp[pos + 1]--;
            tmp[pos]--;             
        }         
    }

    int answer = 0;
    for (int i = 0; i < 100; ++i)
        answer += tmp[i];

    std::cout << answer << std::endl;
    return 0;
}