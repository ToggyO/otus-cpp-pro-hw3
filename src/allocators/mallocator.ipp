template <typename T>
T* Mallocator<T>::allocate(const size_t &n, [[maybe_unused]] const std::uintptr_t &alignment)
{
    // The return value of allocate(0) is unspecified.
    // Mallocator returns nullptr in order to avoid depending
    // on malloc(0)’s implementation-defined behavior
    // (the implementation can define malloc(0) to return NULL,
    // in which case the bad_alloc check below would fire).
    // All allocators can return NULL in this case.
    if (n == 0) { return nullptr; }

    // All allocators should contain an integer overflow check.
    // The Standardization Committee recommends that std::length_error
    // be thrown in the case of integer overflow.
    if (n > max_size())
    {
        throw std::length_error("Mallocator<T>::allocate() – Integer overflow.");
    }

    void * const pv = malloc(n * sizeof(T));

    // Allocators should throw std::bad_alloc in the case of memory allocation failure.
    if (pv == nullptr) { throw std::bad_alloc(); }

    return static_cast<T *>(pv);
}

template <typename T>
template <typename U>
T* Mallocator<T>::allocate(const size_t &n, [[maybe_unused]] const U *const hint) const
{
    return allocate(n);
}

template <typename T>
void Mallocator<T>::construct(T * const p, const T& t) const
{
    void * const pv = static_cast<void *>(p);
    new (pv) T(t);
}

template <typename T>
size_t Mallocator<T>::max_size() const
{
    // The following has been carefully written to be independent of
    // the definition of size_t and to avoid signed/unsigned warnings.
    return (static_cast<size_t>(0) - static_cast<size_t>(1)) / sizeof(T);
}