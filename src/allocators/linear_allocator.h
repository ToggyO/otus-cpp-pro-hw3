#pragma once

#include <algorithm>

#include "allocator.h"

class LinearAllocator : public Allocator
{
public:
    LinearAllocator(const std::size_t, void* const);

    LinearAllocator(const LinearAllocator&) = delete;
    LinearAllocator(LinearAllocator&&) noexcept;

    ~LinearAllocator() noexcept override;

    LinearAllocator& operator=(LinearAllocator&) = delete;
    LinearAllocator& operator=(LinearAllocator&&) noexcept;

    virtual void* allocate(const std::size_t&, const std::uintptr_t& = sizeof(std::uintptr_t)) override;

    virtual void deallocate(void* const) noexcept override final;

    virtual void rewind(void* const) noexcept;

    virtual void clear() noexcept;

protected:
    void* m_current;
};


// TODO: вынести, зарефачить
inline std::size_t align_forward_adjustment(const void *const ptr, const std::size_t &alignment) noexcept
{
    const auto uiptr = reinterpret_cast<std::uintptr_t>(ptr);

    const auto k = uiptr - 1u;
    const auto l = k + alignment;
    const auto negative_alignment = -alignment;

    const auto aligned = l & negative_alignment;

    auto p = aligned - uiptr;
    return p;
}

// TODO: вынести
inline void* ptr_add(const void *const ptr, const std::uintptr_t &amount) noexcept
{
    return reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(ptr) + amount);
}
