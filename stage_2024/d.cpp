// TL - time-limit-exceeded
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

struct State
{
    int pos;
    int dir;
};

int main()
{
    int N;
    std::cin >> N;

    std::vector<char> data(N);
    State state = {0, 1};
    for (int i =0; i < N; ++i)
    {
        std::cin >> data[i];
        if (data[i] == 'F')
            state.pos += state.dir;
        else if (data[i] == 'L')
            state.dir = -1;
        else if (data[i] == 'R')
            state.dir = 1;  
    }

    int pos = state.pos;
    std::unordered_set<int> answer;

    State tmp_prev = {0, 1};
    for (int i = 0; i < N; ++i)
    {
        State tmp = tmp_prev;
        char command = data[i];
        if (command == 'R')
        {
            if (i == N - 1)
            {
                answer.insert(tmp_prev.pos + tmp_prev.dir);
            }
            else if (i + 1 < N && data[i + 1] == 'F')
            {
                answer.insert(tmp_prev.dir + state.pos); // F
                answer.insert(tmp_prev.pos - state.pos); // L
            }
            tmp_prev.dir = 1;
        }
        else if (command == 'L')
        {
            if (i + 1 < N && data[i + 1] == 'F')
            {
                answer.insert(tmp_prev.dir + state.pos); // F
                answer.insert(tmp_prev.pos - state.pos); // R
            }
            tmp_prev.dir = -1;
        }
        else if (command == 'F')
        {
            if (i + 1 < N && data[i + 1] == 'L')
            {

            }
            else if (i + 1 < N && data[i + 1] == 'R')
            {
                
            }
            else if (i + 1 < N && data[i + 1] == 'F')
            {

            }
            else
                answer.insert(state.pos + tmp_prev.dir);
            tmp_prev.pos += tmp_prev.dir;
        }
    }

    std::cout << answer.size() << std::endl;
    return 0;
}
