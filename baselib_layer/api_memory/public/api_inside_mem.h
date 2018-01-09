/****************************************************************************
 *
 *  api_inside_mem.h                                      
 *  Created on: 2017/12/08
 *  Version: 1.0
 * 
*****************************************************************************/
#ifndef __API_INSIDE_MEM_H__
#define __API_INSIDE_MEM_H__

#ifdef __cplusplus 	
extern "C" { 
#endif

#include <stdio.h>
#include <stdint.h>

#define INSIDE_MEM_SUCCESS         0
#define INSIDE_MEM_FAILED         -1

#define IN
#define OUT

/*****************************************************************
** 函数名称: api_inside_mempool_create
** 函数说明: 多生产多消费内存池创建 线程安全
** 入参列表:
**       --  pool_name: 内存池名称
**       --  obj_num: 内存对象个数 建议(obj_num % 512 == 0)
**       --  obj_size:内存对象大小
** 出参列表:
**      --   无
** 返回类型:
        --   指针 void *
** 函数版本: 1.0
** 注意使用: pool_name 不能重名
*****************************************************************/
void * api_inside_mempool_create(IN uint32_t obj_num, IN uint32_t obj_size);


/*****************************************************************
** 函数名称: api_inside_mempool_free
** 函数说明: 内存池释放 
** 入参列表:
**       --  pool_ptr: 内存池指针
** 出参列表:
**      --   无
** 返回类型:
        --   void
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
void api_inside_mempool_free(IN void * pool_ptr);

/*****************************************************************
** 函数名称: api_inside_mempool_obj_alloc
** 函数说明: 向内存池申请对象内存
** 入参列表:
**       --  pool_ptr: 内存池指针
** 出参列表:
**       --  
** 返回类型:
        --   void * 返回 obj: 内存对象
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
void * api_inside_mempool_obj_alloc(IN void * pool_ptr);


/*****************************************************************
** 函数名称: api_inside_mempool_obj_free
** 函数说明: 内存池还回对象内存 
** 入参列表:
**       --  pool_ptr: 内存池指针
**       --  obj: 内存对象
** 出参列表:
**      --   无
** 返回类型:
        --   int32_t
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
int32_t api_inside_mempool_obj_free(IN void * pool_ptr, IN void * obj);


/*****************************************************************
** 函数名称: api_inside_mempool_avail_count
** 函数说明: dpdk 内存池剩余可用节点个数
** 入参列表:
**       --  pool_ptr: 内存池指针
** 出参列表:
**      --   used_num:已用内存节点
**      --   free_num:剩余内存节点
** 返回类型:
        --   int32_t 
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
int32_t api_inside_mempool_state_count(IN void * pool_ptr, int32_t * used_num, int32_t * free_num);

#ifdef __cplusplus 	
}
#endif
#endif 
