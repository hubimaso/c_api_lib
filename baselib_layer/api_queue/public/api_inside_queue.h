﻿/****************************************************************************
 *
 *  api_inside_queue.h                                      
 *  Created on: 2017/12/08
 *  Version: 1.0
 * 
*****************************************************************************/
#ifndef __API_INSIDE_QUEUE_H__
#define __API_INSIDE_QUEUE_H__

#ifdef __cplusplus 	
extern "C" { 
#endif

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

#define INSIDE_QUEUE_SUCCESS         0
#define INSIDE_QUEUE_FAILED         -1

#define IN
#define OUT


/*****************************************************************
** 函数名称: api_inside_ring_muti_create
** 函数说明: 多生产多消费队列创建 线程安全 
** 入参列表:
**       --  ring_name: 队列名称
**       --  ring_size: 队列大小 (2^n)
** 出参列表:
**      --   无
** 返回类型:
        --   void *
** 函数版本: 1.0
** 注意使用: 仅支持定长数据 不能重名
*****************************************************************/
void * api_inside_ring_muti_create(IN const char * ring_name, IN uint32_t ring_size);

/*****************************************************************
** 函数名称: api_inside_ring_single_create
** 函数说明: 单生产单消费队列创建 非线程安全
** 入参列表:
**       --  ring_name: 队列指针
**       --  ring_size: 队列大小 (2^n)
** 出参列表:
**      --   无
** 返回类型:
        --   指针 void *
** 函数版本: 1.0
** 注意使用: pool_name 不能重名，非线程安全
*****************************************************************/
//void * api_inside_ring_single_create(IN const char * ring_name, IN uint32_t ring_size);

/*****************************************************************
** 函数名称: api_inside_ring_get_by_name
** 函数说明: 通过队列名称获取队列指针
** 入参列表:
**       --  ring_name: 内存池名称
** 出参列表:
**      --   无
** 返回类型:
        --   指针 void *
** 函数版本: 1.0
** 注意使用: 
*****************************************************************/
//void * api_inside_ring_get_by_name(IN const char * ring_name);

/*****************************************************************
** 函数名称: api_inside_ring_enqueue
** 函数说明: 向队列插入单个对象
** 入参列表:
**       --  ring_ptr: 内存池指针
**       --  obj: 内存对象
** 出参列表:
**      --   无
** 返回类型:
**       --  int32_t 0 on success, -1 on failure
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
int32_t api_inside_ring_enqueue(IN void * ring_ptr, void * obj);

/*****************************************************************
** 函数名称: api_inside_ring_enqueue_burst
** 函数说明: 向队列插入多个对象
** 入参列表:
**       --  ring_ptr: 内存池指针
**       --  obj_list: 内存对象数组
**       --  obj_num: 内存对象个数
** 出参列表:
**      --   无
** 返回类型:
        --   uint32_t (返回实际加入对象个数)
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
//uint32_t api_inside_ring_enqueue_burst(IN void * ring_ptr, IN void * const * obj_list, IN uint32_t obj_num);

/*****************************************************************
** 函数名称: api_inside_ring_dequeue
** 函数说明: 队列出队单个对象
** 入参列表:
**       --  ring_ptr: 内存池指针
** 出参列表:
**       --  obj: 内存对象
** 返回类型:
        --   int32_t 成功与失败 
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
int32_t api_inside_ring_dequeue(IN void * ring_ptr, OUT void ** obj);


/*****************************************************************
** 函数名称: api_inside_ring_dequeue_burst
** 函数说明: 队列出队多个对象
** 入参列表:
**       --  ring_ptr: 内存池指针
** 出参列表:
**       --  obj_list: 内存对象数组
** 返回类型:
        --   uint32_t (返回实际出队对象个数)
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
//uint32_t api_inside_ring_dequeue_burst(IN void * ring_ptr, OUT void ** obj_list);

/*****************************************************************
** 函数名称: api_inside_ring_dump
** 函数说明: dump inside ring状态信息到指定文件 
** 入参列表:
**       --  file_ptr: 文件指针
**       --  ring_ptr: 队列指针
** 出参列表:
**      --   无
** 返回类型:
        --   void
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
//void api_inside_ring_dump(IN FILE *file_ptr, IN void * ring_ptr);

/*****************************************************************
** 函数名称: api_inside_ring_avail_count
** 函数说明: inside ring 剩余可用节点个数
** 入参列表:
**       --  ring_ptr: 队列指针
** 出参列表:
**      --   无
** 返回类型:
        --   uint32_t 返回可用队列节点个数
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
uint32_t api_inside_ring_avail_count(IN void * ring_ptr);

/*****************************************************************
** 函数名称: api_inside_ring_used_count
** 函数说明: inside ring 已用节点个数
** 入参列表:
**       --  ring_ptr: 队列指针
** 出参列表:
**      --   无
** 返回类型:
        --   uint32_t 返回可用队列节点个数
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
uint32_t api_inside_ring_used_count(IN void * ring_ptr);


#ifdef __cplusplus 	
}
#endif
#endif 
