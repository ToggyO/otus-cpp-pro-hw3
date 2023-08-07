#include "linear_allocator.h"

#include <cassert>

LinearAllocator::LinearAllocator(const std::size_t size_bytes, void* const start)
    : Allocator(size_bytes, start),
    m_current{const_cast<void*>(start)}
{}

LinearAllocator::LinearAllocator(LinearAllocator &&other) noexcept
    : Allocator(std::move(other)),
      m_current{other.m_current}
{
    // TODO: CHECK
    other.m_current = nullptr;
}

LinearAllocator::~LinearAllocator() noexcept
{
    // TODO: check
    clear();
}

LinearAllocator& LinearAllocator::operator=(LinearAllocator &&other) noexcept
{
    m_current = other.m_current;
    Allocator::operator=(std::move(other));
    other.m_current = nullptr;
    return *this;
}

void* LinearAllocator::allocate(const std::size_t &size, const std::uintptr_t &alignment)
{
    assert(size > 0 && alignment > 0);

    auto adjustment = align_forward_adjustment(m_current, alignment);

    if (m_used_bytes + adjustment + size > m_size) { throw std::bad_alloc(); }

    auto aligned_address = ptr_add(m_current, adjustment);
    m_current = ptr_add(aligned_address, size);

    m_used_bytes = reinterpret_cast<std::uintptr_t>(m_current)
        - reinterpret_cast<std::uintptr_t>(m_start);

    ++m_allocations_count;

    return aligned_address;
}

void LinearAllocator::deallocate([[maybe_unused]] void* const ptr) noexcept
{
    // you can't free from a linear allocator
}

void LinearAllocator::rewind(void* const mark) noexcept
{
    assert(m_current >= mark && m_start <= mark);

    m_current = mark;

    m_used_bytes = reinterpret_cast<std::uintptr_t>(m_current)
        - reinterpret_cast<std::uintptr_t>(m_start);
}

void LinearAllocator::clear() noexcept
{
    m_used_bytes = 0;
    m_allocations_count = 0;
    m_current = const_cast<void*>(m_start);
}

