#include <iostream>
#include <vector>
#include <string>

bool isValueInVector(const std::vector<long long int>& vec, int value)
{
    for (const auto& element : vec)
        if (element == value)
            return true;
    return false;
}

int main()
{
    int n, k, d;
    std::cin >> n >> k >> d;

    std::vector<long long int> reminder(1, n % k);
    std::vector<std::string> answer(1, std::to_string(n));
    for (int i = 0; i < d; ++i)
    {
        std::vector<long long int> update_reminder;
        std::vector<std::string> update_answer;
        for (int v = 0; v < reminder.size(); ++v)
            for (int j = 0; j < 10; ++j)
            {
                int tmp = (reminder[v] * 10 + j) % k;
                if (tmp == 0 && !isValueInVector(update_reminder, tmp))
                {
                    update_reminder.push_back(tmp);
                    update_answer.push_back(answer[v] + std::to_string(j));
                }
            }
        reminder = std::move(update_reminder);
        answer = std::move(update_answer);
    }
    if (reminder.empty())
        std::cout << -1 << std::endl;
    else
        std::cout << answer[0] << std::endl;
    return 0;
}