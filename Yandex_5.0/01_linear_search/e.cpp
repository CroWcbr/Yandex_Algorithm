#include <iostream>
#include <vector>
#include <algorithm>

struct MyStruct {
    int i;
    int a;
    int b;
};

int main()
{
	int n;
	std::cin >> n;
    
    std::vector<int> data_good;
    std::vector<int> data_bad;
    MyStruct max_good = {-1, 0, 0};
    MyStruct max_bad = {-1, 0, 0};
    long long int answer = 0;
    for (int i = 1; i <= n; ++i)
    {
        int a,b;
        std::cin >> a >> b;
        if (a - b <= 0)
        {
            data_bad.push_back(i);
            if (a > max_bad.a)
                max_bad = {i, a, b};
        }
        else
        {
            data_good.push_back(i);
            answer += a - b;
            if (b > max_good.b)
                max_good = {i, a, b};
        }
    }

    if (max_bad.a > max_good.b)
    {
        answer += max_bad.a;
        if (!data_bad.empty())
        {
            data_bad.erase(std::find(data_bad.begin(), data_bad.end(), max_bad.i));
            data_bad.insert(data_bad.begin(), max_bad.i);
        }
    }
    else
    {
        answer += max_good.b;
        if (!data_good.empty())
        {
            data_good.erase(std::find(data_good.begin(), data_good.end(), max_good.i));
            data_good.push_back(max_good.i);
        }
    }

    std::cout << answer << std::endl;
    for (int i = 0; i < data_good.size(); ++i)
        std::cout << data_good[i] << " ";
    for (int i = 0; i < data_bad.size(); ++i)
        std::cout << data_bad[i] << " ";
    std::cout << std::endl;

    return 0;
}
