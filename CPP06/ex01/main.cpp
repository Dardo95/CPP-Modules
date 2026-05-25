#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data data;
    data.value = 42;
    data.price = 3.14f;

    uintptr_t raw = Serializer::serialize(&data);
    Data* result = Serializer::deserialize(raw);

    std::cout << "Original pointer:     " << &data << std::endl;
    std::cout << "Deserialized pointer: " << result << std::endl;

    if (result == &data)
        std::cout << "OK: pointers are equal" << std::endl;
    else
        std::cout << "FAIL: pointers differ" << std::endl;

    return 0;
}