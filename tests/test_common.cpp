#include <gtest/gtest.h>

#include <iostream>
#include <map>
#include <string>

#include "adapters/allocator_adapter.h"
#include "allocators/fall_back_allocator.h"
#include "allocators/linear_allocator.h"
#include "allocators/mallocator.h"

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

TEST(TestCustomAllocator, TestStdMap) {
    std::map<int, int> map;

    for (auto i = 0; i <= 9; i++)
    {
        map[i] = factorial(i);
    }

    print_map(map);
}

template <typename Key, typename Value, size_t SIZE_BYTES>
using MapFallbackAllocator = FallBackAllocator<LinearAllocator<SIZE_BYTES>, Mallocator<std::pair<const Key, Value>>>;

template <typename Key, typename Value, size_t SIZE_BYTES>
using MapAllocatorAdapter = AllocatorAdapter<std::pair<const Key, Value>, MapFallbackAllocator<Key, Value, SIZE_BYTES>>;

template <typename Key, typename Value, size_t SIZE_BYTES>
using Map = std::map<Key, Value, std::less<>, MapAllocatorAdapter<Key, Value, SIZE_BYTES>>;

TEST(TestCustomAllocator, TestMap) {
    const std::size_t mem_size_bytes = sizeof(int) * 10;

    MapFallbackAllocator<int, int, mem_size_bytes> allocator;

    MapAllocatorAdapter<int, int, mem_size_bytes> adapter(allocator);

    Map<int, int, mem_size_bytes> map(adapter);

    for (auto i = 0; i <= 9; i++)
    {
        map[i] = factorial(i);
    }

    print_map(map);

//    map.erase("key1"); TODO: check

    std::cout << "KEK" << std::endl;
}