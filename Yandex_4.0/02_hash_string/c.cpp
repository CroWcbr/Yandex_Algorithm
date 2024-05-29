#include <iostream>
#include <string>
#include <vector>

int main()
{
    // std::string str = "abracadabra";
    std::string str = "ababa";
    // std::cin >> str;

	const int p = 257;
	const int mod = 1000000007;
    std::vector<long long> h(str.length());
    long long prev = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        h[i] = (prev * p + (int)str[i]) % mod;
        prev = h[i];
        std::cout << h[i] << " : " << prev * p << " : " << (int)str[i] << std::endl;
    }

    std::vector<int> answer(str.length());
    answer[0] = 0;

    for (int i = 1, n = str.length(); i < n; ++i)
    {
        int count = 0;
        // long long hash = 0;
        // prev = 0;
        long long tmp = h[i - 1] * p;
        for (int j1 = 0, j2 = i; j2 < n; ++j1, ++j2)
        {
            // hash = (prev * p + (int)str[j2]) % mod;
            // prev = hash;
            std::cout << j1 << "/" << j2 << "\t" << h[j1] << "\t" << (h[j2] - tmp + static_cast<long long>(mod) * p) % mod << std::endl;
            if (h[j1] != (h[j2] - tmp + static_cast<long long>(mod) * p) % mod)
                break;
            ++count;
        }
        answer[i] = count;
    }

    std::cout << h[0] << std::endl;
    std::cout << h[1] << std::endl;
    std::cout << (h[3] - h[1] * p) % mod << std::endl;

    for (auto& v : answer)
        std::cout << v << " ";
    std::cout << std::endl;
}
