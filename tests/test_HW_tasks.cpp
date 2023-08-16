#include <gtest/gtest.h>

#include <map>

#include "adapters/allocator_adapter.h"
#include "allocators/fall_back_allocator.h"
#include "allocators/linear_allocator.h"
#include "allocators/mallocator.h"
#include "containers/my_vector.h"
#include "utils.h"

/* @brief Fill std::map with 10 elements, allocated by standard allocator */
TEST(TestHW3, TestMapWithStdAllocator) {
    std::map<int, int> map;

    for (auto i = 0; i <= 9; i++)
    {
        map[i] = factorial(i);
    }

    print_map(map);
}
/* -------------------------- */


template <typename Key, typename Value, size_t SIZE_BYTES>
using MapFallbackAllocator = FallBackAllocator<LinearAllocator<SIZE_BYTES>, Mallocator<std::pair<const Key, Value>>>;

template <typename Key, typename Value, size_t SIZE_BYTES>
using MapAllocatorAdapter = AllocatorAdapter<std::pair<const Key, Value>, MapFallbackAllocator<Key, Value, SIZE_BYTES>>;

template <typename Key, typename Value, size_t SIZE_BYTES>
using Map = std::map<Key, Value, std::less<>, MapAllocatorAdapter<Key, Value, SIZE_BYTES>>;

/* @brief Fill std::map with 10 elements, allocated by custom allocator */
TEST(TestHW3, TestMapWithCustomAllocator) {
    const std::size_t mem_size_bytes = 400; // sizeof std::map node is 40 bytes

    MapFallbackAllocator<int, int, mem_size_bytes> allocator;
    MapAllocatorAdapter<int, int, mem_size_bytes> adapter(allocator);

    Map<int, int, mem_size_bytes> map(adapter);

    for (auto i = 0; i <= 9; i++)
    {
        map[i] = factorial(i);
    }

    EXPECT_EQ(map.size(), 10);

    print_map(map);
}
/* -------------------------- */


/* @brief Fill std::vector with 10 elements, allocated by custom allocator */
TEST(TestHW3, TestStdVectorWithCustomAllocator) {
    const std::size_t mem_size = 100;
    FallBackAllocator<LinearAllocator<mem_size>, Mallocator<int>> al;
    AllocatorAdapter<int, FallBackAllocator<LinearAllocator<mem_size>, Mallocator<int>>> ad(al);
    std::vector<int, AllocatorAdapter<int, FallBackAllocator<LinearAllocator<mem_size>, Mallocator<int>>>> v(ad);

    for (auto i = 0; i <= 9; i++)
    {
        v.push_back(factorial(i));
    }

    print_vector(v);
}
/* -------------------------- */


/* @brief Fill custom vector with 10 elements, allocated by standard allocator */
TEST(TestHW3, TestCustomVectorWithStdAllocator)
{
    const std::size_t mem_size_bytes = 400;
    FallBackAllocator<LinearAllocator<mem_size_bytes>, Mallocator<int>> al;
    AllocatorAdapter<int, FallBackAllocator<LinearAllocator<mem_size_bytes>, Mallocator<int>>> ad(al);

    MyVector<int, AllocatorAdapter<int, FallBackAllocator<LinearAllocator<mem_size_bytes>, Mallocator<int>>>> v(ad);
    for (int i = 0; i < 10; i++)
    {
        v.push_back(factorial(i));
    }

    print_vector(v);
}
/* -------------------------- */


template <typename T, size_t SIZE_BYTES>
using MyVectorFallbackAllocator = FallBackAllocator<LinearAllocator<SIZE_BYTES>, Mallocator<T>>;

template <typename T, size_t SIZE_BYTES>
using MyVectorAllocatorAdapter = AllocatorAdapter<T, MyVectorFallbackAllocator<T, SIZE_BYTES>>;

template <typename T, size_t SIZE_BYTES>
using MyVectorType = MyVector<T, MyVectorAllocatorAdapter<T, SIZE_BYTES>>;

/* @brief Fill custom vector with 10 elements, allocated by custom allocator */
TEST(TestHW3, TestCustomVectorWithCustomAllocator) {
    const std::size_t mem_size_bytes = 40; // sizeof int is 4 bytes

    MyVectorFallbackAllocator<int, mem_size_bytes> allocator;
    MyVectorAllocatorAdapter<int, mem_size_bytes> adapter(allocator);

    MyVectorType<int, mem_size_bytes> my_vector(adapter);

    for (auto i = 0; i <= 9; i++)
    {
        my_vector.push_back((int)factorial(i));
    }

    EXPECT_EQ(my_vector.size(), 10);

    print_vector(my_vector);
}