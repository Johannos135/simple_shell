#ifndef STRING_FUN_H
#define STRING_FUN_H

/* Encapsulate in custom_string1 c file */
int _strlen(char *str);
int _isdigit( const char *str);
int *_strtok(char *str, const char *delimiter);
int *_strdup(char *str);
int compare_char(char *str, const char *delimiter);

/* Encapsulate in custom_string2 c file */
void reverse_str(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strchr(char *str, char character);

#endif
