#include "utils.h"

std::size_t align_forward_adjustment(const void *const ptr, const std::size_t &alignment) noexcept
{
    const auto not_aligned_address = reinterpret_cast<std::uintptr_t>(ptr);
    if ( (alignment != 0u) && (not_aligned_address % alignment != 0u) )
    {
        const std::size_t multiplier = (not_aligned_address / alignment) + 1u;
        const std::size_t aligned_address = multiplier * alignment;
        return aligned_address - not_aligned_address;
    }

    return 0u;
}

void* ptr_add(const void *const ptr, const std::uintptr_t &amount) noexcept
{
    return reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(ptr) + amount);
}
