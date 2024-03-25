#include <iostream>
#include <set>
#include <map>

int main()
{
    std::map<int, int> ans;
    for (int i3 = 0; i3 < 3; i3++)
    {
        int n;
        std::cin >> n;

        std::set<int> tmp;
        for (int i = 0; i < n; i++)
        {
            int x;
            std::cin >> x;
            tmp.insert(x);
        }
        for (auto i : tmp)
            ans[i]++;
    }

    for (auto i : ans)
        if (i.second > 1)
            std::cout << i.first << " ";
    std::cout << std::endl;
    return 0;
}