#pragma once

#include <algorithm>

#include "allocator.h"

template <size_t SIZE_BYTES>
class LinearAllocator : public Allocator<SIZE_BYTES>
{
public:
    LinearAllocator() noexcept;

    explicit LinearAllocator(void* const) noexcept;

    LinearAllocator(const LinearAllocator&) = delete;
    LinearAllocator(LinearAllocator&&) noexcept;

    ~LinearAllocator() noexcept override;

    LinearAllocator& operator=(const LinearAllocator&) = delete;
    LinearAllocator& operator=(LinearAllocator&&) noexcept;

    virtual void* allocate(const std::size_t&, const std::uintptr_t& = sizeof(std::uintptr_t)) override;

    void deallocate(void* const) override;

    virtual void rewind(void* const) noexcept;

    virtual void clear() noexcept;

    [[nodiscard]]
    const void* get_current() const noexcept { return m_current; }

protected:
    void* m_current;

    void init() noexcept;
};

template <size_t SIZE_BYTES>
bool operator==(const LinearAllocator<SIZE_BYTES> &lhs, const LinearAllocator<SIZE_BYTES> &rhs)
{
    return (lhs.get_current() == rhs.get_current())
           && (Allocator<SIZE_BYTES>&)lhs == (Allocator<SIZE_BYTES>&)rhs;
}

template <size_t SIZE_BYTES>
bool operator!=(const LinearAllocator<SIZE_BYTES> &lhs, const LinearAllocator<SIZE_BYTES> &rhs)
{
    return !(lhs == rhs);
}

#include "linear_allocator.inl"