#pragma once

template <class Primary, class Fallback>
class FallBackAllocator : private Primary, private Fallback
{
//    static_assert(!traits); TODO: в будущем сделать проверку, что шаблонные аргументы имеют разные базовые типы
public:
    void* allocate(const std::size_t &size, const std::uintptr_t &alignment);

    void deallocate(void* const) noexcept;

    bool owns(void* const ptr) const;
};

template <class Primary, class Fallback>
bool operator==(const FallBackAllocator<Primary, Fallback> &lhs, const FallBackAllocator<Primary, Fallback> &rhs)
{
    return true;
}

template <class Primary, class Fallback>
bool operator!=(const FallBackAllocator<Primary, Fallback> &lhs, const FallBackAllocator<Primary, Fallback> &rhs)
{
    return false;
}

#include "fall_back_allocator.inl"