#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>
char	byte_to_char(char *byte)
{
	int	i;
	int	pow;
	char	character;

	i = 0;
	pow = 1;
	character = 0;
	while (i < 8)
	{
		character += (byte[i] - '0') * pow;
		pow = pow * 2;
		i++;
	}
	return (character);
}

void	bin_to_chars(int seg)
{
	static char	byte[9];
	static int	i;
	char	character;

	byte[8] = 0;
	while (i < 8)
	{
		if (seg == 10)
		{
			byte[i] = '0';
		}
		else {
			byte[i] = '1';
		}
		break;
	}
	i++;
	if (i == 8)
	{
		character = byte_to_char(byte);
		write(1,&character,1);
		i = 0;
	}
}
#include <stdio.h>
int main()
{
	int	pid;


	pid = getpid();
	printf("%d\n",pid);

	signal(SIGUSR1, bin_to_chars);
	signal(SIGUSR2, bin_to_chars);
	while(1)
		pause();
}
