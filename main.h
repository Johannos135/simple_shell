#ifndef _MAIN_
#define _MAIN_


#include "stringfun.h"
#include "template.h"


/*prompt function prototype*/
void prompt(void);

/* message_error.c */
char *concat_error(node_sh *nodesh, char *message, char *bad,
		char *counter);
char *directory_err(node_sh *nodesh);
char *error404(node_sh *nodesh);
char *exit_error(node_sh *nodesh);
char *environ_error(node_sh *nodesh);

/*permission error*/
char *path_err(node_sh *nodesh);

/* help.c */
void environ_helper(void);
void setenv_helper(void);
void unsetenv_helper(void);
void general_info(void);
void exit_helper(void);

#endif
