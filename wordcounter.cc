#include "wordcounter.hh"

WordCounter::WordCounter(char const* input_filename)
{
    input_file = std::ifstream(input_filename);
    if (!input_file.is_open())
    {
        std::cout << "Could not open file : \"" << input_filename << "\"" << std::endl;
    }
}

WordCounter::~WordCounter()
{
    input_file.close();
}

void WordCounter::AddWordToMap(std::string word)
{
    unsigned int current_count = dict[word];
    dict[word]                 = current_count + 1;
}

bool WordCounter::WordIsPrecededBySpace(std::smatch match, std::string line)
{
    bool retVal = false;

    auto position = match.position(0); // TODO should be size_t according to the documentation, but is not for some reason.
    if (position > 0)                  // beginning of line
    {
        static_assert(sizeof(size_t) >= sizeof(position), "destination type too small");
        size_t pos = static_cast<size_t>(position);
        if (line[pos - 1] == ' ')
        {
            retVal = true;
        }
    }
    return retVal;
}

bool WordCounter::WordIsFollowedBySpace(std::smatch match, std::string line)
{
    bool retVal = false;

    auto position = match.position(0);
    static_assert(sizeof(size_t) >= sizeof(position), "destination type too small");
    size_t pos = static_cast<size_t>(position + match[0].length());
    if (pos < line.size()) // end of line
    {
        if (line[pos] == ' ')
        {
            retVal = true;
        }
    }
    return retVal;
}

void WordCounter::ParseWords(std::regex re)
{
    std::string line;
    std::smatch match;

    while (getline(input_file, line))
    {
        while (std::regex_search(line, match, re))
        {
            if (WordIsPrecededBySpace(match, line) && WordIsFollowedBySpace(match, line))
            {
                AddWordToMap(match[0]); // no grouping in RE
            }
            line = match.suffix().str();
        }
    }
}

void WordCounter::FillVector()
{
    Comparator compFunctor =
    [](std::pair<std::string, unsigned int> e1, std::pair<std::string, unsigned int> e2) {
        return e1.second > e2.second;
    };

    vectorOfWords = std::vector<std::pair<std::string, unsigned int>>(dict.begin(), dict.end());
    sort(vectorOfWords.begin(), vectorOfWords.end(), compFunctor);
    /*
    for (auto idx : vectorOfWords)
    {
        std::cout << idx.first << " " << idx.second << std::endl;
    }
    */
}

std::string WordCounter::GetWordAtIndex(unsigned int index)
{
    if (index < vectorOfWords.size())
    {
        return vectorOfWords[index].first;
    }
    return "No string found at index";
}

unsigned int WordCounter::GetWordCount(std::string word)
{
    return dict[word];
}
