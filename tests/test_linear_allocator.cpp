#include <gtest/gtest.h>

#include "allocators/linear_allocator.h"

static constexpr int alignment = 8;
static constexpr std::size_t mem_size_bytes = 100;

TEST(LinearAllocatorTest, Ctors) {
    LinearAllocator<mem_size_bytes> allocator;

    allocator.allocate(4, alignment);
    EXPECT_EQ(allocator.get_used_bytes(), 4);

    LinearAllocator<mem_size_bytes> allocator1(std::move(allocator));
    EXPECT_EQ(allocator1.get_used_bytes(), 4);
    EXPECT_EQ(allocator1.get_size(), 100);
    EXPECT_EQ(allocator1.get_allocations_count(), 1);

    // TODO: вызывается move ctor вместо move assign operator. Что я сделал не так?
    LinearAllocator<mem_size_bytes> allocator2 = std::move(allocator1);
    //
    EXPECT_EQ(allocator2.get_used_bytes(), 4);
    EXPECT_EQ(allocator2.get_size(), 100);
    EXPECT_EQ(allocator2.get_allocations_count(), 1);
}

TEST(LinearAllocatorTest, EqualityOpeartors) {
    LinearAllocator<mem_size_bytes> allocator;
    allocator.allocate(4, alignment);

    const auto r = allocator.get_start();
    LinearAllocator<mem_size_bytes> allocator1(const_cast<void* const>(r));
    allocator1.allocate(4, alignment);

    EXPECT_TRUE(allocator == allocator1);
    EXPECT_FALSE(allocator != allocator1);
}

TEST(LinearAllocatorTest, AllocationAndProperAlignment) {
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
    LinearAllocator<mem_size_bytes> allocator;

    void* ptr = allocator.allocate(4, alignment);
    EXPECT_EQ(allocator.get_used_bytes(), 4);

    ptr = allocator.allocate(5, alignment);
    EXPECT_EQ(allocator.get_used_bytes(), 13);
    EXPECT_TRUE(allocator.owns(ptr));

    ptr = ::operator new (10);
    EXPECT_FALSE(allocator.owns(ptr));
}