template <size_t SIZE_BYTES>
FreeListAllocator<SIZE_BYTES>::FreeListAllocator() noexcept
        : Allocator<SIZE_BYTES>(std::malloc(SIZE_BYTES))
//          m_free_blocks{reinterpret_cast<FreeBlock*>(ptr_add(this->m_start, SIZE_BYTES))} TODO: remove
{

    auto start_block = reinterpret_cast<FreeBlock*>(ptr_add(this->m_start, 0));
    start_block->size = SIZE_BYTES;
    m_free_blocks =  start_block;
}

template <size_t SIZE_BYTES>
FreeListAllocator<SIZE_BYTES>::FreeListAllocator(FreeListAllocator<SIZE_BYTES> &&other) noexcept
        : Allocator<SIZE_BYTES>(std::move(other)),
          m_free_blocks{other.m_free_blocks}
{
    other.m_current = nullptr;
}

template <size_t SIZE_BYTES>
FreeListAllocator<SIZE_BYTES>& FreeListAllocator<SIZE_BYTES>::operator=(FreeListAllocator<SIZE_BYTES> &&other) noexcept
{
    m_free_blocks = other.m_free_blocks;
    Allocator<SIZE_BYTES>::operator=(std::move(other));
    other.m_current = nullptr;
    return *this;
}

template <std::size_t SIZE_BYTES>
void* FreeListAllocator<SIZE_BYTES>::allocate(const std::size_t &size, const std::uintptr_t &alignment)
{
    assert(size > 0 && alignment > 0);

    FreeBlock *prev_free_block = nullptr;
    FreeBlock *free_block = m_free_blocks;

    FreeBlock *best_fit_prev = nullptr;
    FreeBlock *best_fit = nullptr;

    std::uintptr_t best_fit_adjustment = 0;
    std::size_t best_fit_total_size = 0;

    while (free_block != nullptr)
    {
        auto adjustment = (std::uintptr_t)0; // TODO: implement alignment with header
        auto total_size = size + adjustment;

        if (free_block->size > total_size
            && (best_fit == nullptr || free_block->size < best_fit->size))
        {
            best_fit_prev = prev_free_block;
            best_fit = free_block;
            best_fit_adjustment = adjustment;
            best_fit_total_size = total_size;

            if (free_block->size == total_size) { break; }
        }

        prev_free_block = free_block;
        free_block = free_block->next;
    }

    if (best_fit == nullptr) { throw std::bad_alloc(); }

    if (best_fit->size - best_fit_total_size <= sizeof(AllocationHeader))
    {
        best_fit_total_size = best_fit->size;

        if (best_fit_prev != nullptr)
        {
            best_fit_prev->next = best_fit->next;
        }
        else
        {
            m_free_blocks = best_fit->next;
        }
    }
    else
    {
//        assert(best_fit_total_size > sizeof(FreeBlock)); // TODO: need?

        auto new_block = reinterpret_cast<FreeBlock*>(ptr_add(best_fit, best_fit_total_size));
        auto k = (std::uintptr_t)new_block - (std::uintptr_t)best_fit;
        auto best_fit_size = best_fit->size;
        new_block->size = best_fit_size - best_fit_total_size;
        new_block->next = best_fit->next;

        if (best_fit_prev != nullptr)
        {
            best_fit_prev->next = new_block;
        }
        else
        {
            m_free_blocks = new_block;
        }
    }

    auto aligned_address = reinterpret_cast<std::uintptr_t>(best_fit) + best_fit_adjustment;
    auto header = reinterpret_cast<AllocationHeader*>(aligned_address - sizeof(AllocationHeader));

    header->size = best_fit_total_size;
    header->adjustment = best_fit_adjustment;

    this->m_used_bytes += best_fit_total_size;
    ++this->m_allocations_count;

    return reinterpret_cast<void*>(aligned_address);
}

template <std::size_t SIZE_BYTES>
void FreeListAllocator<SIZE_BYTES>::deallocate(void* const)
{
    // TODO: OWNS!!!!!!!!!!
    // TODO: implement me
}