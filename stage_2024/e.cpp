#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


struct Pair {
    std::string first;
    int second;
    int index;
};

bool comparePairs(const Pair& a, const Pair& b) {
    return a.first < b.first;
}

int binary(const std::vector<Pair>& dict, const std::string& prefix)
{
    int left = 0;
    int right = dict.size() - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (dict[middle].first.compare(0, prefix.size(), prefix) == 0)
        {
            if (middle == 0 || dict[middle - 1].first.compare(0, prefix.size(), prefix) != 0)
            {
                left = middle;
                break;
            }
            else
                right = middle - 1;
        }
        else if (dict[middle].first.compare(prefix) < 0)
            left = middle + 1;
        else
            right = middle - 1;
    }

    if (left >= dict.size() || dict[left].first.compare(0, prefix.size(), prefix) != 0)
        return -1;

    int answer_pos = 0;
    while (left < dict.size() && dict[left].first.compare(0, prefix.size(), prefix) == 0)
    {
        if (dict[answer_pos].second < dict[left].second)
            answer_pos = left;
        ++left;
    }   

    return dict[answer_pos].index;
}

int main()
{
    int N, Q;
    std::cin >> N >> Q;

    std::vector<Pair> dict(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> dict[i].first >> dict[i].second;
        dict[i].index = i + 1;
    }
    std::sort(dict.begin(), dict.end(), comparePairs);

    std::vector<int> result(Q);
    std::string prefix;
    for (int i = 0; i < Q; ++i)
    {
        char tmp;
        std::cin >> tmp;
        if (tmp == '+')
        {
            std::cin >> tmp;
            prefix.push_back(tmp);
        }
        else
            prefix.pop_back();
        
        result[i] = binary(dict, prefix);
    }

    for (int i : result)
        std::cout << i << std::endl;

    return 0;
}