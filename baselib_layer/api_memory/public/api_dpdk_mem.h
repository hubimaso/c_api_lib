﻿/****************************************************************************
 *
 *  api_dpdk_mem.h                                      
 *  Created on: 2017/12/08
 *  Version: 1.0
 * 
*****************************************************************************/
#ifndef __API_DPDK_MEM_H__
#define __API_DPDK_MEM_H__

#ifdef __cplusplus 	
extern "C" { 
#endif

#include <stdio.h>
#include <stdint.h>

#define DPDK_MEM_SUCCESS         0
#define DPDK_MEM_FAILED         -1

#define IN
#define OUT

/*****************************************************************
** 函数名称: api_dpdk_mempool_muti_create
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
void * api_dpdk_mempool_muti_create(IN const char * pool_name, IN uint32_t obj_num, IN uint32_t obj_size);

/*****************************************************************
** 函数名称: api_dpdk_mempool_single_create
** 函数说明: 单生产单消费内存池创建 非线程安全
** 入参列表:
**       --  pool_name: 内存池名称
**       --  obj_num: 内存对象个数 建议(obj_num % 512 == 0)
**       --  obj_size:内存对象大小
** 出参列表:
**      --   无
** 返回类型:
        --   指针 void *
** 函数版本: 1.0
** 注意使用: pool_name 不能重名，非线程安全
*****************************************************************/
void * api_dpdk_mempool_single_create(IN const char * pool_name, IN uint32_t obj_num, IN uint32_t obj_size);

/*****************************************************************
** 函数名称: api_dpdk_mempool_get_by_name
** 函数说明: 通过内存池名称获取内存池指针
** 入参列表:
**       --  pool_name: 内存池名称
** 出参列表:
**      --   无
** 返回类型:
        --   指针 void *
** 函数版本: 1.0
** 注意使用: 
*****************************************************************/
void * api_dpdk_mempool_get_by_name(IN const char * pool_name);


/*****************************************************************
** 函数名称: api_dpdk_mempool_free
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
void api_dpdk_mempool_free(IN void * pool_ptr);

/*****************************************************************
** 函数名称: api_dpdk_mempool_obj_alloc
** 函数说明: 向内存池申请对象内存
** 入参列表:
**       --  pool_ptr: 内存池指针
** 出参列表:
**       --  obj: 内存对象
** 返回类型:
        --   int32_t (0 成功 非0 失败)
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
int32_t api_dpdk_mempool_obj_alloc(IN void * pool_ptr, OUT void ** obj);


/*****************************************************************
** 函数名称: api_dpdk_mempool_obj_free
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
int32_t api_dpdk_mempool_obj_free(IN void * pool_ptr, IN void * obj);

/*****************************************************************
** 函数名称: api_dpdk_mempool_obj_alloc_bulk
** 函数说明: 向内存池批量申请多个内存对象
** 入参列表:
**       --  pool_ptr: 内存池指针
**       --  obj_num: 对象个数
** 出参列表:
**       --  obj_list: 内存对象数组
** 返回类型:
        --   int32_t (0 成功 非0 失败)
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
int32_t api_dpdk_mempool_obj_alloc_bulk(IN void * pool_ptr, OUT void ** obj_list, IN uint32_t obj_num);


/*****************************************************************
** 函数名称: api_dpdk_mempool_obj_insert_bulk
** 函数说明: 向内存池批量插入多个内存对象 
** 入参列表:
**       --  pool_ptr: 内存池指针
**       --  obj_list: 内存对象数组
**       --  obj_num: 对象个数
** 出参列表:
**      --   无
** 返回类型:
        --   int32_t
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
int32_t api_dpdk_mempool_obj_insert_bulk(IN void * pool_ptr, IN void *const * obj_list, IN uint32_t obj_num);

/*****************************************************************
** 函数名称: api_dpdk_mempool_dump
** 函数说明: dump dpdk 内存状态信息到指定文件 
** 入参列表:
**       --  file_ptr: 文件指针
**       --  pool_ptr: 内存池指针
** 出参列表:
**      --   无
** 返回类型:
        --   void
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
void api_dpdk_mempool_dump(IN FILE * file_ptr, IN void * pool_ptr);

/*****************************************************************
** 函数名称: api_dpdk_mempool_avail_count
** 函数说明: dpdk 内存池剩余可用节点个数
** 入参列表:
**       --  pool_ptr: 内存池指针
** 出参列表:
**      --   无
** 返回类型:
        --   uint32_t 返回可用内存池节点个数
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
uint32_t api_dpdk_mempool_avail_count(IN const void * pool_ptr);

/*****************************************************************
** 函数名称: api_dpdk_mempool_used_count
** 函数说明: dpdk 内存池已用节点个数
** 入参列表:
**       --  pool_ptr: 内存池指针
** 出参列表:
**      --   无
** 返回类型:
        --   uint32_t 返回可用内存池节点个数
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
uint32_t api_dpdk_mempool_used_count(IN const void * pool_ptr);


/*****************************************************************
** 函数名称: api_dpdk_memcpy
** 函数说明: dpdk 内存拷贝
** 入参列表:
**       --  dst_ptr: 目的指针
**       --  pool_ptr: 源指针
**       --  n: 拷贝内容大小
** 出参列表:
**      --   无
** 返回类型:
        --   void *
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
void * api_dpdk_memcpy(IN void * dst_ptr, IN void * src_ptr, IN size_t n);



#ifdef __cplusplus 	
}
#endif
#endif 