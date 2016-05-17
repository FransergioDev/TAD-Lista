#include <iostream>

#include "vector.hpp"

main() {
    Vector<int> v(10);
    std::cout << v.size() << std::endl;
    v.resize(12);
    std::cout << v.size() << std::endl;


    return EXIT_SUCCESS;
}
