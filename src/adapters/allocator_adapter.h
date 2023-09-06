#pragma once

#include <iostream> // cout
#include <type_traits> // is_same

template <typename T, class AllocationStrategy>
class AllocatorAdapter
{
    static_assert(!std::is_same<T, void>(), "Void is noty allowed as allocation type");
public:
    using value_type = T;
    using pointer = T*;
    using size_type = size_t;

    template <typename U>
    struct rebind { using other = AllocatorAdapter<U, AllocationStrategy>;  };

    AllocatorAdapter() noexcept;

    explicit AllocatorAdapter(AllocationStrategy&) noexcept;

    template <class U>
    explicit AllocatorAdapter(const AllocatorAdapter<U, AllocationStrategy>&) noexcept;

    ~AllocatorAdapter() = default;

    pointer allocate(size_type);

    void deallocate(pointer, size_type);

    const AllocationStrategy& get_strategy() const { return m_allocation_strategy; }

private:
    const AllocationStrategy &m_allocation_strategy;
};

template<class T, class U, class AllocationStrategy>
bool operator==(const AllocatorAdapter<T, AllocationStrategy> &lhs, const AllocatorAdapter<U, AllocationStrategy> &rhs)
{
    return lhs.get_strategy() == rhs.get_strategy();
}

template<class T, class U, class AllocationStrategy>
bool operator!=(const AllocatorAdapter<T, AllocationStrategy> &lhs, const AllocatorAdapter<U, AllocationStrategy> &rhs)
{
    return !(lhs == rhs);
}

#include "allocator_adapter.inl"
