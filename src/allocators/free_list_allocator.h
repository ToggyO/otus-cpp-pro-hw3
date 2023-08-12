#pragma once

#include "allocator.h"

struct FreeBlock
{
    std::size_t size;
    FreeBlock *next;
};

struct AllocationHeader
{
    std::size_t size;
    std::uintptr_t adjustment;
};

template <std::size_t SIZE_BYTES>
class FreeListAllocator : public Allocator<SIZE_BYTES>
{
public:
    FreeListAllocator() noexcept;

    FreeListAllocator(const FreeListAllocator&) = delete;
    FreeListAllocator(FreeListAllocator&&) noexcept;

    ~FreeListAllocator() override = default;

    FreeListAllocator& operator=(FreeListAllocator&) = delete;
    FreeListAllocator& operator=(FreeListAllocator&&) noexcept;

    virtual void* allocate(const std::size_t&, const std::uintptr_t& = sizeof(std::uintptr_t)) override;

    virtual void deallocate(void* const) override;

private:
    FreeBlock *m_free_blocks;
};

#include "free_list_allocator.ipp"
