#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <set>

typedef std::function<bool(std::pair<std::string, unsigned int>, std::pair<std::string, unsigned int>)> Comparator;

Comparator compFunctor =
[](std::pair<std::string, unsigned int> e1, std::pair<std::string, unsigned int> e2) {
    return e1.second < e2.second;
};

int main(int argc, char const* argv[])
{
    //  std::cout << argc << std::endl;
    if (argc != 2)
    {
        std::cout << "Usage : test text_file" << std::endl;
        exit(1);
    }

    char const*   input_filename = argv[1];
    std::ifstream input_file(input_filename);
    if (!input_file.is_open())
    {
        std::cout << "Could not open file : \"" << input_filename << "\"" << std::endl;
        exit(2);
    }

    std::string                         line;
    std::regex                          re("[a-zA-Z0-9\\.]+");
    std::smatch                         match;
    std::map<std::string, unsigned int> dict;

    while (getline(input_file, line))
    {
        //std::cout << line << std::endl;
        while (std::regex_search(line, match, re))
        {
            for (auto x : match)
            {
                //	      std::cout << x << std::endl;
                //std::cout << dict[x] << std::endl;
                unsigned int current_count = dict[x];
                dict[x]                    = current_count + 1;
            }
            line = match.suffix().str();
        }
    }

    /*
  for (auto idx : dict)
    {
      std::cout << idx.first << " " << idx.second << std::endl;
      }*/

    std::set<std::pair<std::string, unsigned int>, Comparator> setOfWords(dict.begin(), dict.end(), compFunctor);
    for (auto idx : setOfWords)
    {
        std::cout << idx.first << " " << idx.second << std::endl;
    }

    input_file.close();
}
