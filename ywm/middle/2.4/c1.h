#ifndef _C_1_H_
#define _C_1_H_
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>
#include <math.h>

#if WIN
#include <process.h>
#else
#include <pthread.h>
#endif

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status;
typedef int Boolean;
#define nullptr NULL;
#endif // _C_1_H_
