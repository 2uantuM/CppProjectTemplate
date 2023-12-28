#include <iostream>

#include "fmt/core.h"

int print_hello_world()
{
    fmt::print("Hello World\n");

    // Adress Sanitizer should see this :)
    // int *x = new int[42];

    return 1;
}

unsigned int factorial(unsigned int number)
{
    return number <= 1 ? 1 : factorial(number - 1) * number;
}
