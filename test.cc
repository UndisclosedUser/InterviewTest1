#include <iostream>
#include <fstream>
#include <regex>

int main(int argc, char const *argv[])
{
  //  std::cout << argc << std::endl;
  if (argc != 2)
    {
      std::cout << "Usage : test text_file" << std::endl;
      exit(1);
    }

  char const * input_filename = argv[1];
  std::ifstream input_file(input_filename);
  if (!input_file.is_open())
    {
      std::cout << "Could not open file : \"" << input_filename << "\"" << std::endl;
      exit(2);
    }

  std::string line;
  std::regex re("[a-zA-Z0-9\\.]+");
  std::smatch match;
  while (getline(input_file, line))
    {
      //std::cout << line << std::endl;
      while (std::regex_search(line, match, re))
	{
	  for (auto x:match)
	    {
	      std::cout << x << std::endl;
	    }
	  line = match.suffix().str();
	}
    }

  input_file.close();
}
