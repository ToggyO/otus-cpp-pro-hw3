#pragma once

#include <iostream>

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

template<typename Map>
static void print_map(const Map& map)
{
    for (const auto& pair : map)
    {
        std::cout << std::dec << pair.first << ' ' << pair.second << std::endl;
    }
}

template<class Vector>
void print_vector(const Vector &v)
{
    for (auto it : v)
    {
        printf("%d\n", it);
    }
    printf("\n");
}
