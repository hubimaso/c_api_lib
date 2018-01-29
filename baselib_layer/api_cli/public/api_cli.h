/****************************************************************************
 *
 *  api_cli.h                                      
 *  Created on: 2018/01/24
 *  Version: 1.0
 * 
*****************************************************************************/
#ifndef __API_CLI_H__
#define __API_CLI_H__

#ifdef __cplusplus 	
extern "C" { 
#endif

#include <stdint.h>
#include <stdarg.h>

#include "libcli.h"

#define IN
#define OUT

#define API_CLI_SUCCESS         0
#define API_CLI_FAILED         -1

//主版本号
#define CLI_VER_MAJOR 1

//次版本号
#define CLI_VER_MINOR 0

//修订版本号
#define CLI_VER_REVISION 0

enum
{
    CLI_UNPRIVILEGED,           // 无需授权 
    CLI_PRIVILEGED,             // 需要授权
};

enum
{
    CLI_MODE_ANY,
    CLI_MODE_EXEC,
    CLI_MODE_CONFIG,
};

typedef int32_t ( * callback_t)(void * cli_handler, const char * cmd_name, char ** argv , int32_t argc );

typedef struct _st_cli_cmd_info
{
    void * cli_handler;         // (IN) cli 句柄
    void * cmd_parent_handler;  // (IN) cmd 句柄
    char * cmd_name;            // (IN) cmd 名称
    callback_t callback;        // (IN) call function
    int32_t    privilege;       // (IN) 访问权限
    int32_t    mode;            // (IN) 访问方式
    char *     help_str;        // (IN) 帮助信息
}cli_cmd_info_t;

#define API_CLI_PRINT(cli_handler, ...) cli_print(cli_handler, __VA_ARGS__)

/*****************************************************************
** 函数名称: api_cli_init
** 函数说明: cli 初始化
** 入参列表:
**       --  host_name
** 出参列表:
**      --   无
** 返回类型: 
        --   void * 返回 cli 句柄
** 函数版本: 1.0
** 注意使用:
*****************************************************************/
void * api_cli_init(char * host_name);

/*****************************************************************
** 函数名称: api_cli_uninit
** 函数说明: CLI 反初始化
** 入参列表:
**       --  handler:cli 句柄
** 出参列表:
**      --   无
** 返回类型:
        --   
** 函数版本: 1.0
** 注意使用:  
*****************************************************************/
int32_t api_cli_uninit(IN void * cli_handler);

/*****************************************************************
** 函数名称: api_cli_register_cmd
** 函数说明: CLI 注册命令
** 入参列表:
**       --  cmd_info : 注册命令信息
** 出参列表:
**      --   无
** 返回类型:
        --   
** 函数版本: 1.0
** 注意使用:  
*****************************************************************/
void * api_cli_register_cmd(IN cli_cmd_info_t * cmd_info);

/*****************************************************************
** 函数名称: api_cli_set_idle_timeout
** 函数说明: CLI 超时时间设置
** 入参列表:
**      --   cli_handler : cmd 句柄
**      --   seconds : 超时时间秒
** 出参列表:
**      --   无
** 返回类型:
--
** 函数版本: 1.0
** 注意使用:
*****************************************************************/
void api_cli_set_idle_timeout(IN void * cli_handler, IN uint32_t seconds);

/*****************************************************************
** 函数名称: api_cli_file_output
** 函数说明: CLI 显示已存在的文件
** 入参列表:
**      --   cmd_handler : cmd 句柄
**      --   file_handler : 要显示的文件句柄
** 出参列表:
**      --   无
** 返回类型:
--
** 函数版本: 1.0
** 注意使用:
*****************************************************************/
void api_cli_file_output(IN void * cli_handler, IN FILE * file_handler);

/*****************************************************************
** 函数名称: api_cli_service_start
** 函数说明: CLI 启动服务
** 入参列表:
**       --  cli_handler:cli 句柄
**       --  server_port:cli 服务端监听端口
** 出参列表:
**      --   无
** 返回类型:
        --   
** 函数版本: 1.0
** 注意使用: 如果作为模块，用作线程处理函数
*****************************************************************/
int32_t api_cli_service_start(IN void * cli_handler, IN uint16_t server_port);

#ifdef __cplusplus 	
}
#endif
#endif 
