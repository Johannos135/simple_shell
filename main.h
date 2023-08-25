#ifndef _MAIN_
#define _MAIN_

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

extern char **environ;

/* Encapsulate in custom_string1 c file */
int _strlen(const char *str);
int _isdigit(const char *str);
char *_strtok(char *str, const char *delimiter);
char *_strdup(const char *str);
int compare_char(char *str, const char *delimiter);

/* Encapsulate in custom_string2 c file */
void reverse_str(char *str);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strchr(char *str, char character);

/* Encapsulate in custom_string3 */
int _strspn(char *str, char *value);
int _longueur(int number);
char *_itoa(int number);
int _atoi(char *str);

/* memoryhandler.c */
void _memcpy(void *destination, const void *source, unsigned int len);
void *_realloc(void *src, unsigned int sizeof_src, unsigned int sizeof_dest);
char **_realloc_v2(char **src, unsigned int sizeof_src,
		unsigned int sizeof_dest);


/* prompt function prototype */
void prompt(void);
void _sigint_g(int s);
/* message_error.c */
char *concat_error(node_sh *nodesh, char *message, char *bad,
		char *counter);
char *directory_err(node_sh *nodesh);
char *error404(node_sh *nodesh);
char *exit_error(node_sh *nodesh);
char *environ_error(node_sh *nodesh);

/*permission error*/
char *path_err(node_sh *nodesh);

/* helper.c */
void environ_helper(void);
void setenv_helper(void);
void unsetenv_helper(void);
void general_info(void);
void exit_helper(void);

/* directory_handler.c */
void changed_dot(node_sh *nodesh);
void changed_to(node_sh *nodesh);
void changed_previous(node_sh *nodesh);
void changed_to_home(node_sh *nodesh);

/* dirchange.c */
int change_current(node_sh *nodesh);

/* list_handler.c */
void free_dividor(list_separator **entete);
list_separator *separator_list(list_separator **entete, char separator);
store_line *aj_ligne(store_line **entete, char *cmdline);
void line_free(store_line **entete);

/** main.h **/
void dt_fr(node_sh *nodesh);
void data_setter(node_sh *nodesh, char **argv);

/* _error_g.c */
int _error_g(node_sh *nodesh, int err_value);
int _help_g(node_sh *nodesh);

/* syntax_verify */
int cpt_char(char *value, int count);
int error_dividor(char *value, int count, char dernier);
int char_indice(char *value, int *count);
void display_error_syntax(node_sh *nodesh, char *value, int i, int check);
int syntax_verify(node_sh *nodesh, char *value);

/* var_repartition.c */
void environ_checker(store_var **h, char *in, node_sh *nodesh);
int variable_checkers(store_var **entete, char *value,
		char *etat, node_sh *nodesh);
char *val_replacement(store_var **head, char *value,
		char *new_value, int sizeof_n);
char *var_replacement(char *value, node_sh *nodeshsh);

/* execute_cmd.c */
int is_cdir(char *chemin, int *count);
char *_which(char *cmd, char **_environ);
int is_executable(node_sh *nodesh);
int cmd_code_checker(char *dir, node_sh *nodesh);
int execute_cmd(node_sh *nodesh);

/* execute_line.c */
int execute_line(node_sh *nodesh);
int quit_shell(node_sh *nodesh);
int (*_builtin_g(char *cmd))(node_sh *);

/* line_getter.c */
void provide_line(char **ptrptr_cmd, size_t *n, char *buffer, size_t sizeof_b);
ssize_t get_line(char **ptrptr_cmd, size_t *n, FILE *stream);

/* read_getter.c */
char *read_line(int *in_value);

/* variable_handler.c */
store_var *aj_var(store_var **entete, int lng_var,
		char *value, int lng_val);
void variable_free(store_var **entete);

/* environment_name.c */
int compare_namev(const char *name_environ, const char *name);
char *_getenv(const char *name, char **_environ);
int _env(node_sh *nodesh);

/* environment */
char *swap_info(char *name, char *value);
void set_env(char *name, char *value, node_sh *nodesh);
int _setenv(node_sh *nodesh);
int _unsetenv(node_sh *nodesh);

/* splitter */
char *swap_char(char *valeur, int check);
void aj_noeuds(list_separator **dividor_head,
		store_line **linehead, char *valeur);
void suivant(list_separator **seplist, store_line **linelist, node_sh *nodesh);
int split_commands(node_sh *nodesh, char *valeur);
char **split_line(char *valeur);

void runner(node_sh *nodesh);

#endif
