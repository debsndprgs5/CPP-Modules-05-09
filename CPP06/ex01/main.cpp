#include <iostream>
#include "Serialization.hpp"

int main( void )
{
    s_data *data = new s_data;

    data->name = "Karen";
    data->age = 57;

    std::cout << "Name: " << data->name << std::endl;
    std::cout << "Serialized Name:" << Serialization::serialize(data) << std::endl;
    std::cout << "Unserialized Name:" << Serialization::deserialize(Serialization::serialize(data))->name << std::endl;

    std::cout << "Age: " << data->age << std::endl;
    std::cout << "Serialized Age:" << Serialization::serialize(data) << std::endl;
    std::cout << "Unserialized Age:" << Serialization::deserialize(Serialization::serialize(data))->age << std::endl;
    delete data;

    return 0;
}
