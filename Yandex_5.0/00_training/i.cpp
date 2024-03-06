#include <ctime>
#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
    std::vector<std::string> day = {
        "Sunday",
        "Monday", 
        "Tuesday", 
        "Wednesday", 
        "Thursday", 
        "Friday", 
        "Saturday"
        }; 
    std::map<std::string, int> month = {
        {"January", 0},
        {"February", 1},
        {"March", 2},
        {"April", 3},
        {"May", 4},
        {"June", 5},
        {"July", 6},
        {"August", 7},
        {"September", 8}, 
        {"October",  9},
        {"November", 10},
        {"December", 11}
        };
    
    int n;
    std::cin >> n;
    int year;
    std::cin >> year;

    std::tm timeinfo = {};
    timeinfo.tm_year = year - 1900;

    std::vector<int> prazdnic(7, 0);
    for (int i = 0; i < n; ++i)
    {
        int d;
        std::string m;
        std:: cin >> d >> m;

        timeinfo.tm_mon = month[m];
        timeinfo.tm_mday = d;
       
       std::mktime(&timeinfo);

       prazdnic[timeinfo.tm_wday]++;
    }

    std::string first_day_string;
    std::cin >> first_day_string;
    int first_day = -1;
    while (first_day < 7)
        if (day[++first_day] == first_day_string)
            break;

    std::vector<int> count_day(7, 0);  
    int days_in_year = 365;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        ++days_in_year;
    for (int i = 0; i < days_in_year; ++i)
        count_day[(first_day + i) % 7]++;

    for (int i = 0; i < 7; ++i)
        std::cout << day[i] << "\t" << count_day[i] << std::endl;

    int d_min = 0;
    int d_max = 0;
    for (int i = 1; i < 7; ++i)
    {
        if (count_day[i] - prazdnic[i] < count_day[d_min] - prazdnic[d_min])
            d_min = i;
        if (count_day[i] - prazdnic[i] > count_day[d_max] - prazdnic[d_max])
            d_max = i;
    }

    std::cout << day[d_max] << " " << day[d_min] << std::endl;

    return 0;
}