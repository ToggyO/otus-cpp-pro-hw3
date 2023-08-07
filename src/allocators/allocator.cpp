#include "allocator.h"

#include <cassert>

template <size_t SIZE_BYTES>
Allocator<SIZE_BYTES>::Allocator(void* const start)
    : m_size{SIZE_BYTES},
    m_used_bytes{0},
    m_allocations_count{0},
    m_start{start}
{}

template <size_t SIZE_BYTES>
Allocator<SIZE_BYTES>::Allocator(Allocator &&other) noexcept
    : m_size{other.m_size},
    m_used_bytes{other.m_used_bytes},
    m_allocations_count{other.m_allocations_count},
    m_start{other.m_start}
{
    other.m_size = 0;
    other.m_used_bytes = 0;
    other.m_allocations_count = 0;
    other.m_start = nullptr;
}

template <size_t SIZE_BYTES>
Allocator<SIZE_BYTES>& Allocator<SIZE_BYTES>::operator=(Allocator<SIZE_BYTES> &&other) noexcept
{
    m_size = other.m_size;
    m_used_bytes = other.m_used_bytes;
    m_allocations_count = other.m_allocations_count;
    m_start = other.m_start;

    other.m_size = 0;
    other.m_used_bytes = 0;
    other.m_allocations_count = 0;
    other.m_start = nullptr;

    return *this;
}

template <size_t SIZE_BYTES>
Allocator<SIZE_BYTES>::~Allocator() noexcept
{
    // TODO: CHECK!!!!
    assert(m_allocations_count == 0 && m_used_bytes == 0);
}

