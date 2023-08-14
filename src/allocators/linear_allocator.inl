template <size_t SIZE_BYTES>
LinearAllocator<SIZE_BYTES>::LinearAllocator() noexcept
    : Allocator<SIZE_BYTES>(nullptr),
    m_current{nullptr}
{}

template <size_t SIZE_BYTES>
LinearAllocator<SIZE_BYTES>::LinearAllocator(void* const start) noexcept
        : Allocator<SIZE_BYTES>(start),
          m_current{const_cast<void*>(this->m_start)}
{}

template <size_t SIZE_BYTES>
LinearAllocator<SIZE_BYTES>::LinearAllocator(LinearAllocator<SIZE_BYTES> &&other) noexcept
    : Allocator<SIZE_BYTES>(std::move(other)),
      m_current{other.m_current}
{
    other.m_current = nullptr;
}

template <size_t SIZE_BYTES>
LinearAllocator<SIZE_BYTES>::~LinearAllocator() noexcept
{
    clear();
}

template <size_t SIZE_BYTES>
LinearAllocator<SIZE_BYTES>& LinearAllocator<SIZE_BYTES>::operator=(LinearAllocator<SIZE_BYTES> &&other) noexcept
{
    m_current = other.m_current;
    Allocator<SIZE_BYTES>::operator=(std::move(other));
    other.m_current = nullptr;
    return *this;
}

template <size_t SIZE_BYTES>
void* LinearAllocator<SIZE_BYTES>::allocate(const std::size_t &size, const std::uintptr_t &alignment)
{
    assert(size > 0 && alignment > 0);

    // Memory allocation within first call of allocate method
    if (this->m_start == nullptr) { init(); }

    auto adjustment = align_forward_adjustment(m_current, alignment);

    if (this->m_used_bytes + adjustment + size > this->m_size)
    {
        throw std::bad_alloc();
    }

    auto aligned_address = ptr_add(m_current, adjustment);
    m_current = ptr_add(aligned_address, size);

    this->m_used_bytes = reinterpret_cast<std::uintptr_t>(m_current)
        - reinterpret_cast<std::uintptr_t>(this->m_start);

    ++this->m_allocations_count;

    return aligned_address;
}

template <size_t SIZE_BYTES>
void LinearAllocator<SIZE_BYTES>::deallocate([[maybe_unused]] void* const ptr)
{
    // you can't free from a linear allocator
}

template <size_t SIZE_BYTES>
void LinearAllocator<SIZE_BYTES>::rewind(void* const mark) noexcept
{
    assert(m_current >= mark && this->m_start <= mark);

    m_current = mark;

    this->m_used_bytes = reinterpret_cast<std::uintptr_t>(m_current)
        - reinterpret_cast<std::uintptr_t>(this->m_start);
}

template <size_t SIZE_BYTES>
void LinearAllocator<SIZE_BYTES>::clear() noexcept
{
    this->m_used_bytes = 0;
    this->m_allocations_count = 0;
    m_current = const_cast<void*>(this->m_start);
}

template <size_t SIZE_BYTES>
void LinearAllocator<SIZE_BYTES>::init() noexcept
{
    this->m_start = std::malloc(SIZE_BYTES);
    m_current = this->m_start;
}

