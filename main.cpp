#include <iostream>
#include <cstdlib>
#include <type_traits>

struct A {
    int field;
    int foo() {return 0;}
};

template <typename, typename = void> struct has_foo_function : std::false_type {};
template <typename T> struct has_foo_function<T, std::void_t< decltype(std::declval<T>().foo()) >> : std::true_type {};

template <typename, typename = void> struct has_field : std::false_type {};
template <typename T> struct has_field<T, std::void_t< decltype(T::field) > >: std::true_type {};

int main()
{
    std::cout << has_foo_function<A>::value << std::endl;
    std::cout << has_field<A>::value << std::endl;

    std::cout << has_foo_function<int>::value << std::endl;
    std::cout << has_field<int>::value << std::endl;
    
    return 0;
}
