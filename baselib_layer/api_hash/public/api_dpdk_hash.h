/****************************************************************************
 *
 *  api_dpdk_hash.h                                      
 *  Created on: 2017/12/08
 *  Version: 1.0
 * 
*****************************************************************************/
#ifndef __API_DPDK_HASH_H__
#define __API_DPDK_HASH_H__

#ifdef __cplusplus 	
extern "C" { 
#endif

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

#define DPDK_HASH_SUCCESS         0
#define DPDK_HASH_FAILED         -1

#define IN
#define OUT


/*****************************************************************
** 函数名称: api_dpdk_hash_create
** 函数说明: hash表创建 非线程安全
** 入参列表:
**       --  hash_name: hash表名称
**       --  hash_size: hash大小
**       --  hash_keylen:hash key 长度
** 出参列表:
**      --   无
** 返回类型:
        --   void *
** 函数版本: 1.0
** 注意使用: 
**      --   hash_name 不能重名
**      --   hash_keylen:如果key是字符串, 取字符串长度，结构体则是结构体大小
**      --   hash_keylen: 建议是 16 的整数倍对齐，提高性能
*****************************************************************/
void * api_dpdk_hash_create(IN char * hash_name, IN uint32_t hash_size, IN uint32_t hash_keylen);

/*****************************************************************
** 函数名称: api_dpdk_hash_data_add
** 函数说明: 向 hash 表添加key 和 data 非线程安全
** 入参列表:
**       --  hash_ptr: hash 表指针
**       --  hash_key: hash key对象
**       --  data:hash data指针
** 出参列表:
**      --   无
** 返回类型:
        --   int32_t (0 成功 非0 失败)
** 函数版本: 1.0
** 注意使用: hash_key 与 api_dpdk_hash_create hash_keylen相对应
*****************************************************************/
int32_t api_dpdk_hash_data_add(IN const void * hash_ptr, IN const void * hash_key, IN void * data);

/*****************************************************************
** 函数名称: api_dpdk_hash_data_get
** 函数说明: 通过 hash key 从 hash 表获取 data 线程安全
** 入参列表:
**       --  hash_ptr: hash表指针
**       --  hash_key: hash key对象
** 出参列表:
**       --  data:hash data指针
** 返回类型:
        --   int32_t (0 成功 非0 失败)
** 函数版本: 1.0
** 注意使用: 
*****************************************************************/
int32_t api_dpdk_hash_data_get(IN const void * hash_ptr, IN const void * hash_key, OUT void ** data);

/*****************************************************************
** 函数名称: api_dpdk_hash_key_del
** 函数说明: 通过 hash key 从 hash 表获取 data 非线程安全
** 入参列表:
**       --  hash_ptr: hash表指针
**       --  hash_key: hash key对象
** 出参列表:
**       --  无
** 返回类型:
        --   int32_t
** 函数版本: 1.0
** 注意使用: 
*****************************************************************/
int32_t api_dpdk_hash_key_del(IN const void *hash_ptr, IN const void *hash_key);



#ifdef __cplusplus 	
}
#endif
#endif 
