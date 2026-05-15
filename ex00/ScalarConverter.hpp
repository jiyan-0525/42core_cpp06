#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <string_view>
// #include <limits>
#include <cmath>
#include <iomanip>

class ScalarConverter {
public:
    static void convert(std::string_view literal);

private:
    ScalarConverter();
    ScalarConverter(std::string_view literal);
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();
};

#endif