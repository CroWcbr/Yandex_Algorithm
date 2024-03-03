#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    long long int answer = 0;
    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        answer += a / 4;
        a = a % 4;
        if (a == 3)
           answer += 2;
        else
            answer += a;
    }

    std::cout << answer << std::endl;

    return 0;
}