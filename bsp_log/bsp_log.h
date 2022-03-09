#ifndef __BSP_LOG_H
#define __BSP_LOG_H
#include "bsp.h"
#include "stdio.h"
#include "string.h"

//可变宏定义
#ifdef DEBUG_MODE
#define log(format,...) printf(format "\r\n", ##__VA_ARGS__)
#define logInfo(format,...) printf(" [Info]:  " format "\r\n", ##__VA_ARGS__)
#define logDebug(format,...) printf(" [Debug]:  " format "\r\n", ##__VA_ARGS__)
#define logErr(format,...) printf(" [Error]:  " format "\r\n", ##__VA_ARGS__)
#define logIntArray(...) bsp_log_int_array(__VA_ARGS__)
#define logUcharArray(...) bsp_log_uchar_array(__VA_ARGS__)
#else
#define log(format,...)
#define logIntArray(...)
#define logUcharArray(...)
#define logInfo(format,...)
#define logDebug(format,...)
#define logErr(format,...)
#endif

void bsp_log_init(uint32_t rate);
int fputc(int ch,FILE *f);
void bsp_log_int_array(int data[],int size);
void bsp_log_uchar_array(uint8_t data[],int size);
#endif
