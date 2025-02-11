#include <signal.h>
#include <unistd.h>
#include "Libft/libft.h"

char	*put_binary(int	num)
{
	int	i;
	char	*bin;

	i = 0;
	bin = ft_calloc(9, 1); 
	while (i < 8)
		bin[i++] = '0';
	i = 0;
	if (num < 0)
	{
		bin[7] = '1';
		num = 128 + num;
	}
	while (num)
	{
		bin[i] = num % 2 + '0';
		i++;
		num = num / 2 ;
	}
	return bin;
}

char	*handler(char *str)
{
	int	i;
	char	*bin_string;

	bin_string = malloc(sizeof(char) * ft_strlen(str) + 1);
	bin_string[0] = 0;
	i = 0;
	while (str[i])
	{
		bin_string = ft_strjoin(bin_string,put_binary(str[i]));
		i++;
	}
	return bin_string;
}
#include <stdio.h>
int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;
	int					i;

	if (ac != 3)
		return (printf("./<file.exe> <PID> <string> !!!!!!\n"));
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	pid = ft_atoi(av[1]);
	i = 0;
	while(av[2][i])
	{
		if (3)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(800);
		i++;
	}
	free(bin);
} 
