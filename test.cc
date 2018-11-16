#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
  //  std::cout << argc << std::endl;
  if (argc != 2)
    {
      std::cout << "Usage : test text_file" << std::endl;
    }

  char const * input_filename = argv[1];
  std::ifstream input_file(input_filename);
  if (!input_file.is_open())
    {
      std::cout << "Could not open file : \"" << input_filename << "\"" << std::endl;
      exit(1);
    }
}

