/*
H. Выборы
В одной демократической стране приближаются парламентские выборы. Выборы проходят по следующей схеме: каждый житель страны, достигший восемнадцатилетнего возраста, отдает свой голос за одну из политических партий. После этого партия, которая набрала максимальное количество голосов, считается победившей на выборах и формирует правительство. Если несколько партий набрали одинаковое максимальное количество голосов, то они должны сформировать коалиционное правительство, что обычно приводит к длительным переговорам.
Один бизнесмен решил выгодно вложить свои средства и собрался поддержать на выборах некоторые партии. В результате поддержки он планирует добиться победы одной из этих партий, которая затем сформирует правительство, которое будет действовать в его интересах. При этом возможность формирования коалиционного правительства его не устраивает, поэтому он планирует добиться строгой победы одной из партий.
Чтобы повлиять на исход выборов, бизнесмен собирается выделить деньги на агитационную работу среди жителей страны. Исследование рынка показало, что для того, чтобы один житель сменил свои политические воззрения, требуется потратить одну условную единицу. Кроме того, чтобы i-я партия в случае победы сформировала правительство, которое будет действовать в интересах бизнесмена, необходимо дать лидеру этой партии взятку в размере pi условных единиц. При этом некоторые партии оказались идеологически устойчивыми и не согласны на сотрудничество с бизнесменом ни за какие деньги.
По результатам последних опросов известно, сколько граждан планируют проголосовать за каждую партию перед началом агитационной компании. Помогите бизнесмену выбрать, какую партию следует подкупить, и какое количество граждан придется убедить сменить свои политические воззрения, чтобы выбранная партия победила, учитывая, что бизнесмен хочет потратить на всю операцию минимальное количество денег.

Формат ввода
В первой строке вводится целое число n – количество партий (1 ≤ n ≤ 10^5). Следующие n строк описывают партии. Каждая из этих строк содержит по два целых числа: vi – количество жителей, которые собираются проголосовать за эту партию перед началом агитационной компании, и pi – взятка, которую необходимо дать лидеру партии для того, чтобы сформированное ей в случае победы правительство действовало в интересах бизнесмена (1 ≤ vi ≤ 10^6, 1 ≤ pi ≤ 10^6 или pi = -1). Если партия является идеологически устойчивой, то pi равно -1. Гарантируется, что хотя бы одно pi не равно -1.

Формат вывода
В первой строке выведите минимальную сумму, которую придется потратить бизнесмену. Во второй строке выведите номер партии, лидеру которой следует дать взятку. В третьей строке выведите n целых чисел – количество голосов, которые будут отданы за каждую из партий после осуществления операции. Если оптимальных решений несколько, выведите любое.
*/

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

    if (mid >= 0)
        return true;
    else
        return false;
}

int64_t binary_search_votes(std::vector<Party> party,
                    int64_t max_vote,
                    int choice_id) 
{
    int64_t L = 0;
    int64_t R = max_vote;

    while (L < R)
    {
        int64_t mid = (L + R) / 2;
        if (check(mid, party, choice_id))
            R = mid;
        else
            L = mid + 1;
    }
    return L;
}

int binary_search_id(std::vector<Party> party) 
{
    int choice_id = -1;
    std::sort(party.begin(), party.end());
    std::vector <int64_t> Sum_count(party.size());
    int64_t count = 0;
    for (int i = party.size() - 1; i >= 0; --i)
    {
        Sum_count[i] = count;
        count += party[i].vote;
    }

    int64_t answer = std::numeric_limits<int64_t>::max();
    int64_t l1, r1, mid1, l2, r2, mid2;
    for (int i = 0; i < party.size(); ++i)
    {
        if (party[i].gift == -1)
            continue;

        l1 = party[i].vote;
        r1 = count;
        while (l1 + 1 < r1)
        {
            mid1 = (l1 + r1) / 2;
            l2 = 0;
            r2 = party.size();
            while (l2 + 1 < r2)
            {
                mid2 = (l2 + r2) / 2;
                if (party[mid2].vote >= mid1)
                    r2 = mid2;
                else
                    l2 = mid2;
            }
            
            if (Sum_count[r2 - 1] - (party.size() - r2) * (mid1 - 1) + party[i].vote <= mid1)
                r1 = mid1;
            else
                l1 = mid1;
        }

        if (answer > r1 + party[i].gift - party[i].vote)
        {
            answer = r1 + party[i].gift - party[i].vote;
            choice_id = i;            
        }
    }
    return party[choice_id].id;
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

    int choice_id = binary_search_id(party);
    int64_t additional_vote = binary_search_votes(party, max_vote, choice_id);

    std::cout << additional_vote + party[choice_id].gift << std::endl;
    std::cout << choice_id + 1 << std::endl;
    update_data_vote(party, additional_vote, choice_id);
    for (int i = 0; i < n; ++i)
        std::cout << party[i].vote << " ";
    std::cout << std::endl;
    return 0;
}
