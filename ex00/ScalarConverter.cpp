#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(std::string_view literal) {
    (void)literal;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string_view literal) {
    double d;

    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        d = static_cast<double>(literal[0]);
    } else {
        try{
            size_t idx;
            d = std::stod(std::string(literal), &idx);
            if (idx != literal.length() && !(idx == literal.length() - 1 && literal.back() == 'f')) {
                throw std::invalid_argument("Invalid literal");
            }
        } catch (const std::invalid_argument& e) {
            // std::cout << "Error: " << e.what() << std::endl;
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }

    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) 
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d))) 
        std::cout << "Non displayable" << std::endl;
    else 
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d > 2147483647.0 || d < -2147483648.0)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
