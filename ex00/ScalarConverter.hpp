#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <string_view>
#include <limits>
#include <cmath>
#include <cctype>

class ScalarConverter {
public:
    ScalarConverter() = delete;
    ScalarConverter(std::string_view str) = delete;
    ScalarConverter(const ScalarConverter &other) = delete;
    ScalarConverter &operator=(const ScalarConverter &other) = delete;
    ~ScalarConverter() = delete;

    static void convert(std::string_view literal);
};

#endif