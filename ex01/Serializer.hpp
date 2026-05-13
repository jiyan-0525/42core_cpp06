#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP
#include <iostream>
#include <string>
#include <cstdint>
#include <string_view>

struct Data {
    int id;
    std::string name;
    bool active;
};

class Serializer {
public:
    Serializer();
    Serializer(std::string_view filename);
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
    ~Serializer();

    uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);

private:
    void writeHeader();
    void writeFooter();
};

#endif