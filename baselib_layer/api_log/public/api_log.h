/****************************************************************************
 *
 *  api_log.h                                      
 *  Created on: 2017/12/08
 *  Version: 1.0
 * 
*****************************************************************************/
#ifndef __API_LOG_H__
#define __API_LOG_H__

#ifdef __cplusplus 	
extern "C" { 
#endif

#include <stdint.h>
#include <stdarg.h>

#include "zlog.h"

#define IN
#define OUT

#define API_LOG_SUCCESS         0
#define API_LOG_FAILED         -1

typedef enum 
{
    LOG_LEVEL_DEBUG = 20,
    LOG_LEVEL_INFO = 40,
    LOG_LEVEL_NOTICE = 60,
    LOG_LEVEL_WARN = 80,
    LOG_LEVEL_ERROR = 100,
    LOG_LEVEL_FATAL = 120
} log_level;

#define API_LOG(level, ...) \
    dzlog(__FILE__, sizeof(__FILE__)-1, __FUNCTION__, sizeof(__FUNCTION__)-1, __LINE__, \
    level, __VA_ARGS__)


/*****************************************************************
** 函数名称: api_log_init
** 函数说明: LOG 初始化
** 入参列表:
**       --  mod_name:模块名称
**       --  log_dir:日志存放路径
** 出参列表:
**      --   无
** 返回类型:
        --   无
** 函数版本: 1.0
** 注意使用:  不需要存放日志 则log_dir == NULL
*****************************************************************/
int32_t api_log_init(IN const char * mod_name, IN const char * log_dir);

/*****************************************************************
** 函数名称: api_log_uninit*
** 函数说明: LOG 反初始化
** 入参列表:
**       --  thread_name:线程名称
** 出参列表:
**      --   无
** 返回类型:
        --   无
** 函数版本: 1.0
** 注意使用:  
*****************************************************************/
int32_t api_log_uninit(void);


#ifdef __cplusplus 	
}
#endif
#endif 
