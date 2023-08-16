template <class Primary, class Fallback>
void* FallBackAllocator<Primary, Fallback>::allocate(const std::size_t &size, const std::uintptr_t &alignment)
{
    void* result = nullptr;
    try
    {
        result = Primary::allocate(size, alignment);
    }
    catch (std::bad_alloc &bae)
    {
        result = Fallback::allocate(size, alignment);
    }

    return result;
}

template <class Primary, class Fallback>
void FallBackAllocator<Primary, Fallback>::deallocate(void* const ptr) noexcept
{
    if (Primary::owns(ptr))
    {
        Primary::deallocate(ptr);
    }
    else
    {
        Fallback::deallocate(ptr);
    }
}

template <class Primary, class Fallback>
bool FallBackAllocator<Primary, Fallback>::owns(void* const ptr) const
{
    return Primary::owns(ptr) || Fallback::owns(ptr);
}