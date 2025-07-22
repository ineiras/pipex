#include <unistd.h> // fork, pipe, dup2, acces, execv, write, read, 
#include <fcntl.h>  // open, close,
#include <stdlib.h> // malloc, free, getenv
#include <stdio.h> // printf
#include <sys/wait.h> // wait, waitpid,
#include <stdbool.h>
#include "libft/libft.h"

// Main Functions:
void	parent_process(int *p_fd, char *argv[], char *envp[]);
void	child_process(int *p_fd, char *argv[], char *envp[]);

// Exdcute Program && PATH funcitons:
void	exec_program(char *cmd, char *envp[]);
char	*get_path(char *cmd, char **envp);
char	*get_command_path(char *cmd, char *path);
int		check_path(char	*cmd, char **envp);

// Utils Function:
void	exit_program(bool sys_call, char *msg);
void	free_split(char **str_splited);
