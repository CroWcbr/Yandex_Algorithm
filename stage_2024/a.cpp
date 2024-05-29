#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string input;
    std::getline(std::cin, input);

    int len = 0;
    std::vector<std::string> tmp;
    std::string tmp_str;
    input.push_back(' ');
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] == ' ' || input[i] == ',')
        {
            if (!tmp_str.empty())
            {
                if (len < tmp_str.size())
                    len = tmp_str.size();
                tmp.push_back(tmp_str);                
                tmp_str.clear();
            }

            if (input[i] == ',')
            {
                tmp.back().push_back(',');
            }
        }
        else
            tmp_str.push_back(input[i]);
    }

    len *= 3;
    int cur_len = tmp[0].size();
    std::cout << tmp[0];
    for (int i = 1; i < tmp.size(); ++i)
    {
        if (cur_len + 1 + tmp[i].size() <= len)
        {
            std::cout << " " << tmp[i];
            cur_len += 1 + tmp[i].size();
        }
        else
        {
            std::cout << std::endl << tmp[i];
            cur_len = tmp[i].size();
        }
    }
    std::cout << std::endl;

    return 0;
}