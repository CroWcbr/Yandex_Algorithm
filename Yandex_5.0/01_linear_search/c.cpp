#include <iostream>

int main()
{
	int N;
    std::cin >> N;

    int l;
    std::cin >> l;
    int max, tmp;
    max = tmp = l;
    for (int i = 1; i < N; ++i)
    {
        std::cin >> l;
        tmp += l;
        if (l > max)
            max = l;
    }

    int answer = max + max - tmp;
    std::cout << (answer <= 0 ? tmp : answer) << std::endl;
    return 0;
}