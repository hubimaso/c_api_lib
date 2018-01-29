#include <features.h>
#define __USE_GNU
#include <sched.h>
#undef	__USE_GNU
#include <sys/prctl.h>
#include <sys/sysinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

#include "api_timer.h"

uint64_t g_prog_boottime_ms = 3600 * 24 * 1000;
uint64_t g_prog_boottime_s = 3600 * 24;

struct timeval g_systime;
uint64_t g_systime_s;
uint64_t g_systime_us;

static void * sys_time_thread(void *para)
{
    uint64_t p_para = (uint64_t)para;
    int cpuid = (int)p_para;
    char thread_name[32] = {0};

    // set cpu bind
    cpu_set_t cpu_set_mask;
    CPU_ZERO(&cpu_set_mask);
    CPU_SET(cpuid, &cpu_set_mask);
    sched_setaffinity(0, sizeof(&cpu_set_mask), &cpu_set_mask);
    
    sprintf(thread_name, "SYSTIME@%u", cpuid);
    prctl(PR_SET_NAME,(unsigned long)(thread_name));

    uint64_t prog_time_ms = g_prog_boottime_ms;
    uint32_t prog_time_s  = prog_time_ms / 1000;
    uint32_t tick_count   = prog_time_ms % 1000;

    struct timespec  time_diff_cur;
    struct timespec  time_diff_last;
    clock_gettime(CLOCK_MONOTONIC, &time_diff_cur);
    time_diff_last = time_diff_cur;
    time_diff_last.tv_nsec -= time_diff_last.tv_nsec % 1000000;

    usleep(100);

    while (1)
    {
        clock_gettime(CLOCK_MONOTONIC_COARSE, &time_diff_cur);

        if (time_diff_cur.tv_sec > time_diff_last.tv_sec
            || time_diff_cur.tv_nsec >= time_diff_last.tv_nsec + 1000000)
        {
            time_diff_last.tv_nsec += 1000000;
            if (time_diff_last.tv_nsec >= 1000000000)
            {
                time_diff_last.tv_nsec = 0;
                time_diff_last.tv_sec++;
            }

            prog_time_ms++;
            tick_count++;
            if (tick_count >= 1000)
            {
                prog_time_s++;
                tick_count = 0;
                g_prog_boottime_s  = prog_time_s;
            }
            g_prog_boottime_ms = prog_time_ms;
            
            gettimeofday(&g_systime, NULL);
            g_systime_s = g_systime.tv_sec;
            g_systime_us = g_systime.tv_sec*1000000 + g_systime.tv_usec;

            if (tick_count == 0)
            {
                /* per second */
                #if 0              
                printf("boot time %lu ms boot time %lu s sys time %lu s\n", g_prog_boottime_ms, g_prog_boottime_s, g_systime_s);
                #endif
            }

            clock_gettime(CLOCK_MONOTONIC_COARSE, &time_diff_cur);
        }

        if (time_diff_cur.tv_sec > time_diff_last.tv_sec
            || time_diff_cur.tv_nsec >= time_diff_last.tv_nsec + 970000)
        {
            /* <=30us */
            usleep(10);
        }
        else if (time_diff_cur.tv_nsec >= time_diff_last.tv_nsec + 950000)
        {
            /* 30~50us */
            usleep(20);
        }
        else if (time_diff_cur.tv_nsec >= time_diff_last.tv_nsec + 900000)
        {
            /* 50~100us */
            usleep(36);
        }
        else if (time_diff_cur.tv_nsec >= time_diff_last.tv_nsec + 800000)
        {
            /* 100~200us */
            usleep(70);
        }
        else if (time_diff_cur.tv_nsec >= time_diff_last.tv_nsec + 650000)
        {
            /* 200~350us */
            usleep(160);
        }
        else
        {
            /* 350~1000us */
            usleep(250);
        }

    }

    return NULL;
}

// 更新系统时间线程
int32_t api_updatetime_thread(int32_t cpuid)
{
	  int32_t ret = 0;
    pthread_t p_systime_pid;
    uint64_t para = cpuid;
    
    gettimeofday(&g_systime, NULL);
    g_systime_s = g_systime.tv_sec;

    ret = pthread_create(&p_systime_pid, NULL, sys_time_thread, (void *)para);
    if(ret)
    {
        return API_TIMER_FAILED;
    }
    pthread_detach(p_systime_pid);    
    return 0;
}

// 获取系统时间单位 s
uint64_t api_sec_time_get(void)
{
	return (uint64_t)g_systime_s;
}

// 获取系统时间单位 ms
uint64_t api_ms_time_get(void)
{
	return (uint64_t)g_systime_us / 1000;
}

// 获取系统时间单位 us
uint64_t api_us_time_get(void)
{
	return (uint64_t)g_systime_us;
}