template <class Primary, class Fallback>
void* FallBackAllocator<Primary, Fallback>::allocate(const std::size_t &size, const std::uintptr_t &alignment)
{
    void* result = Primary::allocate(size, alignment);
    if (!result)
    {
        result = Fallback::allocate(size, alignment);
    }

    return result;
}

template <class Primary, class Fallback>
void FallBackAllocator<Primary, Fallback>::deallocate(void* const ptr) const noexcept
{
    if (Primary::owns(ptr))
    {
        Primary::dealocate(ptr);
    }
    else
    {
        Fallback::dealocate(ptr);
    }
}