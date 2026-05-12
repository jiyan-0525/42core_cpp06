#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>
#include <string_view>

class ScalarConverter {
public:
    static void convert(std::string_view str);

private:
ScalarConverter();
ScalarConverter(std::string_view str);
ScalarConverter(const ScalarConverter &other);
ScalarConverter &operator=(const ScalarConverter &other);
~ScalarConverter();
};

#endif