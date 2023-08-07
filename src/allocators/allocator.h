#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdlib>

class Allocator
{
public:
    Allocator(const std::size_t, void* const);

    Allocator(const Allocator&) = delete;
    Allocator(Allocator&&) noexcept;

    virtual ~Allocator() noexcept;

    Allocator& operator=(Allocator&) = delete;
    Allocator& operator=(Allocator&&) noexcept;

    virtual void* allocate(const std::size_t&, const std::uintptr_t& = sizeof(std::uintptr_t)) = 0;

    virtual void deallocate(void* const ptr) = 0;

    const void* get_start() const noexcept { return m_start; }

protected:
    std::size_t m_size;
    std::size_t m_used_bytes;
    std::size_t m_allocations_count;

    void *m_start;
};
