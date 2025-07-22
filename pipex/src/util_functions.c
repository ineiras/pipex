#include "pipex.h"

void	exit_program(bool sys_call, char *msg)
{
	if (sys_call == false)
	{
		ft_printf("%s\n", msg);
		exit (EXIT_FAILURE);
	}
	perror(msg);
	exit (EXIT_FAILURE);
}

void	free_split(char **str_splited)
{
	int	i;

	i = 0;
	while (str_splited[i])
	{
		free(str_splited[i]);
		i++;
	}
	free(str_splited);
}
