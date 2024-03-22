// thread can not be used.....
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <atomic>
// #include <chrono>
#include <thread>

// #define DEBUG 0

std::atomic<int> global_answer(0);
typedef int my_type;

struct Line
{
    int16_t x1;
    int16_t y1;
    int16_t x2;
    int16_t y2;
};

void print_line(Line& l) { std::cout << l.x1 << " " << l.y1 << " " << l.x2 << " " << l.y2 << std::endl; }

struct Vector
{
    int16_t x;
    int16_t y;
};

struct Line_and_hash
{
    std::vector<Line> line;
    std::unordered_set<my_type> hash;
};

const int RANGE = 20001; // Размер диапазона от -10^4 до 10^4
const int BOUNDER = 10000; // граница 10^4

my_type my_key(int x, int y)
{
    return x * RANGE + y;
}

void read_input_first(std::ifstream& input,
                        int n, 
                        std::vector<Line>& line,
                        std::vector<my_type>& vector_hash)
{
    int16_t x1, y1, x2, y2;
    for (int i = 0; i < n; ++i)
    {
        input >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2 || (x2 == x1 && y1 > y2))
            line[i] = {x2, y2, x1, y1};
        else
            line[i] = {x1, y1, x2, y2};

        vector_hash[i] = my_key(line[i].x2 - line[i].x1, line[i].y2 - line[i].y1);

// if (DEBUG2) { std::cout << "\t" << vector_hash[i] << std::endl; }
    }
}

void read_input_second(std::ifstream& input,
                        int n,
                        std::unordered_map<my_type, Line_and_hash>& data)
{
    int16_t x1, y1, x2, y2;
    Line tmp_line;
    for (int i = 0; i < n; ++i)
    {
        input >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2 || (x2 == x1 && y1 > y2))
            tmp_line = {x2, y2, x1, y1};
        else
            tmp_line = {x1, y1, x2, y2};

        my_type hash = my_key(tmp_line.x2 - tmp_line.x1, tmp_line.y2 - tmp_line.y1);
        data[hash].line.push_back(tmp_line);
        data[hash].hash.insert(my_key(tmp_line.x1, tmp_line.y1));

// if (DEBUG2) { std::cout << "1\t" << hash << std::endl; }
// if (DEBUG2) { std::cout << "2\t" << my_key(tmp_line.x1, tmp_line.y1) << std::endl; }
    }
}

void process_data(const std::vector<Line>& first_line, 
                    const std::vector<my_type>& first_vector_hash, 
                    std::unordered_map<my_type, Line_and_hash>& data, 
                    int start, 
                    int end,
                    int n)
{
    for (int i = start; i < end; ++i)
    {
        auto data_find = data.find(first_vector_hash[i]);
        if (data_find == data.end())
            continue;
        Line_and_hash& tmp_second = data_find->second;
        for (auto v : tmp_second.line)
        {
            int dx = v.x1 - first_line[i].x1;
            int dy = v.y1 - first_line[i].y1;
            int tmp_answer = 0;
            for (int i_sec = i; i_sec < n; ++i_sec)
            {
                data_find = data.find(first_vector_hash[i_sec]);
                if (data_find == data.end())
                    continue;

                std::unordered_set<my_type>& tmp = data_find->second.hash;
                my_type tmp_hash = my_key(first_line[i_sec].x1 + dx, first_line[i_sec].y1 + dy);  
                if (tmp.find(tmp_hash) != tmp.end())
                    tmp_answer++;
      
            }
            if (global_answer < tmp_answer)
                global_answer = tmp_answer;
        }
    }
}

int main()
{
    // auto start_crono = std::chrono::steady_clock::now();
    std::ifstream input("input.txt");

    int n;
    input >> n;

    std::vector<Line> first_line(n);
    std::vector<my_type> first_vector_hash(n);
    read_input_first(input, n, first_line, first_vector_hash);

    std::unordered_map<my_type, Line_and_hash> data;
    read_input_second(input, n, data);
    input.close();

    // std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_crono).count() << std::endl;
// if (DEBUG) { std::cout << "-----------------" << std::endl; }

    if (n < 100)
    {
        process_data(std::ref(first_line), 
                    std::ref(first_vector_hash), 
                    std::ref(data),
                    0,
                    n,
                    n);
    }
    else
    {
        int num_threads = 10;
        std::vector<std::thread> threads;
        int chunk_size = n / num_threads;
        int start = 0;
        for (int i = 0; i < num_threads; ++i)
        {
            int end = start + chunk_size;
            if (end > n)
                end = n;
            // std::cout << start << "\t" << end << std::endl;
            threads.emplace_back(process_data, 
                                std::ref(first_line), 
                                std::ref(first_vector_hash), 
                                std::ref(data),
                                start,
                                end,
                                n);
            start = end;
        }

        for (auto& thread : threads)
            thread.join();
    }

    // std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_crono).count() << std::endl;
    std::cout << n - global_answer << std::endl;
    return 0;
}