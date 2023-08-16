template <class T, class Allocator>
MyVector<T, Allocator>::MyVector(const Allocator &allocator) noexcept
    : alloc{allocator}, m_data((T*)std::malloc(0))
{}

template <class T, class Allocator>
void MyVector<T, Allocator>::push_back(const T& x)
{
    if (m_size == m_capacity)
    {
        m_capacity = m_capacity * 2 + 1;
        T* newData = allocator_traits::allocate(alloc, m_capacity);
        std::copy(m_data, m_data + m_capacity * sizeof(T), newData); //naive
        std::swap(newData, m_data);
        allocator_traits::deallocate(alloc, newData, m_capacity);
    }

    allocator_traits::construct(alloc, m_data + m_size, x);
    ++m_size;
}
