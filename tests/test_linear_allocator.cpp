#include <gtest/gtest.h>

#include "allocators/linear_allocator.h"

// TODO: тесты констуркторов, тесты операторов сравнения
TEST(LinearAllocatorTest, AllocationAndProperAlignment) {
    int alignment = 8;
    const std::size_t mem_size_bytes = 100;

    LinearAllocator<mem_size_bytes> allocator;
    const auto& used_bytes = allocator.get_used_bytes();

    allocator.allocate(9, alignment);
    EXPECT_EQ(used_bytes, 9);

    allocator.allocate(5, alignment);
    EXPECT_EQ(used_bytes, 21);

    allocator.allocate(8, alignment);
    EXPECT_EQ(used_bytes, 32);

    allocator.allocate(12, alignment);
    EXPECT_EQ(used_bytes, 44);

    allocator.allocate(16, alignment);
    EXPECT_EQ(used_bytes, 64);

    EXPECT_EQ(allocator.get_allocations_count(), 5);
}

TEST(LinearAllocatorTest, TestOwns) {
    int alignment = 8;
    const std::size_t mem_size_bytes = 100;

    LinearAllocator<mem_size_bytes> allocator;

    void* ptr = allocator.allocate(4, alignment);
    EXPECT_EQ(allocator.get_used_bytes(), 4);

    ptr = allocator.allocate(5, alignment);
    EXPECT_EQ(allocator.get_used_bytes(), 13);
    EXPECT_TRUE(allocator.owns(ptr));

    ptr = ::operator new (10);
    EXPECT_FALSE(allocator.owns(ptr));
}