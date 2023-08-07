#pragma once

#include <type_traits>

template <typename T, class AllocationStrategy>
class AllocatorAdapter
{
    static_assert(!std::is_same<T, void>(), "Void is noty allowed as allocation type");
public:
    using value_type = T;

    AllocatorAdapter() noexcept;

    explicit AllocatorAdapter(AllocationStrategy&) noexcept;

    template <class U>
    explicit AllocatorAdapter(const AllocatorAdapter<U, AllocationStrategy>&) noexcept;

    ~AllocatorAdapter() = default;

    // TODO: дополить copy/move
//    AllocatorAdapter(const AllocatorAdapter&) noexcept = delete;
//    AllocatorAdapter(AllocatorAdapter&&) noexcept = delete;
//
//    AllocatorAdapter<T, AllocationStrategy>& operator=(const AllocatorAdapter&) = delete;
//    AllocatorAdapter<T, AllocationStrategy>& operator=(AllocatorAdapter&&) = delete;
    //

    T* allocate(std::size_t);

    void deallocate(T*, std::size_t);

    const AllocationStrategy& get_strategy() const { return m_allocation_strategy; }

private:
    const AllocationStrategy &m_allocation_strategy;
};

template<class T, class U, class AllocationStrategy>
bool operator==(const AllocatorAdapter<T, AllocationStrategy> &lhs, const AllocatorAdapter<U, AllocationStrategy> &rhs)
{
    // TODO: implement me
    return true;
}

template<class T, class U, class AllocationStrategy>
bool operator!=(const AllocatorAdapter<T, AllocationStrategy> &lhs, const AllocatorAdapter<U, AllocationStrategy> &rhs)
{
//    return !(lhs == rhs);
    // TODO: implement me
    return false;
}

#include "allocator_adapter.ipp"
