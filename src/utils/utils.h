#pragma once

#include <cstdint>

std::size_t align_forward_adjustment(const void *const ptr, const std::size_t &alignment) noexcept;

void* ptr_add(const void *const ptr, const std::uintptr_t &amount) noexcept;