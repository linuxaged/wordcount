#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

typedef std::pair<std::string, int> PAIR;
struct CmpByValue
{
    bool operator()(const PAIR &p1, const PAIR &p2)
    {
        return p1.second < p2.second;
    }
};
int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "用法: ./count file.txt"<< std::endl;
                  return -1;
    }
    else
    {
        std::ifstream input;
        input.open(argv[1]);
        if (input.is_open())
        {
            std::map<std::string, int> count;
            std::string word;
            while (input >> word)
                ++count[word];
            input.close();
            for (auto &kv : count)
            {
                std::cout << kv.first << " * " << kv.second << std::endl;
            }
            std::cout << "==================================" << std::endl;
            std::vector<PAIR> words(count.begin(), count.end());
            std::sort(words.begin(), words.end(), CmpByValue());
            for (auto &i : words)
            {
                std::cout << i.first << " * " << i.second << std::endl;
            }
            std::cout << '\n';
        }

    }


    return 0;
}