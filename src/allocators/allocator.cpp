#include "allocator.h"

#include <cassert>

Allocator::Allocator(const std::size_t size_bytes, void* const start)
    : m_size{size_bytes},
    m_used_bytes{0},
    m_allocations_count{0},
    m_start{start}
{
    assert(size_bytes > 0);
}

Allocator::Allocator(Allocator &&other) noexcept
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

Allocator& Allocator::operator=(Allocator &&other) noexcept
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

Allocator::~Allocator() noexcept
{
    // TODO: CHECK!!!!
    assert(m_allocations_count == 0 && m_used_bytes == 0);
}

