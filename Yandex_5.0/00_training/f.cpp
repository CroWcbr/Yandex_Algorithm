#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    
    int a;
    std::cin >> a;

    bool prev_even = (a % 2 == 0);
    for (int i = 1; i < n; ++i)
    {
        std::cin >> a;
        
        bool a_even = (a % 2 == 0);
        // std::cout << a << "\t" << prev_even << "\t" << a_even << std::endl;
        if ((prev_even && a_even) || \
            (!prev_even && !a_even))
        {
            prev_even = prev_even ? true : false;
            std::cout << "x";
        }
        else
        {
            prev_even = false;
            std::cout << "+";
        }
    }

    return 0;
}