#pragma once

// TODO: remove
//#include <cstddef>
//#include <cstdint>
//#include <type_traits>

template <class Primary, class Fallback>
class FallBackAllocator : private Primary, private Fallback
{
//    static_assert(!traits); TODO: проверка, что разные базовые типы
public:
    void* allocate(const std::size_t &size, const std::uintptr_t &alignment);

    void deallocate(void* const) noexcept;
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

#include "fall_back_allocator.ipp"