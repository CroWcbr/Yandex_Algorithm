#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        std::cin >> n;

        std::vector<int> data(n);
        for (int a = 0; a < n; ++a)
            std::cin >> data[a];
        // sort(data.begin(), data.end());

        std::vector<int> answer;
        std::vector<int> tmp;
        int min = -1;
        for (int a = 0; a < n; ++a)
        {
            if (min == -1 || min > data[a])
            {
                min = data[a];
                if (min < tmp.size() + 1)
                {
                    answer.push_back(tmp.size());
                    tmp.clear();  
                }
            }

            tmp.push_back(data[a]);
            // std::cout << a << "\t" << data[a] << "\t" << tmp.back() << "\t" << tmp.size() << std::endl;
            if (min == tmp.size() || a == n - 1)
            {
                answer.push_back(tmp.size());
                tmp.clear();
                min = -1;
            }
        }
        std::cout << answer.size() << std::endl;
        for (int a = 0; a < answer.size(); ++a)
            std:: cout << answer[a] << " ";
        std::cout << std::endl;
    }

    return 0;
}
