#include <iostream>
#include <map>
#include <vector>

#include "adapters/allocator_adapter.h"
#include "allocators/linear_allocator.h"

template <typename T, class Allocator>
using Vector = std::vector<T, AllocatorAdapter<T, Allocator>>;

using MapAdapterAllocator = AllocatorAdapter<std::pair<const int, long>, LinearAllocator>;

template <typename T, typename U, class Compare, class Allocator>
using Map = std::map<T, U, Compare, MapAdapterAllocator>;

int main()
{
    // TODO: ВЫДКЛЯТЬ ПАМЯТЬ ТОЛЬКО ПРИ ПЕРВОМ ВЫЗОВЕ allocate
    // т.е. если контейнре создан, но не было добавления, то память выделена зря
    std::cout << "ALLOCATOR!" << std::endl;

    const std::size_t memory_size = 20000;
    void* memory = std::malloc(memory_size);
    LinearAllocator allocator(memory_size, memory);



    // Vector
//    AllocatorAdapter<int, LinearAllocator> v_adapter(allocator);
//    Vector<int, LinearAllocator> v(v_adapter);
//
//    v.push_back(1);
//    v.push_back(2);
//    v.push_back(3);
//
//    v.erase(v.begin() + 1);
    //

    // Map
    MapAdapterAllocator m_adapter(allocator);
    std::map<int, long, std::less<>, MapAdapterAllocator> m(m_adapter);
    m[4] = 3423421343;
    m[1] = 1332423434;
    //

    return 0;
}
