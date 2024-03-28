#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <limits>

#define DEBUG 1

bool check(int64_t mid, const std::vector<int>& data_vote, int choice_id)
{
    int64_t target_choice = data_vote[choice_id] + mid;
    for (int i = 0; i < data_vote.size(); ++i)
    {
        if (i == choice_id || data_vote[i] < target_choice)
            continue;
        
        mid = mid - (data_vote[i] - target_choice + 1);

        if (mid < 0)
            break;
    }

    if (mid >= 0)
        return true;
    else
        return false;
}

void binary_search(const std::vector<int>& data_vote, 
                    const std::vector<int>& data_gift,
                    int64_t max_vote,
                    int& choice_id,
                    int64_t& additional_vote) 
{
    int64_t answer = std::numeric_limits<int64_t>::max();
    for (int i = 0; i < data_vote.size(); ++i)
    {
        if (data_gift[i] == -1)
            continue;

        int64_t L = 0;
        int64_t R = max_vote;

        while (L < R)
        {
            int64_t mid = (L + R) / 2;
            if (check(mid, data_vote, i))
                R = mid;
            else
                L = mid + 1;
        }

        if (answer > L + data_gift[i])
        {
            answer = L + data_gift[i];
            choice_id = i;
            additional_vote = L;
        }
    }
}

int main()
{
    std::ifstream input("input.txt");
    int n;
    input >> n;

    std::vector<int> data_vote(n);
    std::vector<int> data_gift(n);
    int64_t max_vote = 0;
    for (int i = 0; i < n; ++i)
    {
        input >> data_vote[i] >> data_gift[i];
        max_vote += data_vote[i];
    }
    input.close();


    int choice_id;
    int64_t additional_vote;
    binary_search(data_vote, data_gift, max_vote, choice_id, additional_vote);

    std::cout << additional_vote + data_gift[choice_id] << std::endl;
    std::cout << choice_id + 1 << std::endl;
    bool flag = false;
    data_vote[choice_id] += additional_vote;
    int i = 0;
    for (; i < n, additional_vote; ++i)
    {
        if (i == choice_id)
            ;
        else if (flag && data_vote[i] > 0)
        {
            data_vote[i]--;
            additional_vote--;
        }
        else if (data_vote[choice_id] > data_vote[i])
            ;
        else
        {
            while (data_vote[choice_id] <= data_vote[i])
            {
                data_vote[i]--;
                additional_vote--;
            }
        }
        if (i == n - 1)
        {
            flag = true;
            i = -1;
        }
    }
    for (int i = 0; i < n; ++i)
        std::cout << data_vote[i] << " ";
    std::cout << std::endl;
    return 0;
}
