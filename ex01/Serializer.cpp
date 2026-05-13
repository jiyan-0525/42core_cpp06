#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(std::string_view filename) {
    (void)filename;
}

Serializer::Serializer(const Serializer &other) {
    (void)other;
}

Serializer &Serializer::operator=(const Serializer &other) {
    (void)other;
    return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

void Serializer::writeHeader() {
    std::cout << "=== Serialization Start ===" << std::endl;
}

void Serializer::writeFooter() {
    std::cout << "=== Serialization End ===" << std::endl;
}
