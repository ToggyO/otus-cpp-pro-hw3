#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdlib>

template <size_t SIZE_BYTES>
class Allocator
{
    static_assert(SIZE_BYTES > 0);
public:
    explicit Allocator(void* start);

    Allocator(const Allocator&) = delete;
    Allocator(Allocator&&) noexcept;

    virtual ~Allocator() noexcept;

    Allocator& operator=(Allocator&) = delete;
    Allocator& operator=(Allocator&&) noexcept;

    virtual void* allocate(const std::size_t&, const std::uintptr_t& = sizeof(std::uintptr_t)) = 0;

    virtual void deallocate(void* const ptr) = 0;

    [[nodiscard]]
    const void* get_start() const noexcept { return m_start; }

protected:
    std::size_t m_size;
    std::size_t m_used_bytes;
    std::size_t m_allocations_count;

    void *m_start;
};
