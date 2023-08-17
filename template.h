#ifndef _TEMPLATE_
#define _TEMPLATE_

#define SIZEOF_BUF 1024
#define SIZEOF_TOKBUF 128
#define TK_DELIM " \t\r\n\a"

extern char **environment;

/**
 * struct node_data - this template gathers runtime data.
 * @argv: this field is for arg vector.
 * @args: this fields is for the number of argv.
 * @_environment: this field is for the env variable
 * @input: this field is for all the input entered in the cls.
 * @status: dernier status du shell
 * @cpt: Count all the lines.
 * @pid: represents the ID of the process
 */
typedef struct node_data
{
	char **argv;
	char **args;
	char **_environment;
	char *input;
	int status;
	int cpt;
	char *pid;
} node_sh;

/**
 * struct singlelist_sep - this template is of separators symbols
 * @dividor: two dividor possible & and ;
 * @next: this fields is for the next value of the node
 */
typedef struct singlelist_sep
{
	char dividor;
	struct singlelist_sep *next;
} list_separator;

/**
 * struct singlelist_cmd - this template is for storing command
 * lines.
 * @cmd_line: this field represents the command line.
 * @next: this fields is for the next node value.
 */
typedef struct singlelist_cmd
{
	char *cmd_line;
	struct singlelist_cmd *next;
} store_line;

/**
 * struct singlelist_var - this template stores variables
 * @sizeof_var: holds the sizeof the variable.
 * @value: holds the value.
 * @sizeof_val: holds the sizeof the value.
 * @next: this fields is for the next node value.
 */
typedef struct singlelist_var
{
	int sizeof_var;
	char *value;
	int sizeof_val;
	struct singlelist_var *next;
} store_var;

/**
 * struct str_builtin - this template holds builtin commands.
 * @name: holds the build command's name
 * @fonction: holds a particular data type.
 */
typedef struct str_builtin
{
	char *name;
	int (*fonction)(node_sh *nodesh);
} builtins;

#endif
