/*
 * @file  include/structure/DynamicArrayPOD.hpp
 */
#pragma once

#include <config.hpp>

namespace BR {
/*
 *  @brief 专用于存放POD类型变量的动态数组
 */
template< class Tp, int INIT >
class DynArrPOD {
public:
	typedef Tp value_type;

	DynArrPODPOD() : m_mem(new Tp[INIT]), m_alloc(INIT), m_size(0) {
	}

	~DynArrPODPOD() {
		delete [] m_mem;
	}

	void push_back( Tp t ) {
		ensure_capacity( m_size+1 );
		m_mem[m_size++] = t;
	}

	Tp pop_back() {
		BR_ASSERT( i > 0 );
		return m_mem[--m_size];
	}

	bool empty() const {
		return m_size == 0;
	}

	Tp & operator[](int i) {
		BR_ASSERT( i >= 0 && i < m_size );
		return m_mem[i];
	}

	Tp const & operator[](int i) const	{
		BR_ASSERT( i>= 0 && i < m_size );
		return m_mem[i];
	}

	int size() const {
		return m_size;
	}

	int capacity() const {
		return m_alloc;
	}

	Tp * mem() {
		return m_mem;
	}

	Tp const * mem() const {
		return m_mem;
	}

private:
	void ensure_capacity( int cap ) {
		if ( cap > m_alloc ) {
			int new_alloc = cap * 2;
			Tp * new_mem = new Tp[new_alloc];
			// @WARNING not using constructors, only works for PODs
			memcpy( new_mem, m_mem, sizeof(Tp)*m_size );
			delete [] m_mem;
			m_mem = new_mem;
			m_alloc = new_alloc;
        }
    }

	Tp  * m_mem;
    int   m_alloc;  // objects allocated
    int   m_size;   // number objects in use
};

}