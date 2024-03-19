#include <iostream>
#include <string>
#include <set>

int main()
{
	int n;
	std::cin >> n;

    std::set<std::string> answer;
    for (int i_n = 0; i_n < n; ++i_n)
    {
        int k;
        std::cin >> k;
        std::set<std::string> tmp;
        tmp = std::move(answer);

        for(int i = 0; i < k; ++i)
        {
            std::string song;
            std::cin >> song;
            if (tmp.empty())
                answer.insert(song);
            else
            {
                if (tmp.find(song) != tmp.end())
                    answer.insert(song);   
            }
        }
    }
    
    std::cout << answer.size() << std::endl;
    for (auto& song : answer)
        std::cout << song << " ";
    std::cout << std::endl;
    return 0;
}