#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int binary(const std::vector<std::string>& dict, int k, const std::string& prefix)
{
    int left = 0;
    int right = dict.size() - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (dict[middle].compare(0, prefix.size(), prefix) == 0)
        {
            if (middle == 0 || dict[middle - 1].compare(0, prefix.size(), prefix) != 0)
            {
                left = middle;
                break;
            }
            else
                right = middle - 1;
        }
        else if (dict[middle].compare(prefix) < 0)
            left = middle + 1;
        else
            right = middle - 1;
    }

    if (left < dict.size() && dict[left].compare(0, prefix.size(), prefix) == 0)
    {
        int kIndex = left + k - 1;
        if (kIndex < dict.size() && dict[kIndex].compare(0, prefix.size(), prefix) == 0)
            return kIndex + 1;
    }   

    return -1;
}

int main()
{
    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::string> dict(N);
    for (int i = 0; i < N; ++i)
        std::cin >> dict[i];
    
    std::vector<int> result(Q);
    for (int i = 0; i < Q; ++i)
    {
        std::string prefix;
        int k;
        std::cin >> k >> prefix;

        result[i] = binary(dict, k, prefix);

        // TL - линейная сложность
        // auto it = std::lower_bound(dict.begin(), dict.end(), prefix);
        
        // int count = 0;
        // result[i] = -1;
        // while (it != dict.end() && (*it).compare(0, prefix.size(), prefix) == 0)
        // {
        //     count++;
        //     if (count == k)
        //     {
        //         result[i] = std::distance(dict.begin(), it) + 1;
        //         break;
        //     }
        //     ++it;
        // }
    }

    for (int i : result)
        std::cout << i << std::endl;

    return 0;
}
