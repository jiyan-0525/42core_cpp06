#include "Serializer.hpp"

int main() {
    Data data;
    data.id = 42;
    Data* ptr = &data;

    Serializer serializer;
    uintptr_t raw = serializer.serialize(ptr);
    Data* deserializedData = serializer.deserialize(raw);
    std::cout << "Original value: " << data.id << std::endl;
    std::cout << "Serialized(integer) value: " << raw << std::endl;
    std::cout << "Deserialized pointer value: " << deserializedData << std::endl;

    if (ptr == deserializedData) {
        std::cout << "Deserialization successful, pointers match." << std::endl;
    } else {
        std::cout << "Deserialization failed, pointers do not match." << std::endl;
        std::cout << "Deserialized value: " << deserializedData->id << std::endl;
    }
    return 0;
}