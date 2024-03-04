#include <iostream>
#include <vector>
#include <string>

void update(const std::vector<char>& d, std::vector<bool>& a, int r, int c, int dr, int dc)
{
    a[r * 8 + c] = true;
    r += dr;
    c += dc;
    while (r >= 0 && r < 8 && c >= 0 && c < 8)
    {
        if (d[r * 8 + c] == '*')
            a[r * 8 + c] = true;
        else
            break;
        r += dr;
        c += dc;
    }
}

int main()
{
    std::vector<char> d(64);

    char ch;
    for (int r = 0; r < 8; ++r)
    {
        for (int c = 0; c < 8;)
        {
            std::cin >> ch;
            if (ch == 'R' || ch == 'B' || ch == '*')
                d[r * 8 + c++] = ch;
        }
    }

    std::vector<bool> a(64, false);
    for (int r = 0; r < 8; ++r)
    {
        for (int c = 0; c < 8; ++c)
        {
            if (d[r * 8 + c] == 'R')
            {
                update(d, a, r, c, 0, -1);
                update(d, a, r, c, 0, 1);
                update(d, a, r, c, -1, 0);
                update(d, a, r, c, 1, 0);
            }
            else if (d[r * 8 + c] == 'B')
            {
                update(d, a, r, c, -1, -1);
                update(d, a, r, c, -1, 1);
                update(d, a, r, c, 1, -1);
                update(d, a, r, c, 1, 1);
            }
        }
    }

    // for (int r = 0; r < 8; ++r)
    // {
    //     for (int c = 0; c < 8; ++c)
    //         std::cout << a[r * 8 + c];
    //     std::cout <<std::endl;
    // }

    int answer = 64;
    for (int i = 0; i < 64; ++i)
        if (a[i])
            --answer;
    
    std::cout << answer << std::endl;

    return 0;
}