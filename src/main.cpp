#include <iostream>
#include <map>
#include <vector>

#include "adapters/allocator_adapter.h"
#include "allocators/linear_allocator.h"

template <typename T, class Allocator>
using Vector = std::vector<T, AllocatorAdapter<T, Allocator>>;

template <size_t SIZE_BYES>
using MapAdapterAllocator = AllocatorAdapter<std::pair<const int, long>, LinearAllocator<SIZE_BYES>>;

template <typename T, typename U, class Compare, size_t SIZE_BYES>
using Map = std::map<T, U, Compare, MapAdapterAllocator<SIZE_BYES>>;

int main()
{
    // TODO: ВЫДКЛЯТЬ ПАМЯТЬ ТОЛЬКО ПРИ ПЕРВОМ ВЫЗОВЕ allocate
    // т.е. если контейнре создан, но не было добавления, то память выделена зря
    std::cout << "ALLOCATOR!" << std::endl;

    const std::size_t memory_size = 20000;
//    void* memory = std::malloc(memory_size);
//    LinearAllocator<memory_size> allocator;



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
//    MapAdapterAllocator<memory_size> m_adapter(allocator);
    std::map<int, long, std::less<>, MapAdapterAllocator<memory_size>> m;
    m[4] = 3423421343;
    m[1] = 1332423434;
    //

    return 0;
}
