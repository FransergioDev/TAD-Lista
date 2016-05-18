#include <iostream>

#include "vector.hpp"

void printonscreen (Vector<int> & x)
{
    std::cout << "O tamanho do vetor: " << x.size() << std::endl;
    if(x.size() > 0)
    {
        std::cout << "O primeiro elemento:" << x.front() << std::endl;
        std::cout << "O ultimo elemento:" << x.back() << std::endl;

    }
    if(x.size() > 3)
        std::cout << "O terceiro elemento:" << x[2] <<  std::endl;
    std::cout << "\n";
}


int main() {
    Vector<int> v(1);
    v.push_back(387);

    printonscreen(v);

    v.push_back(197);

    printonscreen(v);

    v.push_back(076);

    printonscreen(v);

    v.push_back(358);

    printonscreen(v);

    v.pop_back();

    printonscreen(v);

    for(auto i (0u); i < 146; ++i)
    {
        v.push_back(i * 37);
    }

    printonscreen(v);

    long long unsigned Total = v.size();

    for(auto i (0u); i < Total - 8; ++i)
    {
        v.pop_back();
    }

    printonscreen(v);

    v.clear();

    printonscreen(v);

    return EXIT_SUCCESS;
}
