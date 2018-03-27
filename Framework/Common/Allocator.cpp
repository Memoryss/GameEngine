#include "Allocator.hpp"
#include <cassert>
#include <cstring>

#ifndef ALIGN
#define ALIGN(x, a) (((x) + ((a) - 1)) & ~((a) - 1))
#endif

namespace Ella {


    const uint8_t Allocator::PATTERN_ALIGN;

    const uint8_t Allocator::PATTERN_ALLOC;

    const uint8_t Allocator::PATTERN_FREE;

    Ella::BlockHeader * Allocator::NextBlock(BlockHeader *pBlock)
    {

    }

    Allocator::Allocator(size_t data_size, size_t page_size, size_t alignment)
    {

    }

    Allocator::Allocator(const Allocator &clone)
    {

    }

    Ella::Allocator::Allocator & Allocator::operator(const(const Allocator &clone)
    {

    }

    Allocator::~Allocator()
    {

    }

    void Allocator::Reset(size_t data_size, size_t page_size, size_t alignment)
    {

    }

    void * Allocator::Allocate()
    {

    }

    void Allocator::Free(void *p)
    {

    }

    void Allocator::FreeAll()
    {

    }

    void Allocator::FillFreePage(PageHeader *pPage)
    {

    }

    void Allocator::FillFreeBlock(BlockHeader *pBlock)
    {

    }

    void Allocator::FillAllocatedBlock(BlockHeader *pBlock)
    {

    }

}