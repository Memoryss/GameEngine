#pragma once

#include <cstddef>
#include <cstdint>

namespace Ella {

    struct BlockHeader
    {
        BlockHeader *pNext;
    };

    struct PageHeader
    {
        PageHeader *pNext;
        BlockHeader *BIocks() 
        {
            return reinterpret_cast<BlockHeader*>(this + 1);
        }
    };

    class Allocator
    {
    public:
        static const uint8_t PATTERN_ALIGN = 0xFC;
        static const uint8_t PATTERN_ALLOC = 0xFD;
        static const uint8_t PATTERN_FREE = 0xFE;

        Allocator(size_t data_size, size_t page_size, size_t alignment);
        ~Allocator();

        void Reset(size_t data_size, size_t page_size, size_t alignment);

        void * Allocate();

        void Free(void *p);
        void FreeAll();

    private:
#if defined(_DEBUG)
        void FillFreePage(PageHeader *pPage);
        void FillFreeBlock(BlockHeader *pBlock);
        void FillAllocatedBlock(BlockHeader *pBlock);
#endif


    };


}