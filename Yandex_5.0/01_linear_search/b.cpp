#include <iostream>
#include <vector>

int main()
{
	int N, K;
	std::cin >> N >> K;

    int prev, next;
    std::cin >> prev;
    int min_next = -1;
    int left_next = -1;

    int answer = 0;
    int left = 0;
    int min = prev;
    for (int i = 1; i < N; ++i)
    {
        std::cin >> next;
        if (min >= next)
        {
            min = next;
            left = i;
            min_next = -1;
            left_next = -1;
            continue;
        }

        if (min_next == -1 || min_next >= next)
        {
            min_next = next;
            left_next = i;
        }

        if (i - left > K)
        {
            left = left_next;
            min = min_next;
            min_next = -1;
            left_next = -1;
        }

        if (answer < next - min)
            answer = next - min;
    }
    std::cout << answer << std::endl;
    return 0;
}