#pragma once

// TODO: check
//#include <cstddef>
//#include <cstdint>
//#include <cstdlib>

#include "../utils/utils.h"

template <size_t SIZE_BYTES>
class Allocator
{
    static_assert(SIZE_BYTES > 0);
public:
    explicit Allocator(void*);

    Allocator(const Allocator&) = delete;
    Allocator(Allocator&&) noexcept;

    virtual ~Allocator() noexcept;

    Allocator& operator=(Allocator&) = delete;
    Allocator& operator=(Allocator&&) noexcept;

    virtual void* allocate(const std::size_t&, const std::uintptr_t& = sizeof(std::uintptr_t)) = 0;

    virtual void deallocate(void* const) = 0;

    virtual bool owns(void* const ptr) const { return (m_start <= ptr) && (ptr <= (ptr_add(m_start, SIZE_BYTES))); }

    [[nodiscard]]
    const std::size_t& get_size() const noexcept { return m_size; }

    [[nodiscard]]
    const std::size_t& get_used_bytes() const noexcept { return m_used_bytes; }

    [[nodiscard]]
    const std::size_t& get_allocations_count() const noexcept { return m_allocations_count; }

    [[nodiscard]]
    const void* get_start() const noexcept { return m_start; }

protected:
    std::size_t m_size;
    std::size_t m_used_bytes;
    std::size_t m_allocations_count;

    void *m_start;
};

template <size_t SIZE_BYTES>
bool operator==(const Allocator<SIZE_BYTES> &lhs, const Allocator<SIZE_BYTES> &rhs)
{
    return lhs.get_start() == rhs.get_start()
        && lhs.get_size() == rhs.get_size()
        && lhs.get_used_bytes() == rhs.get_used_bytes()
        && lhs.get_allocations_count() == rhs.get_allocations_count();
}

template <size_t SIZE_BYTES>
bool operator!=(const Allocator<SIZE_BYTES> &lhs, const Allocator<SIZE_BYTES> &rhs)
{
    return !(lhs == rhs);
}

#include "allocator.ipp"