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

/* helper_lists.c */
div_list *add_sep_node_end(div_list **entete, char sep);
void free_div_list(div_list **entete);
ligne *add_ldanse_node_end(ligne **entete, char *ldanse);
void free_ligne(ligne **entete);

/* helper_liststrdansg2.c */
store_var *aj_rv_node(store_var **entete, int lvar, char *var, int lval);
void lib_rv_list(store_var **entete);

/* helper_str functions */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *strdansg1, char *strdansg2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* helper_mem.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallochangedp(char **ptr, unsigned int old_size, unsigned int new_size);

/* helper_str2.c */
char *_strdup(const char *s);
int _strlongu(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* helper_str3.c */
void reverse_str(char *s);

/* check_syntax_err.c */
int repeated_char(char *entree, int i);
int err_sep_op(char *entree, int i, char last);
int first_char(char *entree, int *i);
void print_syntax_err(node_sh *nodesh, char *entree, int i, int checker);
int check_syntax_err(node_sh *nodesh, char *entree);

/* shell_boucle.c */
char *sans_comment(char *dans);
void shell_boucle(node_sh *nodesh);

/* read_ldanse.c */
char *read_ldanse(int *fin_v);

/* splitter.c */
char *swap_char(char *entree, int checker);
void add_nodes(div_list **entete_s, ligne **entete_l, char *entree);
void go_next(div_list **list_s, ligne **list_l, node_sh *nodesh);
int splitter_commands(node_sh *nodesh, char *entree);
char **splitter_ldanse(char *entree);

/* repart_variable.c */
void environ_checker(store_var **h, char *dans, node_sh *donnee);
int check_vars(store_var **h, char *dans, char *st, node_sh *donnee);
char *replaced_entree(store_var **entete, char *entree, char *new_entree, int lon);
char *repart_variable(char *entree, node_sh *nodesh);

/* get_ldanse.c */
void provide_ldanse(char **ldanseptr, size_t *n, char *buffer, size_t j);
ssize_t get_ldanse(char **ldanseptr, size_t *n, FILE *stream);

/* exec_ldanse */
int exec_ldanse(node_sh *nodesh);

/* execute_cmd.c */
int is_changedir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(node_sh *nodesh);
int check_err_cmd(char *dir, node_sh *nodesh);
int execute_cmd(node_sh *nodesh);

/* env-nom.c */
char *_getenv(const char *nom, char **_environ);
int _env(node_sh *nodesh);

/* env-var.c */
char *copy_dansfo(char *nom, char *value);
void set_env(char *nom, char *value, node_sh *nodesh);
int _setenv(node_sh *nodesh);
int _unsetenv(node_sh *nodesh);

/* changed.c */
void changed_dot(node_sh *nodesh);
void changed_to(node_sh *nodesh);
void changed_previous(node_sh *nodesh);
void changed_to_home(node_sh *nodesh);

/* changed_shell.c */
int changed_shell(node_sh *nodesh);

/* get_builtdans */
int (*get_builtdans(char *cmd))(node_sh *nodesh);

/* _exit.c */
int exit_shell(node_sh *nodesh);

/* helper_stdlib.c */
int get_longu(int n);
char *helper_itoa(int n);
int _atoi(char *s);

/* errhandler1.c */
char *strcat_changed(node_sh *, char *, char *, char *);
char *err_get_changed(node_sh *nodesh);
char *err_not_found(node_sh *nodesh);
char *err_exit_shell(node_sh *nodesh);

/* errhandler2.c */
char *err_get_alias(char **args);
char *err_env(node_sh *nodesh);
char *err_syntax(char **args);
char *err_permission(char **args);
char *err_path_126(node_sh *nodesh);


/* get_err.c */
int get_err(node_sh *nodesh, int eval);

/* signal_getter.c */
void signal_getter(int sig);

/* helper1.c */
void helper1_env(void);
void helper1_setenv(void);
void helper1_unsetenv(void);
void helper1_general(void);
void helper1_exit(void);

/* helper12.c */
void helper1(void);
void helper1_alias(void);
void helper1_changed(void);

/* get_help.c */
int get_help(node_sh *nodesh);

#endif
