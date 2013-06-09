/*
 * @file  memory/MemPoolBase.hpp
 */
#pragma once
 
namespace BR {
/*
 *  @brief 内存池基类
 */
class MemPoolBase {
public:
    MemPoolBase() { }
    virtual ~MemPoolBase() { }

    virtual int item_size() const = 0;
    virtual void * alloc() = 0;
    virtual void free( void * ) = 0;
    virtual void track() = 0;
};

}