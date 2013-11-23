#include <type_traits>
#include <cassert>

// C++11 Proof of concept of different implementations of
// member methods for different types of class instances.

template<class T> struct tag {};

template<class T>
struct Foo {

    // obviously, you can play with where you actually put these attributes
    // (at least with gcc)
    [[ dispatched_to ]]
    std::string bar(tag<std::string>) {
        return std::string{"foo"};
    }

    int bar(tag<int>) [[ dispatched_to ]] {
        return 5;
    }

    auto bar() [[ dispatcher ]]
    ->decltype(this->bar(tag<T>{})) // 'this' seems to be needed here.
    {
        return bar(tag<T>{});
    }
};
