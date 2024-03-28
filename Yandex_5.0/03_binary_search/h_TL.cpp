#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>

#define DEBUG 0
struct Party
{
    int vote;
    int gift;
    int id;
};

bool operator<(const Party & p1, const Party & p2)
{
	if (p1.vote < p2.vote)
		return true;
	else if (p1.vote == p2.vote && p1.gift < p2.gift)
	    return true;
	return false;
}

bool check(int64_t mid, std::vector<Party>& party, int choice_id)
{
    int64_t target_choice = party[choice_id].vote + mid;
    for (int i = 0; i < party.size(); ++i)
    {
        if (i == choice_id || party[i].vote < target_choice)
            continue;
        
        mid = mid - (party[i].vote - target_choice + 1);

        if (mid < 0)
            break;
    }
if (DEBUG) std::cout << "mid : " << mid << std::endl;
    if (mid >= 0)
        return true;
    else
        return false;
}

void binary_search(std::vector<Party> party,
                    int64_t max_vote,
                    int& choice_id,
                    int64_t& additional_vote) 
{
    std::sort(party.begin(), party.end());
    // for (int i = 0; i < party.size(); ++i)
    //     std::cout << party[i].vote << "(" << party[i].gift << ") ";
    // std::cout << std::endl;

    int64_t answer = max_vote + 1;
    for (int i = 0; i < party.size(); ++i)
    {
        if (party[i].gift == -1)
            continue;

        if (choice_id != -1)
        {
            int tmp_additional = answer - party[i].gift;
            if (tmp_additional < 0)
                continue;
            if (party[i].vote + tmp_additional <= party[choice_id].vote + additional_vote)
                continue;
        }

        int64_t L = 0;
        int64_t R = max_vote;

        while (L < R)
        {
            int64_t mid = (L + R) / 2;
if (DEBUG) std::cout << mid << " " << L << " " << R << std::endl;
            if (check(mid, party, i))
                R = mid;
            else
                L = mid + 1;
if (DEBUG) std::cout << "\t" << mid << " " << L << " " << R << std::endl;
        }
        if (answer > L + party[i].gift)
        {
            answer = L + party[i].gift;
            choice_id = i;
            additional_vote = L;
        }
    }
    choice_id = party[choice_id].id;
}

void update_data_vote(std::vector<Party>& party, int additional_vote, int choice_id)
{
    bool flag = false;
    party[choice_id].vote += additional_vote;
    for (int i = 0, n = party.size(); i < n, additional_vote; ++i)
    {
        if (i == choice_id)
            ;
        else if (flag && party[i].vote > 0)
        {
            party[i].vote--;
            additional_vote--;
        }
        else if (party[choice_id].vote > party[i].vote)
            ;
        else
        {
            while (party[choice_id].vote <= party[i].vote)
            {
                party[i].vote--;
                additional_vote--;
            }
        }
        if (i == n - 1)
        {
            flag = true;
            i = -1;
        }
    }
}

int main()
{
    std::ifstream input("input.txt");
    int n;
    input >> n;
    std::vector<Party> party(n);
    int64_t max_vote = 0;
    for (int i = 0; i < n; ++i)
    {
        input >> party[i].vote >> party[i].gift;
        max_vote += party[i].vote;
        party[i].id = i;
    }
    input.close();

    int choice_id = -1;
    int64_t additional_vote = 0;
    binary_search(party, max_vote, choice_id, additional_vote);

    std::cout << additional_vote + party[choice_id].gift << std::endl;
    std::cout << choice_id + 1 << std::endl;
    update_data_vote(party, additional_vote, choice_id);
    for (int i = 0; i < n; ++i)
        std::cout << party[i].vote << " ";
    std::cout << std::endl;
    return 0;
}
