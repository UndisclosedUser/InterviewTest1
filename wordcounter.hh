#ifndef WORD_COUNTER_HH
#define WORD_COUNTER_HH

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <set>

typedef std::function<bool(std::pair<std::string, unsigned int>, std::pair<std::string, unsigned int>)> Comparator;

class WordCounter
{
public:
    WordCounter(char const* input_filename);
    ~WordCounter();
    void         ParseWords(std::regex re);
    void         FillVector();
    std::string  GetWordAtIndex(unsigned int index);
    unsigned int GetWordCount(std::string word);

private:
    bool WordIsPrecededBySpace(std::smatch match, std::string line);
    bool WordIsFollowedBySpace(std::smatch match, std::string line);
    void AddWordToMap(std::string word);

    std::ifstream                                     input_file;
    std::map<std::string, unsigned int>               dict;
    std::vector<std::pair<std::string, unsigned int>> vectorOfWords;
};

#endif // WORD_COUNTER_HH
