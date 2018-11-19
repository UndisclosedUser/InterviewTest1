#include "wordcounter.hh"

Comparator const WordCounter::compFunctor =
[](std::pair<std::string, unsigned int> e1, std::pair<std::string, unsigned int> e2) {
    return e1.second < e2.second;
};

WordCounter::WordCounter(char const* input_filename)
{
    input_file = std::ifstream(input_filename);
    if (!input_file.is_open())
    {
        std::cout << "Could not open file : \"" << input_filename << "\"" << std::endl;
        exit(2);
    }
}

WordCounter::~WordCounter()
{
    input_file.close();
}

void WordCounter::ParseWords(std::regex re)
{
    std::string line;
    std::smatch match;

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
}

void WordCounter::FillSet()
{
    setOfWords = std::set<std::pair<std::string, unsigned int>, Comparator>(dict.begin(), dict.end(), compFunctor);

    for (auto idx : setOfWords)
    {
        std::cout << idx.first << " " << idx.second << std::endl;
    }
}

std::string WordCounter::GetWordAtIndex(unsigned int index)
{
}
