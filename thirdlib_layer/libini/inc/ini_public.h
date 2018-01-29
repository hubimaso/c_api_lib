/****************************************************************************
*  ini_public.h
*  Created on: 2017-07-21
*  Version: 1.0
*
*****************************************************************************/

#ifndef INI_PUBLIC_H_
#define INI_PUBLIC_H_
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "stdint.h"

// 加载配置文件(配置文件必须存在)
void* ini_load(const char *path);

// 加载完配置文件需要释放句柄
void ini_unload(void **ini_handler);

// 读配置项
const char *ini_get_value(const void *ini_handler, const char *selection, const char *item);

// 写配置项
int ini_set_value(const void *ini_handler, const char *selection, const char *item, const char *new_value);

// 强制写配置项(如果没有key,新建key)
int ini_set_value_force(const void *ini_handler, const char *selection, const char *item, const char *new_value);

// 保存文件 与写配置项配套使用
int ini_save(const void *ini_handler);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* BASELIB_INI_H_ */
