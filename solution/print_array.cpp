#include <iostream>
#include <string>
#include <array>

#include "consts.h"
#include "data_types.h"
#include "print_array.h"

void print_array(std::string message, std::array<double, 3> array_to_print, data_types type)
{
    std::cout << message << ": ";
    for (int i = 0; i < 3; i++)
    {
        std::cout << (type == data_types::coords ? consts::coords_names.at(i) : consts::ders_names.at(i)) 
                  << " = " 
                  << array_to_print.at(i) 
                  << ( i == 2 ? "" : "; ");
    }
    std::cout << std::endl;
}
