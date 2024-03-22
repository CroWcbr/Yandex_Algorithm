// time 2800 ms.... but 11 test i cannot pass.... I need to change algoritm

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <chrono>
#define DEBUG 0

typedef int my_type;

struct Point
{
    int16_t x;
    int16_t y;
};

void print_point(Point& l) { std::cout << l.x << " " << l.y << std::endl; }

struct Vector
{
    int16_t x;
    int16_t y;
};

void print_vector(Vector& v) { std::cout << v.x << " " << v.y << std::endl; }

struct Point_and_hash
{
    std::vector<Point> line;
    std::unordered_map<int16_t, std::unordered_set<int16_t>> hash; // x y
};

const int RANGE = 20001;

struct Shape_box
{
    int16_t x_left;
    int16_t x_right;
    int16_t y_top;
    int16_t y_down;
};

my_type my_key(int x, int y)
{
    return x * RANGE + y;
}

void read_input_first(std::ifstream& input,
                        int n, 
                        std::vector<Point>& line,
                        std::vector<my_type>& vector_hash,
                        std::vector<my_type>& first_point_hash)
{
    int16_t x1, y1, x2, y2;
    for (int i = 0; i < n; ++i)
    {
        input >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2 || (x2 == x1 && y1 > y2))
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        line[i] = {x1, y1};
        vector_hash[i] = my_key(x2 - x1, y2 - y1);
        first_point_hash[i] = my_key(x1, y1);
    }
}

void read_input_second(std::ifstream& input,
                        int n,
                        std::unordered_map<my_type, Point_and_hash>& data,
                        Shape_box& shape_box)
{
    int16_t x1, y1, x2, y2;
    for (int i = 0; i < n; ++i)
    {
        input >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2 || (x2 == x1 && y1 > y2))
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }

        // std::min(shape_box.x_left, x1);
        // std::max(shape_box.x_right, x1);
        // std::max(shape_box.y_top, y1);
        // std::min(shape_box.y_down, y1);

        my_type tmp_hash = my_key(x2 - x1, y2 - y1);
        data[tmp_hash].line.push_back({x1, y1});
        data[tmp_hash].hash[x1].insert(y1);
    }
}

int main()
{
    // auto start = std::chrono::steady_clock::now();
    std::ifstream input("input.txt");

    int n;
    input >> n;

    std::vector<Point> first_line(n);
    std::vector<my_type> first_vector_hash(n);
    std::vector<my_type> first_point_hash(n);
    read_input_first(input, n, first_line, first_vector_hash, first_point_hash);

    Shape_box shape_box = {10000, -10000, -10000, 10000};
    std::unordered_map<my_type, Point_and_hash> data;
    read_input_second(input, n, data, shape_box);
    input.close();

// check
    int add_match = 0;
    auto it = first_vector_hash.begin();
    int i_del = 0;
    while (it != first_vector_hash.end())
    {
        if (data.find(*it) == data.end())
        {
            first_line.erase(first_line.begin() + i_del);
            first_point_hash.erase(first_point_hash.begin() + i_del);
            it = first_vector_hash.erase(it);
            ++add_match;
            n--;
        }
        else
        {
            ++i_del;
            ++it;
        }
    }
if (DEBUG) std::cout << n << "\t" << add_match << std::endl;

// if (DEBUG) std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << std::endl;
// if (DEBUG) { std::cout << "-----------------" << std::endl; }
    
    int answer = 0;
    for (int i = 0; i < n - answer; ++i)
    {
// if (DEBUG) { std::cout << "first point : "; print_line(first_line[i]); }  
        auto data_find = data.find(first_vector_hash[i]);
        if (data_find == data.end())
            continue;
        std::vector<Point>& tmp_line = data_find->second.line; // find right vector   
        for (int iv = 0; iv < tmp_line.size(); ++iv)
        {
// if (DEBUG) { print_line(v); }
            int dx = tmp_line[iv].x - first_line[i].x;
            int dy = tmp_line[iv].y - first_line[i].y;
// if (DEBUG) { std::cout << "\t" << dx << " " << dy << std::endl; }
            int tmp_answer = 0;
            for (int i_sec = i; i_sec < n; ++i_sec)
            {
                data_find = data.find(first_vector_hash[i_sec]);
                if (data_find == data.end())
                    continue;
                std::unordered_map<int16_t, std::unordered_set<int16_t>>& tmp_hash = data_find->second.hash;
                auto tmp_xy = tmp_hash.find(first_line[i_sec].x + dx);
                if (tmp_xy != tmp_hash.end() && tmp_xy->second.find(first_line[i_sec].y + dy) != tmp_xy->second.end())
                    ++tmp_answer;
            }
            answer = std::max(answer, tmp_answer);
        }
    }

// if (DEBUG)     std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << std::endl;
    std::cout << n - answer + add_match << std::endl;
    return 0;
}