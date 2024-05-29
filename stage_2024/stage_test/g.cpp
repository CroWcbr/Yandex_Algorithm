#include <iostream>
#include <string>

int main()
{
    std::string J_str, S_str;
    std::cin >> J_str >> S_str;

	int J[128];
    for(int i = 0; i < 128; ++i)
        J[i] = 0;
    for (auto c : J_str)
        J[c] = 1;

    int answer = 0;  
    for (auto c : S_str)
        if (J[(int)c])
            ++answer;
	
    std::cout << answer << std::endl;

    return 0;
}