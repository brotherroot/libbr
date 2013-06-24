/*
 * @file  include/memory/MemPool.hpp
 */
#pragma once

#include <config.hpp>

#include <memory/MemPoolBase.hpp>
#include <structure/DynArrPOD.hpp>

namespace BR {
/*
 *  @brief 内存池
 */
template< int SIZE >
class MemPool : public MemPoolBase {
public:
	MemPool() :
		m_root( BR_NULLPTR ), m_curr_alloc(0), m_have_alloc(0), m_max_alloc(0), m_untracked(0) { }

	~MemPool() {
		// Delete the blocks.
		for( int i=0; i<m_blocks.size(); ++i ) {
			delete m_blocks[i];
		}
	}

	virtual int item_size() const	{
		return SIZE;
	}

	int curr_alloc() const		{
		return m_curr_alloc;
	}

	virtual void * alloc() {
		if ( m_root == BR_NULLPTR ) {
			// 分配新块
			Block * block = new Block();
			m_blocks.push( block );

			for( int i=0; i<COUNT-1; ++i ) {
				block->chunk[i].next = &block->chunk[i+1];
			}
			block->chunk[COUNT-1].next = BR_NULLPTR;
			m_root = block->chunk;
		}
		void * result = m_root;
		m_root = m_root->next;
		++m_curr_alloc;
		if ( m_curr_alloc > m_max_alloc ) {
			m_max_alloc = m_curr_alloc;
		}
		++m_have_alloc;
		++m_untracked;
		return result;
	}

	virtual void free( void * mem ) {
		if ( !mem ) {
			return;
		}
		--m_curr_alloc;
		Chunk* chunk = (Chunk *)mem;
#ifndef NDEBUG
		memset( chunk, 0xFE, sizeof(Chunk) );
#endif
		chunk->next = m_root;
		m_root = chunk;
	}

	void trace( char const * name ) {
		printf( "Mempool %s watermark=%d [%dk] current=%d size=%d nAlloc=%d blocks=%d\n",
			name, m_max_alloc, m_max_alloc*SIZE/1024, m_curr_alloc, SIZE, m_have_alloc, m_block.size() );
	}

	void track() {
		--m_untracked;
	}

	int untracked() const {
		return m_untracked;
	}

	static int const COUNT = (4*1024) / SIZE;

private:
	union Chunk {
		Chunk * next;
		char    mem[SIZE];
	};

	struct Block {
		Chunk chunk[COUNT];
	};

	DynArrPOD< Block *, 10 > m_blocks;
	Chunk * m_root;
	int m_curr_alloc;
	int m_have_alloc;
	int m_max_alloc;
	int m_untracked;
};

}