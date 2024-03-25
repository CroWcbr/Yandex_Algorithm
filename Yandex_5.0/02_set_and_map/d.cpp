#include <iostream>
#include <map>

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::map<int, int> tmp;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;

        if (tmp.find(x) != tmp.end() && i - tmp[x] <= k)
        {
            std::cout << "YES" << std::endl;
            return 0;
        }
        tmp[x] = i;
    }


    std::cout << "NO" << std::endl;
    return 0;
}