#include "pipex.h"

char	*get_command_path(char *cmd, char *path)
{
	int		i;
	char	*cmd_path;
	char	**path_splited;

	i = 0;
	path_splited = ft_split(path, ':');
	while (path_splited[i])
	{
		cmd_path = ft_strjoin_del(path_splited[i], cmd, '/');
		if (access(cmd_path, X_OK) == 0)
		{
			free_split(path_splited);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_split(path_splited);
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			path = get_command_path(cmd, path);
			return (path);
		}
		i++;
	}
	return (NULL);
}

void	exec_program(char *cmd, char *envp[])
{
	char	*path;
	char	**cmd_splited;
		
	cmd_splited = ft_split(cmd, ' ');
	path = get_path(cmd_splited[0] , envp);
	if (!path)
	{
		free_split(cmd_splited);
		exit_program(false, "Invalid path/fail to execute command.");
	}
	if (execve(path, cmd_splited, envp) == -1)
	{
		free_split(cmd_splited);
		exit_program(true, "execution failed");
	}
}

int	check_path(char	*cmd, char **envp)
{	
	char	**cmd_splited;
	char	*path;

	cmd_splited = ft_split(cmd, ' ');
	path = get_path(cmd_splited[0] , envp);
	if (!path)
	{
		free_split(cmd_splited);
		return (EXIT_FAILURE);
	}
	free_split(cmd_splited);
	return (0);
}
