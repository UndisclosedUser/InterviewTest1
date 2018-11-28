#ifndef SAFERCAST
#define SAFERCAST

#include <typeinfo>
#include <limits>

#define Diff_tToSize_t(d) safercast<std::_Bit_const_iterator::difference_type, size_t, decltype(d)>(d, __FILE__, __LINE__)

template <typename input, typename output>
bool typeCheck(input i)
{
    return (static_cast<double>(i) <= static_cast<double>(std::numeric_limits<output>::max())) && (static_cast<double>(i) >= static_cast<double>(std::numeric_limits<output>::lowest()));
}

template <typename input1, typename output, typename input2>
output safercast(input2 i, const char* file, int line)
{
    static_assert(std::is_same<std::remove_cv<std::remove_reference<input1>>, std::remove_cv<std::remove_reference<input2>>>::value, "types differ");
    if (typeCheck<input1, output>(i))
    {
        return static_cast<output>(i);
    }
    else
    {
	std::cout << "overflow at " << file << ":" << line << " (" << i << ")" << std::endl;
        return 0;
    }
}

#endif //SAFERCAST
