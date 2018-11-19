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
}
