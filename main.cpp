#include <iostream>
#include <string>

#include "dispatch.hpp"

// Compile: g++ -std=c++11 -Wno-attributes main.cpp

auto main() -> int {
    Foo<std::string>    foo_s;
    Foo<int>            foo_i;

    assert( foo_s.bar() == std::string{"foo"} );
    assert( foo_i.bar() ==       5            );

    std::cout << "All tests passed." << std::endl;

    return EXIT_SUCCESS;
}