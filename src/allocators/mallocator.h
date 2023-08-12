#include <cstddef>  // Required for size_t and ptrdiff_t and NULL
#include <new>       // Required for placement new and std::bad_alloc
#include <stdexcept> // Required for std::length_error
#include <cstdlib>  // For malloc() and free()
#include <iostream>  // For std::cout
#include <ostream>   // For std::endl
#include <list>      // For std::list

template <typename T>
class Mallocator
{
public:
    // The following will be the same for virtually all allocators.
    using value_type = T;

    // The following must be the same for all allocators.
    template <typename U> struct rebind { typedef Mallocator<U> other;  };

    // Default constructor, copy constructor, rebinding constructor, and destructor.
    // Empty for stateless allocators.
    Mallocator() = default;

    Mallocator(const Mallocator&) = default;
    Mallocator(Mallocator&&) = default;

    template <typename U>
    Mallocator(const Mallocator<U>&) { }

    ~Mallocator() = default;

    // The following will be different for each allocator.
    [[nodiscard]]
    T* allocate(const size_t&, [[maybe_unused]] const std::uintptr_t&);

    void deallocate(void* const p) const { free(p); }

    // The following will be the same for all allocators that ignore hints.
    template <typename U>
    T* allocate(const size_t&, [[maybe_unused]] const U *const) const;

    void construct(T * const p, const T& t) const;

    void destroy(T * const p) const; // Defined below.

    bool owns(void* const ptr) const { return true; }

    T* address(T& r) const { return &r; }

    [[nodiscard]]
    const T * address(const T& s) const { return &s; }

    [[nodiscard]]
    size_t max_size() const;

    // Returns true if and only if storage allocated from *this
    // can be deallocated from other, and vice versa.
    // Always returns true for stateless allocators.
    bool operator==(const Mallocator& other) const { return true; }

    bool operator!=(const Mallocator& other) const {  return !(*this == other); }

    // Allocators are not required to be assignable, so
    // all allocators should have a private unimplemented
    // assignment operator. Note that this will trigger the
    // off-by-default (enabled under /Wall) warning C4626
    // "assignment operator could not be generated because a
    // base class assignment operator is inaccessible" within
    // the STL headers, but that warning is useless.
private:
    Mallocator& operator=(const Mallocator&);
};

// A compiler bug causes it to believe that p->~T() doesn’t reference p.
#ifdef _MSC_VER
#pragma warning(push)
    #pragma warning(disable: 4100) // unreferenced formal parameter
#endif

// The definition of destroy() must be the same for all allocators.
template <typename T>
void Mallocator<T>::destroy(T * const p) const {
    p->~T();
}

#include "mallocator.ipp"
