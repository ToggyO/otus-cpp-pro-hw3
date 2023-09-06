template <typename T, class AllocationStrategy>
AllocatorAdapter<T, AllocationStrategy>::AllocatorAdapter() noexcept
        : m_allocation_strategy{AllocationStrategy()}
{}

template <typename T, class AllocationStrategy>
AllocatorAdapter<T, AllocationStrategy>::AllocatorAdapter(AllocationStrategy &strategy) noexcept
    : m_allocation_strategy{strategy}
{}

template <typename T, class AllocationStrategy>
template <class U>
AllocatorAdapter<T, AllocationStrategy>::AllocatorAdapter(const AllocatorAdapter<U, AllocationStrategy> &other) noexcept
        : m_allocation_strategy{other.get_strategy()}
{}

template <typename T, class AllocationStrategy>
T* AllocatorAdapter<T, AllocationStrategy>::allocate(std::size_t n)
{
#ifdef DEBUG
    auto type_id = typeid(T).name();
    std::cout << "Allocating " << n << " elements of type '" << type_id << "'" << std::endl;
    std::cout << "sizeof(" << type_id << ") = " << sizeof(T) << " bytes" << std::endl;
#endif
    return static_cast<T*>(
            const_cast<AllocationStrategy&>(m_allocation_strategy).allocate(n * sizeof(T), alignof(T)));
}

template <typename T, class AllocationStrategy>
void AllocatorAdapter<T, AllocationStrategy>::deallocate(T* ptr, [[maybe_unused]] std::size_t n)
{
#ifdef DEBUG
    auto type_id = typeid(T).name();
    std::cout << "Deallocating element of type '" << type_id << "' " << std::endl;
    std::cout << "Memory address = " << std::hex << ptr << std::endl;
#endif
    const_cast<AllocationStrategy&>(m_allocation_strategy).deallocate(ptr);
}