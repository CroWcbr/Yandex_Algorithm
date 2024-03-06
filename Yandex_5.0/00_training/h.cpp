#include <iostream>
#include <cmath>

double min_time(int L, int x1, double v1, int x2, double v2) 
{
    if (v1 == 0 && v2 == 0)
        return (x1 == x2 || x1 + x2 == L) ? 0 : -1;

    double dt = 0.00001;
    double t = 0;
    double d1 = x1;
    double d2 = x2;
    // while (fabs(d1 - d2) > 1e-9 || fabs(fabs(d1 + d2) - L) < 1e-9)
    for (;fabs(d1 - d2) > 1e-9 || fabs(fabs(d1 + d2) - L) < 1e-9;t += dt)
    {
        std::cout << t << "\t" << d1 << "\t" << d2 << std::endl;
        d1 = fmod(x1 + v1 * t, L);
        if (d1 < 0)
            d1 += L;
        d2 = fmod(x2 + v2 * t, L);
        if (d2 < 0)
            d2 += L;  
    }
    return t;
}

int main() {
    int L, x1, v1, x2, v2;
    std::cin >> L >> x1 >> v1 >> x2 >> v2;
    
    double t = min_time(L, x1, v1, x2, v2);
    if (t < 0)
        std::cout << "no" << std::endl;
    else
        std::cout << "yes" << std::endl << min_time(L, x1, v1, x2, v2) << std::endl;
    return 0;
}