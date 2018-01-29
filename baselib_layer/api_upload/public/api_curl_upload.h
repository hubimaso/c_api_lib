/****************************************************************************
 *
 *  api_curl_upload.h                                       
 *  Created on: 2017/11/30
 *  Version: 1.0
 * 
*****************************************************************************/
#ifndef __API_CURL_UPLOAD_H__
#define __API_CURL_UPLOAD_H__

#ifdef __cplusplus 	
extern "C" { 
#endif


#include <stdint.h>

#define CURL_UPLOAD_SUCCESS         0
#define CURL_UPLOAD_FAILED         -1

enum {
  ERRCODE_OK = 0,
  ERRCODE_UNSUPPORTED_PROTOCOL,    /* 1 */
  ERRCODE_FAILED_INIT,             /* 2 */
  ERRCODE_URL_MALFORMAT,           /* 3 */
  ERRCODE_NOT_BUILT_IN,            /* 4 - [was obsoleted in August 2007 for
                                    7.17.0, reused in April 2011 for 7.21.5] */
  ERRCODE_COULDNT_RESOLVE_PROXY,   /* 5 */
  ERRCODE_COULDNT_RESOLVE_HOST,    /* 6 */
  ERRCODE_COULDNT_CONNECT,         /* 7 */
  ERRCODE_WEIRD_SERVER_REPLY,      /* 8 */
  ERRCODE_REMOTE_ACCESS_DENIED,    /* 9 a service was denied by the server
                                    due to lack of access - when login fails
                                    this is not returned. */
  ERRCODE_FTP_ACCEPT_FAILED,       /* 10 - [was obsoleted in April 2006 for
                                    7.15.4, reused in Dec 2011 for 7.24.0]*/
  ERRCODE_FTP_WEIRD_PASS_REPLY,    /* 11 */
  ERRCODE_FTP_ACCEPT_TIMEOUT,      /* 12 - timeout occurred accepting server
                                    [was obsoleted in August 2007 for 7.17.0,
                                    reused in Dec 2011 for 7.24.0]*/
  ERRCODE_FTP_WEIRD_PASV_REPLY,    /* 13 */
  ERRCODE_FTP_WEIRD_227_FORMAT,    /* 14 */
  ERRCODE_FTP_CANT_GET_HOST,       /* 15 */
  ERRCODE_HTTP2,                   /* 16 - A problem in the http2 framing layer.
                                    [was obsoleted in August 2007 for 7.17.0,
                                    reused in July 2014 for 7.38.0] */
  ERRCODE_FTP_COULDNT_SET_TYPE,    /* 17 */
  ERRCODE_PARTIAL_FILE,            /* 18 */
  ERRCODE_FTP_COULDNT_RETR_FILE,   /* 19 */
  ERRCODE_OBSOLETE20,              /* 20 - NOT USED */
  ERRCODE_QUOTE_ERROR,             /* 21 - quote command failure */
  ERRCODE_HTTP_RETURNED_ERROR,     /* 22 */
  ERRCODE_WRITE_ERROR,             /* 23 */
  ERRCODE_OBSOLETE24,              /* 24 - NOT USED */
  ERRCODE_UPLOAD_FAILED,           /* 25 - failed upload "command" */
  ERRCODE_READ_ERROR,              /* 26 - couldn't open/read from file */
  ERRCODE_OUT_OF_MEMORY,           /* 27 */
  /* Note: ERRCODE_OUT_OF_MEMORY may sometimes indicate a conversion error
           instead of a memory allocation error if CURL_DOES_CONVERSIONS
           is defined
  */
  ERRCODE_OPERATION_TIMEDOUT,      /* 28 - the timeout time was reached */
  ERRCODE_OBSOLETE29,              /* 29 - NOT USED */
  ERRCODE_FTP_PORT_FAILED,         /* 30 - FTP PORT operation failed */
  ERRCODE_FTP_COULDNT_USE_REST,    /* 31 - the REST command failed */
  ERRCODE_OBSOLETE32,              /* 32 - NOT USED */
  ERRCODE_RANGE_ERROR,             /* 33 - RANGE "command" didn't work */
  ERRCODE_HTTP_POST_ERROR,         /* 34 */
  ERRCODE_SSL_CONNECT_ERROR,       /* 35 - wrong when connecting with SSL */
  ERRCODE_BAD_DOWNLOAD_RESUME,     /* 36 - couldn't resume download */
  ERRCODE_FILE_COULDNT_READ_FILE,  /* 37 */
  ERRCODE_LDAP_CANNOT_BIND,        /* 38 */
  ERRCODE_LDAP_SEARCH_FAILED,      /* 39 */
  ERRCODE_OBSOLETE40,              /* 40 - NOT USED */
  ERRCODE_FUNCTION_NOT_FOUND,      /* 41 - NOT USED starting with 7.53.0 */
  ERRCODE_ABORTED_BY_CALLBACK,     /* 42 */
  ERRCODE_BAD_FUNCTION_ARGUMENT,   /* 43 */
  ERRCODE_OBSOLETE44,              /* 44 - NOT USED */
  ERRCODE_INTERFACE_FAILED,        /* 45 - CURLOPT_INTERFACE failed */
  ERRCODE_OBSOLETE46,              /* 46 - NOT USED */
  ERRCODE_TOO_MANY_REDIRECTS,      /* 47 - catch endless re-direct loops */
  ERRCODE_UNKNOWN_OPTION,          /* 48 - User specified an unknown option */
  ERRCODE_TELNET_OPTION_SYNTAX,    /* 49 - Malformed telnet option */
  ERRCODE_OBSOLETE50,              /* 50 - NOT USED */
  ERRCODE_PEER_FAILED_VERIFICATION, /* 51 - peer's certificate or fingerprint
                                     wasn't verified fine */
  ERRCODE_GOT_NOTHING,             /* 52 - when this is a specific error */
  ERRCODE_SSL_ENGINE_NOTFOUND,     /* 53 - SSL crypto engine not found */
  ERRCODE_SSL_ENGINE_SETFAILED,    /* 54 - can not set SSL crypto engine as
                                    default */
  ERRCODE_SEND_ERROR,              /* 55 - failed sending network data */
  ERRCODE_RECV_ERROR,              /* 56 - failure in receiving network data */
  ERRCODE_OBSOLETE57,              /* 57 - NOT IN USE */
  ERRCODE_SSL_CERTPROBLEM,         /* 58 - problem with the local certificate */
  ERRCODE_SSL_CIPHER,              /* 59 - couldn't use specified cipher */
  ERRCODE_SSL_CACERT,              /* 60 - problem with the CA cert (path?) */
  ERRCODE_BAD_CONTENT_ENCODING,    /* 61 - Unrecognized/bad encoding */
  ERRCODE_LDAP_INVALID_URL,        /* 62 - Invalid LDAP URL */
  ERRCODE_FILESIZE_EXCEEDED,       /* 63 - Maximum file size exceeded */
  ERRCODE_USE_SSL_FAILED,          /* 64 - Requested FTP SSL level failed */
  ERRCODE_SEND_FAIL_REWIND,        /* 65 - Sending the data requires a rewind
                                    that failed */
  ERRCODE_SSL_ENGINE_INITFAILED,   /* 66 - failed to initialise ENGINE */
  ERRCODE_LOGIN_DENIED,            /* 67 - user, password or similar was not
                                    accepted and we failed to login */
  ERRCODE_TFTP_NOTFOUND,           /* 68 - file not found on server */
  ERRCODE_TFTP_PERM,               /* 69 - permission problem on server */
  ERRCODE_REMOTE_DISK_FULL,        /* 70 - out of disk space on server */
  ERRCODE_TFTP_ILLEGAL,            /* 71 - Illegal TFTP operation */
  ERRCODE_TFTP_UNKNOWNID,          /* 72 - Unknown transfer ID */
  ERRCODE_REMOTE_FILE_EXISTS,      /* 73 - File already exists */
  ERRCODE_TFTP_NOSUCHUSER,         /* 74 - No such user */
  ERRCODE_CONV_FAILED,             /* 75 - conversion failed */
  ERRCODE_CONV_REQD,               /* 76 - caller must register conversion
                                    callbacks using curl_easy_setopt options
                                    CURLOPT_CONV_FROM_NETWORK_FUNCTION,
                                    CURLOPT_CONV_TO_NETWORK_FUNCTION, and
                                    CURLOPT_CONV_FROM_UTF8_FUNCTION */
  ERRCODE_SSL_CACERT_BADFILE,      /* 77 - could not load CACERT file, missing
                                    or wrong format */
  ERRCODE_REMOTE_FILE_NOT_FOUND,   /* 78 - remote file not found */
  ERRCODE_SSH,                     /* 79 - error from the SSH layer, somewhat
                                    generic so the error message will be of
                                    interest when this has happened */

  ERRCODE_SSL_SHUTDOWN_FAILED,     /* 80 - Failed to shut down the SSL
                                    connection */
  ERRCODE_AGAIN,                   /* 81 - socket is not ready for send/recv,
                                    wait till it's ready and try again (Added
                                    in 7.18.2) */
  ERRCODE_SSL_CRL_BADFILE,         /* 82 - could not load CRL file, missing or
                                    wrong format (Added in 7.19.0) */
  ERRCODE_SSL_ISSUER_ERROR,        /* 83 - Issuer check failed.  (Added in
                                    7.19.0) */
  ERRCODE_FTP_PRET_FAILED,         /* 84 - a PRET command failed */
  ERRCODE_RTSP_CSEQ_ERROR,         /* 85 - mismatch of RTSP CSeq numbers */
  ERRCODE_RTSP_SESSION_ERROR,      /* 86 - mismatch of RTSP Session Ids */
  ERRCODE_FTP_BAD_FILE_LIST,       /* 87 - unable to parse FTP file list */
  ERRCODE_CHUNK_FAILED,            /* 88 - chunk callback reported error */
  ERRCODE_NO_CONNECTION_AVAILABLE, /* 89 - No connection available, the
                                    session will be queued */
  ERRCODE_SSL_PINNEDPUBKEYNOTMATCH, /* 90 - specified pinned public key did not
                                     match */
  ERRCODE_SSL_INVALIDCERTSTATUS,   /* 91 - invalid certificate status */
  ERRCODE_HTTP2_STREAM,            /* 92 - stream error in HTTP/2 framing layer
                                    */
  ERRCODE_PTR_NULL,                                    
  ERRCODE_LAST /* never use! */
};

#define IN
#define OUT

#define MAX_UPLOAD_STR_LEN     64
#define MAX_UPLOAD_URL_LEN     256
#define MAX_UPLOAD_SUFFIX_LEN  16
#define MAX_UPLOAD_IP_LEN      32

#define MAX_UPLOAD_THREAD_NUM  8
#define MAX_UPLOAD_SERVER_NUM  128

// upload 方式
enum
{
    CURL_UPLOAD_FTP   = 0,
    CURL_UPLOAD_SFTP  = 1, 
};

// upload 文件信息
typedef struct _st_upload_fileinfo
{
    char        local_filepath[MAX_UPLOAD_URL_LEN];  // (IN)upload 本地文件名称
    char        remote_filedir[MAX_UPLOAD_URL_LEN];  // (IN)upload 服务器文件目录
    char        remote_filename[MAX_UPLOAD_URL_LEN]; // (IN)upload 服务器文件名称
    char        local_suffix[MAX_UPLOAD_SUFFIX_LEN];//  (IN)upload 本地文件后缀    
    char        remote_suffix[MAX_UPLOAD_SUFFIX_LEN];// (IN)upload 服务器备份文件后缀
    uint8_t     send_sernum;           // (OUT)一份多发场景下，发送给多个服务器个数统计
}upload_fileinfo_t;

// upload 服务器配置信息
typedef struct _st_upload_serinfo
{
    uint8_t     upload_type;                     // (IN)upload 方式 (FTP/SFTP)
    uint8_t     thread_num;                      // (IN)线程个数
    uint8_t     thread_id;                       // (IN)当前线程ID,多线程场景使用
    uint8_t     server_id;                       // (IN)当前severID,负载分发场景使用
    char        serv_addr[MAX_UPLOAD_IP_LEN];    // (IN)upload 服务器地址
    uint16_t    serv_port;                       // (IN)upload 服务器端口
    char        username[MAX_UPLOAD_STR_LEN];    // (IN)upload 用户名
    char        password[MAX_UPLOAD_STR_LEN];    // (IN)upload 用户密码
    char        serv_url[MAX_UPLOAD_URL_LEN];    // (OUT)upload url
    void       *handler[MAX_UPLOAD_THREAD_NUM];  // (OUT)upload 句柄
    char        conn_stat;                       // (OUT)服务器连接是否可用 可用:1, 不可用:0
	uint64_t    upload_size;                     // (OUT)上传文件大小 bytes
}upload_serinfo_t;


/*****************************************************************
** 函数名称: api_upload_init
** 函数说明:     初始化 非线程安全
** 入参列表:
**       --  upload_serinfo: upload 服务配置节点信息
** 出参列表:
**      --   无
** 返回类型:
        --   int32_t (0 成功 非0 失败)
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
int32_t api_upload_init(IN upload_serinfo_t *upload_serinfo);

/*****************************************************************
** 函数名称: api_upload_put
** 函数说明: upload 文件上报接口
** 入参列表:
**       --  upload_serinfo: upload 服务配置节点信息
**       --  local_file: 要上报的本地文件
**       --  remote_tmp: 上报过程中的临时文件
** 出参列表:
**      --   无
** 返回类型:
        --   int32_t 返回错误码
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
int32_t api_upload_put(IN upload_serinfo_t *upload_serinfo, IN upload_fileinfo_t *upload_fileinfo);

/*****************************************************************
** 函数名称: api_upload_conncheck
** 函数说明: // upload 连接状态检查
** 入参列表:
**       --  upload_serinfo: upload 服务配置节点信息
**       --  tmp_path: 检查的文件或目录
** 出参列表:
**      --   无
** 返回类型:
        --   int32_t (0 成功 非0 失败)
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
int32_t api_upload_conncheck(IN upload_serinfo_t *upload_serinfo, IN char * tmp_path);


/*****************************************************************
** 函数名称: api_upload_cleanup
** 函数说明: upload 句柄清理
** 入参列表:
**       --  upload_serinfo: upload 服务配置节点信息
** 出参列表:
**      --   无
** 返回类型:
        --   void
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
void api_upload_cleanup(IN upload_serinfo_t *upload_serinfo);

/*****************************************************************
** 函数名称: api_upload_uninit
** 函数说明:     反初始化 非线程安全
** 入参列表:
**      -- 
** 出参列表:
**      --   无
** 返回类型:
        --   无
** 函数版本: 1.0
** 注意使用: 无
*****************************************************************/
void api_upload_uninit(void);

#ifdef __cplusplus 	
}
#endif
#endif 
