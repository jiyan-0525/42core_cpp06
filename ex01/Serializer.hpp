#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP
#include <iostream>
#include <string>
#include <cstdint>
#include <string_view>

struct Data {
    int id;
};

class Serializer {
private:
    Serializer();
    Serializer(std::string_view name);
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif