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
    void        ParseWords(std::regex re);
    void        FillSet();
    std::string GetWordAtIndex(unsigned int index);

private:
    std::ifstream                                              input_file;
    std::map<std::string, unsigned int>                        dict;
    std::set<std::pair<std::string, unsigned int>, Comparator> setOfWords;
    static const Comparator                                    compFunctor;
};

#endif // WORD_COUNTER_HH
