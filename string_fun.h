#ifndef _STRING_FUN_
#define _STRING_FUN_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include "template.h"

/* Encapsulate in custom_string1 c file */
int _strlen(const char *str);
int _isdigit(const char *str);
int *_strtok(char *str, const char *delimiter);
int *_strdup(char *str);
int compare_char(char *str, const char *delimiter);

/* Encapsulate in custom_string2 c file */
void reverse_str(char *str);
char *_strcat(char *dest,const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strchr(char *str, char character);

/* Encapsulate in custom_string3 */
int _strspn(char *str, char *value);

#endif
