#pragma once

#include <cstddef>
#include <memory>

template <class T, class Allocator = std::allocator<T>>
class MyVector
{
public:
    // Member types
    using value_type       = T;
    using allocator_type   = Allocator;
    using allocator_traits = std::allocator_traits<allocator_type>;

    MyVector() = default;

    explicit MyVector(const Allocator &allocator) noexcept;

    void push_back(const T&);

    class iterator
    {
    public:
        iterator(T* ptr) noexcept
            : current(ptr)
        {}

        iterator operator++()
        {
            return iterator(current++);
        }

        bool operator==(const iterator& it) { return current == it.current; }

        bool operator!=(const iterator& it) { return current != it.current;  }

        T operator*() const { return *current; }

        T operator->() const { return current; }

    private:
        T* current;
    };

    iterator begin() const { return iterator(m_data); }

    iterator end() const { return iterator(m_data + m_size); }

    [[nodiscard]]
    std::size_t size() const { return m_size; }


private:
    std::size_t m_size = 0;
    std::size_t m_capacity = 0;
    T* m_data = nullptr;

    Allocator alloc;
};

#include "my_vector.inl"
