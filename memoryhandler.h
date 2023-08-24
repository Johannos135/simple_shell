#ifndef _MEMORYHANDLER_
#define _MEMORYHANDLER_

#include "template.h"
#include "stringfun.h"

/* memoryhandler.c */
void _memcpy(void *destination, const void *source, unsigned int len);
void *_realloc(void *src, unsigned int sizeof_src, unsigned int sizeof_dest);
char **_realloc_v2(char **src, unsigned int sizeof_src, unsigned int sizeof_dest);
#endif
