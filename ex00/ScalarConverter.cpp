#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(std::string_view literal) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    void(other);
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string_view literal) {
    std::string str(literal);
    double d;

    if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (str.find("nan") != std::string::npos){
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
    }else
        {
            std::cout << "float: " << str.substr(0, str.size() - 1) << "f" << std::endl;
            std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
        }
        return;
}
}