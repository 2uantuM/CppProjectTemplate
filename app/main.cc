// #define FMT_HEADER_ONLY // may need this line

#include <filesystem>
#include <fstream>
#include <iostream>

#include <fmt/format.h>

#include "config.hpp"
#include "my_lib.h"

int main()
{
    std::cout << "FMT: " << FMT_VERSION << '\n';
    // Compiler Warning and clang tidy error
    // std::int32_t i = 0;

    // Adress Sanitizer should see this
    // int *x = new int[42];
    // x[100] = 5; // Boom!

    const auto welcome_message =
        fmt::format("Welcome to {} v{}\n", project_name, project_version);
    fmt::print("{}", welcome_message);

    return 0;
}
