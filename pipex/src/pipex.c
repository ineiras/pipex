#include "pipex.h"

void	parent_process(int *p_fd, char *argv[], char *envp[])
{
	int	outfile;

	if (check_path(argv[3], envp) == EXIT_FAILURE)
	{
		close(p_fd[0]);
		exit_program(false, "Wrong second command.");
	}
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		exit_program(true, "Cannot open outfile.");
	dup2(p_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(p_fd[0]);
	exec_program(argv[3], envp);
}

void	child_process(int *p_fd, char *argv[], char *envp[])
{
	int	infile;
	
	close(p_fd[0]);
	if (check_path(argv[2], envp) == EXIT_FAILURE)
		exit_program(false, "Wrong first command.");
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		exit_program(false, "Cannot open infile.");
	dup2(infile, STDIN_FILENO);
	dup2(p_fd[1], STDOUT_FILENO);
	close(infile);
	close(p_fd[1]);
	exec_program(argv[2], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pid;
	int		status;
	int		p_fd[2];

	if (argc != 5)
		exit_program(false, "Incorrect input.");
	if (pipe(p_fd) == -1)
		exit_program(true, "Pipe failed.");
	pid = fork();
	if (pid == -1)
		exit_program(true, "Fork failed");
	if (pid == 0)
		child_process(p_fd, argv, envp);
		waitpid(pid, &status, 0);
	close(p_fd[1]);
	if (!WIFEXITED(status) || WEXITSTATUS(status) == EXIT_FAILURE)
	{	
		close(p_fd[0]);
		exit(EXIT_SUCCESS);
	}
	parent_process(p_fd, argv, envp);
	return (0);
}
