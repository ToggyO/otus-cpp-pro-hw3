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
    // TODO: remove
//    typedef T value_type;
//    typedef T * pointer;
//    typedef const T * const_pointer;
//    typedef T& reference;
//    typedef const T& const_reference;
//    typedef size_t size_type;
//    typedef ptrdiff_t difference_type;

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
    T* allocate(const size_t &n, [[maybe_unused]] const std::uintptr_t &alignment)
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

    void deallocate(T * const p, [[maybe_unused]] const size_t n) const { free(p); }

    // The following will be the same for all allocators that ignore hints.
    template <typename U> T * allocate(const size_t n, [[maybe_unused]] const U * const hint) const
    {
        return allocate(n);
    }

    void construct(T * const p, const T& t) const
    {
        void * const pv = static_cast<void *>(p);
        new (pv) T(t);
    }

    void destroy(T * const p) const; // Defined below.

    bool owns(void* const ptr) { return true; }

    T* address(T& r) const { return &r; }

    [[nodiscard]]
    const T * address(const T& s) const { return &s; }

    [[nodiscard]]
    size_t max_size() const
    {
        // The following has been carefully written to be independent of
        // the definition of size_t and to avoid signed/unsigned warnings.
        return (static_cast<size_t>(0) - static_cast<size_t>(1)) / sizeof(T);
    }

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
