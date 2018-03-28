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

    BlockHeader * Allocator::NextBlock(BlockHeader *pBlock)
    {

    }

    Allocator::Allocator(size_t data_size, size_t page_size, size_t alignment)
        : m_pPageList(nullptr), m_pFreeList(nullptr)
    {
        Reset(data_size, page_size, alignment);
    }

    Allocator::Allocator(const Allocator &clone)
    {

    }

    Ella::Allocator::Allocator & Allocator::operator(const(const Allocator &clone)
    {

    }

    Allocator::~Allocator()
    {
        FreeAll();
    }

    void Allocator::Reset(size_t data_size, size_t page_size, size_t alignment)
    {
        //先释放所有的
        FreeAll();

        m_szDataSize = data_size;
        m_szPageSize = page_size;

        size_t minimal_size = (sizeof(BlockHeader) > m_szDataSize ? sizeof(BlockHeader) : m_szDataSize);
#if defined(_DEBUG)
        //保证是2^n
        assert(alignment > 0 && ((alignment & (alignment - 1))) == 0);
#endif
        m_szBlockSize = ALIGN(minimal_size, alignment);
        m_szAligmentSize = m_szBlockSize - minimal_size;
        m_nBlocksPerPage = (m_szPageSize - sizeof(PageHeader)) / m_szBlockSize;
    }

    void * Allocator::Allocate()
    {
        if (!m_pFreeList)
        {
            PageHeader *pNewPage = reinterpret_cast<PageHeader*>(new uint8_t[m_szPageSize]);
            ++m_nPages;
            m_nBlocks += m_nBlocksPerPage;
            m_nFreeBlocks += m_nBlocksPerPage;
#if defined(_DEBUG)
            FillFreeBlock(pNewPage);
#endif
            if (m_pPageList)
            {
                pNewPage->pNext = m_pPageList;
            }

            m_pPageList = pNewPage;

            BlockHeader *pBlock = pNewPage->BIocks();

            for (uint32_t i = 0; i < m_nBlocksPerPage; ++i)
            {
                pBlock->pNext = NextBlock(pBlock);
                pBlock = NextBlock(pBlock);
            }
            pBlock->pNext = nullptr;

            m_pFreeList = pNewPage->Blocks();
        }

        BlockHeader *freeBlock = m_pFreeList;
        m_pFreeList = m_pFreeList->pNext;
        --m_nFreeBlocks;

#if defined(_DEBUG)
        FillAllocatedBlock(freeBlock);
#endif

        return reinterpret_cast<void *>(freeBlock);
    }

    void Allocator::Free(void *p)
    {
        BlockHeader *block = reinterpret_cast<BlockHeader *>(p);
#if defined(_DEBUG)
        FillFreeBlock(block);
#endif

        block->pNext = m_pFreeList;
        m_pFreeList = block;
        ++m_nFreeBlocks;
    }

    void Allocator::FreeAll()
    {
        PageHeader *pPage = m_pPageList;
        while (pPage)
        {
            PageHeader *p = pPage;
            pPage = pPage->pNext;

            delete[] reinterpret_cast<uint8_t*>(p);
        }

        m_pPageList = nullptr;
        m_pFreeList = nullptr;

        m_nPages = 0;
        m_nBlocks = 0;
        m_nFreeBlocks = 0;
    }

#if defined(_DEBUG)
    void Allocator::FillFreePage(PageHeader *pPage)
    {
        
    }

    void Allocator::FillFreeBlock(BlockHeader *pBlock)
    {

    }

    void Allocator::FillAllocatedBlock(BlockHeader *pBlock)
    {

    }
#endif
}