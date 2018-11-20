#include "wordcounter.hh"

int main(int argc, char const* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage : test text_file" << std::endl;
        exit(1);
    }

    WordCounter wc(argv[1]);
    wc.ParseWords(std::regex("[a-zA-Z0-9\\.]+"));
    wc.FillSet();

    // get most used word
    std::cout << "Most used word : " << wc.GetWordAtIndex(0u) << std::endl;
    
    // get 25th most used word
    std::cout << "25th most used word : " << wc.GetWordAtIndex(24u) << std::endl;
    
    // get number of occurences of one word (example taken here : species).
    std::string WordWeWant("species");
    std::cout << "Number of occurences of the word " << WordWeWant << " : " << wc.GetWordCount(WordWeWant) << std::endl;
}
