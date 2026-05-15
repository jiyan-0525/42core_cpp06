#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(std::string_view name) {
    (void)name;
}

Serializer::Serializer(const Serializer &other) {
    (void)other;
}

Serializer &Serializer::operator=(const Serializer &other) {
    (void)other;
    return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serializer(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserializer(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
