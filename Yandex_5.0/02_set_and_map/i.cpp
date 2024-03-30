/*
I. Играйте в футбол!
Ася Вуткина — известный футбольный комментатор. Будучи профессионалом своего дела, Ася тщательно следит за всеми матчами всех европейских чемпионатов.
Благодаря накопленной информации, Ася может во время трансляции матча сообщить какую-нибудь интересную статистику, например: «Индзаги третий матч подряд забивает гол на 9-й минуте» или «Матерацци никогда не открывает счет в матче».
Но мозг Аси не безграничен, а помнить всю историю футбола просто невозможно. Поэтому Ася попросила вас написать программу, которая собирает статистику матчей и умеет отвечать на некоторые запросы, касающиеся истории футбола.
Информация о матче сообщается программе в следующей форме:
"<Название 1-й команды>" - "<Название 2-й команды>" <Счет 1-й команды>:<Счет 2-й команды>
<Автор 1-го забитого мяча 1-й команды> <Минута, на которой был забит мяч>'
<Автор 2-го забитого мяча 1-й команды> <Минута, на которой был забит мяч>'
...
<Автор последнего забитого мяча 1-й команды> <Минута, на которой был забит мяч>'
<Автор 1-го забитого мяча 2-й команды> <Минута, на которой был забит мяч>'
...
<Автор последнего забитого мяча 2-й команды> <Минута, на которой был забит мяч>'
Запросы к программе бывают следующих видов:
Total goals for <Название команды>
— количество голов, забитое данной командой за все матчи.
Mean goals per game for <Название команды>
— среднее количество голов, забиваемое данной командой за один матч. Гарантирутся, что к моменту подачи такого запроса команда уже сыграла хотя бы один матч.
Total goals by <Имя игрока>
— количество голов, забитое данным игроком за все матчи.
Mean goals per game by <Имя игрока>
— среднее количество голов, забиваемое данным игроком за один матч его команды.
Гарантирутся, что к моменту подачи такого запроса игрок уже забил хотя бы один гол.
Goals on minute <Минута> by <Имя игрока>
— количество голов, забитых данным игроком ровно на указанной минуте матча.
Goals on first <T> minutes by <Имя игрока>
— количество голов, забитых данным игроком на минутах с первой по T-ю включительно.
Goals on last <T> minutes by <Имя игрока>
— количество голов, забитых данным игроком на минутах с (91 - T)-й по 90-ю включительно.
Score opens by <Название команды>
— сколько раз данная команда открывала счет в матче.
Score opens by <Имя игрока>
— сколько раз данный игрок открывал счет в матче.

Формат ввода
Входной файл содержит информацию о матчах и запросы в том порядке, в котором они поступают в программу Аси Вуткиной.
Во входном файле содержится информация не более чем о 100 матчах, в каждом из которых забито не более 10 голов. Всего в чемпионате участвует не более 20 команд, в каждой команде не более 10 игроков забивают голы.
Все названия команд и имена игроков состоят только из прописных и строчных латинских букв и пробелов, а их длина не превышает 30. Прописные и строчные буквы считаются различными. Имена и названия не начинаются и не оканчиваются пробелами и не содержат двух пробелов подряд. Каждое имя и название содержит хотя бы одну букву.
Минута, на которой забит гол — целое число от 1 до 90 (про голы, забитые в дополнительное время, принято говорить, что они забиты на 90-й минуте).
Для простоты будем считать, что голов в собственные ворота в европейских чемпионатах не забивают, и на одной минуте матча может быть забито не более одного гола (в том числе на 90-й). Во время чемпионата игроки не переходят из одного клуба в другой.
Количество запросов во входном файле не превышает 500.

Формат вывода
Для каждого запроса во входном файле выведите ответ на этот запрос в отдельной строке. Ответы на запросы, подразумевающие нецелочисленный ответ, должны быть верны с точностью до трех знаков после запятой.
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>

#include <unordered_map>
#include <unordered_set>

struct Team
{
    int goal;
    int match;
    int first_goal;
};

struct Player
{
    int goal;
    std::unordered_map<int, int> goal_time;
    std::string team;
    int first_goal;
};

std::unordered_map<std::string, Team> g_team;
std::unordered_map<std::string, Player> g_player;
const std::string TOTAL_GOALS_FOR = "Total goals for";
const std::string MEAN_GOALS_PER_GAME_FOR = "Mean goals per game for";
const std::string TOTAL_GOALS_BY = "Total goals by";
const std::string MEAN_GOALS_PER_GAME_BY = "Mean goals per game by";
const std::string GOALS_ON_MINUTE = "Goals on minute";
const std::string GOALS_ON_FIRST = "Goals on first";
const std::string GOALS_ON_LAST = "Goals on last";
const std::string BY = "by";
const std::string SCORE_OPENS_BY = "Score opens by";

void parse_game_info_update_player(const std::string& player, const int time, const std::string& team)
{
    auto it = g_player.find(player);
    if (it != g_player.end())
    {
        it->second.goal += 1;
        it->second.goal_time[time]++;
    }
    else
        g_player.insert({player, {1, {{time, 1}}, team, 0}});
}

void parse_game_info_player(std::ifstream& input, const std::string& team, const int goal_score, std::string& p_name, int& p_time)
{
    std::string line;
    std::string player;
    int goal_time;
    for (int i = 0; i < goal_score; ++i)
    {
        std::getline(input, line);
        size_t last_space_pos = line.find_last_of(' ');

        player = line.substr(0, last_space_pos);
        goal_time = std::stoi(line.substr(last_space_pos + 1));
        
        parse_game_info_update_player(player, goal_time, team);

        if (i == 0)
        {
            p_name = player;
            p_time = goal_time;
        }
    }
}

void parse_game_info_update_team(const std::string& team, const int goal)
{
    auto it = g_team.find(team);
    if (it != g_team.end())
    {
        it->second.goal += goal;
        it->second.match += 1;
    }
    else
        g_team.insert({team, {goal, 1, 0}});
}

void parse_game_info_first_set(const std::string& p)
{
    g_player[p].first_goal += 1;
    g_team[g_player[p].team].first_goal += 1;
}

void parse_game_info_first(const std::string& p1, const int t1, const std::string& p2, const int t2)
{
    if (!p1.empty() && !p2.empty())
    {
        if (t1 > t2)
            parse_game_info_first_set(p2);
        else
            parse_game_info_first_set(p1);
    }
    else if(!p1.empty())
        parse_game_info_first_set(p1);
    else if(!p2.empty())
        parse_game_info_first_set(p2);
}

void parse_game_info(std::string& line, std::ifstream& input)
{
    size_t first_quote_pos = line.find('"');
    size_t second_quote_pos = line.find('"', first_quote_pos + 1);
    std::string team1 = line.substr(first_quote_pos, second_quote_pos - first_quote_pos + 1);

    size_t third_quote_pos = line.find('"', second_quote_pos + 1);
    size_t fourth_quote_pos = line.find('"', third_quote_pos + 1);
    std::string team2 = line.substr(third_quote_pos, fourth_quote_pos - third_quote_pos + 1);

    size_t fifth_pos = line.find(':', fourth_quote_pos + 1);
    int goal1 = std::stoi(line.substr(fourth_quote_pos + 2, fifth_pos - fourth_quote_pos - 2));
    int goal2 = std::stoi(line.substr(fifth_pos + 1));
    parse_game_info_update_team(team1, goal1);
    parse_game_info_update_team(team2, goal2);

    std::string player1, player2;
    int time1, time2;
    parse_game_info_player(input, team1, goal1, player1, time1);
    parse_game_info_player(input, team2, goal2, player2, time2);

    parse_game_info_first(player1, time1, player2, time2);
}

void process_info(std::string& line)
{
    if (line.find(TOTAL_GOALS_FOR) == 0)
    {
        std::string team = line.substr(TOTAL_GOALS_FOR.length() + 1);
        auto it = g_team.find(team);
        if (it != g_team.end())
            std::cout << it->second.goal << std::endl;
        else
            std::cout << 0 << std::endl;
    }
    else if (line.find(MEAN_GOALS_PER_GAME_FOR) == 0)
    {
        std::string team = line.substr(MEAN_GOALS_PER_GAME_FOR.length() + 1);
        auto it = g_team.find(team);
        if (it != g_team.end())
            std::cout << std::fixed << std::setprecision(3) << static_cast<double>(it->second.goal) / it->second.match << std::endl;
        else
            std::cout << 0 << std::endl;
    }
    else if (line.find(TOTAL_GOALS_BY) == 0)
    {
        std::string player = line.substr(TOTAL_GOALS_BY.length() + 1);
        auto it = g_player.find(player);
        if (it != g_player.end())
            std::cout << it->second.goal << std::endl;
        else
            std::cout << 0 << std::endl;
    }
    else if (line.find(MEAN_GOALS_PER_GAME_BY) == 0)
    {
        std::string player = line.substr(MEAN_GOALS_PER_GAME_BY.length() + 1);
        auto it = g_player.find(player);
        if (it != g_player.end())
            std::cout << std::fixed << std::setprecision(3) << static_cast<double>(it->second.goal) / g_team[it->second.team].match << std::endl;
        else
            std::cout << 0 << std::endl;
    }
    else if (line.find(GOALS_ON_MINUTE) == 0)
    {
        int t = std::stoi(line.substr(GOALS_ON_MINUTE.length() + 1));
        std::string player = line.substr(line.find(BY) + BY.length() + 1);
        auto it = g_player.find(player);
        if (it != g_player.end())
            std::cout << it->second.goal_time[t] << std::endl;
        else
            std::cout << 0 << std::endl;        
    }
    else if (line.find(GOALS_ON_FIRST) == 0)
    {
        int t = std::stoi(line.substr(GOALS_ON_FIRST.length() + 1));
        std::string player = line.substr(line.find(BY) + BY.length() + 1);
        auto it = g_player.find(player);
        if (it != g_player.end())
        {
            auto& goal_time = it->second.goal_time;
            int answer = 0;
            for (auto& gt : goal_time)
            {
                if (t >= gt.first)
                    answer += gt.second;
            }
            std::cout << answer << std::endl;
        }
        else
            std::cout << 0 << std::endl; 
    } 
    else if (line.find(GOALS_ON_LAST) == 0)
    {
        int t = std::stoi(line.substr(GOALS_ON_LAST.length() + 1));
        std::string player = line.substr(line.find(BY) + BY.length() + 1);
        auto it = g_player.find(player);
        if (it != g_player.end())
        {
            auto& goal_time = it->second.goal_time;
            int answer = 0;
            for (auto& gt : goal_time)
            {
                if (91 - t <= gt.first)
                    answer += gt.second;
            }
            std::cout << answer << std::endl;
        }
        else
            std::cout << 0 << std::endl;
    }
    else if (line.find(SCORE_OPENS_BY) == 0)
    {
        std::string team_or_player = line.substr(SCORE_OPENS_BY.length() + 1);
        if (team_or_player[0] == '"')
        {
            auto it = g_team.find(team_or_player);
            if (it != g_team.end())
                std::cout << it->second.first_goal << std::endl;
            else
                std::cout << 0 << std::endl;
        }
        else
        {
            auto it = g_player.find(team_or_player);
            if (it != g_player.end())
                std::cout <<  it->second.first_goal << std::endl;
            else
                std::cout << 0 << std::endl;            
        }
    }
}

int main()
{
    std::ifstream input("input.txt");


    std::string line;
    while (!input.eof())
    {
        std::getline(input, line);

        if (line.empty())
            continue;        

        if (line[0] == '"')
        {
            parse_game_info(line, input);
        }
        else
        {
            process_info(line);
        }
    }

    input.close();

    return 0;
}